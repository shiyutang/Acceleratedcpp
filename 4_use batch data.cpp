//
// Created by Daisy on 2020/10/15.
//

#include <iostream>
#include "algorithm"
#include "iomanip"
#include "string"
#include "vector"
#include "ios"

using std::cout; using std::endl;
using std::cin; using std::sort;
using std::string; using std::vector;
using std::streamsize; using std::setprecision;

int calGrades(){
    cout << "please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello" << name << "!" << endl;

    cout << "please enter your midterm and final grades:";
    double midterm, final;
    cin >> midterm >> final;

    cout << "enter all of your Homework grades,"
            " followed by end of file";

    vector<double> homework;
    double x;

    while (cin >> x){
        homework.push_back(x);
    }

    typedef vector<double>::size_type vec_sz;
    vec_sz size = homework.size();
    if (size == 0){
        cout << endl << "you should enter your grades" << endl;
        return 1;
    }
    sort(homework.begin(),homework.end());
    vec_sz mid = size/2;  //result in integers
    double median;
    median = size%2 == 0 ? (homework[mid] + homework[mid-1])/2
                         : homework[mid];

    streamsize prec = cout.precision();
    cout << "your final grade is" << setprecision(3)
         << 0.2 * midterm + 0.4*final+0.2*median
         << setprecision(prec)<<endl;
    return 0;
}

int splitinto43_2(){
    cout << "please enter your numbers: ";
    vector<double> nums;
    double x;
    while (cin>>x){
        nums.push_back(x);
    }
    sort(nums.begin(),nums.end());

    typedef vector<double>::size_type vec_sz;
    vec_sz numsize = nums.size();
    vec_sz fouth = numsize - 1 - numsize/4;
    int begin = numsize - 1;

    for(int i=0;i!= 4; ++i){
        for (int cnt = begin; cnt != fouth; --cnt) {
            cout << nums[cnt] << " ";
        }
        cout << endl;
        begin = fouth;
        fouth = i < 2? fouth - numsize/4: -1;
    }
    return 0;
}