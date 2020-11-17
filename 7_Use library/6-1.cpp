//
// Created by Daisy on 2020/11/17.
//
# include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "using library.h"

using namespace std;


string::size_type width(const vector<string>& v)
{
    string::size_type maxlen = 0;  // 注意初始化，不然会是一个很大值
    for(auto it = v.begin(); it != v.end(); ++it)
    {
        if((*it).size() > maxlen)
            maxlen = (*it).size();
    }
    return maxlen;
}

vector<string> frame(const vector<string>& v)
{
    vector<string> ret;
    string::size_type maxlen = width(v);
    string border(maxlen+4, '*');
    cout<<"maxlen"<<maxlen<<endl;

    ret.push_back(border);

    for(vector<string>::const_iterator it = v.begin(); it != v.end(); ++it)
    {
        ret.push_back("* " + *it + string(maxlen-(*it).size(), ' ') + " *");
    }
    ret.push_back(border);
    return ret;
}

vector<string> hcat(const vector<string>& left,
                    const vector<string>& right)
{
    vector<string> ret;
    string::size_type  widthl = width(left) + 1;

    vector<string>::const_iterator itl = left.begin(), itr = right.begin();

    while (itl!=left.end() || itr != right.end())
    {
        string s;
        if(itl!=left.end())
        {
            s = *itl;
            itl++;
        }
        s += string(widthl-s.size(), ' ');
        if(itr!=right.end())
        {
            s += (*itr);
            itr ++;
        }
        ret.push_back(s);
    }
    return ret;
}


int exermain(){
    string longstr = "  I am a good student";
    string str = "Me too";
    vector<string> left = split(longstr);
    vector<string> right = split(str);

//    for(auto v = split_res.begin();v!=split_res.end();++v)
//    {
//        cout << *v << endl;
//    }
    vector<string> res1 = frame(left);
    vector<string> res = hcat(left, right);
    for(auto v = res1.begin();v!=res1.end();++v)
    {
        cout << *v << endl;
    }
    for(auto v = res.begin();v!=res.end();++v)
    {
        cout << *v << endl;
    }
    vector<int> u(10,100);
    vector<int> v;
    copy(u.begin(), u.end(), back_inserter(v));
    v.insert(v.begin(),u.begin(), u.end());
    for (vector<int>::const_iterator it= v.begin();  it!= v.end(); it++)
    {
        cout << *it << endl;
    }
}