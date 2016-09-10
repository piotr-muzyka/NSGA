#include "MainWindow.h"
#include <mgl2/qt.h>
#include <mgl2/surf.h>
#include <assert.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    core(new Nsga)
{
    ui->setupUi(this);
    qout.reset(new QDebugStream(std::cout, *(ui->logBox)));
    QMGL.reset(new QMathGL(ui->plotWidget));
    QMGL->setDraw(&drawer);
    QMGL->update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    assert(core != NULL);
    ui->logBox->clear();

    settings.f[0] = std::string(ui->funf1->text().toStdString());
    settings.f[1] = std::string(ui->funf2->text().toStdString());

    settings.g[0] = std::string(ui->fung1->text().toStdString());
    settings.g[1] = std::string(ui->fung2->text().toStdString());
    settings.g[2] = std::string(ui->fung3->text().toStdString());
    settings.g[3] = std::string(ui->fung4->text().toStdString());
    settings.g[4] = std::string(ui->fung5->text().toStdString());
    settings.g[5] = std::string(ui->bound->text().toStdString());

    settings.lowerBound = ui->loBoundval->text().toDouble();
    settings.upperBound = ui->upBoundval->text().toDouble();

   core->execute(settings);
   drawer.initData(core->result());
   QMGL->update();

//   ui->ResultView->
}

void MainWindow::setValidValue(QLineEdit* line, unsigned& field)
{
    assert(line != NULL);
    const QString validStyle = "background-color: white;";
    const QString invalidStyle = "background-color: rgb(255, 96, 96);";

    if (line->text().toUInt() > 0)
    {
        line->setStyleSheet(validStyle);
        field = line->text().toUInt();
    }
    else
        line->setStyleSheet(invalidStyle);
}

void MainWindow::on_indivnr_textChanged(const QString)
{
     setValidValue(ui->indivnr, settings.individualsCount);
}

void MainWindow::on_genernr_textChanged(const QString)
{
    setValidValue(ui->genernr, settings.generationsCount);
}

void MainWindow::on_varnr_textChanged(const QString)
{
    setValidValue(ui->varnr, settings.variablesCount);
}
