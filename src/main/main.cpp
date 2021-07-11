#include "core/launcher/launcher.h"

int main(int argc, char *argv[]) {
  const auto launcher = core::launcher::сreate(argc, argv);
  return launcher ? launcher->exec() : 1;
}
