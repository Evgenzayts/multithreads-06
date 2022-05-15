// Copyright 2022 Evgenzayts evgenzaytsev2002@yandex.ru

#include "Logging.hpp"

void LogPrint(const std::vector<unsigned char>& data_vector,
              JsonFile& log_file) {
  std::string str = GetDataStr(data_vector);
  std::string hash = GetDataHash(data_vector);

  if (CmpHash(hash)) {
    BOOST_LOG_TRIVIAL(info) << "[" << str << "] " << hash;
    std::time_t timestamp(std::time(nullptr));
    log_file.add_record(JsonData(timestamp, hash, str));
  }
  BOOST_LOG_TRIVIAL(trace) << "[" << str << "] " << hash;
}

void LogSet() {
  // уровень логирования trace
  auto log_trace = logging::add_file_log(
      keywords::file_name = "../logs/trace_log_file_%N.log",
      keywords::rotation_size = 10 * 1024 * 1024,
      keywords::format =
          "[%TimeStamp%][%Severity%][%ThreadID%]: %Message%");
  log_trace->set_filter(logging::trivial::severity >= logging::trivial::trace);
  // уровень логирования info
  auto log_info = logging::add_file_log(
      keywords::file_name = "../logs/info_log_file_%N.log",
      keywords::rotation_size = 10 * 1024 * 1024,
      keywords::format =
          "[%TimeStamp%][%Severity%][%ThreadID%]: %Message%");
  log_info->set_filter(logging::trivial::severity >= logging::trivial::info);
  // вывод в консоль
  auto log_console = logging::add_console_log(
      std::clog,
      keywords::format =
          "[%TimeStamp%][%Severity%][%ThreadID%]: %Message%");
  log_console->set_filter(logging::trivial::severity >= logging::trivial::info);

  logging::add_common_attributes();
}
