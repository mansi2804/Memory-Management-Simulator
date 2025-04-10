#ifndef PROCESS_H
#define PROCESS_H

#include <string>

class Process {
public:
    std::string name;
    int requiredMemory;

    Process(const std::string& name, int memory);
};

#endif // PROCESS_H
