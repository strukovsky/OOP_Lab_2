//
// Created by strukovsky on 03.10.2020.
//

#include "../header/Person.h"
#include <cstring>
Person::Person(char *_surname, char *_name, char *_patronymic): surname(_surname), name(_name), patronymic(_patronymic) {

}

Person::Person() {
    surname = new char[0];
    name = new char[0];
    patronymic = new char[0];
}

int Person::compare(const Person &other) const {
    return strcmp(surname, other.surname) + strcmp(name, other.name) + strcmp(patronymic, other.patronymic);
}

ostream &operator<<(ostream &o, const Person &p) {
    return o<<p.surname<<" "<<p.name<<" "<<p.patronymic;
}

istream &operator>>(istream &i, Person &p) {
    i>>p.surname;
    i>>p.name;
    i>>p.patronymic;
    return i;
}
