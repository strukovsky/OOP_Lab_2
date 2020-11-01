//
// Created by strukovsky on 01.11.2020.
//

#ifndef LAB2_MAN_H
#define LAB2_MAN_H
#include <iostream>
using namespace std;
class Man {
   char* name;
   char* surname;
    int year_of_edu;

    static char buff[4096];
    static void input_field(istream& i, char*& field);
public:
    Man( char* _name,  char* _surname, int _year_of_edu);
    Man();
    friend ostream& operator<<(ostream&, const Man&);
    friend istream& operator>>(istream&, Man&);

    int getYearOfEdu();
};


#endif //LAB2_MAN_H
