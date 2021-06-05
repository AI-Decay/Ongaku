#pragma once
#include "utils/type_info_name/type_info_name.h"
#include <QtDebug>

namespace base::song_environment {

template <typename metadata_type> class song {
public:
  virtual bool is_valid() = 0;
  virtual bool read_metadata() = 0;

protected:
  metadata_type metadata_;
};

} // namespace base::song_environment
