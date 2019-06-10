#include "mainwindow.h"
#include <QApplication>

//ничего не трогаем
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GameWindow gameWindow;
    TrainingWindow trainingWindow;
    MainWindow mainWindow;
    PauseWindow pauseWindow;

    gameWindow.setMainWindow(&mainWindow);
    gameWindow.setPauseWindow(&pauseWindow);
    trainingWindow.setMainWindow(&mainWindow);
    mainWindow.setGameWindow(&gameWindow);
    mainWindow.setTrainingWindow(&trainingWindow);

    mainWindow.show();

    return QApplication::exec();
}
