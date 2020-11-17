//
// Created by Daisy on 2020/10/17.
//
#include <iostream>
#include <string>

using std::cout;using std::string;
using std::endl;

int pmain0(){
    double start=1,end=101;
    string endstr = std::to_string(end);
    string::size_type maxlen = endstr.size();

    for(int i=start;i!=end;++i){
        int res = i*i;
        string name = std::to_string(i);
        string spaces(maxlen-name.size(),' ');
        cout << spaces << i << ' '<< res << endl;
    }
    return 0;
}