#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//*******************************************************************//
//********* инициализация диалога для каждой мат. операции **********//
//*******************************************************************//

void MainWindow::on_btnPlus_clicked()
{
    new Dialog(this, SumVectors);
}

void MainWindow::on_btnUmnozh_clicked()
{
    new Dialog(this, MulOnNumber);
}

void MainWindow::on_btnVecProizved_clicked()
{
    new Dialog(this, MulVectors);
}

void MainWindow::on_btnMinus_clicked()
{
    new Dialog(this, SubVectors);
}

void MainWindow::on_btnModul_clicked()
{
    new Dialog(this, AbsVector);
}

void MainWindow::on_btnSkalyar_clicked()
{
    new Dialog(this, MulSkalyar);
}

void MainWindow::on_btnUgol_clicked()
{
     new Dialog(this, AngleVectors);
}

void MainWindow::on_btnSmesh_clicked()
{
    new Dialog(this, MulSmeshVectors);
}
