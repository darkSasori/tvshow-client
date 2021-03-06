#include "tvshow.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

TvShow::TvShow(QString url, QObject *parent)
    : QObject(parent),
      m_url(url),
      m_count(0)
{
    this->manager = new QNetworkAccessManager(this);

    connect(this->manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(finished(QNetworkReply*)));

    this->now();
}

void TvShow::now()
{
    emit startLoading();
    this->manager->get(QNetworkRequest(QUrl(this->m_url+"/now")));
    this->clearList();
}

void TvShow::filter(QString str)
{
    foreach (QObject* obj, this->m_list) {
        ((Item*)obj)->filter(str.toUpper());
    }
}

void TvShow::finished(QNetworkReply *reply)
{
    if (!reply->error()) {
        QJsonDocument response = QJsonDocument::fromJson(reply->readAll());
        QJsonObject root = response.object();
        this->setCount(root["count"].toInt());

        QJsonArray items = root["items"].toArray();
        for (auto it:items) {
            QJsonObject obj = it.toObject();
            QJsonObject objChannel = obj["channel_id"].toObject();

            ChannelNumber numbers;
            QString channel = objChannel["title"].toString();
            auto channelNumbers = objChannel["numbers"].toObject();
            for (auto ch : channelNumbers.keys()) {
                numbers[ch] = channelNumbers[ch].toInt();
            }

            QString title = obj["title"].toString();
            QString desc = obj["desc"].toString();
            QDateTime start = (QDateTime::fromMSecsSinceEpoch(obj["start"].toDouble())).addSecs(10800);
            QDateTime end = (QDateTime::fromMSecsSinceEpoch(obj["end"].toDouble())).addSecs(10800);

            this->m_list.append(new Item(channel, numbers, start, end, title, desc));
            emit listChanged();
        }
    }
#ifdef QT_DEBUG
    else {
        qDebug() << "Error: " << reply->errorString();
    }
#endif

    reply->deleteLater();
    emit endLoading();
}

QList<QObject*> TvShow::list()
{
    return this->m_list;
}

void TvShow::setList(QList<QObject*> list)
{
    this->m_list = list;
    emit listChanged();
}

int TvShow::count()
{
    return this->m_count;
}

void TvShow::setCount(int count)
{
    this->m_count = count;
    emit countChanged();
}

QObject* TvShow::currentItem()
{
    return this->m_currentItem;
}

void TvShow::setCurrentItem(QObject *item)
{
    this->m_currentItem = item;
    emit currentItemChanged();
}

void TvShow::clearList()
{
    this->m_list.clear();
    emit listChanged();
}
