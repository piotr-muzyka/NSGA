#include "MainWindow.h"
#include "ui_mainwindow.h"
#include <mgl2/qmathgl.h>
#include <mgl2/qt.h>
#include <mgl2/surf.h>
#include <ExpressionParser.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMathGL *QMGL = new QMathGL(ui->plotWidget);
    QMGL->setDraw(&drawer);
    QMGL->update();
}

MainWindow::~MainWindow()
{
    delete ui;
}
