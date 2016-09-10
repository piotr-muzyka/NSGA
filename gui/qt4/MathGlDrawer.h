#ifndef MATHGLDRAWER_H
#define MATHGLDRAWER_H

#include <mgl2/qt.h>
#include <Expression.h>
#include <QString>

class MathGlDrawer : public mglDraw
{
public:
    MathGlDrawer();

    void initData(doublesMatrix results);
    int Draw(mglGraph* gr);
private:
    Expression parser;
    mglData a;
    mglData f1;
    mglData f2;
    mglData g1;
//    mglData g2;
//    mglData g3;
//    mglData g4;
//    mglData g5;


    doublesMatrix results;
};

#endif // MATHGLDRAWER_H
