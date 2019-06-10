#pragma once


#include <QDebug>
#include <QMainWindow>
#include <QMessageBox>



#include "trainingwindow.h"
#include "gamewindow.h"




class GameWindow;
class PauseWindow;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void playGame();
    void trainingText();
    void exitApp();

private slots:
    // Слоты от кнопок главного окна
    void on_pushButton_play_clicked();
    void on_pushButton_training_clicked();
    void on_pushButton_exit_clicked();



private:
    Ui::MainWindow *ui;

    TrainingWindow *trainingWindow;
    GameWindow *gameWindow;

};

