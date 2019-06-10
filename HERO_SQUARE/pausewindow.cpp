#include "pausewindow.h"
#include "ui_pausewindow.h"


PauseWindow::PauseWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PauseWindow)
{
    ui->setupUi(this);
}

PauseWindow::~PauseWindow()
{
    delete ui;
}



void PauseWindow::on_pushButton_exit_clicked()
{
    this->close();      // Закрываем окно
    emit exitGame(); // И вызываем сигнал на открытие главного окна
}


void PauseWindow::on_pushButton_continue_clicked()
{
    this->close();      // Закрываем окно
    emit continueGame();
}
