#include "veditorwidget.h"
#include "ui_veditorwidget.h"

VEditorWidget::VEditorWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VEditorWidget)
{
    ui->setupUi(this);

    workplace = new Workplace(this);

    view = ui->graphicsView;
    view->setScene(workplace);

    workplace->addLine(-100,0,100,0);
    workplace->addLine(0,-100,0,100);

    workplace->setSceneRect(QRectF(-500,-500,1000,1000));

//    QGraphicsLineItem line(0,0,100,100);

    currentActionTypeButton = ui->selectionTypePushButton;
}

VEditorWidget::~VEditorWidget()
{
    delete ui;
    delete workplace;
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
    workplace->setCurrentAction(currentAction());
}

void VEditorWidget::on_pushButton_4_clicked()
{
    workplace->addText("Я люблю Ульяшу сильнее всех на свете");
}
