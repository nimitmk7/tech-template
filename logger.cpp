#include "logger.h"

void Logger::log(const std::string& operation) { 
    logs.push_back(operation); 
}

const std::vector<std::string>& Logger::getLogs() const { 
    return logs; 
}
