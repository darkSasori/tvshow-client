#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QHostAddress>

class Server : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString host READ host WRITE setHost NOTIFY hostChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(quint16 port READ port WRITE setPort NOTIFY portChanged)
public:
    explicit Server(QHostAddress host, QString name, quint16 port, QObject *parent = 0);

    QString host();
    void setHost(QString host);

    QString name();
    void setName(QString name);

    quint16 port();
    void setPort(quint16 port);

signals:
    void hostChanged();
    void nameChanged();
    void portChanged();

public slots:

private:
    QString m_name;
    QHostAddress m_host;
    quint16 m_port;
};

#endif // SERVER_H
