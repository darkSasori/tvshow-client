#ifndef UDPSOCKET_H
#define UDPSOCKET_H

#include <QObject>
#include <QUdpSocket>
#include "server.h"

class UdpSocket : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject*> list READ list WRITE setList NOTIFY listChanged)
    Q_PROPERTY(QObject* current READ current WRITE setCurrent NOTIFY currentChanged)
public:
    explicit UdpSocket(quint16 port, QObject *parent = 0);

    Q_INVOKABLE void refresh();

    Q_INVOKABLE void play(int net);

    QList<QObject*> list();
    void setList(QList<QObject*> list);

    QObject* current();
    void setCurrent(QObject* current);

signals:
    void listChanged();
    void currentChanged();

public slots:
    void readyRead();

private:
    void initializeList();

    QList<QObject*> m_list;
    QObject* m_current;
    quint16 m_port;
    QUdpSocket *m_sock;
};

#endif // UDPSOCKET_H
