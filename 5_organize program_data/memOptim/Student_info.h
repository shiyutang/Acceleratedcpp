//
// Created by Daisy on 2020/10/17.
//

#ifndef ACCLERATEDCPP_STUDENT_INFO_H
#define ACCLERATEDCPP_STUDENT_INFO_H

#include <iostream>
#include <string>
#include <vector>

struct Student_info{
    std::string name;
    double final_res;
};

bool comp(const Student_info&, const Student_info&);
std::istream& read_op(std::istream&,Student_info&);
std::istream& read_hw_op(std::istream&,double,double,Student_info&);
#endif //ACCLERATEDCPP_STUDENT_INFO_H
