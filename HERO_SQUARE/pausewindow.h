#pragma once

#include <QWidget>
#include <QDebug>
#include "pausewindow.h"
#include "gamewindow.h"

namespace Ui {
    class PauseWindow;
}

class PauseWindow : public QWidget
{
    Q_OBJECT
public:
    explicit PauseWindow(QWidget *parent = nullptr);
    ~PauseWindow();

signals:


   void continueGame();
   void exitGame();

public slots:


    void on_pushButton_continue_clicked();
    void on_pushButton_exit_clicked();

private:
    int level;
    Ui::PauseWindow *ui;

};


