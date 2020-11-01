//
// Created by strukovsky on 01.11.2020.
//

#include "../header/Man.h"
#include <cstring>
char Man::buff [] ;

Man::Man( char *_name, char *_surname, int _year_of_edu):
name(_name), surname(_surname), year_of_edu(_year_of_edu)
{

}



void Man::input_field(istream &i, char *&field) {
    i>>Man::buff;
    delete []field;
    field = new char[strlen(Man::buff) + 1];
    strcpy(field, buff);

}

ostream &operator<<(ostream &o, const Man &m) {
    o<<m.name<<" "<<m.surname<<" "<<m.year_of_edu;
    return o;
}

Man::Man() {
    name = new char[0];
    surname = new char[0];
    year_of_edu = 0;
}

istream &operator>>(istream &i, Man &m) {
    Man::input_field(i, m.name);
    Man::input_field(i, m.surname);
    i>>m.year_of_edu;
    return i;
}

int Man::getYearOfEdu() {
    return year_of_edu;
}
