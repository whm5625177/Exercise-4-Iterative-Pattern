#include <iostream>
#include <chrono>
#include <thread>

// Function to draw a single element of the pattern
void drawElement(const std::string& symbol)
{
    // Draw the element with the specified symbol
    std::cout << symbol; // Print the symbol to represent the element
}

// Function to tile the pattern across a surface
void tilePattern(int width, int height, int tileSize)
{
    // Define the symbols to be used in the pattern
    std::string symbols[] = {"❄️"};

    // Loop indefinitely to create a realtime and infinitely-extendable pattern
    while (true)
    {
        // Loop through the surface and draw elements of the pattern at regular intervals
        for (int y = 0; y < height; y += tileSize)
        {
            for (int x = 0; x < width; x += tileSize)
            {
                // Select a symbol from the array based on position
                std::string symbol = symbols[0]; // Only use the first symbol

                // Draw the element with the selected symbol
                drawElement(symbol);
                std::cout.flush(); // Flush the output to ensure immediate display
                std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Add a delay between each symbol
            }
            std::cout << std::endl; // Move to the next line after finishing a row
        }
    }
}

int main()
{
    int surfaceWidth = 100;
    int surfaceHeight = 50;
    int tileSize = 1; // Set tileSize to 1 to draw one character at a time

    tilePattern(surfaceWidth, surfaceHeight, tileSize);

    return 0;
}

