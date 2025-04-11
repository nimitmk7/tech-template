#pragma once

#include <string>
#include <vector>

namespace tt::logger {

/**
 * @brief Records and retrieves log messages.
 */
class Logger {
 public:
  /**
   * @brief Logs an operation message.
   * @param operation A C-string describing the operation.
   */
  void log(const char* operation);

  /**
   * @brief Retrieves all logged messages.
   * @return A constant reference to the log messages.
   */
  const std::vector<std::string>& getLogs() const;

 private:
  std::vector<std::string> logs_;
};

}  // namespace tt::logger
