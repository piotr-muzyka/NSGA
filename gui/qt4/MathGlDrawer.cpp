#include "MathGlDrawer.h"
#include <mgl2/surf.h>
#include <QMessageBox>
#include <iostream>

MathGlDrawer::MathGlDrawer()
{
}

void MathGlDrawer::initData()
{
    unsigned n=100;
    x1.Create(n,n);
    x2.Create(n,n);
    a.Create(n,n);

    parser.parse(fn_string.toStdString());

    doublesVector xVector = parser.createVectorWithLength(n,-5,5);

    for(doublesVector::size_type i = 0; i != n; i++)
        for(doublesVector::size_type j = 0; j != n; j++)
        {
            parser("x1") = xVector[i];
            parser("x2") = xVector[j];
            x1.SetVal(parser("x1"),i,j);
            x2.SetVal(parser("x2"),i,j);
            a.SetVal(parser.value(),i,j);
        }
}

int MathGlDrawer::Draw(mglGraph* gr)
{
    initData();
    gr->Title("Surf plot");
    gr->Rotate(50,60);
    gr->Box();
    gr->SetRanges(x1,x2,a);
    gr->Axis();
    gr->Surf(x1,x2,a);

    return 0;
}
