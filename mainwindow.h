#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}




class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnPlus_clicked();          // сложение векторов
    void on_btnMinus_clicked();         // вычитание векторов
    void on_btnUmnozh_clicked();        // умножение на число
    void on_btnVecProizved_clicked();   // векторное произведение
    void on_btnModul_clicked();         // модуль вектора
    void on_btnSkalyar_clicked();       // скалярное произведение
    void on_btnUgol_clicked();          // угол между векторами
    void on_btnSmesh_clicked();         // смешанное произведение

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
