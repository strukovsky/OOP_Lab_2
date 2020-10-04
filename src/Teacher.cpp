//
// Created by strukovsky on 03.10.2020.
//

#include <cstring>
#include "../header/Teacher.h"
#include <fstream>

int Teacher::count;

Teacher::Teacher()
{
    department = 0;
    person = Person();
    status = 0;
}


Teacher::Teacher(int _department, char *surname, char* name, char* patronymic, int _status) :
        department(_department),
        person(surname, name, patronymic),
        status(_status) {
    count++;
}




Teacher* Teacher::search(Teacher *table, const Person& query) {
    Teacher *current = nullptr;
    for (int i = 0; i < count; i++) {
        current = &table[i];
        if (current->person.compare(query)== 0)
            break;
    }
    return current;
}

vector<Teacher> *Teacher::filter(Teacher *table, int status) {
    auto *result = new vector<Teacher>;
    for (int i = 0; i < Teacher::count; i++) {
      if (table[i].status == status)
      {
          Teacher t(table[i]);
          result->push_back(t);
      }
    }
    return result;
}

void Teacher::sort(Teacher *table) {
    for (int i = count - 1; i >= 0; i--) {
        for (int j = 0; j < i; ++j) {
            if (table[i].person.compare(table[j].person) < 0) {
                Teacher tmp(table[i]);
                table[i] = table[j];
                table[j] = tmp;
            }
        }
    }
}

ostream &operator<<(ostream &o, Teacher &t) {
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

void Teacher::add(Teacher table[], int _department, const Person& p, int _status) {
    table[count].status = _status;
    table[count].person = p;
    table[count].department = _department;
    count++;

}

void Teacher::add(Teacher *table, const Teacher &t) {
    table[count-1].status = t.status;
    table[count-1].person = t.person;
    table[count-1].department = t.department;

}


void Teacher::describe(Teacher *table) {
    for (int i = 0; i < count; ++i) {
        cout << table[i];
    }
}

void Teacher::quit(Teacher *table) {
    ofstream f;
    f.open("base.txt", ios::out);
    if (f.is_open()) {
        for (int i = 0; i < count; ++i) {
            f<<table[i];
        }
    }
    f.close();
}



Teacher::Teacher(const Teacher& t) {
    this->status = t.status;
    this->person = t.person;
    this->department = t.department;
}

int Teacher::count_of_person(Teacher *table, const Teacher& p) {
    int result = 0;
    Teacher *current = nullptr;
    for (int i = 0; i < count; i++) {
        current = &table[i];
        if (current->person.compare(p.person)== 0)
            if(current->department == p.department && current->status == p.status)
            result++;
    }
    return result;
}





