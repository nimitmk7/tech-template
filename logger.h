#ifndef LOGGER_H
#define LOGGER_H

#include <vector>
#include <string>

class Logger {
    private:
        std::vector<const char*> logs;
    public:
        void log(const char* operation);
        const std::vector<const char*>& getLogs() const;
    };


#endif