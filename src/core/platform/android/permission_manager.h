#pragma once
#include <QObject>
#include <QtAndroidExtras>
#include <string>

namespace core::platform::android {

class permission_manager {
  Q_GADGET
public:
  enum class permission { READ_EXTERNAL_STORAGE };
  Q_ENUM(permission)

  permission_manager();

  QtAndroid::PermissionResultMap
  request_permission(std::initializer_list<permission> permissions_list);

private:
};
} // namespace core::platform::android
