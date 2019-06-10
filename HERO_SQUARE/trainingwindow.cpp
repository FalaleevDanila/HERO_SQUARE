#include "trainingwindow.h"
#include "ui_trainingwindow.h"


TrainingWindow::TrainingWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TrainingWindow)
{
    ui->setupUi(this);
}

TrainingWindow::~TrainingWindow()
{
    delete ui;
}


void TrainingWindow::on_pushButton_exit_clicked()
{
    this->close();
    emit exit();
}
