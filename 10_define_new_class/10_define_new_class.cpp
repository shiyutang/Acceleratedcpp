//
// Created by Daisy on 2020/12/14.
//

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include "../5_organize program_data/original/grade.h"

using std::istream;
using namespace std;

class Student_info_dnc{
private:
    std::string n;
    double midterm, final;
    std::vector<double> homework;
    std::istream& readhw(std::istream&);

public:
    std::istream& read(std::istream&);
    double grade() const;
    std::string name() const {return n;}
    bool valid() const {return  !homework.empty();}
    Student_info_dnc(): midterm(0),final(0) {};
    Student_info_dnc(std::istream& in) {read(in);};
};

double Student_info_dnc::grade() const
{
    return ::calgrade(midterm,final,homework);
}

bool compare_dnc(const  Student_info_dnc& x, const  Student_info_dnc& y)
{
    return x.name() < y.name();
}

bool compare_dnc_pass(const  Student_info_dnc& x, const  Student_info_dnc& y)
{
    return x.grade() > y.grade();
}

std::istream& Student_info_dnc::readhw(std::istream& in){
    if(in){
        homework.clear();
        double x;
        while(in>>x)
            homework.push_back(x);

        in.clear();
    }
    return in;
}

std::istream& Student_info_dnc::read(std::istream& in ) {
    in >> n >> midterm >> final;
    readhw(in);
    return in;
};

string PF_grade(double grade)
{
    if(grade>60)
        return "P";
    else
        return "F";
}



int dnc()
{
    vector<Student_info_dnc> students;
    Student_info_dnc record;
    string::size_type maxlen = 0;

    while (record.read(cin))
    {
        maxlen = max(maxlen, record.name().size());
        students.push_back(record);
    }

    sort(students.begin(),students.end(), compare_dnc);

    for (vector<Student_info_dnc>::size_type i = 0; i!=students.size(); ++i)
    {
        cout <<setw(maxlen+1) << students[i].name();
        if (students[i].valid()){
            double final_grade = students[i].grade();
            streamsize prec = cout.precision();
            cout << setprecision(3)
            <<setw(maxlen+1) << final_grade
            <<setw(maxlen+1) << PF_grade(final_grade)
            << setprecision(prec) << endl;
        }
        else
            cout << " This student didn't submit homework" << endl;
    }

//    sort(students.begin(), students.end(), compare_dnc_pass);

    return 0;
}


//d 80 90 80 80 80 80
//c 80 90 80 80 80 80
//a 80 90 44 34 23 12
//e 80 90 80 80 80 80
//b 80 90
// end of file


//d 80 90 80 80 80 80
//c 20 40 30 30 10 80
//a 80 90 44 34 23 12
//e 20 10 30 10 20 20
//b 80 90 10
// end of file
