#pragma once
#include <iostream>
namespace vim
{
    // Class to represent a 2D grid of strings
	class VIMstring
	{
	public:
        // Default constructor initializes a 1x1 grid
		VIMstring();

        // Constructor to initialize a grid with specific dimensions
		VIMstring(int Y, int X);

        // Resizes the grid to new dimensions while preserving existing data
		void Reallocate(int Y, int X);

        // Prints the grid to the console
		void PrintArray();

        // Provides access to a specific element in the grid
		std::string& GetElement(int y, int x);
		
        // Destructor to free dynamically allocated memory
        ~VIMstring();

        // Returns the number of rows in the grid
		int GetYSize();

        // Returns the number of columns in the grid
		int GetXSize();

	private:
        // Pointer to the dynamically allocated 1D array representing the 2D grid
		std::string* array;

        // Dimensions of the grid
		int indexY, indexX;
	};

    // External global instance of VIMstring
	extern VIMstring strArray;

    // Outputs text at the specified coordinates in the grid
	void outYX(int Y, int X, std::string text);
}
