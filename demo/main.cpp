#include "JsonFile.hpp"
#include "Logging.hpp"
#include <thread>

std::atomic<bool> stop_process;

void StopProgram(int sig) {
  if (sig == SIGINT)
    stop_process = true;
}

void Process(JsonFile& log_file) {
  while (!stop_process) {
    std::vector<unsigned char> data_vector = GetRandDataVector();
    LogPrint(data_vector, log_file);
  }
}

int main(int argc, char* argv[]) {
  unsigned int M = std::thread::hardware_concurrency(); // количество потоков
  auto log_file = new JsonFile;
  signal(SIGINT, StopProgram);

  if (argc == 1) {
    throw std::runtime_error("Invalid number of arguments");
  } else if (argc == 2) {
    log_file->set_path(argv[1]);
  } else if (argc == 3) {
    log_file->set_path(argv[1]);
    M = std::atoi(argv[2]);
  } else {
    throw std::runtime_error("Too many arguments");
  }

  LogSet();   // настройка логирования

  std::srand(time(nullptr));
  auto threads = new std::vector<std::thread>;
  threads->reserve(M);

  for (uint i = 0; i < M; ++i)
    threads->emplace_back(Process, std::ref(*log_file));
  for (auto& thread : *threads)
    thread.join();

  log_file->save_data();
}
