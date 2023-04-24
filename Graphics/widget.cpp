#include "widget.h"
#include <QMessageBox>
#include "blockSheme.h"
#include <QGraphicsSceneMouseEvent>

Widget::Widget(QWidget *parent): QGraphicsView(parent) {
    scence = new QGraphicsScene(this); // Новая сцена
    setScene(scence);
    BlockScheme* block = new BlockScheme(this);
    block->setParent(this);
    scence->addItem(block);

    //scence->addRect(-300,0,300,300); // Добавляем прямоугольник
    //scence->addText("Текст через Graphics View Framework"); // Добавляем текст
    //scence->addEllipse(-50, -50, 100, 100);
}

Widget::~Widget(){

}

void Widget::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {// Левая кнопка, режим перемещения
        QPoint point = event->pos().toPoint(); // Запоминаем начальные координаты мыши
        BlockScheme* block = new BlockScheme(this);
        block->setPos(point);
        scence->addItem(block);
    }

//    if (event->button() == Qt::RightButton) {// Правая кнопка - меняем вид фигуры
//        if (geometry == Geometry::ELLIPS) {
//            geometry = Geometry::RECTANGLE;
//        } else geometry = Geometry::ELLIPS;
//        emit reDraw(); // переотрисовка
//        update();
//    }
}

