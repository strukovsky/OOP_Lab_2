//
// Created by strukovsky on 01.11.2020.
//

#include "../header/Learner.h"


ostream &operator<<(ostream &o, const Learner &l) {

    o<<l.man<<l.number_of_group<<"-";

    switch (l.departament) {
        case Departament::KT:
            o<<"KT";
            break;
        case Departament::PIN:
            o<<"PIN";
            break;
        case Departament::PM:
            o<<"PM";
            break;
        case Departament::NONE:
            o<<"None";
            break;
    }
    return o;
}

istream &operator>>(istream &i, Learner &l) {
    i>>l.man;
    int d = 0;
    i>>d;
    l.departament = Departament(d);
    i>>l.number_of_group;
    return i;
}

Learner::Learner() {
    man = Man();
    departament = Departament::NONE;
    number_of_group = 0;


}

void Learner::setMan(Man m) {
    man = m;

}

void Learner::setDepartament(int d) {
    departament = Departament(d);
}

void Learner::setNumberOfGroup(int  n) {
    number_of_group = n;
}
