#include "song_list_model/song_list_model.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[]) {
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

  QGuiApplication app(argc, argv);

  list_model::song_list_model song_model;
  song_model.load_songs_from_direcory("E:/Google Download");
  QQmlApplicationEngine engine;
  qmlRegisterSingletonInstance("Models.SongList", 1, 0, "SongListModel",
                               &song_model);

  const QUrl url(QStringLiteral("qrc:/ui/ongaku.qml"));
  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreated, &app,
      [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
          QCoreApplication::exit(-1);
      },
      Qt::QueuedConnection);
  engine.load(url);

  return app.exec();
}
