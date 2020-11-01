//
// Created by strukovsky on 01.11.2020.
//

#ifndef LAB2_LEARNER_H
#define LAB2_LEARNER_H
#include "Man.h"
#include "Departament.h"
#include <iostream>
class Learner {
    Departament departament;
    int number_of_group;
public:
    Learner(char*_name, char* _surname, int _year_of_edu, Departament _departament, int _number_of_group):
    man(_name, _surname, _year_of_edu), departament(_departament), number_of_group(_number_of_group)
    {

    }


    friend ostream& operator<<(ostream&, const Learner&);
    friend istream& operator>>(istream&, Learner&);

    void setMan(Man m);
    void setDepartament(int d);
    void setNumberOfGroup(int n);

    Learner();


    Man man;
};


#endif //LAB2_LEARNER_H
