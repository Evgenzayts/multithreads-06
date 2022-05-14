//
// Created by ubuntu on 5/10/22.
//

#ifndef INCLUDE_LOGGING_HPP
#define INCLUDE_LOGGING_HPP

#include <boost/log/sinks.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/exceptions.hpp>
#include <boost/log/utility/setup.hpp>
#include "HashWork.hpp"
#include "JsonFile.hpp"

namespace logging = boost::log;
namespace keywords = boost::log::keywords;

void LogPrint(const std::vector<unsigned char>& data_vector, JsonFile& log_file);
void LogSet();

#endif  // INCLUDE_LOGGING_HPP
