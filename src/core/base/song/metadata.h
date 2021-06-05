#pragma once
#include <list>
#include <string>

namespace base::song_environment {

template <typename data_type = std::string> class metadata {
  data_type title;
  data_type sub_title;
  data_type comment;
  data_type description;
  data_type year;
  data_type date;
  data_type user_rating;
  data_type publisher;
  data_type copyright;
  data_type parental_rating;
  data_type rating_organization;
  std::list<data_type> keywords;
  std::list<data_type> category;
  std::list<data_type> genre;
  std::list<data_type> author;

  std::uint64_t size_bytes;
  std::uint64_t duration_ms;
};

} // namespace base::song_environment
