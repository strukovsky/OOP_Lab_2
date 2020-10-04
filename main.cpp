#include <iostream>
#include <cstring>
#include "header/Teacher.h"
const int COUNT_OF_RECORDS = 1000;



int main() {
    auto* table = new Teacher[COUNT_OF_RECORDS];
    int command = 0;
    for(int i = 0; i < COUNT_OF_RECORDS; i++)
    {
        cout<<"Enter command number\n";
        cout<<"1 - add new Professor\n";
        cout<<"2 - search Professor by fio\n";
        cout<<"3 - filter by department\n";
        cout<<"4 - print table\n";
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
                Teacher::add(table, department, fio, status);
                break;
            }
            case 2:
            {
                if(Teacher::get_count() < 1)
                {
                    cout<<"There is no records in database.\n";
                    break;
                }
                cout<<"Enter query.\nEnter surname";
                Person p;
                cin>>p;
                cout<<*Teacher::search(table, p);
                break;
            }
            case 3:
            {
                if(Teacher::get_count() < 1)
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
                auto* vec = Teacher::filter(table, criteria_department);
                for( auto& q: *vec)
                    cout<<q;
                break;
            }
            case 4:
                if(Teacher::get_count() > 0)
                    Teacher::describe(table);
                else cout<<"There is no records in database.\n";
                break;
            case 5:
                if(Teacher::get_count() > 1)
                    Teacher::sort(table);
                else cout<<"Too small amount of records to sort.\n";
                break;
            case 6:
                Teacher::quit(table);
                goto end;
        }
    }
    end:
    char *name = new char[100];
    char *surname = new char[100];
    char *patronymic = new char[100];
    strcpy(name, "a");
    strcpy(surname, "b");
    strcpy(patronymic, "c");
    Person p(name, surname, patronymic);
    Teacher t(1, name, surname, patronymic, 2);
    int count = Teacher::count_of_person(table, t);
    if(count == 0)
    {
        cout<<"No such item. Adding\n";
        Teacher::add(table, t);
        Teacher::describe(table);
    } else cout<<"Number of entering of "<<t<<": "<<count;

    return 0;
}
