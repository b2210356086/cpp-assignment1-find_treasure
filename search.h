#include <fstream>

void search(int** &mapRowPtr, int** &keyRowPtr, int mapRowAmount, int mapColumnAmount, int keyDimensions, int xStart, int yStart, int xEnd, int yEnd, std::ofstream &outputFile); //Finds the treasure recursively, more details in "search.cpp" file