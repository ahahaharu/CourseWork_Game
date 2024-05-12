#ifndef ANIMATEDRECT_H
#define ANIMATEDRECT_H

#include <QWidget>
#include <QPainter>

class AnimatedRect : public QWidget
{
    Q_PROPERTY(QPoint pos READ pos WRITE setPos)

public:
    AnimatedRect(QWidget *parent = nullptr);
    ~AnimatedRect();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QPoint m_pos;
};

#endif // ANIMATEDRECT_H
