#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <MathGlDrawer.h>
<<<<<<< HEAD
#include <mgl2/qmathgl.h>
=======
>>>>>>> 54a7326f98b8a17f22f682e7bddb938529e04e9f

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
<<<<<<< HEAD
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QMathGL *QMGL;
=======
private:
    Ui::MainWindow *ui;
>>>>>>> 54a7326f98b8a17f22f682e7bddb938529e04e9f
    MathGlDrawer drawer;
};

#endif // MAINWINDOW_H
