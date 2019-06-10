#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Инициализируем окно обучения
    trainingWindow = new TrainingWindow();
    // подключаем к слоту запуска главного окна по кнопке в окне обучения
    connect(trainingWindow, &TrainingWindow::exit, this, &MainWindow::show);
    // Инициализируем окно загрузки
    gameWindow= new GameWindow();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_play_clicked()
{
    gameWindow->show();
    this->close();
}

void MainWindow::on_pushButton_training_clicked()
{
    trainingWindow->show();  // Показываем инструкцию
    this->close();    // Закрываем основное окно
}

void MainWindow::on_pushButton_exit_clicked()
{
    QMessageBox::StandardButton chec = QMessageBox::question(this, " Notification "," Are you sure? ",QMessageBox::Yes| QMessageBox::No);
    if(chec==QMessageBox::Yes){
       this->close();
    }
}


