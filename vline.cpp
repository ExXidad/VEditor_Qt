#include "vline.h"

VLine::VLine(const QPointF &p1, const QPointF &p2) : VItem(),
    QGraphicsLineItem(QLineF(p1,p2))
{

}

void VLine::setLine(const QPointF &p1, const QPointF &p2)
{
    QGraphicsLineItem::setLine(QLineF(p1, p2));
}
