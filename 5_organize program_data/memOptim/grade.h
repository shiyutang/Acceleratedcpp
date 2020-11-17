#ifndef ACCLERATEDCPP_GRADE_H
//
// Created by Daisy on 2020/10/17.
//
#define ACCLERATEDCPP_GRADE_H
#include <vector>
#include "Student_info.h"

double med(std::vector<double>);
double calgrade(double midterm, double final, const std::vector<double> &hw);
#endif //ACCLERATEDCPP_GRADE_H
