#pragma once
#include <QAbstractListModel>
#include <QFileInfoList>
#include <QList>
#include <QStringList>
#include <QVariant>

namespace list_model {

class song_list_model : public QAbstractListModel {
  Q_OBJECT
public:
  enum class roles : int { color = Qt::UserRole + 1, text };
  song_list_model(QObject *parent = nullptr);
  bool load_songs_from_direcory(const std::string path);
  virtual int rowCount(const QModelIndex &parent) const override;
  virtual QVariant data(const QModelIndex &index, int role) const override;
  virtual QHash<int, QByteArray> roleNames() const override;

private:
  QStringList extension_list_{"*.mp3", "*.wav", "*.aac", "*.mp4"};
  QFileInfoList file_info_list_;
};

} // namespace list_model
