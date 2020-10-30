//
// Created by Daisy on 2020/10/17.
//

#include <algorithm>
#include <stdexcept>
#include <vector>

using std::domain_error; using std::sort;
using std::vector;

double median(vector<double> vec){
    typedef vector<double>::size_type vec_sz;
    vec_sz size_v = vec.size();
    vec_sz middle = size_v/2;
    if(size_v==0)
        throw domain_error("median ofr an empty vector");
    sort(vec.begin(),vec.end());
    return size_v % 2 == 1 ?  vec[middle]
                           :  (vec[middle] + vec[middle-1])/2;
}

