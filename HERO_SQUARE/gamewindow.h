#pragma once

#include <QWidget>
#include <QDebug>
#include <QShortcut>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsView>

#include "pausewindow.h"
#include "body.h"
#include "mainwindow.h"

class PauseWindow;

namespace Ui {

class GameWindow;

}

class GameWindow : public QWidget
{
    Q_OBJECT

public:

    explicit GameWindow(MainWindow *mainWindow, QWidget *parent = nullptr);
    void getLevel();

signals:

    void pauseGame();


public slots:

     void keyPressEvent(QKeyEvent *event) override;

private:

    Ui::GameWindow     *ui;
    QGraphicsScene  *scene;     // Объявляем графическую сцену
    Body             *body;
    QTimer          *timer;     /* Объявляем игровой таймер, благодаря которому
                                     * будет производиться изменения положения объекта на сцене
                                     * При воздействии на него клавишами клавиатуры
                                     * */
    PauseWindow *pauseWindow;
    MainWindow   *mainWindow;
public:

};


