#pragma once

#include <QWidget>
#include <QDebug>

class MainWindow;

namespace Ui {
    class TrainingWindow;
}

class TrainingWindow : public QWidget
{
    Q_OBJECT
public:
    explicit TrainingWindow(QWidget *parent = nullptr);
    ~TrainingWindow();
signals:

    // Сигнал для первого окна на открытие
    void exit();

public slots:

    // Слот-обработчик нажатия кнопки
    void on_pushButton_exit_clicked();



private:
    Ui::TrainingWindow *ui;

    MainWindow* mainWindow;
};

#pragma once
