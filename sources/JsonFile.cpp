//
// Created by ubuntu on 5/10/22.
//
#include "JsonFile.hpp"

JsonFile& JsonFile::operator=(const JsonData& one_data) {
  this->add_record(one_data);

  return *this;
}

void JsonFile::add_record(const JsonData& data) {
  std::lock_guard<std::mutex> lk(_mute);

  nlohmann::json json_record;
  json_record["timestamp"] = int(data.timestamp);
  json_record["hash"] = data.hash;
  json_record["data"] = data.data;

  _data.push_back(json_record);
}
void JsonFile::save_data() {
  std::ofstream file(_path);
  if (!file) {
    throw std::runtime_error("Json file does not exist");
  }
  file << _data.dump(4);
  file.close();
}
void JsonFile::set_path(char* path) {
  _path = path;
}
