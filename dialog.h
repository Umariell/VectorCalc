#ifndef DIALOG_H
#define DIALOG_H

#include "rowinput.h"
#include <QDialog>
#include <QPushButton>
#include <QTextEdit>
#include <QFile>


namespace Ui {
class Dialog;
}

//*******************************************************************//
//************* МАТЕМАТИЧЕСКИЕ ОПЕРАЦИИ *****************************//
//*******************************************************************//
enum MathOperations {
    MulVectors,     // Умножение векторов
    MulOnNumber,    // Умножение вектора на число
    MulSkalyar,     // Скалярное произведение
    SumVectors,     // Сложение векторов
    SubVectors,     // Вычитание векторов
    AbsVector,      // Модуль вектора
    AngleVectors,   // Угол между векторами
    MulSmeshVectors // Смешанное произведение векторов
};

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent, MathOperations op);
    ~Dialog();

private slots:
    void solver_func();

//*******************************************************************//
//************* создание окна с вычислениями ************************//
//*******************************************************************//
private:
    Ui::Dialog *ui;

    //создание трех строк для векторов
    RowInput *row1, *row2 = nullptr, *row3 = nullptr;
    QPushButton *btn;                       // кнопка "вычислить"
    QTextEdit *textEdit;                    // область с выводом ответа
    MathOperations currentOp;               // мат.операции

    void add_to_history(const QString &name, const QString &str, QFile &file);
};

#endif // DIALOG_H
