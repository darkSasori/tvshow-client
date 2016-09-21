#ifndef UDPSOCKET_H
#define UDPSOCKET_H

#include <QObject>
#include <QDataStream>
#include <QUdpSocket>
#include "server.h"
#include "item.h"

typedef QList<Server*> ServerList;

typedef struct {
    char cmd;
    int number;
} command;

class UdpSocket : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject*> list READ list WRITE setList NOTIFY listChanged)
    Q_PROPERTY(QObject* current READ current WRITE setCurrent NOTIFY currentChanged)
    Q_PROPERTY(QString operatorName READ getOperator WRITE setOperator NOTIFY operatorChanged)
public:
    explicit UdpSocket(quint16 port, QObject *parent = 0);

    Q_INVOKABLE void refresh();

    Q_INVOKABLE void play(Item *item);

    QList<QObject*> list();
    void setList(QList<QObject*> list);

    QObject* current();
    void setCurrent(QObject* current);

    QString getOperator();
    void setOperator(QString operatorName);

signals:
    void listChanged();
    void currentChanged();
    void operatorChanged();

public slots:
    void readyRead();

private:
    void initializeList();

    QList<QObject*> m_list;
    QObject* m_current;
    quint16 m_port;
    QUdpSocket *m_sock;
    QString m_operator;
};

#endif // UDPSOCKET_H
