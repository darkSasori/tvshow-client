#ifndef TVSHOW_H
#define TVSHOW_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include "item.h"

class TvShow : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject*> list READ list WRITE setList NOTIFY listChanged)
    Q_PROPERTY(int count READ count WRITE setCount NOTIFY countChanged)
    Q_PROPERTY(QObject* currentItem READ currentItem WRITE setCurrentItem NOTIFY currentItemChanged)
public:
    explicit TvShow(QString m_url, QObject *parent = 0);

    Q_INVOKABLE void now();

    QList<QObject*> list();
    void setList(QList<QObject*> list);

    int count();
    void setCount(int count);

    QObject* currentItem();
    void setCurrentItem(QObject* item);

    void clearList();

signals:
    void listChanged();
    void countChanged();
    void currentItemChanged();

public slots:
    void finished(QNetworkReply *reply);

private:
    QString m_url;
    QList<QObject*> m_list;
    int m_count;
    QNetworkAccessManager *manager;
    QObject *m_currentItem;
};

#endif // TVSHOW_H
