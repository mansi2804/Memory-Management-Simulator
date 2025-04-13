# Memory Management Simulator

## Overview
The Memory Management Simulator is a console-based program written in C++ that helps users understand how memory allocation and deallocation work in operating systems. It simulates different memory management techniques and provides a clear visualization of memory blocks, fragmentation, and allocation strategies.

## Features
- Simulates four memory allocation strategies:
  1. **First Fit**
  2. **Best Fit**
  3. **Worst Fit**
  4. **Next Fit**
- Allows users to:
  - Allocate memory for processes.
  - Deallocate memory by specifying the start address.
  - View the current memory status.
  - Reset the entire memory.
- Handles internal and external fragmentation.
- Displays memory blocks in a clear and structured format.

## How to Run
1. **Compile the Program**:
   Use the following command to compile the program:
   ```bash
   g++ -std=c++11 -o simulator Simulator.cpp MemoryManager.cpp
   ```

2. **Run the Program**:
   Execute the compiled binary:
   ```bash
   ./simulator
   ```

3. **Follow the On-Screen Instructions**:
   - Choose options from the menu to start the simulation, view instructions, or exit.
   - Enter memory size, allocation strategies, and process details as prompted.

## Menu Options
1. **Start Simulation**:
   - Enter the total memory size.
   - Choose from the following allocation strategies:
     - First Fit
     - Best Fit
     - Worst Fit
     - Next Fit
   - Allocate or deallocate memory for processes.
   - View the current memory status or reset memory.

2. **View Instructions**:
   - Displays a brief guide on how to use the simulator.

3. **Exit**:
   - Exits the program.

## Sample Input/Output
### Example Run
```plaintext
1) Start Simulation
2) View Instructions
3) Exit
1
Enter total memory size: 10

Simulation Menu:
1) Allocate Memory
2) Deallocate Memory
3) View Memory Status
4) Reset Memory
5) Exit Simulation
1
Enter process name: A
Enter process size: 3
Choose allocation strategy:
1) First Fit
2) Best Fit
3) Worst Fit
4) Next Fit
1
Process A allocated successfully.

Simulation Menu:
1) Allocate Memory
2) Deallocate Memory
3) View Memory Status
4) Reset Memory
5) Exit Simulation
3
Start: 0, Size: 3, Free: No
Start: 3, Size: 7, Free: Yes
```

## File Structure
- `Simulator.cpp`: Contains the main program logic and menu-driven interface.
- `MemoryManager.h` and `MemoryManager.cpp`: Implements memory allocation, deallocation, and visualization logic.
- `MemoryBlock.h`: Defines the `MemoryBlock` class to represent memory blocks.

## Allocation Strategies
1. **First Fit**: Allocates the first available block that is large enough.
2. **Best Fit**: Allocates the smallest available block that is large enough.
3. **Worst Fit**: Allocates the largest available block.
4. **Next Fit**: Allocates the next available block starting from the last allocated position.

## Notes
- Ensure you have a C++11-compatible compiler.
- Input validation is included to handle invalid choices or memory sizes.

## License
This project is for educational purposes and is open for modification and use.
