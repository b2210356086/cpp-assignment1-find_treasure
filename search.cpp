#include "search.h"

void search(int** &mapRowPtr, int** &keyRowPtr, int mapRowAmount, int mapColumnAmount, int keyDimensions, int xStart, int yStart, int xEnd, int yEnd, std::ofstream &outputFile)
{
    //Calculates the dot product of Map Matrix and Key Matrix inbetween given x/y Start and End coordinates. 
    int dotProduct = 0;
    for (int i = xStart; i < xEnd; i++)
    {
        for (int j = yStart; j < yEnd; j++)
        {
            dotProduct += mapRowPtr[i][j] * keyRowPtr[i % keyDimensions][j % keyDimensions];
        }
    }
    //
    //Adds 5 until dot product is greater than or equals to zero
    while (dotProduct < 0)
    {
        dotProduct += 5;
    }
    //
    outputFile << (xStart + xEnd)/2 << ',' << (yStart + yEnd)/2 << ':' << dotProduct << '\n'; //Writes the submatrix center coordinates and dot product to "output.txt" file
    
    /* Decides on the next step of the function depending on dot product mod 5 (result).
    If result is 0 then the treasure is found and recursion ends.
    Otherwise the search function is called recursively with new coordinates depending on the result which decides upon the direction that coordinates will be moved.
    Out of bounds (reverse direction) situations are checked with if/else statements. */
    switch(dotProduct % 5)
    {
        case 0:
            break;
        case 1:
            if (xStart < keyDimensions)
            {
                search(mapRowPtr, keyRowPtr, mapRowAmount, mapColumnAmount, keyDimensions, xStart + keyDimensions, yStart, xEnd + keyDimensions, yEnd, outputFile);
            }
            else
            {
                search(mapRowPtr, keyRowPtr, mapRowAmount, mapColumnAmount, keyDimensions, xStart - keyDimensions, yStart, xEnd - keyDimensions, yEnd, outputFile);
            }
            break;
        case 2:
            if (xEnd + keyDimensions > mapRowAmount)
            {
                search(mapRowPtr, keyRowPtr, mapRowAmount, mapColumnAmount, keyDimensions, xStart - keyDimensions, yStart, xEnd - keyDimensions, yEnd, outputFile);
            }
            else    
            {
                search(mapRowPtr, keyRowPtr, mapRowAmount, mapColumnAmount, keyDimensions, xStart + keyDimensions, yStart, xEnd + keyDimensions, yEnd, outputFile);
            }
            break;
        case 3:
            if (yEnd + keyDimensions > mapColumnAmount)
            {
                search(mapRowPtr, keyRowPtr, mapRowAmount, mapColumnAmount, keyDimensions, xStart, yStart - keyDimensions, xEnd, yEnd - keyDimensions, outputFile);
            }
            else
            {
                search(mapRowPtr, keyRowPtr, mapRowAmount, mapColumnAmount, keyDimensions, xStart, yStart + keyDimensions, xEnd, yEnd + keyDimensions, outputFile);
            }
            break;
        case 4:
            if (yStart < keyDimensions)
            {
                search(mapRowPtr, keyRowPtr, mapRowAmount, mapColumnAmount, keyDimensions, xStart, yStart + keyDimensions, xEnd, yEnd + keyDimensions, outputFile);
            }
            else
            {
                search(mapRowPtr, keyRowPtr, mapRowAmount, mapColumnAmount, keyDimensions, xStart, yStart - keyDimensions, xEnd, yEnd - keyDimensions, outputFile);
            }
            break;
    }
    //
}