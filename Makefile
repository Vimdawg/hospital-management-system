# Compiler
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Isrc

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Target executable
TARGET = $(BIN_DIR)/hpcms

# Source files
SOURCES = $(SRC_DIR)/main.cpp \
          $(SRC_DIR)/data_structures/Queue.cpp \
          $(SRC_DIR)/data_structures/Stack.cpp \
          $(SRC_DIR)/data_structures/PriorityQueue.cpp \
          $(SRC_DIR)/data_structures/CircularQueue.cpp \
          $(SRC_DIR)/models/Patient.cpp \
          $(SRC_DIR)/models/MedicalSupply.cpp \
          $(SRC_DIR)/models/EmergencyCase.cpp \
          $(SRC_DIR)/models/Ambulance.cpp \
          $(SRC_DIR)/modules/PatientAdmissionClerk.cpp \
          $(SRC_DIR)/modules/MedicalSupplyManager.cpp \
          $(SRC_DIR)/modules/EmergencyDeptOfficer.cpp \
          $(SRC_DIR)/modules/AmbulanceDispatcher.cpp \
          $(SRC_DIR)/utils/InputValidator.cpp \
          $(SRC_DIR)/utils/MenuSystem.cpp

# Object files
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJECTS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)
	@echo "Build complete: $(TARGET)"

# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create directories if they don't exist
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean build files
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
	@echo "Clean complete"

# Run the program
run: $(TARGET)
	./$(TARGET)

# Phony targets
.PHONY: all clean run

