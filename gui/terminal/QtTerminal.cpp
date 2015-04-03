#include "QtTerminal.h"
#include <iostream>
#include <QString>
#include <QTextStream>

using namespace std;

QtTerminal::QtTerminal()
{
}

bool QtTerminal::init()
{
    return true;
}

void QtTerminal::run()
{
    cout << "Hello World!" << endl;
}
