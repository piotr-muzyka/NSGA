#ifndef MATHGLDRAWER_H
#define MATHGLDRAWER_H

#include <mgl2/qt.h>
#include <ExpressionParser.h>
#include <QString>

class MathGlDrawer : public mglDraw
{
public:
    MathGlDrawer();
    void initData();
    int Draw(mglGraph* gr);
    QString fn_string;
private:
    ExpressionParser parser;
    mglData a;
    mglData x1;
    mglData x2;
};

#endif // MATHGLDRAWER_H
