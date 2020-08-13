#ifndef WORKPLACE_H
#define WORKPLACE_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>

#include "veditorwidget.h"
#include "vitem.h"
#include "Enums.h"
#include "vline.h"

using namespace Enums;

namespace Ui {
class Workplace;
}

class Workplace : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit Workplace(QWidget *parent = nullptr);
    ~Workplace();

    void setCurrentAction(ActionTypes newActionType) {m_currentAction = newActionType;}

    ActionTypes currentAction() {return m_currentAction;}

    std::vector<VItem *> items() {return m_items;}
    VItem ** currentItem() {return &m_currentItem;}

    void deleteCurrentItem();
private:
    Ui::Workplace *ui;

    QPointF mousePressPoint;
    QPointF mouseReleasePoint;

    bool leftMouseButtonPressed = false;

    std::vector<VItem *> m_items;
    VItem *m_currentItem;

    ActionTypes m_currentAction;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    void addNewItem(const ActionTypes &passedType);
};

#endif // WORKPLACE_H
