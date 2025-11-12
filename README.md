# Hospital Patient Care Management System (HPCMS)

## Overview
The Hospital Patient Care Management System is a console-based C++ application that simulates peak-hour operations in a hospital. The system demonstrates the practical use of fundamental data structures (Queue, Stack, Priority Queue, Circular Queue) to manage patients, medical supplies, emergency cases, and ambulance dispatching.

## Features
- **Patient Admission Clerk**: Manage patient admissions using a Queue (FIFO)
- **Medical Supply Manager**: Track medical supplies using a Stack (LIFO)
- **Emergency Department Officer**: Handle emergency cases using a Priority Queue
- **Ambulance Dispatcher**: Manage ambulance shifts using a Circular Queue

## Project Structure
```
DatStructuresLab2/
├── src/
│   ├── main.cpp                    # Main entry point
│   ├── data_structures/            # Core data structure implementations
│   ├── models/                     # Data models (Patient, Supply, etc.)
│   ├── modules/                    # Role-specific modules
│   └── utils/                      # Utility functions
├── bin/                            # Compiled executable
├── obj/                            # Object files
├── tests/                          # Test files
├── docs/                           # Documentation
├── data/                           # Sample data files
├── Makefile                        # Build automation
└── README.md                       # This file
```

## Requirements
- C++ compiler (g++ or equivalent)
- C++11 or higher
- Standard C++ libraries only (no STL containers for data structures)

## Building the Project

### Using Make (Recommended)
```bash
# Build the project
make

# Run the program
make run

# Clean build files
make clean
```

### Manual Compilation
```bash
# Create necessary directories
mkdir -p bin obj

# Compile manually (example)
g++ -std=c++11 -Wall -Wextra -Isrc -o bin/hpcms src/main.cpp \
    src/data_structures/*.cpp \
    src/models/*.cpp \
    src/modules/*.cpp \
    src/utils/*.cpp
```

## Usage
1. Run the executable: `./bin/hpcms`
2. Select a role from the main menu (1-4)
3. Perform operations within the selected role
4. Return to main menu or exit

## Data Structures Implemented
- **Queue**: Array-based or linked-list implementation for patient admission
- **Stack**: Array-based or linked-list implementation for medical supplies
- **Priority Queue**: Heap-based or sorted array for emergency cases
- **Circular Queue**: Array-based with modulo arithmetic for ambulance dispatch

## Team Members
- Role A: Patient Admission Clerk (Queue)
- Role B: Medical Supply Manager (Stack)
- Role C: Emergency Department Officer (Priority Queue)
- Role D: Ambulance Dispatcher (Circular Queue)

## Implementation Notes
- All core data structures are implemented from scratch (no STL containers)
- Input validation and error handling included
- Modular design with separate header and source files
- Clear, readable code with comments

## Testing
Manual testing scenarios are provided in the `tests/` directory. Each module should be tested for:
- Normal operations
- Boundary conditions (empty/full structures)
- Edge cases and error handling

## License
Academic project for Data Structures & Algorithms course

## Version
1.0 - November 12, 2025

