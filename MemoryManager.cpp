#include "MemoryManager.h"
#include <iostream>
#include <algorithm>

MemoryManager::MemoryManager(int totalMemory) : totalMemory(totalMemory), lastAllocatedIndex(0) {
    memoryBlocks.emplace_back(0, totalMemory, true);
}

void MemoryManager::allocateBlock(MemoryBlock& block, int size) {
    if (block.size > size) {
        MemoryBlock newBlock(block.start + size, block.size - size, true);
        block.size = size;
        block.isFree = false;

        auto it = std::find(memoryBlocks.begin(), memoryBlocks.end(), block);
        memoryBlocks.insert(it + 1, newBlock);
    } else {
        block.isFree = false;
    }
}


bool MemoryManager::firstFit(int size) {
    for (auto& block : memoryBlocks) {
        if (block.isFree && block.size >= size) {
            allocateBlock(block, size);
            return true;
        }
    }
    return false;
}

bool MemoryManager::bestFit(int size) {
    auto bestBlock = memoryBlocks.end();
    for (auto it = memoryBlocks.begin(); it != memoryBlocks.end(); ++it) {
        if (it->isFree && it->size >= size &&
            (bestBlock == memoryBlocks.end() || it->size < bestBlock->size)) {
            bestBlock = it;
        }
    }
    if (bestBlock != memoryBlocks.end()) {
        allocateBlock(*bestBlock, size);
        return true;
    }
    return false;
}

bool MemoryManager::worstFit(int size) {
    auto worstBlock = memoryBlocks.end();
    for (auto it = memoryBlocks.begin(); it != memoryBlocks.end(); ++it) {
        if (it->isFree && it->size >= size &&
            (worstBlock == memoryBlocks.end() || it->size > worstBlock->size)) {
            worstBlock = it;
        }
    }
    if (worstBlock != memoryBlocks.end()) {
        allocateBlock(*worstBlock, size);
        return true;
    }
    return false;
}

bool MemoryManager::nextFit(int size) {
    int n = memoryBlocks.size();
    for (int i = 0; i < n; ++i) {
        int index = (lastAllocatedIndex + i) % n;
        if (memoryBlocks[index].isFree && memoryBlocks[index].size >= size) {
            allocateBlock(memoryBlocks[index], size);
            lastAllocatedIndex = index;
            return true;
        }
    }
    return false;
}

bool MemoryManager::deallocate(int start) {
    for (auto& block : memoryBlocks) {
        if (block.start == start && !block.isFree) {
            block.isFree = true;
            mergeFreeBlocks();
            return true; // Deallocation successful
        }
    }
    return false; // Deallocation failed
}

void MemoryManager::mergeFreeBlocks() {
    for (auto it = memoryBlocks.begin(); it != memoryBlocks.end(); ++it) {
        auto next = std::next(it);
        if (next != memoryBlocks.end() && it->isFree && next->isFree) {
            it->size += next->size;
            memoryBlocks.erase(next);
            --it;
        }
    }
}

void MemoryManager::resetMemory() {
    memoryBlocks.clear();
    memoryBlocks.emplace_back(0, totalMemory, true); // Reset to a single free block
    lastAllocatedIndex = 0;
}

void MemoryManager::display() const {
    for (const auto& block : memoryBlocks) {
        std::cout << "Start: " << block.start << ", Size: " << block.size
                  << ", Free: " << (block.isFree ? "Yes" : "No") << std::endl;
    }
}