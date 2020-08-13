#ifndef VEDITORWIDGET_H
#define VEDITORWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QGraphicsScene>
#include <QDebug>
#include <QPushButton>
#include <QGraphicsView>

#include "vitem.h"
#include <vector>
#include "Enums.h"
#include "workplace.h"

using namespace Enums;

class Workplace;

namespace Ui {
class VEditorWidget;
}

class VEditorWidget : public QWidget
{
    Q_OBJECT

public:
    explicit VEditorWidget(QWidget *parent = nullptr);
    ~VEditorWidget();

private:
    Ui::VEditorWidget *ui;

    Workplace *workplace;

    QGraphicsView *view;

public:
    void changeCurrentAction(const ActionTypes &newAction, QPushButton *newButton);

    ActionTypes currentAction() {return currentActionType;}

    void updateWorkplaceCurrentAction();

private slots:
    //void changeCurrentAction(const ActionTypes &newAction, QPushButton *newButton);
    void on_selectionTypePushButton_clicked(bool checked);

    void on_lineTypePushButton_clicked(bool checked);

    void on_rectTypePushButton_clicked(bool checked);

    void on_pushButton_4_clicked();

private:
    ActionTypes currentActionType = SelectionType;

    QPushButton *currentActionTypeButton;
};

#endif // VEDITORWIDGET_H
