#include "BatteryItem.h"
#include <QPainter>
#include <QDebug>

BatteryItem::BatteryItem(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
}

BatteryItem::BatteryItem(QWidget *parent, int value, int color /*= 0*/)
    : QWidget(parent)
{
    //ui.lab_value->setText("dd");
    //设置电池大小
    //setFixedSize(26, 16);
    //setFixedSize(100, 50);
    setBatteryColor(color);
    setBatteryValue(value);
    setShowText(1);
}

void BatteryItem::setBatteryValue(int value)
{
    if (value < 0 )
    {
        value = 0;
    }
    if (value > 100)
    {
        value = 100;
    }
    m_value = value;


    //更新界面

    update();

}

void BatteryItem::setBatteryColor(int color)
{
    if (color<0||color>2)
    {
        color = 0;
    }

    //QColor(136, 205, 112) - 翠绿1
    //QColor(137, 249, 83) - 翠绿2
    switch (color)
    {
    case 0://绿色
        m_color = QColor(0, 255, 0);
        break;
    case 1://黄色
        m_color = QColor(218, 165, 32);
        //m_color = QColor(255, 255, 0);
        break;
    case 2://红色
        m_color = QColor(255, 0, 0);
        break;
    }
    //更新界面
    update();
}

void BatteryItem::setShowText(int flg/*=0*/, QString str/*=""*/)
{
    m_showTextFlg = flg;
    m_showText = str;
    update();
}



BatteryItem::~BatteryItem()
{

}


void BatteryItem::paintEvent(QPaintEvent *event)
{

    QSize itemSize = this->size();
    const int margin = 3;
    int w = itemSize.width();
    int h = itemSize.height();

    int x0, y0, w0, h0;
    int x1, y1, w1, h1;
    int x2, y2, w2, h2;


    x0 = 1; y0 = x0;
    w0 = w - 2 * x0 - margin;
    h0 = h - 2 * y0;


    x1 = 4; y1 = x1;
    w1 = w - 2 * x1 - 4;
    h1 = h - 2 * y1;


    x2 = x0 + w0 ;
    y2 = h / 3;
    w2 = margin;
    h2 = h / 3;

    QPainter painter(this);
    QPen pen;

    painter.setPen(m_color);
    pen = painter.pen();
    pen.setWidth(2);
    painter.setPen(pen);


    painter.drawRoundedRect(x0, y0, w0, h0, 2, 2);



    painter.setBrush(m_color);

    painter.drawRoundedRect(x2, y2, w2, h2, 1, 1);


    int w1_current = m_value*0.01*(w1);

    painter.drawRect(x1, y1, w1_current, h1);


    painter.setPen(QColor(0, 0, 0));

    switch (m_showTextFlg)
    {
    case 0:
        break;
    case 1:
        painter.drawText(x0, y0, w0, h0,
            Qt::AlignHCenter | Qt::AlignVCenter,
            QString::asprintf("%d%%", m_value));
        break;
    case 2:
        painter.drawText(x0, y0, w0, h0,
            Qt::AlignHCenter | Qt::AlignVCenter,
            m_showText);
        break;
    }



    QWidget::paintEvent(event);
}
