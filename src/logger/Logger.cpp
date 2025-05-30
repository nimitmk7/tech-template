#include <tt/logger/Logger.h>

namespace tt::logger {

void Logger::log(const char* operation) { logs_.push_back(operation); }

const std::vector<std::string>& Logger::getLogs() const { return logs_; }

}  // namespace tt::logger
