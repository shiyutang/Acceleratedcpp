//
// Created by Daisy on 2020/11/15.
//

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

struct Student_infor{
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};

istream& read_hw(istream& in, Student_infor& s){
    if (in){      //以防预先已经出错
        vector<double> hw; // clear 之前的数据
        double x;
        while (in >> x)
            hw.push_back(x);
        // 最后重置输入流的状态，清除之前的错误标记，从而输入可以继续
        in.clear();
    }
    return in;
}


istream& read(istream& is, Student_infor& s){
    double midterm,final;
    is >> s.name >> midterm >> final;
    read_hw(is,s);
    return is;
}

bool did_all_hw(Student_infor stu)
{
    return (find(stu.homework.begin(),stu.homework.end(),0) == stu.homework.end());
}

double mmedian(vector<double> vec){
    typedef vector<double>::size_type vec_sz;
    vec_sz size_v = vec.size();
    vec_sz middle = size_v/2;
    if(size_v==0)
        throw domain_error("median of an empty vector");
    sort(vec.begin(),vec.end());
    return size_v % 2 == 1 ?  vec[middle]
                           :  (vec[middle] + vec[middle-1])/2;
}

double average(const vector<double>& v)
{
    return accumulate(v.begin(),v.end(),0.0)/v.size();
}

double average_grade(const Student_infor& s)
{
    return 0.2*s.midterm+0.4*s.final+0.4*average(s.homework);
}


double optimistic_median(const Student_infor& s)
{
    vector<double> nonzero;
    remove_copy(s.homework.begin(), s.homework.end(),
                back_inserter(nonzero), 0);
    if (nonzero.empty())
        return 0.2*s.midterm+0.4*s.final;
    else
        return 0.2*s.midterm+0.4*s.final+0.4*mmedian(nonzero);
}

double ggrade(double midterm, double final, const vector<double> &hw){
    if(hw.empty())
        throw domain_error("This student has done no homework");
    return 0.2*midterm+0.4*final+0.4*mmedian(hw);
}

double grade(const Student_infor& s){
    return ggrade(s.midterm, s.final, s.homework);
}


double grade_aux(const Student_infor& s)
{
    try {
        return grade(s);
    } catch (domain_error)
    {
        return 0.2*s.midterm+0.4*s.final;
    }
}


double analyze(const vector<Student_infor>& s,
               double func(const Student_infor&))
{
    vector<double> grades;
    transform(s.begin(),s.end(),
              back_inserter(grades), func);
    return mmedian(grades);
}

void write_analysis(ostream& out, const string& name,
                    double analyze(const vector<Student_infor>& s,
                                   double func(const Student_infor&)),
                    double function(const Student_infor& s),
                    const vector<Student_infor>& did,
                    const vector<Student_infor>& didnt)
{
    out << name << "median(did) = " << analyze(did,function) <<
           "median(didnt) = " << analyze(didnt,function) << endl;
}


int studentmain()
{
    vector<Student_infor> did, didnt;

    Student_infor student;
    while (read(cin,student))
    {
        if (did_all_hw(student))
            did.push_back(student);
        else
            didnt.push_back(student);
    }
    if (did.empty()){
        cout << "No student did all the homework" << endl;
        return 1;
    }
    else{
        cout << "All student did all the homework" << endl;
        return 1;
    }

    write_analysis(cout,"median", analyze, grade_aux, did, didnt);
    write_analysis(cout,"average", analyze, average_grade, did, didnt);
    write_analysis(cout,"median of work turned in", analyze,optimistic_median, did, didnt);
    return 0;
}
