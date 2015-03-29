#ifndef QT4WINDOW_H
#define QT4WINDOW_H

#include <Gui.h>
#include <MainWindow.h>
#include <QApplication>
#include <memory>

class Qt4Window : public Gui
{
public:
    Qt4Window();
    bool init();
    void run();
private:
    std::auto_ptr<QApplication> app;
    std::auto_ptr<MainWindow> main;
};

#endif // QT4WINDOW_H
