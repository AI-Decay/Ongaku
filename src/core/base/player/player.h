#pragma once

namespace player_base {

enum class player_states { playing, starting, stopping, stopped };

class player {
protected:
  virtual player_states start() = 0;
  virtual player_states stop() = 0;
  virtual ~player() = 0;
};

inline player::~player(){};

} // namespace player_base
