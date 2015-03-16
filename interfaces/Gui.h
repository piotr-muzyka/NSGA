#ifndef GUI_H
#define GUI_H

class Gui
{
public:
    virtual ~Gui() {}

    virtual bool init() = 0;
    virtual void run() = 0;
};

#endif // GUI_H
