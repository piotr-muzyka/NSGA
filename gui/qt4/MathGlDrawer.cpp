#include "MathGlDrawer.h"
#include <mgl2/surf.h>
#include <QMessageBox>
#include <iostream>
#include <iomanip>

MathGlDrawer::MathGlDrawer()
{
}

void MathGlDrawer::initData(doublesMatrix results)
{
    std::sort(results.begin(), results.end());
    f1.Create(results.size());
    f2.Create(results.size());

    const auto columnWidth = 15;
    const auto columnsCount = results[0].size();
    std::cout << std::setw(columnWidth) << std::left << "f1"
              << std::setw(columnWidth) << std::left << "f2";
    for(unsigned i = 2; i < columnsCount; ++i)
              std::cout << std::setw(columnWidth) << std::left << "x"+std::to_string(i-1);
    std::cout << std::endl
              << std::setfill('-') << std::setw(columnWidth*columnsCount) << "-"
              << std::setfill(' ') << std:: endl;
    for(unsigned i = 0; i != results.size(); i++)
    {
        f1.SetVal(results[i][0],i);
        f2.SetVal(results[i][1],i);
        for(auto x : results[i])
            std::cout << std::setw(columnWidth) << std::left << x;
        std::cout << std::endl;
    }
}

int MathGlDrawer::Draw(mglGraph* gr)
{
    gr->Title("NSGA-II");
    gr->Box();
    gr->SetRanges(f1,f2);
    gr->Axis();
    gr->Plot(f1,f2," o");
    gr->Label('y',"f2",0);
    gr->Label('x',"f1",0);

    return 0;
}
