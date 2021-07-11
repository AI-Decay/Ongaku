#include "permission_manager.h"
using namespace core::platform::android;

permission_manager::permission_manager() {}

QtAndroid::PermissionResultMap permission_manager::request_permission(
    std::initializer_list<permission_manager::permission> permissions_list) {

  auto make_permissions_string = [](permission permission_) {
    return "android.permission." + QVariant::fromValue(permission_).toString();
  };

  QtAndroid::PermissionResultMap result;

  for (auto permission_ : permissions_list) {
    auto permission_string = make_permissions_string(permission_);

    if (QtAndroid::checkPermission(permission_string) ==
        QtAndroid::PermissionResult::Denied) {

      result.insert(
          QtAndroid::requestPermissionsSync(QStringList({permission_string})));
    }
  }
  return result;
}
