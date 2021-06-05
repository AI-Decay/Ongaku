#pragma once
#include "core/base/player/player.h"
#include <QMediaPlayer>
#include <atomic>
#include <thread>

class audio_player : protected base::player_environment::player {
public:
  audio_player();

  base::player_environment::player_states start() { return state; }

private:
  std::thread play_thread_;
  base::player_environment::player_states state;
};
