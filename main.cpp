#include <iostream>
#include <QtSql>
#include <QtCore>
#include "word.h"
#include "wordcontainer.h"
#include "interface.h"

using namespace std;

int main()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/mehrshad/projects/english/database.db");
    WordContainer *dict = new WordContainer(db);

    Interface *ui = new Interface(dict);
    ui->exec();

    return 0;
}

