#pragma once
#include <string>
#include <typeinfo>

namespace utils::type_info {

template <typename T> class type_wrapper {};

template <typename T> class type_info_name {
  type_wrapper<T> type;

  static std::string get_typename() { return typeid(type).name(); }
};

} // namespace utils::type_info
