#include "Qt4Window.h"

Qt4Window::Qt4Window()
{
}

bool Qt4Window::init()
{
    std::string name = "program";
    int dummy_argc = 1;
    char* dummy_argv[] = {const_cast<char*>(name.c_str())};

    app.reset(new QApplication(dummy_argc, dummy_argv));
    main.reset(new MainWindow());

    return true;
}

void Qt4Window::run()
{
    main->show();
    app->exec();
}
