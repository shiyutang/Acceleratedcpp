//
// Created by Daisy on 2020/10/17.
//

#include <iostream>
#include <list>

using std::list;

struct Student_info{
    std::string name;
    double midterm, final, homework;
};

double grade1(double midterm, double final, double homework){
    return 0.2*midterm+0.4*final+0.4*homework;
}

double grade2(const Student_info& s){
    return grade1(s.midterm, s.final, s.homework);
}

bool fgrade(const Student_info& s){
    return grade2(s) < 60;
}

list<Student_info> extract_fais(list<Student_info>& students){
    list<Student_info> fail;
    list<Student_info>::iterator iter = students.begin();

    while (iter != students.end()){
        if (fgrade(*iter)){
            fail.push_back(*iter);
            iter = students.erase(iter);
        }
        else ++iter;
    }
    return fail;
}

int pmain() {
    list<Student_info> student;
    list<Student_info> fail;
    fail = extract_fais(student);
    return 0;
}