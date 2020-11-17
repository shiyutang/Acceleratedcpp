#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"

using std::cin;using std::setprecision;
using std::cout;using std::sort;
using std::domain_error;using std::streamsize;
using std::endl; using std::string;
using std::max; using std::vector;
using std::setw;

int pmain1(){
    vector<Student_info> students;
    Student_info record;
    string::size_type  maxlen= 0;

    while (read_op(cin, record)){
        maxlen = max(maxlen,record.name.size());
        students.push_back(record);
    }

    sort(students.begin(),students.end(), comp);
    for (std::vector<Student_info>::size_type i = 0;
         i!=students.size(); ++i){
        cout<< setw(maxlen) << students[i].name
            << ' ';

        try {
            streamsize prec = cout.precision();
            cout<<setprecision(3)<<students[i].final_res << endl
                << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }
    }
    return 0;
}

//amy 11 12 31 12 41
//howard 23 22 34 63 51
//f
//f