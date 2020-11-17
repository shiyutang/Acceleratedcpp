//
// Created by Daisy on 2020/10/17.
//
#include <iostream>
#include <vector>
#include "Student_info.h"

using std::istream; using std::vector;

bool compare(const Student_info& x, const Student_info& y){
    return x.name<y.name;
}

istream& read_hw(istream& in, vector<double>& hw){
    if (in){      //以防预先已经出错
        hw.clear(); // 清楚之前的数据

        double x;
        while (in >> x)
            hw.push_back(x);

        // 最后重置输入流的状态，清除之前的错误标记，从而输入可以继续
        in.clear();
    }
    return in;
}

istream& read(istream& is,Student_info& s){
    is >> s.name >> s.midterm >> s.final;
    read_hw(is,s.homework);
    return is;
}
