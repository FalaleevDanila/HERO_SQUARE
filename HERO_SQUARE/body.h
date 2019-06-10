#ifndef BODY_H
#define BODY_H

#include <QGraphicsItem>
#include <QPainter>
#include <QObject>
#include <QGraphicsScene>
#include <QKeyEvent>

class Body: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Body(QObject *parent = nullptr);
    ~Body();



public slots:
     void keyPressEvent(QKeyEvent *event) override;


protected:
    QRectF boundingRect() const;    /* Определяем виртуальный метод,
                                         * который возвращает область, в которой
                                         * находится треугольник
                                         */
    /* Определяем метод для отрисовки треугольника
    */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    qreal angle;    // Угол поворота графического объекта

};

#endif // BODY_H
