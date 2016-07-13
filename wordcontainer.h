#ifndef WORDCONTAINER_H
#define WORDCONTAINER_H
#include <iostream>
#include <QtSql>
#include <QtCore>
#include "word.h"


class WordContainer
{
public:
    WordContainer();
    WordContainer(QSqlDatabase db);

    void addWord(Word* word);
    void show(Date* date);

private:
    Word* wordFromID(int id) const;
    QString intToString(int input) const;

    QSqlDatabase myDb;
};

#endif // WORDCONTAINER_H
