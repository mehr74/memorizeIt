#ifndef INTERFACE_H
#define INTERFACE_H

#include "wordcontainer.h"

class Interface
{
public:
    Interface(WordContainer* wordcontainer);

    void exec();

private:
    void showHelpBox() const;

    WordContainer *myWordContainer;
};

#endif // INTERFACE_H
