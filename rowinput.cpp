#include "rowinput.h"
#include <QDropEvent>
#include <QMimeData>
#include <QDebug>
#include <QStandardItemModel>
#include <QStringList>

RowInput::RowInput(QWidget *parent, int count) : QWidget(parent)
{
    layout = new QHBoxLayout(this);
    for (int i = 0; i < count; i++) {
        auto inpBox = new QDoubleSpinBox(this);
        inpBox->setMaximum(1000);       // диапазон
        inpBox->setAcceptDrops(true);   // для
        inpBox->setMinimum(-1000);      // векторов
        layout->addWidget(inpBox);
        vec.append(inpBox);
    }
    setAcceptDrops(true);
}

// вывод результатов
QString RowInput::as_string()
{
    QStringList list;

    for (int i = 0; i < vec.length(); i++)
        list.append(QString::number(vec[i]->value()));//помещаем всё в список и джойним его с табом

    return list.join("\t");
}

// ведение истории (последнее значение - вверх)
void RowInput::dropEvent(QDropEvent *event)
{
    auto model = new QStandardItemModel();
    model->dropMimeData(event->mimeData(), Qt::CopyAction, 0, 0, QModelIndex());
    QString s = model->index(0, 0).data().value<QString>();
    QStringList list = s.split("\t");
    for (int i = 0; i < vec.length(); i++) {
        if (i >= list.length())
            break;
        vec[i]->setValue(list.at(i).toDouble() );
    }
    event->accept();
}

//событие для перетаскивания значений в разные окна (использование любых введенных и полученных векторов)
void RowInput::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist")) {
        event->acceptProposedAction();//"+"
    } else {
        event->ignore(); //"-"
    }
}
