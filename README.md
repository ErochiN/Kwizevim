# **Documentation for Kwizevim Library**

The "Kwizevim" library provides tools for managing and displaying dynamic 2D grids of strings. It is designed for use cases that require text to be placed at specific coordinates in a console application.

---

## **Namespace: vim**

The `vim` namespace includes the main functionality of the library, such as the `VIMstring` class and the `outYX` function for managing and interacting with a 2D string array.

---

## **Class: VIMstring**

The `VIMstring` class is the core of the library, providing a resizable 2D grid of strings.

### **Public Methods**

#### **Constructor: `VIMstring()`**
- **Description**: Creates a default 1x1 string grid.
- **Example Usage**:
  ```cpp
  vim::VIMstring grid;
  ```

#### **Constructor: `VIMstring(int Y, int X)`**
- **Description**: Creates a string grid with specified dimensions.
- **Parameters**:
  - `Y`: Number of rows.
  - `X`: Number of columns.
- **Example Usage**:
  ```cpp
  vim::VIMstring grid(3, 5); // Creates a 3x5 grid
  ```

#### **`void Reallocate(int Y, int X)`**
- **Description**: Resizes the grid to the specified dimensions while preserving existing data where possible.
- **Parameters**:
  - `Y`: New number of rows.
  - `X`: New number of columns.
- **Behavior**:
  - Data within the bounds of the new grid is retained.
  - Data outside the new bounds is discarded.
- **Example Usage**:
  ```cpp
  grid.Reallocate(5, 7); // Resize to a 5x7 grid
  ```

#### **`void PrintArray()`**
- **Description**: Prints the grid to the console. Each row is displayed on a new line, and elements are separated by spaces.
- **Example Usage**:
  ```cpp
  grid.PrintArray();
  ```

#### **`std::string& GetElement(int y, int x)`**
- **Description**: Provides access to a specific element in the grid.
- **Parameters**:
  - `y`: Row index (0-based).
  - `x`: Column index (0-based).
- **Returns**: A reference to the string at the specified coordinates.
- **Exceptions**:
  - Throws `std::out_of_range` if the indices are out of bounds.
- **Example Usage**:
  ```cpp
  grid.GetElement(1, 2) = "Hello";
  std::cout << grid.GetElement(1, 2);
  ```

#### **`int GetYSize()`**
- **Description**: Returns the number of rows in the grid.
- **Example Usage**:
  ```cpp
  int rows = grid.GetYSize();
  ```

#### **`int GetXSize()`**
- **Description**: Returns the number of columns in the grid.
- **Example Usage**:
  ```cpp
  int cols = grid.GetXSize();
  ```

#### **Destructor: `~VIMstring()`**
- **Description**: Cleans up dynamically allocated memory when the object is destroyed.
- **Behavior**:
  - Automatically called when the object goes out of scope.

---

## **Global Variables**

#### **`vim::VIMstring strArray`**
- **Description**: A global instance of the `VIMstring` class for general use.
- **Default Size**: 1x1 grid.
- **Example Usage**:
  ```cpp
  vim::strArray.GetElement(0, 0) = "Global Example";
  vim::strArray.PrintArray();
  ```

---

## **Functions**

#### **`void outYX(int Y, int X, std::string text)`**
- **Description**: Places a string at the specified coordinates in the global grid (`strArray`). Automatically resizes the grid if the coordinates exceed its current dimensions.
- **Parameters**:
  - `Y`: Row index (0-based).
  - `X`: Column index (0-based).
  - `text`: The string to be placed at the specified coordinates.
- **Behavior**:
  - Clears the console using `system("cls")`.
  - Resizes the grid if needed to accommodate the specified coordinates.
  - Prints the updated grid to the console.
- **Example Usage**:
  ```cpp
  vim::outYX(2, 3, "Hello World");
  ```

---

## **Examples**

### **Basic Usage**

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
    vim::outYX(1, 1, "Hello"); // Place "Hello" at (1,1)
    vim::outYX(3, 4, "World"); // Place "World" at (3,4), resizing the grid if necessary
    return 0;
}
```

---

## **Known Issues and Recommendations**

1. **Console Clearing**:
   - The function `system("cls")` used in `outYX` is specific to Windows. For cross-platform compatibility, use conditional compilation or other platform-specific methods.

2. **Memory Management**:
   - The class uses raw pointers for memory allocation. It is recommended to replace them with modern C++ features like `std::vector` or `std::unique_ptr` for safer and more efficient memory management.

3. **Performance**:
   - Resizing the grid (via `Reallocate`) involves memory reallocation and data copying, which may be inefficient for frequent resizing. Consider preallocating larger grids or using dynamic containers like `std::vector` for better performance.

4. **Thread Safety**:
   - The code is not thread-safe. If used in a multithreaded environment, consider adding synchronization mechanisms.

---

## **Conclusion**

The "Kwizevim" library provides a simple and flexible way to manage and display 2D grids of strings in a console application. With features like dynamic resizing and element access, it is well-suited for applications that require coordinate-based text placement.
