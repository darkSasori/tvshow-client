#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
//#include <QQuickStyle>
#include "tvshow.h"
#include "udpsocket.h"

int main(int argc, char *argv[])
{
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

#ifdef QT_DEBUG
    TvShow tvShow("http://localhost:8080/v1");
#else
    TvShow tvShow("http://tvshow-lineufelipe.rhcloud.com/v1");
#endif
    UdpSocket udpSocket(5555);

//    QQuickStyle::setStyle("Material");

    QQmlApplicationEngine engine;
    QQmlContext *context = engine.rootContext();
    context->setContextProperty("tvshow", &tvShow);
    context->setContextProperty("udpsocket", &udpSocket);

    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}
