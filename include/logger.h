#ifndef LOGGER_H
#define LOGGER_H

#include <vector>
#include <string>

class Logger {
private:
    std::vector<std::string> logs; // Store logs as std::string

public:
    void log(const std::string& operation); // Accept string instead of const char*
    const std::vector<std::string>& getLogs() const; // Return vector of strings
};

#endif // LOGGER_H
