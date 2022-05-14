// Copyright 2022 Evgenzayts evgenzaytsev2002@yandex.ru

#ifndef INCLUDE_JSONFILE_HPP_
#define INCLUDE_JSONFILE_HPP_

#include <nlohmann/json.hpp>
#include <iostream>
#include <ctime>
#include <mutex>
#include <fstream>
#include <string>

struct JsonData{
  std::time_t timestamp;
  std::string hash;
  std::string data;
  JsonData(std::time_t& _timestamp, std::string& _hash, std::string& _data)
      : timestamp(_timestamp), hash(_hash), data(_data) {}
};

class JsonFile {
 private:
  nlohmann::json _data;
  mutable std::mutex _mute;
  std::string _path;

 public:
  JsonFile() = default;
  JsonFile(const JsonFile& file) = delete;
  JsonFile(JsonFile&& file) = delete;

  JsonFile& operator =(const JsonFile& file) = delete;
  JsonFile& operator =(JsonFile&& file) = delete;
  JsonFile& operator =(const JsonData& data);

  void add_record(const JsonData& data);
  void save_data();
  void set_path(char* path);

  ~JsonFile() = default;
};

#endif  // INCLUDE_JSONFILE_HPP_
