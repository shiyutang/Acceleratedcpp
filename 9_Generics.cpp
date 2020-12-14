//
// Created by Daisy on 2020/11/18.
//

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <list>
#include <algorithm>
#include "7_Use library/using library.h"

using namespace std;

template <class T>
T median(vector<T> v)
{
 typedef typename vector<T>::size_type vec_sz;
 vec_sz size = v.size();
 if (size == 0)
     throw domain_error("median of an empty vector");

 sort(v.begin(), v.end());
 vec_sz mid = size / 2;

 return size %2 ==0 ? (v[mid] + v[mid+1]) / 2 : v[mid];
}

// 输入迭代器：顺序只读
template <class In, class X>
In find_diy(In begin,In end,const X& x)
{
    while(begin!=end && *begin!=x)
        ++begin;
    return begin;
}

// 输出迭代器：顺序只写: 单次不跳过，且不重复写入
template <class In, class Out>
Out copy_diy(In begin,In end,Out dest)
{
    while(begin!=end)
        *dest++ = *begin++;

    return dest;
}

// 正向迭代器：顺序读写--不访问前面一个元素
template <class For, class X>
void replace_diy(For begin, For end, const X& x, const X& y)
{
    while (begin != end)
    {
        if (*begin ==x)
            *begin = y;
        ++begin;
    }
}
//双向迭代器：正向迭代器+可逆访问
template <class Bi>
void reverse_diy(Bi begin, Bi end)
{
    vector<pair<const int, string> > a;
    
    while (begin!=end)
    {
        --end;
        if (begin != end)
            swap(*begin++, *end);
    }
}

// 随机访问：相减为整数类型，随机访问，整数相加得到新的迭代器（移位）

template <class Ran, class X>
bool binary_search_diy(Ran begin, Ran end, const X& x)
{
    while (begin<end)
    {
        Ran mid = begin +(end-begin)/2;
        if (x<*mid)
            end = mid;
        else if (*mid <x)
            begin = mid +1;
        else return true;
    }
    return false;
}

template <class Out>

void split_iter(const string& str, Out os){
    typedef string::const_iterator iter;
    vector<string> ret;

    iter i = str.begin();  // 字符串可以有迭代器，但是字符数组不可以
    while (i!= str.end()){
        i = find_if(i,str.end(),not_space);
        iter j = find_if(i, str.end(),space);
        if (i!= str.end())
            *os++ = string(i,j);
        i = j;
    }

}

#include <iterator>

int generics()
{
    string str;
    vector<string> str_vec;
    vector<string> str_vec_copy;
    while (getline(cin,str))
    {
        split_iter(str, ostream_iterator<string>(cout, "\n"));

        split_iter(str, back_inserter(str_vec));
        bool findthe = binary_search_diy(str_vec.begin(),str_vec.end(), "the");
        cout << "found the: " << findthe << endl;

        auto findthe2 = find_diy(str_vec.begin(),str_vec.end(), "the");
        cout << "found the at: " << *findthe2 << endl;


        reverse_diy(str_vec.begin(), str_vec.end());
        cout << "after reverse: ";
        for (auto  it = str_vec.begin(); it != str_vec.end(); it++)
            cout << (*it) << " " ;

//        reverse_diy_noswap(str_vec.begin(), str_vec.end());
//        cout << "after reverse_noswap: ";
//        for (auto  it = str_vec.begin(); it != str_vec.end(); it++)
//            cout << (*it) << " " ;

        replace_diy(str_vec.begin(), str_vec.end(), "t", "r");
        cout << endl << "after replace_diy: ";
        for (auto  it = str_vec.begin(); it != str_vec.end(); it++)
            cout << (*it) << " ";

        copy_diy(str_vec.begin(), str_vec.end(), back_inserter(str_vec_copy));
        cout << endl << "after copy_diy: ";
        for (auto  it = str_vec_copy.begin(); it != str_vec_copy.end(); it++)
            cout << (*it) << " ";

    }
    return 0;
}
//I like playing the piano r t