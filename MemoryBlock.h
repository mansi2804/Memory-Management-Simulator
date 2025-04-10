#ifndef MEMORYBLOCK_H
#define MEMORYBLOCK_H

#include <string>

class MemoryBlock {
public:
    int start;      // Start address of the block
    int size;       // Size of the block
    bool isFree;    // Whether the block is free or allocated

    // Parameterized constructor
    MemoryBlock(int start, int size, bool isFree)
        : start(start), size(size), isFree(isFree) {}

    // == operator for comparison
    bool operator==(const MemoryBlock& other) const {
        return start == other.start && size == other.size && isFree == other.isFree;
    }
    
    std::string getStatus() const;
};

#endif // MEMORYBLOCK_H
