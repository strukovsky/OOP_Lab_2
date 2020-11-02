//
// Created by strukovsky on 03.10.2020.
//

#ifndef LAB2_PREPOD_H
#define LAB2_PREPOD_H
#include <vector>
#include <iostream>
#include "Person.h"
using namespace std;
class Prepod {
protected:
    static int count;

public:
    explicit Prepod();
    ~Prepod();
    explicit Prepod(int, char*, char*, char*, int);
    explicit Prepod(const Prepod&);

    friend Prepod* search(Prepod[], const Person&);
    friend vector<Prepod>* filter(Prepod[], int);

    static void sort(Prepod[]);
    static void add(Prepod[], int, Person&, int);
    static void add_last_elem(Prepod *table, const Prepod &t);

    friend ostream& operator<<(ostream&, Prepod&);
    bool operator == (const Person& p) const;
    bool operator == (const Prepod& p) const;

    static int get_count(){return count;}
    static void describe(Prepod *pTeacher);
    static int find_count_of_object(Prepod *, const Prepod&);
    static void quit(Prepod *pTeacher);

    virtual string toString();

    int status;
    Person person;
    int department;
};


#endif //LAB2_PREPOD_H
