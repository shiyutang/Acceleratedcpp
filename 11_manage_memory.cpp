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

    static const char *letters[] =
            {"A+","A","A-","B+","B","B-","C+","C","C-","D","F"};

    static const std::size_t ngrades = sizeof(numbers) / sizeof(*numbers);

    for (std::size_t i = 0; i < ngrades; ++i)
    {
        if (grade>=numbers[i])
            return letters[i];
    };
    return "?\?\?";
}

void gradetoletter()
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
}



template <class T,class M>
M median(T v)
{
    std::size_t size = sizeof(v)/sizeof(*v);
    if (size == 0)
        throw domain_error("median of an empty vector");

    sort(v, v+size);
    std::size_t mid = size / 2;

    return size %2 ==0 ? &((*(v+mid) + *(v+mid+1)) / 2) : v+mid;
}

int main()
{
    int numbers[] =
            {3,2,4,67,3,1,2,4};
    int a = median(*numbers);
    cout << a << endl;
    for(std::size_t i =0; i < sizeof(numbers)/sizeof((*numbers)); ++i)
    {
        cout << *(numbers+i)<< endl;
    }

    vector<double> nums(numbers, numbers+8);
    double b = median(&nums);
    cout << b << endl;
    std::list<double > student;
    student.sort();
    return 0;
}

