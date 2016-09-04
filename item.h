#ifndef ITEM_H
#define ITEM_H

#include <QObject>
#include <QDateTime>
#include <QTimeZone>

class Item : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString channel READ channel WRITE setChannel NOTIFY channelChanged)
    Q_PROPERTY(int net READ net WRITE setNet NOTIFY netChanged)
    Q_PROPERTY(QDateTime start READ start WRITE setStart NOTIFY startChanged)
    Q_PROPERTY(QDateTime end READ end WRITE setEnd NOTIFY endChanged)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString desc READ desc WRITE setDesc NOTIFY descChanged)
public:
    explicit Item(QString channel, int net, QDateTime start, QDateTime end, QString title, QString desc, QObject *parent = 0);

    QString channel();
    void setChannel(QString channel);

    int net();
    void setNet(int net);

    QDateTime start();
    void setStart(QDateTime start);

    QDateTime end();
    void setEnd(QDateTime end);

    QString title();
    void setTitle(QString title);

    QString desc();
    void setDesc(QString desc);

signals:
    void channelChanged();
    void netChanged();
    void startChanged();
    void endChanged();
    void titleChanged();
    void descChanged();

public slots:

private:
    QString m_channel;
    int m_net;
    QDateTime m_start;
    QDateTime m_end;
    QString m_title;
    QString m_desc;
};

#endif // ITEM_H
