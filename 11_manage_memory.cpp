//
// Created by Daisy on 2020/12/14.
//

#include <vector>
#include <string>
#include <random>
#include <iostream>
#include <fstream>
#include <cfloat>
#include <cstring>
#include <algorithm>
#include <list>
#include "7_Use library/using library.h"

using namespace std;
typedef double (*analysis_fp)(const  std::vector<double >&);

analysis_fp get_analysis_ptr(){
    analysis_fp pointer= nullptr;
    int* p = new int(42);
    ++ *p;
    cout << *p << endl;
    delete p;
    int* pp = new int[20];
    cout << pp[0] << endl;
    vector<int> v(pp, pp+20);
    delete [] pp;

    return pointer;
}

string letter_grade(double grade)
{
    static const double numbers[] =
            {97,94,90,87,84,80,77,74,70,60,0};

    static const char* letters[] =
            {"Ap","An","A-","B+","Bn","B-","C+","Cn","C-","Dn","Fn"};

//    static const std::size_t ngrades = sizeof(numbers) / sizeof(*numbers);
    static const std::size_t ngrades = sizeof(letters) / sizeof(*letters);

    cout <<"Letters" << **letters << ngrades << endl;
    for (std::size_t i = 0; i < ngrades; ++i)
    {
        if (grade>=numbers[i])
            return letters[i];
    };
    return "?\?\?";
}

int testlettergrade()
{
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0,100);
    for(int i=0; i<30; ++i)
    {
        int grade = dist(mt);
        cout << "The grade is: " << grade
        << ", And the letter grade is: "
        << letter_grade(grade) << endl;
    }
    return 0 ;
}

int passparamsTomain(int argc, char** argv)  // 指针数组的指针
{
    if (argc>1)
    {
        int i;
        for(i=1; i< argc-1; ++i )
            cout << argv[i] << " ";
        cout << argv[i] << endl;
    }
    return 0;
}

int copyin()
{
    ifstream  infile(R"(E:\Projects\Accleratedcpp\in.txt)");
    ofstream  outfile(R"(E:\Projects\Accleratedcpp\out.txt)");
    string s;
    while (getline(infile, s))
        outfile << s << endl;
    cout << "gfdgdsss{" << endl;
    return 0;
}

int copymultiin(int argc, char ** argv)
{
    int failcnt = 0;
    ofstream outfile(R"(E:\Projects\Accleratedcpp\out.txt)");
    for (int i= 1; i<argc; ++i)
    {
        ifstream  in(argv[i]);
        if(in)
        {
            string s;
            while(getline(in, s))
                outfile << s << endl;
        }else
        {
            cerr << "cannot open file" << argv[i] << endl;
            ++ failcnt;
        }
    }
    return failcnt;
}

const char* duplicate_chars(const char * p)
{
    size_t length = strlen(p) + 1;
    char* result = new char[length];
    copy(p,p+length, result);
    return result;
}

int testduplicate()
{
    const char letters[] =
            {'a','v','A','B','C','e','d','D','F','\0'};
    const char* p = duplicate_chars(letters);
    for(std::size_t i =0; i < sizeof(letters)/sizeof((*letters)); ++i)
    {
        cout << *(p+i)<< endl;
    }
    cout << letters << endl;
    return 0;
}

template <class In, class ret>
ret median(In begin, In end, ret num)
{
    ptrdiff_t size = end-begin;
    if (size == 0)
        throw domain_error("median of an empty vector");

    ret* copyobj = new ret;
    copy(begin, end, copyobj);

    sort(copyobj, copyobj+size);
    ptrdiff_t mid = size / 2;

    num = size %2 ==0 ? (*(copyobj+mid) + *(copyobj+ mid+1)) / 2 : *(copyobj+mid);
    delete copyobj;

    return num;
}

int testmedian()
{
    int numbers[] = {3,2,4,67,3,1,2,4};
    int a = median(numbers, numbers+sizeof(numbers)/sizeof((*numbers)),numbers[0]);
    cout <<"a: "<<  a << endl;
    for(std::size_t i =0; i < sizeof(numbers)/sizeof((*numbers)); ++i)
    {
        cout << *(numbers+i)<< " ";
    }

    vector<int> nums(numbers, numbers+8);
    int b = median(nums.begin(), nums.end(), nums[0]);
    cout << "b: " << b << endl;
    for(std::size_t i =0; i < nums.size(); ++i)
    {
        cout << *(nums.begin()+i)<< " ";
    }
    return 0;
}

template<class T>
class strLList
{
public:
    typedef T* iterator;
    typedef const T * const_iterator;
    typedef size_t size_type;

    iterator begin(){return data;};
    const_iterator begin() const {return data;};
    iterator end(){return avail;};
    const_iterator end() const {return avail;};

    void push_back(T& str)
    {
        if (avail == limit)
            grow();
        unchecked_append(str);
    }

private:
    iterator data;
    iterator avail;
    iterator limit;
    void grow();
    void unchecked_append(const T &);
    void uncreate();
    allocator<string> alloc;

};

template<class T>
void strLList<T>::grow()
{
    size_type new_size = max(2*(limit-data),std::ptrdiff_t(1));

    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = uninitialized_copy(data,avail,new_data);

    uncreate();
    data = new_data;
    avail = new_avail;
    limit = data+new_size;
}

template<class T>
void strLList<T>::unchecked_append(const T & str)
{
    alloc.construct(avail++, str);
}

template<class T>
void strLList<T>::uncreate()
{
    if(data)
    {
        iterator it = avail;
        while (it!=data)
            alloc.destroy(--it);
        alloc.deallocate(data,limit-data);
    }
    data = limit = avail = 0;
};


strLList<string> split(string& str){
    typedef string::const_iterator iter;
    strLList<string> ret;

    iter i = str.begin();
    while (i!= str.end()){
        i = find_if(i, str.end(),not_space);
        iter j = find_if(i, str.end(),space);
        if (i!= str.end())
            ret.push_back(string(i,j));
        i = j;
    }
    return ret;
}


int strLListmain()
{
    string longstr = "  I am a good student";
    strLList<string> split_res = split(longstr);
    for (string* ii = split_res.begin(); ii !=split_res.end(); ++ii )
    {
        cout << ii << endl;
    }
    return 0;
}