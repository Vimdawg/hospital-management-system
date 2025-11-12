# Design Decisions

## Data Structure Choices

### 1. Patient Admission Queue
- **Structure**: Queue (FIFO)
- **Rationale**: Patients should be served in the order they arrive
- **Implementation**: Array-based or Linked List
- **Time Complexity**: O(1) for enqueue and dequeue

### 2. Medical Supply Stack
- **Structure**: Stack (LIFO)
- **Rationale**: Last-in supplies are used first (simulating inventory management)
- **Implementation**: Array-based or Linked List
- **Time Complexity**: O(1) for push and pop

### 3. Emergency Priority Queue
- **Structure**: Priority Queue
- **Rationale**: Critical cases must be handled before less urgent ones
- **Implementation**: Binary Heap or Sorted Array
- **Time Complexity**: 
  - Heap: O(log n) for insert and extract
  - Sorted Array: O(n) for insert, O(1) for extract

### 4. Ambulance Circular Queue
- **Structure**: Circular Queue
- **Rationale**: Ambulances rotate in shifts (round-robin scheduling)
- **Implementation**: Array-based with modulo arithmetic
- **Time Complexity**: O(1) for all operations

## Architecture Decisions

### Modular Design
- Separate files for each data structure and module
- Clear separation between data models and business logic
- Utility classes for common functionality

### Error Handling
- Graceful handling of empty/full structures
- Input validation at every user interaction point
- Clear error messages for users

### Scalability Considerations
- Fixed-size arrays for simplicity (with clear capacity limits)
- Could be extended to dynamic structures if needed

