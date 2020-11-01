//
// Created by strukovsky on 01.11.2020.
//

#include "../header/Teacher.h"
#include "../header/Student.h"

Teacher::Teacher(int _department, char *_surname, char *_name, char *_patronymic, int _status, int _student_count):
Prepod(_department, _surname, _name, _patronymic, _status){
    student_count = _student_count;
    students = new Student[student_count];
}

Teacher::Teacher():Prepod() {
    student_count = 0;
    students = new Student[student_count];
}

void Teacher::describe(Teacher *table) {
    for (int i = 0; i < count; ++i) {
        cout << table[i];
    }
}

void Teacher::add(Teacher table[], int _department, Person& p, int _status, Student s[], int count_of_students) {
    table[get_count()].students = s;
    table[get_count()].student_count = count_of_students;
    Prepod::add(table, _department, p, _status);


}

ostream &operator<<(ostream &o, const  Teacher& t) {
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

    for (int i = 0; i < t.student_count; ++i) {
        o<<t.students[i]<<endl;
    }
    return o;
}
