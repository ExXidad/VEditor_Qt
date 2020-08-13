#include "workplace.h"
#include "ui_workplace.h"

Workplace::Workplace(QWidget *parent) :
    QGraphicsScene(parent)
{
    //    scene->setSceneRect(QRect(0,0,200,200));
}

Workplace::~Workplace()
{
    delete ui;
    foreach (VItem *item, m_items) {
        delete item;
    }
}

void Workplace::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton){
        mousePressPoint = event->scenePos();
        leftMouseButtonPressed = true;

        addNewItem(currentAction());

        qDebug() << "pressed";
    }
}

void Workplace::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (leftMouseButtonPressed){

        qDebug() << "moved";
    }
}

void Workplace::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() & Qt::LeftButton){
        leftMouseButtonPressed = false;
        mouseReleasePoint = event->scenePos();
        qDebug() << "released";

        switch (currentAction()) {
        case LineType:
            addLine(QLineF(mousePressPoint, mouseReleasePoint));
            break;

        case RectType:
            addRect(QRectF(
                        QPointF(
                            qMin(mousePressPoint.x(), mouseReleasePoint.x()),
                            qMin(mousePressPoint.y(), mouseReleasePoint.y())
                            ),
                        QSizeF(
                            qAbs(mousePressPoint.x() - mouseReleasePoint.x()),
                            qAbs(mousePressPoint.y() - mouseReleasePoint.y())
                            )
                        )
                    );
            break;

        default:
            qDebug() << "NLT";
            break;
        }
    }
}

void Workplace::addNewItem(const ActionTypes &passedType)
{
    VItem *newItem;
    switch (passedType) {
    case LineType:
        newItem = new VLine(QPointF(0,0), QPointF(0,0));
        break;

    case RectType:
        //Implement VRect class
        break;

    default:
        break;
    }

    items().emplace_back(newItem);
    *currentItem() = newItem;
}

void Workplace::deleteCurrentItem()
{
    items().erase(items().end());
    delete currentItem();
}
