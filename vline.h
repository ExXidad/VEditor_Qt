#ifndef VLINE_H
#define VLINE_H

#include <QLine>

#include "vitem.h"

class VLine : public VItem, public QLine
{
public:
    VLine();
    ~VLine();

protected:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // VLINE_H
