//
// Created by Daisy on 2020/11/12.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <numeric>

using namespace std;

bool space(char c)
{
    return isspace(c);
}

bool not_space(char c){
    return !isspace(c);
}

vector<string> split(const string& str){
    typedef string::const_iterator iter;
    vector<string> ret;

    iter i = str.begin();  // 字符串可以有迭代器，但是字符数组不可以
    while (i!= str.end()){
        i = find_if(i,str.end(),not_space);
        iter j = find_if(i, str.end(),space);
        if (i!= str.end())
            ret.push_back(string(i,j));
        i = j;
    }
    return ret;
}

bool is_palindrome(const string& s){
    return equal(s.begin(),s.end(),s.rbegin());
}

int librarymain(){
    // build bottom
    vector<string> bottom;
    string str[] = { "one", "two"};
    bottom = vector<string>(str,str+(sizeof(str)/sizeof(string)));

    vector<string> ret;
    for(vector<string>::const_iterator it = bottom.begin();
        it != bottom.end(); ++it)
        ret.push_back(*it);
    ret.insert(ret.end(), bottom.begin(), bottom.end());
    copy(bottom.begin(),bottom.end(),back_inserter(ret));

    for (vector<string>::const_iterator it = ret.begin();
         it!=ret.end(); ++it)
         cout << *it << endl;

    string longstr = "  I am a good student";
    vector<string> split_res = split(longstr);


    for (vector<string>::const_iterator it=split_res.begin();
         it!=split_res.end();++it)
        cout << *it <<endl;

    string ress = accumulate(split_res.begin(),split_res.end(), string(""));
    cout << "ress" << ress;

    return 0;
}