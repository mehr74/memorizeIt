#include "word.h"
#include <iostream>
#include <string>
#include <QtCore>
#include <ostream>
#include <sstream>
#include <iomanip>
using namespace std;

int Word::ourCount = 0;

Word::Word()
    : myID(ourCount)
    , myTestNum(0)
    , myTrueNum(0)
    , myWrongNum(0)
    , myTitle("")
    , myDefinition("")
{
    ourCount++;
}

Word::Word(QString title, QString definition, vector<QString> examples)
    : myID(ourCount)
    , myTestNum(0)
    , myTrueNum(0)
    , myWrongNum(0)
    , myTitle(title)
    , myDefinition(definition)
{
    ourCount++;
}

vector<QString> Word::getExamples() const
{
    return myExamples;
}

QString Word::getTitle() const
{
    return myTitle;
}

QString Word::getDefinition() const
{
    return myDefinition;
}

int Word::getID() const
{
    return myID;
}

int Word::getTestNum() const
{
    return myTestNum;
}

int Word::getTrueNum() const
{
    return myTrueNum;
}

int Word::getWrongNum() const
{
    return myWrongNum;
}

Date* Word::getDate() const
{
    return myDate;
}

void Word::setTitle(QString title)
{
    myTitle = title;
}

void Word::setDefinition(QString definition)
{
    myDefinition = definition;
}

void Word::addExample(QString example)
{
    myExamples.push_back(example);
}

void Word::setScore(int tstNum, int wrongNum)
{
    myTestNum = tstNum;
    myWrongNum = wrongNum;
    myTrueNum = tstNum - wrongNum;
}

void Word::setDate(Date *date)
{
    myDate = date;
}

string Word::toString() const
{
    ostringstream out;
    out << setfill('*') << setw(60) << "" << endl;
    out << setfill(' ') << "* " << std::left << setw(57) << this->getTitle().toStdString() << "*" <<endl;
    out << setfill(' ') << "* " << std::left << setw(57) << "" << "*" << endl;
    out << fitString(this->getDefinition(), 50);
    for(int i = 0; i < this->getExamples().size(); i++)
    {
        out << fitString(this->getExamples()[i], 47, "-> ");
    }
    out << setfill(' ') << "* " << std::left << setw(57) << "" << "*" << endl;
    out << setfill('*') << setw(60) << "" << endl;
    return out.str();

}

string Word::deepToString() const
{
    ostringstream out;
    out << setfill('*') << setw(60) << "" << endl;
    out << fitString(this->getTitle(), 49,"WORD : ", "* ", " *");
    out << setfill(' ') << "* " << std::left << setw(57) << "" << "*" << endl;
    out << fitString(this->getDefinition(), 50);
    for(int i = 0; i < this->getExamples().size(); i++)
    {
        out << fitString(this->getExamples()[i], 47, "-> ");
    }
    out << setfill(' ') << "* " << std::left << setw(57) << "" << "*" << endl;
    out << "*-------------------------  DATE  -------------------------*" << endl;
    out << setfill(' ') << "* " << std::left << setw(57) << "" << "*" << endl;
    out << "* " << setfill(' ') << std::left << setw(57) << myDate->ToString() << "*" << endl;
    out << setfill(' ') << "* " << std::left << setw(57) << "" << "*" << endl;
    out << "*------------------------- RESULT -------------------------*" << endl;
    out << setfill(' ') << "* " << std::left << setw(57) << "" << "*" << endl;
    out << setfill(' ') << "* " << std::left << "Total   : " << setw(47) << this->getTestNum() << "*" << endl;
    out << setfill(' ') << "* " << std::left << "Correct : " << setw(47) << this->getTrueNum() << "*" << endl;
    out << setfill(' ') << "* " << std::left << "Wrong   : " << setw(47) << this->getWrongNum() << "*" << endl;
    out << setfill(' ') << "* " << std::left << setw(57) << "" << "*" << endl;
    out << setfill('*') << setw(60) << "" << endl;
    return out.str();
}

string Word::fitString(QString input, int lineSize, string sign, string prefix, string postfix) const
{
    int flag = 0;
    ostringstream out;
    int i = 0;
    istringstream definitionStream(input.toStdString());
    string tmp;
    definitionStream >> tmp;
    while(i < input.size())
    {
        out << prefix ;
        if(flag == 0)
        {
            flag = 1;
            out << sign;
        }
        else
        {
            for(int k = 0; k < sign.size(); k++)
                out << " " ;
        }
        int j = lineSize;
        while(j > 0 && j > tmp.size())
        {
            out << tmp << " ";
            j -= (tmp.size() + 1);
            i += (tmp.size() + 1);
            if(!definitionStream.good())
                break;
            definitionStream >> tmp;
        }
        for(int k = 0; k < j; k++)
            out << " " ;

        out << postfix << endl;
    }
    return out.str();
}
