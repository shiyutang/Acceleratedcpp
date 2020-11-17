//
// Created by Daisy on 2020/11/17.
//

#ifndef ACCLERATEDCPP_STUDENTGRADE_H
#define ACCLERATEDCPP_STUDENTGRADE_H

#include <string>
#include <vector>

using namespace std;

struct Student_infor{
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};

istream& read_hw(istream& in, Student_infor&);
istream& read(istream& is, Student_infor&);
bool did_all_hw(Student_infor);
double mmedian(vector<double>);
double average(const vector<double>&);
double average_grade(const Student_infor&);
double optimistic_median(const Student_infor&);
double grade(const Student_infor&);
double grade_aux(const Student_infor&);
void write_analysis(ostream&, const string&,
                    double analysis(const vector<Student_infor>&),
                    const vector<Student_infor>&,
                    const vector<Student_infor>&);

#endif //ACCLERATEDCPP_STUDENTGRADE_H
