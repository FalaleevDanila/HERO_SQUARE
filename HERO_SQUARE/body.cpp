#include "body.h"

Body::Body(QObject *parent):QObject(parent), QGraphicsItem()
{
    angle = 0;     // Задаём угол поворота графического объекта
    setRotation(angle);     // Устанавилваем угол поворота графического объекта
}

Body::~Body()
{

}

QRectF Body::boundingRect() const
{
    return QRectF(-25,-40,50,80);   /// Ограничиваем область, в которой лежит треугольник
}

void Body::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
        QPolygon polygon;   /// Используем класс полигона, чтобы отрисовать треугольник
        /// Помещаем координаты точек в полигональную модель
        polygon << QPoint(25,25) << QPoint(25,-25) << QPoint(-25,-25)<< QPoint(-25,25);
        painter->setBrush(Qt::blue);     /// Устанавливаем кисть, которой будем отрисовывать объект
        painter->drawPolygon(polygon);  /// Рисуем треугольник по полигональной модели
        Q_UNUSED(option);
        Q_UNUSED(widget);
}

void Body::keyPressEvent(QKeyEvent *event)
{
    /* Поочерёдно выполняем проверку на нажатие клавиш
     * с помощью функции асинхронного получения состояния клавиш,
     * которая предоставляется WinAPI
     * */
       int key = event->key();
    if(key == Qt::Key_W){
        angle -= 10;        // Задаём поворот на 10 градусов влево
        setRotation(angle); // Поворачиваем объект
    }
    if(key == Qt::Key_D){
        angle += 10;        // Задаём поворот на 10 градусов вправо
        setRotation(angle); // Поворачиваем объект
    }
    if(key == Qt::Key_W){
        setPos(mapToParent(0, -5));     /* Продвигаем объект на 5 пискселей вперёд
                                         * перетранслировав их в координатную систему
                                         * графической сцены
                                         * */
    }
    if(key == Qt::Key_S){
        setPos(mapToParent(0, 5));      /* Продвигаем объект на 5 пискселей назад
                                         * перетранслировав их в координатную систему
                                         * графической сцены
                                         * */
    }

    /* Проверка выхода за границы поля
     * Если объект выходит за заданные границы, то возвращаем его назад
     * */
    if(this->x() - 10 < -250){
        this->setX(-240);       // слева
    }
    if(this->x() + 10 > 250){
        this->setX(240);        // справа
    }

    if(this->y() - 10 < -250){
        this->setY(-240);       // сверху
    }
    if(this->y() + 10 > 250){
        this->setY(240);        // снизу
    }
}
