//
// Created by strukovsky on 03.10.2020.
//

#include <cstring>
#include "../header/Prepod.h"
#include "../header/Teacher.h"
#include <fstream>
#include <sstream>
int Prepod::count;

Prepod::Prepod()
{
    department = 0;
    person = Person();
    status = 0;
}


Prepod::Prepod(int _department, char *surname, char* name, char* patronymic, int _status) :
        department(_department),
        person(surname, name, patronymic),
        status(_status) {

}




Prepod* search(Prepod *table, const Person& query) {
    Prepod *current = nullptr;
    for (int i = 0; i < Prepod::count; i++) {
        current = &table[i];
        if (*current == query)
            break;
    }
    return current;
}

vector<Prepod> *filter(Prepod *table, int status) {
    auto *result = new vector<Prepod>;
    for (int i = 0; i < Prepod::count; i++) {
      if (table[i].status == status)
      {
          Prepod t;
          t.status = status;
          t.department = table[i].department;
          t.person =*(new Person(table[i].person)) ;
          result->push_back(t);
      }
    }
    return result;
}

void Prepod::sort(Prepod *table) {
    for (int i = count - 1; i >= 0; i--) {
        for (int j = 0; j < i; ++j) {
            if (table[i].person.compare(table[j].person) < 0) {
                Prepod tmp(table[i]);
                table[i] = table[j];
                table[j] = tmp;
            }
        }
    }
}

ostream &operator<<(ostream &o, Prepod &t) {
    o << t.person << " From department ";
    switch (t.department) {
        case 1:
            o<<"IPOVS";
            break;
        case 2:
            o<<"VM";
            break;
        case 3:
            o<<"VT";
            break;
    }
    o<<" With status ";
    switch (t.status) {
        case 1:
            o<<"teacher";
            break;
        case 2:
            o<<"Docent";
            break;
        case 3:
            o<<"Ph. D";
    }
    o<< endl;
    return o;
}

void Prepod::add(Prepod table[], int _department, Person& p, int _status) {
    table[count].status = _status;
    table[count].person = p;
    table[count].department = _department;
    count++;

}

void Prepod::add_last_elem(Prepod *table, const Prepod &t) {
    table[count].status = t.status;
    table[count].person = t.person;
    table[count].department = t.department;
    count++;
}




void Prepod::quit(Prepod *table) {
    ofstream f;
    f.open("base.txt", ios::out);
    if (f.is_open()) {
        for (int i = 0; i < count; ++i) {
            f<<table[i];
        }
    }
    f.close();
}



Prepod::Prepod(const Prepod& t) {
    this->status = t.status;
    this->person = t.person;
    this->department = t.department;
}

int Prepod::find_count_of_object(Prepod *table, const Prepod& p) {
    int result = 0;
    Prepod *current = nullptr;
    for (int i = 0; i < count; i++) {
        current = &table[i];
        if (*current == p)
            if(current->department == p.department && current->status == p.status)
            result++;
    }
    return result;
}



bool Prepod::operator==(const Person& p) const {
    return person.compare(p) == 0;
}

bool Prepod::operator==(const Prepod &p) const {
    return person.compare(p.person) == 0 && department == p.department && status == p.status;
}

Prepod::~Prepod() {
    person.~Person();

}

string Prepod::toString() {
    auto* o = new std::ostringstream ;
    *o << person << " From department ";
    switch (department) {
        case 1:
            *o<<"IPOVS";
            break;
        case 2:
            *o<<"VM";
            break;
        case 3:
            *o<<"VT";
            break;
    }
    *o<<" With status ";
    switch (status) {
        case 1:
            *o<<"teacher";
            break;
        case 2:
            *o<<"Docent";
            break;
        case 3:
            *o<<"Ph. D";
    }
    *o<< endl;
    return o->str();
}





