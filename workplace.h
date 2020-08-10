#ifndef WORKPLACE_H
#define WORKPLACE_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QDebug>

#include "veditorwidget.h"
#include "vitem.h"
#include "Enums.h"

using namespace Enums;

namespace Ui {
class Workplace;
}

class Workplace : public QGraphicsView
{
    Q_OBJECT

public:
    explicit Workplace(QWidget *parent = nullptr);
    ~Workplace();

    void setCurrentAction(ActionTypes newActionType) {currentActionType = newActionType;}
private:
    Ui::Workplace *ui;

    QPoint mousePressPoint;
    QPoint mouseReleasePoint;

    bool leftMouseButtonPressed = false;

    std::vector<VItem *> allItems;

    std::vector<VItem *> items() {return allItems;}

    ActionTypes currentActionType;

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
};

#endif // WORKPLACE_H
