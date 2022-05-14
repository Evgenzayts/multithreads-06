//
// Created by ubuntu on 5/10/22.
//

#define HASH_CHECK "0000"
#define HASH_CHECK_LEN 4

#ifndef INCLUDE_HASHWORK_HPP
#define INCLUDE_HASHWORK_HPP

#include "Logging.hpp"
#include "JsonFile.hpp"
#include "../third-party/PicoSHA2/picosha2.h"
#include <atomic>
#include <csignal>

std::vector<unsigned char>& GetRandDataVector();

std::string GetDataStr(const std::vector<unsigned char>& data_vector);

std::string GetDataHash(const std::vector<unsigned char>& data_vector);

bool CmpHash(const std::string& str);

void StopProgram(int sig);

#endif  // INCLUDE_HASHWORK_HPP
