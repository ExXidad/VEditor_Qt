#ifndef VLINE_H
#define VLINE_H

#include <QLine>
#include <QGraphicsLineItem>

#include "vitem.h"

class VLine : public VItem, public QGraphicsLineItem
{
public:
    VLine(const QPointF &p1, const QPointF &p2);
    ~VLine() override {}

    void setLine(const QPointF &p1, const QPointF &p2);

};

#endif // VLINE_H
