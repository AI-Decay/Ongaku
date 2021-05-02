#pragma once
#include "core/base/player/player.h"
#include <QMediaPlayer>
#include <atomic>
#include <thread>

class audio_player : protected player_base::player {
public:
  audio_player();

private:
  std::thread play_thread_;
};
