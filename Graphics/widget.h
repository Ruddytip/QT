#ifndef WIDGET_H
#define WIDGET_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include <QGraphicsItem>
#include <QContextMenuEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QGraphicsView{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QGraphicsView *view;
    QGraphicsScene *scence;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private slots:

};
#endif // WIDGET_H
