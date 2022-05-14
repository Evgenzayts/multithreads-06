// Copyright 2022 Evgenzayts evgenzaytsev2002@yandex.ru

#ifndef INCLUDE_HASHWORK_HPP_
#define INCLUDE_HASHWORK_HPP_

#define HASH_CHECK "0000"
#define HASH_CHECK_LEN 4


#include "Logging.hpp"
#include "JsonFile.hpp"
#include "../third-party/PicoSHA2/picosha2.h"
#include <atomic>
#include <csignal>
#include <vector>
#include <string>

std::vector<unsigned char>& GetRandDataVector();

std::string GetDataStr(const std::vector<unsigned char>& data_vector);

std::string GetDataHash(const std::vector<unsigned char>& data_vector);

bool CmpHash(const std::string& str);

void StopProgram(int sig);

#endif  // INCLUDE_HASHWORK_HPP_
