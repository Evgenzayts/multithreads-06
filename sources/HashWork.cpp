//
// Created by ubuntu on 5/10/22.
//
#include "HashWork.hpp"

std::vector<unsigned char>& GetRandDataVector() {
  auto data_vector = new std::vector<unsigned char>;
  for (int i = 0; i < 16; ++i) {            // 16 символов в пароле - 8 байт
    unsigned int symbol = std::rand() % 17;
    if (symbol <= 9) {
      data_vector->push_back('0' + symbol);
    } else {
      data_vector->push_back('0' + 7 + symbol);
    }
  }

  return *data_vector;
}

std::string GetDataStr(const std::vector<unsigned char>& data_vector) {
  std::string data;
  for (auto sym : data_vector)
    data.push_back(sym);

  return data;
}

std::string GetDataHash(const std::vector<unsigned char>& data_vector) {
  return picosha2::hash256_hex_string(data_vector);
}

bool CmpHash(const std::string& str) {
  std::string hash_check = HASH_CHECK;
  std::string tail = str.substr(str.length() - HASH_CHECK_LEN, str.length());

  if (tail == hash_check) return true;

  return false;
}
