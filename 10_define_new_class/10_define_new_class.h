//
// Created by Daisy on 2020/12/14.
//

#include <string>
#include <vector>

#ifndef ACCLERATEDCPP_10_DEFINE_NEW_CLASS_H
#define ACCLERATEDCPP_10_DEFINE_NEW_CLASS_H

#endif //ACCLERATEDCPP_10_DEFINE_NEW_CLASS_H

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
    bool valid() const;
    Student_info_dnc(): midterm(0),final(0) {};
    Student_info_dnc(std::istream&) ;
};

bool compare_dnc(const  Student_info_dnc&, const  Student_info_dnc&);
std::string PF_grade(double );