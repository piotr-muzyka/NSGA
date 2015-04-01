#include "MathGlDrawer.h"
#include <mgl2/surf.h>

MathGlDrawer::MathGlDrawer()
{
}

void MathGlDrawer::initData()
{
    unsigned n=100;
    x1.Create(n,n);
    x2.Create(n,n);
    a.Create(n,n,2);

    f1.parse("sin(x1)+cos(x2)");
    f2.parse("cos(x1)+sin(x2)");

    doublesVector xVector = f1.createVectorWithLength(n,-5,9);

    for(doublesVector::size_type i = 0; i != n; i++)
        for(doublesVector::size_type j = 0; j != n; j++)
        {
            x1.SetVal(xVector[i],i,j);
            x2.SetVal(xVector[j],i,j);

            f1.x[0] = f2.x[0] = xVector[i];
            f1.x[1] = f2.x[1] = xVector[j];
            a.SetVal(f1.result(),i,j,0);
            a.SetVal(f2.result(),i,j,1);
        }
}

int MathGlDrawer::Draw(mglGraph* gr)
{
    initData();
//    gr->Title("Surf plot");
    gr->Rotate(50,60);
    gr->Box();
    gr->SetRanges(x1,x2,a);
    gr->Axis();
    gr->Mesh(x1,x2,a);

    return 0;
}
