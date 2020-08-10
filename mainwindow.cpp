#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    vEditorWidget = new VEditorWidget(this);
    vEditorWidget->show();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete vEditorWidget;
}

