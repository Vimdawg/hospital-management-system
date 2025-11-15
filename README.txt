================================================================================
        HOSPITAL PATIENT CARE MANAGEMENT SYSTEM (HPCMS)
================================================================================

DESCRIPTION:
This is a Hospital Patient Care Management System implemented in C++ using
custom data structures including Queues, Stacks, Priority Queues, and 
Circular Queues. The system manages patient admissions, medical supplies,
emergency cases, and ambulance dispatching.

================================================================================
PROJECT STRUCTURE:
================================================================================

DatStructuresLab2/
├── src/
│   ├── main.cpp
│   ├── data_structures/
│   │   ├── CircularQueue.cpp
│   │   ├── CircularQueue.hpp
│   │   ├── PriorityQueue.cpp
│   │   ├── PriorityQueue.hpp
│   │   ├── Queue.cpp
│   │   ├── Queue.hpp
│   │   ├── Stack.cpp
│   │   └── Stack.hpp
│   ├── models/
│   │   ├── Ambulance.cpp
│   │   ├── Ambulance.hpp
│   │   ├── EmergencyCase.cpp
│   │   ├── EmergencyCase.hpp
│   │   ├── MedicalSupply.cpp
│   │   ├── MedicalSupply.hpp
│   │   ├── Patient.cpp
│   │   └── Patient.hpp
│   ├── modules/
│   │   ├── AmbulanceDispatcher.cpp
│   │   ├── AmbulanceDispatcher.hpp
│   │   ├── EmergencyDeptOfficer.cpp
│   │   ├── EmergencyDeptOfficer.hpp
│   │   ├── MedicalSupplyManager.cpp
│   │   ├── MedicalSupplyManager.hpp
│   │   ├── PatientAdmissionClerk.cpp
│   │   └── PatientAdmissionClerk.hpp
│   └── utils/
│       ├── InputValidator.cpp
│       ├── InputValidator.hpp
│       ├── MenuSystem.cpp
│       └── MenuSystem.hpp
├── README.txt (this file)
└── RequirementsPRD.txt

================================================================================
COMPILATION INSTRUCTIONS:
================================================================================

--------------------------------------------------------------------------------
FOR macOS / Linux:
--------------------------------------------------------------------------------

1. Open Terminal and navigate to the project directory:
   cd /path/to/DatStructuresLab2

2. Compile the program using g++:

   g++ -std=c++11 -Wall -Wextra -Isrc \
       src/main.cpp \
       src/data_structures/Queue.cpp \
       src/data_structures/Stack.cpp \
       src/data_structures/PriorityQueue.cpp \
       src/data_structures/CircularQueue.cpp \
       src/models/Patient.cpp \
       src/models/MedicalSupply.cpp \
       src/models/EmergencyCase.cpp \
       src/models/Ambulance.cpp \
       src/modules/PatientAdmissionClerk.cpp \
       src/modules/MedicalSupplyManager.cpp \
       src/modules/EmergencyDeptOfficer.cpp \
       src/modules/AmbulanceDispatcher.cpp \
       src/utils/MenuSystem.cpp \
       -o hpcms

   This will create an executable named "hpcms"

3. Run the program:
   ./hpcms

--------------------------------------------------------------------------------
FOR Windows (using MinGW):
--------------------------------------------------------------------------------

1. Ensure MinGW is installed and added to your system PATH
   - Download from: https://www.mingw-w64.org/
   - Or use: https://winlibs.com/

2. Open Command Prompt (cmd) or PowerShell and navigate to project directory:
   cd C:\path\to\DatStructuresLab2

3. Compile the program using g++:

   g++ -std=c++11 -Wall -Wextra -Isrc src/main.cpp src/data_structures/Queue.cpp src/data_structures/Stack.cpp src/data_structures/PriorityQueue.cpp src/data_structures/CircularQueue.cpp src/models/Patient.cpp src/models/MedicalSupply.cpp src/models/EmergencyCase.cpp src/models/Ambulance.cpp src/modules/PatientAdmissionClerk.cpp src/modules/MedicalSupplyManager.cpp src/modules/EmergencyDeptOfficer.cpp src/modules/AmbulanceDispatcher.cpp src/utils/MenuSystem.cpp -o hpcms.exe

   This will create an executable named "hpcms.exe"

4. Run the program:
   hpcms.exe

   Or simply:
   .\hpcms.exe

--------------------------------------------------------------------------------
ALTERNATIVE: One-liner compilation commands
--------------------------------------------------------------------------------

macOS/Linux (all on one line):
g++ -std=c++11 -Isrc src/main.cpp src/data_structures/*.cpp src/models/*.cpp src/modules/*.cpp src/utils/*.cpp -o hpcms

Windows MinGW (all on one line):
g++ -std=c++11 -Isrc src/main.cpp src/data_structures/*.cpp src/models/*.cpp src/modules/*.cpp src/utils/*.cpp -o hpcms.exe

Note: The wildcard (*) approach may not work in all shells. Use the explicit
file listing if you encounter issues.

================================================================================
COMPILER REQUIREMENTS:
================================================================================

- C++11 or later
- GCC/G++ 4.8.1 or later
- MinGW-w64 for Windows compilation

================================================================================
TROUBLESHOOTING:
================================================================================

1. "g++ not found" error:
   - Ensure g++ compiler is installed and added to system PATH
   - On macOS: Install Xcode Command Line Tools
   - On Windows: Install MinGW and add to PATH

2. Compilation errors:
   - Verify all source files are present in src/ directory
   - Check that you're in the project root directory when compiling
   - Ensure C++11 support is enabled with -std=c++11 flag

3. Include path issues:
   - The -Isrc flag tells the compiler to look in src/ for headers
   - Make sure this flag is included in your compile command

================================================================================
USAGE:
================================================================================

Once the program is running, you will see a main menu with four modules:

1. Patient Admission Clerk Module
   - Manage patient queue and admissions
   
2. Medical Supply Manager Module
   - Track and manage medical supplies
   
3. Emergency Department Officer Module
   - Handle emergency cases with priority queue
   
4. Ambulance Dispatcher Module
   - Manage ambulance dispatch and availability

Follow the on-screen prompts to navigate through the system.

================================================================================
PROJECT INFORMATION:
================================================================================

For detailed requirements and specifications, please refer to:
RequirementsPRD.txt

================================================================================

