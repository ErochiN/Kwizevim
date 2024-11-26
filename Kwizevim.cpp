#include "Kwizevim.h"

namespace vim
{
    // Default constructor: Initializes a 1x1 grid
    VIMstring::VIMstring()
    {
        this->indexY = 1;
        this->indexX = 1;
        this->array = new std::string[indexY * indexX]; // Allocate memory for a single string
    }

    // Parameterized constructor: Initializes a grid of size Y x X
    VIMstring::VIMstring(int Y, int X)
    {
        this->indexY = Y;
        this->indexX = X;
        this->array = new std::string[indexY * indexX]; // Allocate memory for the grid
    }

    // Resizes the grid to new dimensions while preserving existing data
    void VIMstring::Reallocate(int Y, int X)
    {
        // Allocate memory for the new grid
        std::string* temp = new std::string[Y * X];

        // Copy the existing data into the new grid (up to the smaller of old/new dimensions)
        for (int i = 0; i < std::min(indexY, Y); i++)
            for (int j = 0; j < std::min(indexX, X); j++)
                *(temp + X * i + j) = *(array + indexX * i + j);

        // Free the old grid memory
        delete[] array;

        // Update the grid pointer and dimensions
        array = temp;
        this->indexY = Y;
        this->indexX = X;
    }

    // Prints the grid to the console
    void VIMstring::PrintArray()
    {
        for (int i = 0; i < indexY; i++)
        {
            for (int j = 0; j < indexX; j++)
            {
                std::cout << *(array + indexX * i + j) << " "; // Print each element separated by a space
            }
            std::cout << std::endl; // Move to the next line after each row
        }
    }

    // Provides access to a specific element in the grid
    std::string& VIMstring::GetElement(int y, int x)
    {
        // Ensure the requested coordinates are within bounds
	    if (y < 0 || y >= indexY || x < 0 || x >= indexX)
		    throw std::out_of_range("Index out of bounds");
	    
        // Return a reference to the element at the specified position
        return *(array + indexX * y + x);
    }

    // Destructor: Frees the dynamically allocated memory
    VIMstring::~VIMstring() { delete[] array; }

    // Returns the number of rows in the grid
    int VIMstring::GetYSize() { return indexY; }

    // Returns the number of columns in the grid
    int VIMstring::GetXSize() { return indexX; }

    // Global instance of VIMstring
    VIMstring strArray;

    // Outputs text at the specified coordinates in the grid
    void outYX(int Y, int X, std::string text)
    {
	    system("cls"); // Clear the console (Windows-specific)
	    
        // If the specified coordinates exceed the current grid size, resize the grid
	    if (Y >= strArray.GetYSize() || X >= strArray.GetXSize())
		    strArray.Reallocate(std::max(Y + 1, strArray.GetYSize()), std::max(X + 1, strArray.GetXSize()));

	    // Set the specified position in the grid to the provided text
	    strArray.GetElement(Y, X) = text;

	    // Print the updated grid to the console
	    strArray.PrintArray();
    }
}
