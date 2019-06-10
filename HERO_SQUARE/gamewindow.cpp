#include "gamewindow.h"
#include "ui_gamewindow.h"


GameWindow::GameWindow(MainWindow *mainWindow, QWidget *parent)
    :
    mainWindow(mainWindow),
    QWidget(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    pauseWindow = new PauseWindow();

    connect(pauseWindow, &PauseWindow::continueGame, this, &GameWindow::show);

    connect(pauseWindow, &PauseWindow::exitGame, this, &GameWindow::close);

    connect(pauseWindow, &PauseWindow::exitGame, mainWindow, &MainWindow::show);


    // цепляем обработчик нажатия клавиши
    this->resize(1200,600);          /// Задаем размеры виджета, то есть окна
    this->setFixedSize(1200,600);    /// Фиксируем размеры виджета
    scene = new QGraphicsScene();   /// Инициализируем графическую сцену

    body = new Body();      /// Инициализируем треугольник

    ui->graphicsView->setScene(scene);  /// Устанавливаем графическую сцену в graphicsView
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    /// Устанавливаем сглаживание
    //ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); /// Отключаем скроллбар по вертикали
    //ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); /// Отключаем скроллбар по горизонтали

    //scene->setSceneRect(-250,-250,500,500); /// Устанавливаем область графической сцены

    scene->addLine(-250,0,250,0,QPen(Qt::black));   /// Добавляем горизонтальную линию через центр
    scene->addLine(0,-250,0,250,QPen(Qt::black));   /// Добавляем вертикальную линию через центр

    /* Дополнительно нарисуем органичение территории в графической сцене */
    scene->addLine(-250,-250, 250,-250, QPen(Qt::black));
    scene->addLine(-250, 250, 250, 250, QPen(Qt::black));
    scene->addLine(-250,-250,-250, 250, QPen(Qt::black));
    scene->addLine( 250,-250, 250, 250, QPen(Qt::black));

    scene->addItem(body);   /// Добавляем на сцену треугольник
    body->setPos(0,0);      /// Устанавливаем треугольник в центр сцены

    /* Инициализируем таймер и вызываем слот обработки сигнала таймера
     * у Треугольника 20 раз в секунду.
     * Управляя скоростью отсчётов, соответственно управляем скоростью
     * изменения состояния графической сцены
     * */
    timer = new QTimer();
    timer->start(1000 / 50);
}



void GameWindow::keyPressEvent(QKeyEvent *event)
{
   int key = event->key();
   if (key == Qt::Key_Tab) {
       pauseWindow->show();
   }
}
