#ifndef VITEM_H
#define VITEM_H

#include <QMouseEvent>

class VItem
{
public:

protected:
    virtual void mousePressEvent(QMouseEvent *event) = 0;
};

#endif // VITEM_H
