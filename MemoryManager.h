#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H

#include "MemoryBlock.h"
#include <vector>

class MemoryManager {
private:
    std::vector<MemoryBlock> memoryBlocks;
    int totalMemory;
    int lastAllocatedIndex; // For Next Fit strategy

    void allocateBlock(MemoryBlock& block, int size);
    void mergeFreeBlocks();

public:
    MemoryManager(int totalMemory);
    bool firstFit(int size);
    bool bestFit(int size);
    bool worstFit(int size);
    bool nextFit(int size);
    bool deallocate(int start); // Changed return type from void to bool
    void resetMemory();
    void display() const;
};

#endif // MEMORYMANAGER_H
