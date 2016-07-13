#include "interface.h"
#include <iomanip>
#include <iostream>

using namespace std;

Interface::Interface(WordContainer *wordContainer)
    :myWordContainer(wordContainer)
{
}

void Interface::exec()
{
    while(1)
    {
        cout << ">> ";
        string tmp;
        cin >> tmp;
        if(tmp == "exit")
            return;
        if(tmp == "show")
        {
            int dd;
            cin >> dd;
            Date* date = new Date();
            (*date) -= dd;
            myWordContainer->show(date);
        }
        else
            showHelpBox();
    }
}

void Interface::showHelpBox() const
{
    cout << setfill('*') << setw(60) << "" << endl;
    cout << setfill(' ') << "* " << std::left << setw(57) << "" << "*" << endl;
    cout << "* " << setfill(' ') << std::left << setw(15) << "show dd"
         << setw(42) << "Show words learned in 'dd' days ago" << "*" << endl;
    cout << "* " << setfill(' ') << std::left << setw(15) << "test dd"
         << setw(42) << "Test words learned in 'dd' days ago" << "*" << endl;
    cout << "* " << setfill(' ') << std::left << setw(15) << "exit"
         << setw(42) << "Exit this program" << "*" << endl;
    cout << setfill(' ') << "* " << std::left << setw(57) << "" << "*" << endl;
    cout << setfill('*') << setw(60) << "" << endl;
}


