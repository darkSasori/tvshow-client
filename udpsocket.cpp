#include "udpsocket.h"

UdpSocket::UdpSocket(quint16 port, QObject *parent)
    : QObject(parent),
      m_port(port)
{
    this->m_sock = new QUdpSocket(this);

    connect(this->m_sock, SIGNAL(readyRead()), this, SLOT(readyRead()));

    this->initializeList();
    this->setCurrent(this->m_list[0]);
    this->setOperator("NET");

    this->refresh();
}

void UdpSocket::refresh()
{
    this->initializeList();

    QByteArray data("a");
    this->m_sock->writeDatagram(data, QHostAddress::Broadcast, this->m_port);
}

void UdpSocket::play(Item *item)
{
#ifdef QT_DEBUG
    qDebug() << this->current();
    qDebug() << item->getChannelNumber()[this->getOperator()];
#endif
    QByteArray data("c;");
    data += QString::number(item->getChannelNumber()[this->getOperator()]);
    this->m_sock->writeDatagram(data, QHostAddress::Broadcast, this->m_port);
}

void UdpSocket::readyRead()
{
    if (this->m_sock->hasPendingDatagrams()) {
        QByteArray data;
        data.resize(this->m_sock->pendingDatagramSize());

        QHostAddress sender;
        quint16 senderPort;

        this->m_sock->readDatagram(data.data(), data.size(), &sender, &senderPort);
        this->m_list.append(new Server(sender, data.data(), senderPort));
        emit listChanged();
    }
}

void UdpSocket::initializeList()
{
    this->m_list.clear();
    this->m_list.append(new Server(QHostAddress::Broadcast, "All", this->m_port));
    emit listChanged();
}

QList<QObject*> UdpSocket::list()
{
    return this->m_list;
}

void UdpSocket::setList(QList<QObject *> list)
{
    this->m_list = list;
    emit listChanged();
}

QObject* UdpSocket::current()
{
    return this->m_current;
}

void UdpSocket::setCurrent(QObject *current)
{
    this->m_current = current;
    emit currentChanged();
}

QString UdpSocket::getOperator()
{
    return this->m_operator;
}

void UdpSocket::setOperator(QString operatorName)
{
    this->m_operator = operatorName;
    emit operatorChanged();
}
