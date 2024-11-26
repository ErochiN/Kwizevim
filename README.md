### **Documentation for VIMstring**

This documentation explains the usage and functionality of the `VIMstring` class and its associated functions in the `vim` namespace.

---

## **Namespace: vim**

The `vim` namespace encapsulates the `VIMstring` class and related functions for managing and displaying a dynamic 2D grid of strings.

---

## **Class: VIMstring**

The `VIMstring` class provides a dynamic 2D array of strings that can be resized and accessed by row and column indices.

### **Public Member Functions**

#### **Constructor: `VIMstring()`**
- **Description**: Initializes a 1x1 grid.
- **Usage**:
  ```cpp
  vim::VIMstring obj;
  ```

#### **Constructor: `VIMstring(int Y, int X)`**
- **Description**: Initializes a grid with dimensions `Y` (rows) and `X` (columns).
- **Parameters**:
  - `Y`: Number of rows.
  - `X`: Number of columns.
- **Usage**:
  ```cpp
  vim::VIMstring obj(3, 5);
  ```

#### **`void Reallocate(int Y, int X)`**
- **Description**: Resizes the grid to new dimensions, preserving existing data where possible.
- **Parameters**:
  - `Y`: New number of rows.
  - `X`: New number of columns.
- **Notes**:
  - If the new size is smaller, data outside the new bounds will be discarded.
  - Existing data within the new bounds will remain unchanged.
- **Usage**:
  ```cpp
  obj.Reallocate(5, 7);
  ```

#### **`void PrintArray()`**
- **Description**: Prints the entire grid to the console. Each row is printed on a new line, with elements separated by spaces.
- **Usage**:
  ```cpp
  obj.PrintArray();
  ```

#### **`std::string& GetElement(int y, int x)`**
- **Description**: Provides access to the string at the specified row and column.
- **Parameters**:
  - `y`: Row index (0-based).
  - `x`: Column index (0-based).
- **Returns**: A reference to the string at the specified location.
- **Throws**: `std::out_of_range` if the indices are out of bounds.
- **Usage**:
  ```cpp
  obj.GetElement(2, 3) = "Hello";
  std::cout << obj.GetElement(2, 3);
  ```

#### **Destructor: `~VIMstring()`**
- **Description**: Frees dynamically allocated memory for the grid.
- **Usage**: Automatically called when the object goes out of scope.

#### **`int GetYSize()`**
- **Description**: Returns the number of rows in the grid.
- **Returns**: An integer representing the number of rows.
- **Usage**:
  ```cpp
  int rows = obj.GetYSize();
  ```

#### **`int GetXSize()`**
- **Description**: Returns the number of columns in the grid.
- **Returns**: An integer representing the number of columns.
- **Usage**:
  ```cpp
  int cols = obj.GetXSize();
  ```

---

### **Global Variables**

#### **`vim::VIMstring strArray`**
- **Description**: A global instance of `VIMstring` for general usage in the `vim` namespace.
- **Default Dimensions**: 1x1 grid.
- **Example Usage**:
  ```cpp
  vim::strArray.GetElement(0, 0) = "Global";
  vim::strArray.PrintArray();
  ```

---

### **Functions**

#### **`void outYX(int Y, int X, std::string text)`**
- **Description**: Inserts text into the global `strArray` at the specified coordinates. Resizes the grid dynamically if necessary and clears the console before printing.
- **Parameters**:
  - `Y`: Row index (0-based).
  - `X`: Column index (0-based).
  - `text`: The string to be inserted.
- **Notes**:
  - The console is cleared using `system("cls")`. This is Windows-specific.
  - If the specified coordinates exceed the current grid dimensions, the grid is resized.
- **Usage**:
  ```cpp
  vim::outYX(2, 3, "Hello World");
  ```

---

## **Example Usage**

### **Basic Example**

```cpp
#include "Kwizevim.h"

int main() {
    vim::VIMstring grid(3, 3); // Create a 3x3 grid
    grid.GetElement(0, 0) = "A";
    grid.GetElement(1, 1) = "B";
    grid.GetElement(2, 2) = "C";

    grid.PrintArray(); // Print the grid

    grid.Reallocate(5, 5); // Resize to 5x5
    grid.GetElement(4, 4) = "D";

    grid.PrintArray(); // Print the resized grid
    return 0;
}
```

### **Using the Global Instance**

```cpp
#include "Kwizevim.h"

int main() {
    vim::outYX(1, 1, "Hello"); // Output "Hello" at position (1,1)
    vim::outYX(3, 4, "World"); // Output "World" at position (3,4), resizing the grid if necessary
    return 0;
}
```

---

## **Known Issues and Considerations**

1. **Console Clearing**:
   - The `system("cls")` function in `outYX` is Windows-specific. For cross-platform compatibility, use conditional compilation or an alternative method.

2. **Memory Management**:
   - The class uses raw pointers for memory management. Consider using `std::vector` or `std::unique_ptr` for safer and more efficient memory handling.

3. **Performance**:
   - Resizing the grid involves reallocation and copying of data, which can be inefficient for frequent resizing. Preallocating larger grids or using a dynamic container like `std::vector` could improve performance.

4. **Thread Safety**:
   - The code is not thread-safe. Adding synchronization mechanisms may be necessary for multithreaded environments.

---

This documentation provides a complete guide for understanding and using the `VIMstring` class and related functions.
