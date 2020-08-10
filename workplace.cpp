#include "workplace.h"
#include "ui_workplace.h"

Workplace::Workplace(QWidget *parent) :
    QGraphicsView(parent),
    ui(new Ui::Workplace)
{
    ui->setupUi(this);

//    scene->setSceneRect(QRect(0,0,200,200));
}

Workplace::~Workplace()
{
    delete ui;
}

void Workplace::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton){
        mousePressPoint = event->pos();
        leftMouseButtonPressed = true;
        qDebug() << "pressed";
    }
}

void Workplace::mouseMoveEvent(QMouseEvent *event)
{
    if (leftMouseButtonPressed){
        qDebug() << "moved";
    }
}

void Workplace::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() & Qt::LeftButton){
        leftMouseButtonPressed = false;
        mouseReleasePoint = event->windowPos();
        qDebug() << "released";

        switch (currentActionType) {
        case LineType:
            scene()->addLine(QLine(mousePressPoint, mouseReleasePoint));
            break;
        default:
            qDebug() << "NLT";
            break;
        }
    }
}
