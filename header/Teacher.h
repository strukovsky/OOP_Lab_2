//
// Created by strukovsky on 03.10.2020.
//

#ifndef LAB2_TEACHER_H
#define LAB2_TEACHER_H
#include <vector>
#include <iostream>
#include "Person.h"
using namespace std;
class Teacher {
    int department;
    Person person;
    int status;
    static int count;

public:
    explicit Teacher();
    explicit Teacher(int, char*,char*,char*, int);
    explicit Teacher(const Teacher&);

    static Teacher* search(Teacher[], const Person&);
    static vector<Teacher>* filter(Teacher[], int);
    static void sort(Teacher[]);
    static void add(Teacher[], int, const Person&, int);
    static void add(Teacher[], const Teacher&);
    friend ostream& operator<<(ostream&, Teacher&);
    static int get_count(){return count;}
    static void describe(Teacher *pTeacher);
    static int count_of_person(Teacher *, const Teacher&);
    static void quit(Teacher *pTeacher);
};


#endif //LAB2_TEACHER_H
