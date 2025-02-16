#include "logger.h"

void Logger::log(const char* operation) { logs.push_back(operation); }

const std::vector<const char*>& Logger::getLogs() const { return logs; }