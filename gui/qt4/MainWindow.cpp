#include "MainWindow.h"
#include "ui_mainwindow.h"
#include <mgl2/qmathgl.h>
#include <mgl2/qt.h>
#include <mgl2/surf.h>
#include <ExpressionParser.h>
<<<<<<< HEAD
#include <QMessageBox>
=======
>>>>>>> 54a7326f98b8a17f22f682e7bddb938529e04e9f

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
<<<<<<< HEAD
    QMGL = new QMathGL(ui->plotWidget);
    QMGL->setDraw(&drawer);
=======

    QMathGL *QMGL = new QMathGL(ui->plotWidget);
    QMGL->setDraw(&drawer);
    QMGL->update();
>>>>>>> 54a7326f98b8a17f22f682e7bddb938529e04e9f
}

MainWindow::~MainWindow()
{
    delete ui;
}
<<<<<<< HEAD

void MainWindow::on_pushButton_clicked()
{
   drawer.fn_string = ui->lineEdit->text();
   drawer.initData();
   QMGL->update();
}
=======
>>>>>>> 54a7326f98b8a17f22f682e7bddb938529e04e9f
