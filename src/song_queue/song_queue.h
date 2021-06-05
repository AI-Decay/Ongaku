#pragma once
#include <mutex>
#include <queue>
template <class song_type> class song_queue {
public:
  song_queue(){};
  void push_back(song_type &&value) {
    std::lock_guard<std::mutex> lock(mtx);
    queue_.push(value);
  }

  template <typename... Args> void emplace_back(Args &&...args) {
    std::lock_guard<std::mutex> lock(mtx);
    queue_.emplace(std::forward<Args>(args)...);
  }

  void pop_front() {
    std::lock_guard<std::mutex> lock(mtx);
    queue_.pop();
  }

  song_type &&pull_front() {
    std::lock_guard<std::mutex> lock(mtx);
    return queue_.front();
  }

private:
  std::queue<song_type> queue_;
  std::mutex mtx;
};
