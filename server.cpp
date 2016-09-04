#include "server.h"

Server::Server(QHostAddress host, QString name, quint16 port, QObject *parent)
    : QObject(parent),
      m_host(host),
      m_name(name),
      m_port(port)
{
}

QString Server::host()
{
    return this->m_host.toString();
}

void Server::setHost(QString host)
{
    this->m_host = QHostAddress(host);
    emit hostChanged();
}

QString Server::name()
{
    return this->m_name;
}

void Server::setName(QString name)
{
    this->m_name = name;
    emit nameChanged();
}

quint16 Server::port()
{
    return this->m_port;
}

void Server::setPort(quint16 port)
{
    this->m_port = port;
    emit portChanged();
}
