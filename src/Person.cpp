//
// Created by strukovsky on 03.10.2020.
//

#include "../header/Person.h"
#include <cstring>

char Person::buff[4096];

Person::Person(char *_surname, char *_name, char *_patronymic): surname(_surname), name(_name), patronymic(_patronymic) {

}

Person::Person() {
    surname = nullptr;
    name = nullptr;
    patronymic = nullptr;
}

int Person::compare(const Person &other) const {
    return strcmp(surname, other.surname) + strcmp(name, other.name) + strcmp(patronymic, other.patronymic);
}

ostream &operator<<(ostream &o, const Person &p) {
    return o<<p.surname<<" "<<p.name<<" "<<p.patronymic;
}

istream &operator>>(istream &i, Person &p) {
    Person::input_field(i, p.surname);
    Person::input_field(i, p.name);
    Person::input_field(i, p.patronymic);

    return i;
}


void Person::input_field(istream &i, char *&field) {
    i>>Person::buff;
    delete []field;
    field = new char[strlen(Person::buff) + 1];
    strcpy(field, buff);

}

Person::~Person() {
//    delete surname;
//    delete name;
//    delete patronymic;

}

Person::Person(Person& p) {
    delete []surname;
     surname = new char[strlen(p.surname)+1];
     strcpy(surname,p.surname);
     delete []name;
     name = new char[strlen(p.name )+1];
     strcpy(name, p.name);
     delete [] patronymic;
     patronymic = new char[strlen(p.patronymic) + 1];
     strcpy(patronymic, p.patronymic);
}


