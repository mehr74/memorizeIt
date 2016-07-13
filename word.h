#ifndef WORD_H
#define WORD_H

#include <QtCore>
#include <string>
#include <vector>
#include "date.h"
using namespace std;

class Word
{
public:
    Word();
    Word(QString title, QString definition, vector<QString> examples);

    QString getTitle() const;
    QString getDefinition() const;
    vector<QString> getExamples() const;
    int getTestNum() const;
    int getTrueNum() const;
    int getWrongNum() const;
    int getID() const;
    Date* getDate() const;

    void setTitle(QString title);
    void setDefinition(QString definition);
    void addExample(QString example);
    void setScore(int tstNum, int wrongNum);
    void setDate(Date *date);

    string toString() const;
    string deepToString() const;

private:
    string fitString(QString input, int lineSize, string sign = "",
                     string prefix = "*    ", string postfix = "    *") const;

    QString myTitle;
    QString myDefinition;
    vector <QString> myExamples;
    Date *myDate;

    int myTestNum;
    int myWrongNum;
    int myTrueNum;

    int myID;
    static int ourCount;
};

#endif // WORD_H
