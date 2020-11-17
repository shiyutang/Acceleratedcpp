//
// Created by Daisy on 2020/10/17.
//
#include <stdexcept>
#include <vector>
#include <algorithm>

using std::domain_error; using std::vector;
using std::domain_error; using std::sort;
using std::vector;

double med(vector<double> vec){
    typedef vector<double>::size_type vec_sz;
    vec_sz size_v = vec.size();
    vec_sz middle = size_v/2;
    if(size_v==0)
        throw domain_error("median ofr an empty vector");
    sort(vec.begin(),vec.end());
    return size_v % 2 == 1 ?  vec[middle]
                           :  (vec[middle] + vec[middle-1])/2;
}


double calgrade(double midterm, double final, const vector<double>& hw){
    if(hw.size() == 0)
        throw domain_error("This student has done no homework");
    return 0.2*midterm+0.4*final+0.4*med(hw);
}

