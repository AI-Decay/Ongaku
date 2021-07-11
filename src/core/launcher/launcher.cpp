#ifdef __ANDROID__
#include "core/platform/android/permission_manager.h"
#endif
#include "launcher.h"
#include "song_list_model/song_list_model.h"
#include <QDebug>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QStandardPaths>
#include <QtAndroidExtras>

using namespace core;

core::launcher::launcher(int argc, char *argv[]) : argc_(argc), argv_(argv) {}

int core::launcher::exec() {

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

  platform::android::permission_manager p_manager;
  using permission = platform::android::permission_manager::permission;
  p_manager.request_permission({permission::READ_EXTERNAL_STORAGE});

  QGuiApplication app(argc_, argv_);

  list_model::song_list_model song_model;
  const auto load_path =
      QStandardPaths::writableLocation(QStandardPaths::MusicLocation)
          .toStdString();
  song_model.load_songs_from_direcory(load_path);
  QQmlApplicationEngine engine;
  qmlRegisterSingletonInstance("Models.SongList", 1, 0, "SongListModel",
                               &song_model);

  qDebug() << load_path.c_str();
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
