#ifndef ROWINPUT_H
#define ROWINPUT_H

#include <QWidget>
#include <QHBoxLayout>
#include <QDoubleSpinBox>


class RowInput : public QWidget
{
public:
    RowInput(QWidget *parent, int count);
    QHBoxLayout *layout;
    QVector<QDoubleSpinBox *> vec;
    QString as_string();

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
};

#endif // ROWINPUT_H
