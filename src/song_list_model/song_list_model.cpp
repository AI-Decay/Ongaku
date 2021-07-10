#include "song_list_model.h"
#include <QDir>
using namespace list_model;

song_list_model::song_list_model(QObject *parent)
    : QAbstractListModel(parent) {}

bool song_list_model::load_songs_from_direcory(const std::string path) {
  QDir directory{QString::fromStdString(path)};
  bool is_directory_valid = directory.exists() && directory.isReadable();
  if (is_directory_valid) {
    beginResetModel();
    file_info_list_ =
        directory.entryInfoList(extension_list_, QDir::Files, QDir::Name);
    endResetModel();
  }
  return is_directory_valid;
}

int song_list_model::rowCount(const QModelIndex &parent) const {
  int count = 0;

  if (parent.isValid())
    count = 0;
  else
    count = file_info_list_.size();

  return count;
}

QVariant song_list_model::data(const QModelIndex &index, int role) const {
  if (!index.isValid()) {
    return QVariant();
  }

  switch (static_cast<roles>(role)) {
  case roles::color:
    return QVariant("#D7D7D7");
  case roles::text:
    return file_info_list_.at(index.row()).fileName();
  default:
    return QVariant();
  }
}

QHash<int, QByteArray> song_list_model::roleNames() const {
  QHash<int, QByteArray> roles = QAbstractListModel::roleNames();

  roles[static_cast<int>(roles::color)] = "color";
  roles[static_cast<int>(roles::text)] = "text";

  return roles;
}
