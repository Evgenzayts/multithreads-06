// Copyright 2022 Evgenzayts evgenzaytsev2002@yandex.ru

#ifndef INCLUDE_LOGGING_HPP_
#define INCLUDE_LOGGING_HPP_

#include <boost/log/sinks.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/exceptions.hpp>
#include <boost/log/utility/setup.hpp>
#include <vector>
#include <chrono>
#include <ctime>
#include "HashWork.hpp"
#include "JsonFile.hpp"

namespace logging = boost::log;
namespace keywords = boost::log::keywords;

void LogPrint(const std::vector<unsigned char>& data_vector,
              JsonFile& log_file);
void LogSet();

#endif  // INCLUDE_LOGGING_HPP_
