#include <iostream>
#include <cstring>
#include "header/Prepod.h"
#include "header/Learner.h"
#include "header/Teacher.h"
#include "header/Student.h"

const int COUNT_OF_RECORDS = 1000;



int main() {
    auto* teachers = new Teacher[COUNT_OF_RECORDS];
    int command = 0;

    for(int i = 0; i < COUNT_OF_RECORDS; i++)
    {
        cout<<"Enter command number\n";
        cout<<"1 - add new Prepod\n";
        cout<<"2 - search Professor by fio\n";
        cout<<"3 - filter by department\n";
        cout<<"4 - print teachers\n";
        cout<<"5 - sort by fio\n";
        cout<<"6 - quit\n";
        cin>>command;
        while(cin.fail() || command <= 0 || command > 6)
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            cout<<"Failed on entering command! Try again.\n";
            cin>>command;
        }
        switch(command)
        {
            case 1:
            {

                cout<<"Enter number of department\n 1 - IPOVS, 2 - VM, 3 - VT\n";
                int department = 1;

                cin>>department;
                while(cin.fail() || department <= 0 || department >= 4)
                {
                    std::cin.clear();
                    std::cin.ignore(32767,'\n');
                    cout<<"Failed on entering department! Try again.\n";
                    cin>>department;
                }
                cout<<"Enter fio. 3 words separated by space or new line\n";
                Person fio;
                cin>>fio;
                cout<<"Enter status. 1 - Assistent, 2 - Docent, 3 - Professor\n";
                int status = 0;
                cin>>status;
                while(cin.fail() || status <= 0 || status > 4)
                {
                    std::cin.clear();
                    std::cin.ignore(32767,'\n');
                    cout<<"Failed on entering department! Try again.\n";
                    cin>>status;
                }
                int count_of_students = 0;
                cout<<"Enter count of students\n";
                cin>>count_of_students;
                while(cin.fail() || count_of_students < 0)
                {
                    std::cin.clear();
                    std::cin.ignore(32767,'\n');
                    cout<<"Failed on entering department! Try again.\n";
                    cin>>count_of_students;
                }
                auto st = new Student[count_of_students];
                for (int j = 0; j < count_of_students; ++j) {
                    cout<<"Enter student departament. PIN - 1, PM - 2, KT - 3\n";
                    int student_departament = 0;
                    cin>>student_departament;
                    while(cin.fail() || student_departament <= 0 || student_departament > 3)
                    {
                        std::cin.clear();
                        std::cin.ignore(32767,'\n');
                        cout<<"Failed on entering student departament! Try again.\n";
                        cin>>student_departament;
                    }

                    cout<<"Enter data for student. Name, Surname and afterall, year of education\n";
                    Man m;
                    cin>>m;
                    while(cin.fail() || m.getYearOfEdu() < 1 || m.getYearOfEdu()> 6)
                    {
                        std::cin.clear();
                        std::cin.ignore(32767,'\n');
                        cout<<"Failed on entering student data! Try again.\n";
                        cin>>m;
                    }
                    int number_of_group;
                    cout<<"Enter number of group\n";
                    cin>>number_of_group;
                    while(cin.fail() || number_of_group <= 0 || number_of_group > 5)
                    {
                        std::cin.clear();
                        std::cin.ignore(32767,'\n');
                        cout<<"Failed on entering student number of group! Try again.\n";
                        cin>>student_departament;
                    }
                    st[j].setDepartament(student_departament);
                    st[j].setMan(m);
                    st[j].setNumberOfGroup(number_of_group);

                }
                Teacher::add(teachers, department, fio, status, st, count_of_students);
                break;
            }
            case 2:
            {
                if(Prepod::get_count() < 1)
                {
                    cout<<"There is no records in database.\n";
                    break;
                }
                cout<<"Enter query.\nEnter surname";
                Person p;
                cin>>p;
                cout<<*search(teachers, p);
                break;
            }
            case 3:
            {
                if(Prepod::get_count() < 1)
                {
                    cout<<"There is no records in database.\n";
                    break;
                }
                int criteria_department = 0;
                cout<<"Enter department number to filter\n";
                cin >> criteria_department;
                while (cin.fail() || criteria_department < 0 || criteria_department > 4)
                {
                    std::cin.clear();
                    std::cin.ignore(32767,'\n');
                    cout<<"Failed on entering department number to filter! Try again.\n";
                    cin >> criteria_department;
                }
                auto* vec = filter(teachers, criteria_department);
                for( auto& q: *vec)
                    cout<<q;
                break;
            }
            case 4:
                if(Teacher::get_count() > 0)
                {
                    cout<<"Debug "<<teachers[0].students[0].man<<endl;
                    for (int k = 0; k < Teacher::get_count(); ++k) {
                        cout << teachers[k].person << " From department ";
                        switch (teachers[k].department) {
                            case 1:
                                cout <<"IPOVS";
                                break;
                            case 2:
                                cout <<"VM";
                                break;
                            case 3:
                                cout <<"VT";
                                break;
                        }
                        cout <<" With status ";
                        switch (teachers[k].status) {
                            case 1:
                                cout <<"teacher";
                                break;
                            case 2:
                                cout <<"Docent";
                                break;
                            case 3:
                                cout <<"Ph. D";
                        }
                        cout << endl;

                        for (int y = 0; y < teachers[k].student_count; ++y) {
                            cout <<teachers[k].students[y]<<endl;
                        }
                    }
                }

                else cout<<"There is no records in database.\n";
                break;
            case 5:
                if(Prepod::get_count() > 1)
                    Prepod::sort(teachers);
                else cout<<"Too small amount of records to sort.\n";
                break;
            case 6:
                Prepod::quit(teachers);
        }
    }


    return 0;
}
