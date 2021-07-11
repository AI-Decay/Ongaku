#pragma once

#include <memory>

namespace core {

class launcher {
public:
  launcher(int argc, char *argv[]);
  static std::unique_ptr<launcher> сreate(int argc, char *argv[]) {
    return std::make_unique<launcher>(argc,
                                      argv); // TODO platform-dependent classes
  }
  virtual int exec();

private:
  int argc_;
  char **argv_;
};

} // namespace core
