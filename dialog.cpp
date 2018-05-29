#include "dialog.h"
#include "ui_dialog.h"
#include "solver.h"

Dialog::Dialog(QWidget *parent, MathOperations op) :
    QDialog(parent),
    ui(new Ui::Dialog)

//*******************************************************************//
//************* наведение красоты ***********************************//
//*******************************************************************//
{
    ui->setupUi(this);
    currentOp = op;

    int cnt1(0), cnt2(0), cnt3(0);

    auto widget = new QWidget(this);
    ui->horizontalLayout->insertWidget(0, widget);
    btn = new QPushButton(widget);

    switch (currentOp) {
    case MulVectors:
    {
        cnt1 = cnt2 = 3;                                    // countы для двух векторов
        setWindowTitle("Векторное произведение");           // название окна
        btn->setText("Умножить");                           // текст на кнопке
        break;
    }
    case SumVectors:
    {
        cnt1 = cnt2 = 3;
        setWindowTitle("Сложение векторов");
        btn->setText("Сложить");
        break;
    }
    case MulOnNumber:
    {
        cnt1 = 3;
        cnt2 = 1;
        setWindowTitle("Умножение вектора на число");
        btn->setText("Умножить");
        break;
    }
    case MulSkalyar:
    {
        cnt1 = cnt2 = 3;
        setWindowTitle("Скалярное произведение векторов");
        btn->setText("Умножить");
        break;
    }
    case SubVectors:
    {
        cnt1 = cnt2 = 3;
        setWindowTitle("Вычитание векторов");
        btn->setText("Вычесть");
        break;
    }
    case AbsVector:
    {
        cnt1 = 3;
        cnt2 = 0;
        cnt3 = 0;
        setWindowTitle("Модуль вектора");
        btn->setText("Вычислить");
        break;
    }
    case AngleVectors:
    {
        cnt1 = cnt2 = 3;
        setWindowTitle("Угол между векторами");
        btn->setText("Вычислить");
        break;
    }
    case MulSmeshVectors:
    {
        cnt1 = cnt2 = cnt3 = 3;
        setWindowTitle("Смешанное произведение векторов");
        btn->setText("Умножить");
        break;
    }
    }

    auto column = new QVBoxLayout(widget);

    row1 = new RowInput(widget, cnt1);
    column->addWidget(row1);

    if (cnt2) {
        row2 = new RowInput(widget, cnt2);
        column->addWidget(row2);
    }

    if (cnt3) {
        row3 = new RowInput(widget, cnt3);
        column->addWidget(row3);
    }

    connect(btn, &QPushButton::clicked, this, &Dialog::solver_func);
    column->addWidget(btn);
    textEdit = new QTextEdit(widget);
    textEdit->setReadOnly(true);
    column->addWidget(textEdit);
    show();

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::add_to_history(const QString &str, QFile &file)
{
    ui->listWidget->addItem(str);
    file.write(str.toLatin1() + "\r\n");
}


//*******************************************************************//
//************* ВЫЧИСЛЕНИЕ ******************************************//
//*******************************************************************//


void Dialog::solver_func()
{
    double A[3], B[3], D[3];

    QFile file("Result.txt");
    file.open(QIODevice::Append);

    //передача значений вектора А покоординатно в строку
    for (int i = 0; i < row1->vec.count(); i++)
        A[i] = row1->vec[i]->value();
    //сохраняем вектор в листе истории
    add_to_history(row1->as_string(), file);


    if (row2) {
        //передача значений вектора В покоординатно в строку
        for (int i = 0; i < row2->vec.count(); i++)
            B[i] = row2->vec[i]->value();
        //сохраняем вектор в листе истории
        add_to_history(row2->as_string(), file);
    }

    //передача значений вектора D покоординатно в строку ( в смешанном произведении )
    if (row3) {
        for (int i = 0; i < row3->vec.count(); i++)
            D[i] = row3->vec[i]->value();
        add_to_history(row3->as_string(), file);
    }

    QString result;
    QString razmernost;

    // математические операции над векторами
    switch (currentOp) {

    // умножение
    case MulVectors:
    {
        Vector a(A);
        Vector b(B);
        Vector c = a * b;
        result = c.as_string();
        break;
    }
    // сложение
    case SumVectors:
    {
        Vector a(A);
        Vector b(B);
        Vector c = a + b;
        result = c.as_string();
        break;
    }

    // умножение на число
    case MulOnNumber:
    {
        Vector a(A);
        Vector c = a * B[0];
        result = c.as_string();
        break;
    }

    // скалярное произведение
    case MulSkalyar:
    {
        Vector a(A);
        Vector b(B);
        result = QString::number(a.mul_skalyar(b));
        break;
    }

    // вычитание векторов
    case SubVectors:
    {
        Vector a(A);
        Vector b(B);
        Vector c = a - b;
        result = c.as_string();
        break;
    }

    // модуль векторов
    case AbsVector:
    {
        Vector a(A);
        result = QString::number(a.abs());
        break;
    }

    // угол между векторами
    case AngleVectors:
    {
        Vector a(A);
        Vector b(B);
        result = QString::number(a.angle(b));
        razmernost = " рад.";
        break;
    }

    // смешанное произведение векторов
    case MulSmeshVectors:
    {
        Vector a(A);
        Vector b(B);
        Vector d(D);
        result = QString::number(a.smesh(b, d));
        break;
    }
    }
    textEdit->setText(result + razmernost);
    add_to_history(result.replace("(", "").replace(")", ""), file);
    file.close();
}
