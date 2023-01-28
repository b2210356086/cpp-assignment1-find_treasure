#include "matrix.h"
#include <fstream>

int** createMatrix(int rowAmount, int columnAmount)
{
    int** rowPtr = new int*[rowAmount];
    for (int i = 0; i < rowAmount; i++)
    {
        int* colPtr = new int[columnAmount];
        rowPtr[i] = colPtr;
    }
    return rowPtr;
}

void fillMatrix(std::string fileName, int columnAmount, int** &rowPtr)
{
    std::string line;
    std::ifstream file (fileName);
    if (file.is_open())
    {
        int rowCount = 0;
        while (getline(file, line))
        {
            int* elements = new int[columnAmount];
            int start = 0;
            int end = line.find(" ");
            int index = 0;
            while (end != -1)
            {
                elements[index] = std::stoi(line.substr(start, end - start));
                index++;
                start = end + 1;
                end = line.find(" ", start);
            }
            elements[index] = std::stoi(line.substr(start, end - start));
            for (int i = 0; i < columnAmount; i++)
            {
                rowPtr[rowCount][i] = elements[i];
            }
            rowCount++;
            delete[] elements;
        }
        file.close();
    }
}

void deleteMatrix(int rowAmount, int** &rowPtr)
{
    for (int i = 0; i < rowAmount; i++)
    {
        delete[] rowPtr[i];
    }
    delete[] rowPtr;
}