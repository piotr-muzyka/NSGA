#include "MainWindow.h"
#include "ui_mainwindow.h"
#include <mgl2/qmathgl.h>
#include <mgl2/qt.h>
#include <mgl2/surf.h>
#include <ExpressionParser.h>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMGL = new QMathGL(ui->plotWidget);
    QMGL->setDraw(&drawer);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   drawer.fn_string = ui->lineEdit->text();
   drawer.initData();
   QMGL->update();
}
