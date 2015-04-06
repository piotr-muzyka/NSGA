#include "MathGlDrawer.h"
#include <mgl2/surf.h>
<<<<<<< HEAD
#include <QMessageBox>
#include <iostream>
=======
>>>>>>> 54a7326f98b8a17f22f682e7bddb938529e04e9f

MathGlDrawer::MathGlDrawer()
{
}

void MathGlDrawer::initData()
{
<<<<<<< HEAD

    unsigned n=100;
    x1.Create(n,n);
    x2.Create(n,n);
    a.Create(n,n);

    parser.parse(fn_string.toStdString());

    doublesVector xVector = parser.createVectorWithLength(n,-5,5);
    doublesMatrix results = parser.results(xVector, xVector);
=======
    unsigned n=100;
    x1.Create(n,n);
    x2.Create(n,n);
    a.Create(n,n,2);

    f1.parse("sin(x1)+cos(x2)");
    f2.parse("cos(x1)+sin(x2)");

    doublesVector xVector = f1.createVectorWithLength(n,-5,9);
>>>>>>> 54a7326f98b8a17f22f682e7bddb938529e04e9f

    for(doublesVector::size_type i = 0; i != n; i++)
        for(doublesVector::size_type j = 0; j != n; j++)
        {
            x1.SetVal(xVector[i],i,j);
            x2.SetVal(xVector[j],i,j);
<<<<<<< HEAD
            a.SetVal(results[i][j],i,j);
=======

            f1.x[0] = f2.x[0] = xVector[i];
            f1.x[1] = f2.x[1] = xVector[j];
            a.SetVal(f1.result(),i,j,0);
            a.SetVal(f2.result(),i,j,1);
>>>>>>> 54a7326f98b8a17f22f682e7bddb938529e04e9f
        }
}

int MathGlDrawer::Draw(mglGraph* gr)
{
    initData();
<<<<<<< HEAD
    gr->Title("Surf plot");
=======
//    gr->Title("Surf plot");
>>>>>>> 54a7326f98b8a17f22f682e7bddb938529e04e9f
    gr->Rotate(50,60);
    gr->Box();
    gr->SetRanges(x1,x2,a);
    gr->Axis();
<<<<<<< HEAD
    gr->Surf(x1,x2,a);
=======
    gr->Mesh(x1,x2,a);
>>>>>>> 54a7326f98b8a17f22f682e7bddb938529e04e9f

    return 0;
}
