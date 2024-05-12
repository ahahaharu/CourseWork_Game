#include "AnimatedRect.h"

AnimatedRect::AnimatedRect(QWidget *parent) : QWidget(parent)
{
    setFixedSize(30, 100);
}

AnimatedRect::~AnimatedRect() {}

void AnimatedRect::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(Qt::blue);
    painter.drawRect(rect());
}
