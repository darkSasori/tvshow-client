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
             m_desc(desc),
             m_visible(true)
{
}

QString Item::period()
{
    return this->m_start.toString("dd/MM/yyyy hh:mm")
            + " to "
            + this->m_end.toString("dd/MM/yyyy hh:mm");
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

bool Item::visible()
{
    return this->m_visible;
}

void Item::setVisible(bool visible)
{
    this->m_visible = visible;
    emit visibleChanged();
}

void Item::filter(QString q)
{
    if (q.isEmpty()) {
        this->setVisible(true);
        return;
    }
    this->setVisible(this->m_channel.toUpper().contains(q) || this->m_title.toUpper().contains(q));
}
