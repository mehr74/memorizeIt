#include <sstream>
#include "wordcontainer.h"
#include "date.h"
#include <cstdio>
#include <cstdlib>

WordContainer::WordContainer()
{
}

WordContainer::WordContainer(QSqlDatabase db)
{
    myDb = db;
    if(!myDb.open())
        cout << "Failed to open the database." << endl;
}

void WordContainer::addWord(Word * word)
{

}

void WordContainer::show(Date *date)
{
    int flag = 0;
    QSqlQuery qry(myDb);
    qry.prepare("select id from words where day="+intToString(date->Day()) +
                " AND month="+intToString(date->Month()) +
                " AND year="+intToString(date->Year()));
    qry.exec();

    while(qry.next())
    {
        if(flag == 1)
        {
            cout << "Do you want to continue showing words [Y/n]  ";
            string str;
            cin >> str;
            if(str == "n")
                return;
        }
        flag = 1;
        int wordID = qry.value(0).toInt();
        cout << wordFromID(wordID)->deepToString();
    }
}

Word* WordContainer::wordFromID(int id)const
{
    QSqlQuery qry(myDb);
    qry.prepare("select * from words where id='"+ intToString(id) + "'");
    qry.exec();

    while(qry.next())
    {
        QString wordID = qry.value(0).toString();
        QString title = qry.value(1).toString();
        QString definition = qry.value(2).toString();
        int tstNum = qry.value(3).toInt();
        int wrongNum = qry.value(4).toInt();
        int day = qry.value(5).toInt();
        int month = qry.value(6).toInt();
        int year = qry.value(7).toInt();

        Date* tmpDate = new Date(month, day, year);

        Word *tmpWord = new Word();
        tmpWord->setTitle(title);
        tmpWord->setDefinition(definition);
        tmpWord->setScore(tstNum, wrongNum);
        tmpWord->setDate(tmpDate);

        QSqlQuery qry2(myDb);
        qry2.prepare("select * from examples where word_id='"+wordID+"'");
        qry2.exec();

        while(qry2.next())
        {
            QString tmpEx = qry2.value(2).toString();
            tmpWord->addExample(tmpEx);
        }
        return tmpWord;
    }
}

QString WordContainer::intToString(int input) const
{
    QString str;
    while(input > 0)
    {
        str = char((input % 10) + '0') + str;
        input /= 10;
    }
    return str;
}


