#include "veditorwidget.h"
#include "ui_veditorwidget.h"

VEditorWidget::VEditorWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VEditorWidget)
{
    ui->setupUi(this);

    view = ui->graphicsView;
    scene.setSceneRect(QRect(0,0,100,100));
    view->setScene(&scene);



    scene.addLine(-100,0,100,0);
    scene.addLine(0,-100,0,100);

//    QGraphicsLineItem line(0,0,100,100);

    currentActionTypeButton = ui->selectionTypePushButton;
}

VEditorWidget::~VEditorWidget()
{
    delete ui;
}

void VEditorWidget::changeCurrentAction(const ActionTypes &newAction, QPushButton *newButton)
{
    currentActionTypeButton->setChecked(false);

    currentActionType = newAction;
    currentActionTypeButton = newButton;

    currentActionTypeButton->setChecked(true);
    updateWorkplaceCurrentAction();
}

void VEditorWidget::on_selectionTypePushButton_clicked(bool checked)
{
    if (checked)
        changeCurrentAction(SelectionType, ui->selectionTypePushButton);
}

void VEditorWidget::on_lineTypePushButton_clicked(bool checked)
{
    if (checked)
        changeCurrentAction(LineType, ui->lineTypePushButton);
}

void VEditorWidget::on_rectTypePushButton_clicked(bool checked)
{
    if (checked)
        changeCurrentAction(RectType, ui->rectTypePushButton);
}

void VEditorWidget::updateWorkplaceCurrentAction()
{
    ui->graphicsView->setCurrentAction(currentAction());
}
