#include "item.h"

Item::Item(QString channel,
           int net,
           QDateTime start,
           QDateTime end,
           QString title,
           QString desc,
           QObject *parent)
           : QObject(parent),
             m_channel(channel),
             m_net(net),
             m_start(start),
             m_end(end),
             m_title(title),
             m_desc(desc)
{
//    this->m_start.setTimeZone(QTimeZone::utc());
}

QString Item::channel()
{
    return this->m_channel;
}

void Item::setChannel(QString channel)
{
    this->m_channel = channel;
    emit channelChanged();
}

int Item::net()
{
    return this->m_net;
}

void Item::setNet(int net)
{
    this->m_net = net;
    emit netChanged();
}

QDateTime Item::start()
{
    return this->m_start;
}

void Item::setStart(QDateTime start)
{
    this->m_start = start;
    emit startChanged();
}

QDateTime Item::end()
{
    return this->m_end;
}

void Item::setEnd(QDateTime end)
{
    this->m_end = end;
    emit endChanged();
}

QString Item::title()
{
    return this->m_title;
}

void Item::setTitle(QString title)
{
    this->m_title = title;
    emit titleChanged();
}

QString Item::desc()
{
    return this->m_desc;
}

void Item::setDesc(QString desc)
{
    this->m_desc = desc;
    emit descChanged();
}
