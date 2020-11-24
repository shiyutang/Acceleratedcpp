//
// Created by Daisy on 2020/11/17.
//
#include <string>
#include <map>
#include <iostream>
#include <cctype>
#include <vector>
#include "7_Use library/using library.h"

using namespace std;

int coutfreq()
{
    string s;
    map<string, int> counters;
    int cnt = 0;
    while (cin >> s and cnt < 10) {
        cnt = cnt +  1;
        cout << cnt;
        ++counters[s];
    }

    for(map<string,int>::const_iterator it= counters.begin();
        it != counters.end(); ++it)
    {
        cout << it->first << "\t" << it->second << endl;
        cout << (*it).first << "\t" << it->second << endl;
    }
    return 0;
}

// 得到每一行的单词，并记录其出现的位置
// 分割函数作为参数，给函数的功能增加了很多可能性
map<string, vector<int> > xref(istream& in,
                               vector<string> find_words(const string&) = split)
{
    string line;
    int line_num = 0;
    map<string, vector<int> > ret;

    while (getline(in,line) and line_num <10)
    {
        ++line_num;

        vector<string> words = find_words(line);
        for(auto it = words.begin();it != words.end(); ++it)
            ret[*it].push_back(line_num);
    }
    return ret;
}

int corremain()
{
    map<string, vector<int> > ret = xref(cin);
    for (auto it = ret.begin(); it != ret.end(); ++it)
    {
        cout << it->first << " occur on line(s): ";
        vector<int>::const_iterator  line_it = it->second.begin();
        cout << *line_it;
        ++line_it;
        while (line_it != it->second.end())
        {
            cout << ", "<<*line_it;
            ++line_it;
        }
        cout << endl;
    }
    return 0;
}




