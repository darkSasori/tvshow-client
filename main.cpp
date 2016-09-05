#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "tvshow.h"
#include "udpsocket.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    TvShow tvShow("http://tvshow-lineufelipe.rhcloud.com/v1");
    UdpSocket udpSocket(5555);

    QQmlApplicationEngine engine;
    QQmlContext *context = engine.rootContext();
    context->setContextProperty("tvshow", &tvShow);
    context->setContextProperty("udpsocket", &udpSocket);

    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}
