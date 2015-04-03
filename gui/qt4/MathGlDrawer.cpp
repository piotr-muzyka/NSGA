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
    doublesMatrix results = parser.results(xVector, xVector);

    for(doublesVector::size_type i = 0; i != n; i++)
        for(doublesVector::size_type j = 0; j != n; j++)
        {
            x1.SetVal(xVector[i],i,j);
            x2.SetVal(xVector[j],i,j);
            a.SetVal(results[i][j],i,j);
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
