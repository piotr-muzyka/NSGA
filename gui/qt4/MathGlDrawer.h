#ifndef MATHGLDRAWER_H
#define MATHGLDRAWER_H

#include <mgl2/qt.h>
#include <ExpressionParser.h>
<<<<<<< HEAD
#include <QString>
=======
>>>>>>> 54a7326f98b8a17f22f682e7bddb938529e04e9f

class MathGlDrawer : public mglDraw
{
public:
    MathGlDrawer();
    void initData();
    int Draw(mglGraph* gr);
<<<<<<< HEAD
    QString fn_string;
private:
    ExpressionParser parser;
=======
private:
    ExpressionParser f1;
    ExpressionParser f2;
>>>>>>> 54a7326f98b8a17f22f682e7bddb938529e04e9f
    mglData a;
    mglData x1;
    mglData x2;
};

#endif // MATHGLDRAWER_H
