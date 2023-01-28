#include <fstream>
#include "matrix.h"
#include "search.h"

int main(int argc, char* argv[])
{
    //Creates mapmatrix
    std::string mapDimensions = argv[1];
    int indexOfX = mapDimensions.find("x");
    int mapRowAmount = std::stoi(mapDimensions.substr(0, indexOfX));
    int mapColumnAmount = std::stoi(mapDimensions.substr(indexOfX + 1, mapDimensions.length() - indexOfX - 1));
    int** mapRowPtr = createMatrix(mapRowAmount, mapColumnAmount);
    //Creates keymatrix
    int keyDimensions = std::stoi(argv[2]);
    int** keyRowPtr = createMatrix(keyDimensions, keyDimensions);
    //
    
    fillMatrix(argv[3], mapColumnAmount, mapRowPtr); //Fills mapmatrix
    fillMatrix(argv[4], keyDimensions, keyRowPtr); //Fills keymatrix
    
    std::ofstream outputFile (argv[5]); //Creates Output file

    search(mapRowPtr, keyRowPtr, mapRowAmount, mapColumnAmount, keyDimensions, 0, 0, keyDimensions, keyDimensions, outputFile); //Searches and Finds the Treasure, Writes to the output file
    
    //Closes Output file
    if (outputFile.is_open())
    {
        outputFile.close();
    }
    //
    
    deleteMatrix(mapRowAmount, mapRowPtr); //Deletes mapmatrix
    deleteMatrix(keyDimensions, keyRowPtr); //Deletes keymatrix
    
    return 0;
}