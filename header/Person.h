//
// Created by strukovsky on 03.10.2020.
//

#ifndef LAB2_PERSON_H
#define LAB2_PERSON_H
#include <iostream>
using namespace std;
class Person {
    char *surname;
    char *name;
    char *patronymic;
public:
    explicit Person(char *, char*, char*);
    Person();
    int compare(const Person& other) const;
    friend ostream& operator<<(ostream&, const Person&);
    friend istream& operator>>(istream&, Person&);

};


#endif //LAB2_PERSON_H
