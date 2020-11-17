
//
// Created by Daisy on 2020/10/17.
//

#include "grade.h"
#include "Student_info.h"

using std::istream; using std::vector;

bool comp(const Student_info& x, const Student_info& y){
    return x.name<y.name;
}

istream& read_hw_op(istream& in, double mid, double final, Student_info& s){
    if (in){      //以防预先已经出错
        vector<double> hw; // 清楚之前的数据
        double x;
        while (in >> x)
            hw.push_back(x);
        s.final_res = calgrade(mid, final, hw);
        // 最后重置输入流的状态，清除之前的错误标记，从而输入可以继续
        in.clear();
    }
    return in;
}

istream& read_op(istream& is, Student_info& s){
    double midterm,final;
    is >> s.name >> midterm >> final;
    read_hw_op(is,midterm,final,s);
    return is;
}



