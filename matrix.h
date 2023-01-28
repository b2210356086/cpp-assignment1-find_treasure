#include <string>

int** createMatrix(int rowAmount, int columnAmount); //Creates and returns a Dynamic 2D Array with given row and column sizes by using Pointers

void fillMatrix(std::string fileName, int columnAmount, int** &rowPtr); //Splits the elements of a read input file by spaces and fills the given 2D dynamic array with those elements

void deleteMatrix(int rowAmount, int** &rowPtr); //Deletes a 2D Dynamic Array from heap memory