#ifndef TERMINAL_H
#define TERMINAL_H

#include <Gui.h>
#include <memory>

class QtTerminal : public Gui
{
public:
    QtTerminal();
    bool init();
    void run();
private:
    void infiniteLoop();
};

#endif // TERMINAL_H
