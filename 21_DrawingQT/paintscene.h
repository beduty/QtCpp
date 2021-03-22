#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QDebug>

class paintScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit paintScene(QObject *parent = nullptr);

signals:

private:
    QPointF previousPoint;

    // QGraphicsScene interface
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif // PAINTSCENE_H
