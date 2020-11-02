//
// Created by strukovsky on 01.11.2020.
//

#ifndef LAB2_TEACHER_H
#define LAB2_TEACHER_H
#include "Student.h"
#include "Prepod.h"
#include <string>
class Teacher: public Prepod {
public:
    Teacher(int _department, char *_surname,  char* _name,  char* _patronymic, int _status, int _student_count);
    Teacher();

    static void add(Teacher table[], int _department, Person& p, int _status, Student s[], int count_of_students);
    static void describe(Teacher[]);

    friend ostream& operator<<(ostream& o,  const Teacher& t);

    std::string toString();

    int student_count;
    Student *students;
};


#endif //LAB2_TEACHER_H
