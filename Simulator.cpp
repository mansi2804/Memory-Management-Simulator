#include "MemoryManager.h"
#include <iostream>
#include <string>

int main() {
    int choice;
    MemoryManager* memoryManager = nullptr;

    while (true) {
        std::cout << "1) Start Simulation\n2) View Instructions\n3) Exit\n";
        std::cin >> choice;

        if (choice == 1) {
            int totalMemory;
            std::cout << "Enter total memory size: ";
            std::cin >> totalMemory;
            memoryManager = new MemoryManager(totalMemory);

            while (true) {
                std::cout << "\nSimulation Menu:\n";
                std::cout << "1) Allocate Memory\n";
                std::cout << "2) Deallocate Memory\n";
                std::cout << "3) View Memory Status\n";
                std::cout << "4) Reset Memory\n";
                std::cout << "5) Exit Simulation\n";
                int simChoice;
                std::cin >> simChoice;

                if (simChoice == 1) {
                    std::string processName;
                    int processSize;
                    std::cout << "Enter process name: ";
                    std::cin >> processName;
                    std::cout << "Enter process size: ";
                    std::cin >> processSize;

                    std::cout << "Choose allocation strategy:\n";
                    std::cout << "1) First Fit\n2) Best Fit\n3) Worst Fit\n4) Next Fit\n";
                    int strategy;
                    std::cin >> strategy;

                    bool success = false;
                    if (strategy == 1) success = memoryManager->firstFit(processSize);
                    else if (strategy == 2) success = memoryManager->bestFit(processSize);
                    else if (strategy == 3) success = memoryManager->worstFit(processSize);
                    else if (strategy == 4) success = memoryManager->nextFit(processSize);

                    if (success) {
                        std::cout << "Process " << processName << " allocated successfully.\n";
                    } else {
                        std::cout << "Memory allocation failed for process " << processName << ".\n";
                    }
                } else if (simChoice == 2) {
                    int startAddress;
                    std::cout << "Enter the start address of the block to deallocate: ";
                    std::cin >> startAddress;
                    bool success = memoryManager->deallocate(startAddress);
                    if (success) {
                        std::cout << "Memory deallocated successfully.\n";
                    } else {
                        std::cout << "Error: Invalid start address or block already free.\n";
                    }
                } else if (simChoice == 3) {
                    memoryManager->display();
                } else if (simChoice == 4) {
                    memoryManager->resetMemory();
                    std::cout << "Memory reset successfully.\n";
                } else if (simChoice == 5) {
                    break;
                } else {
                    std::cout << "Invalid choice. Try again.\n";
                }
            }

            delete memoryManager;
            memoryManager = nullptr;

        } else if (choice == 2) {
            std::cout << "Instructions:\n";
            std::cout << "1. Enter total memory size.\n";
            std::cout << "2. Choose allocation strategy.\n";
            std::cout << "3. Allocate or deallocate processes.\n";
            std::cout << "4. View memory status.\n";
        } else if (choice == 3) {
            break;
        } else {
            std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}