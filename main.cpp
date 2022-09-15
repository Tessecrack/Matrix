/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <utility>
using namespace std;

//matrix in matrix
int** getRandomMatrix(int length, int width);
void printMatrix(int** matrix, int length, int width);
pair<int, int> getMinIndexDownMainDiag(int** matrix, int length, int width);
pair<int, int> getMaxIndexUpSideDiag(int** matrix, int length, int width);
void matrixInMatrixTask();
//--------------

//matrix in array
int* getRandomArrayMatrix(int length);
void printArrayMatrix(int* matrix, int length);
void matrixInArrayTask();
int getMinIndexDownMainDiagArray(int* matrix, int length);
int getMaxIndexUpSideDiagArray(int* matrix, int length);
//--------------

int main()
{
    //matrixInMatrixTask();
    matrixInArrayTask();
    return 0;
}

void matrixInArrayTask()
{
    const int length = 4;
    const auto matrix = getRandomArrayMatrix(length);
    printArrayMatrix(matrix, length);
    const auto indexMin = getMinIndexDownMainDiagArray(matrix, length);
    const auto indexMax = getMaxIndexUpSideDiagArray(matrix, length);
    cout << "\nindexes in array: " << indexMin << " " << indexMax << endl;
    
    matrix[indexMax] += matrix[indexMin];
    matrix[indexMin] = matrix[indexMax] - matrix[indexMin];
    matrix[indexMax] -= matrix[indexMin];
    
    printArrayMatrix(matrix, length);
}

void matrixInMatrixTask()
{
    const int length = 6;
    const int width = 6;
    
    const auto matrix = getRandomMatrix(length, width);
    printMatrix(matrix, length, width);
    const auto indexMin = getMinIndexDownMainDiag(matrix, length, width);
    const auto indexMax = getMaxIndexUpSideDiag(matrix, length, width);
    
    matrix[indexMin.first][indexMin.second] += matrix[indexMax.first][indexMax.second];
    matrix[indexMax.first][indexMax.second] = matrix[indexMin.first][indexMin.second] - matrix[indexMax.first][indexMax.second];
    matrix[indexMin.first][indexMin.second] -= matrix[indexMax.first][indexMax.second];
    
    printMatrix(matrix, length, width);
}

int getMinIndexDownMainDiagArray(int* matrix, int length)
{
    int fullLength = length * length;
    int indexRow = 1;
    int indexCol = 0;
    int index = indexRow * length + indexCol;
    int min = matrix[index];
    for (int i = 0; i < fullLength; i++)
    {
        int currentRow = i / length;
        int currentCol = i % length;
        
        if (currentRow > currentCol && min > matrix[i])
        {
            min = matrix[i];
            indexRow = currentRow;
            indexCol = currentCol;
            index = i;
        }
    }
    
    cout << "Min element[" << indexRow << "][" << indexCol << "]: " << min << endl;
    return index;
}

int getMaxIndexUpSideDiagArray(int* matrix, int length)
{
    int fullLength = length * length;
    int indexRow = 0;
    int indexCol = 1;
    int index = indexRow * length + indexCol;
    int max = matrix[index];
    for (int i = 0; i < fullLength; i++)
    {
        int currentRow = i / length;
        int currentCol = i % length;
        
        if (length - 1 - currentCol > currentRow  && max < matrix[i])
        {
            max = matrix[i];
            indexRow = currentRow;
            indexCol = currentCol;
            index = i;
        }
    }
    
    cout << "Max element[" << indexRow << "][" << indexCol << "]: " << max << endl;
    return index;
}

int* getRandomArrayMatrix(int length)
{
    int* matrix = new int[length * length];
    for (int i = 0; i < length * length; i++)
    {
        matrix[i] = rand() % length * length;
    }
    return matrix;
}

void printArrayMatrix(int* matrix, int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            cout << matrix[i * length + j] << "\t";
        }
        cout << endl;
    }
}

void printMatrix(int** matrix, int length, int width)
{
    cout << endl;
    for (int i = 0; i < length; i++) 
    {
        for (int j = 0; j < width; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

int** getRandomMatrix(int length, int width)
{
    int** matrix = new int*[length];
    for (int i = 0; i < length; i++)
    {
        matrix[i] = new int[width];
        for (int j = 0; j < width; j++)
        {
            //matrix[i][j] = i * length + j;
            matrix[i][j] = rand() % (length * width);
        }
    }
    return matrix;
}

pair<int, int> getMinIndexDownMainDiag(int** matrix, int length, int width)
{
    pair<int, int> indexMatrix;
    indexMatrix.first = 1;
    indexMatrix.second = 0;
    int min = matrix[indexMatrix.first][indexMatrix.second];
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i > j && min > matrix[i][j])
            {
                min = matrix[i][j];
                indexMatrix.first = i;
                indexMatrix.second = j;
            }
        }
    }
    cout << "Min element["<< indexMatrix.first << "][" << indexMatrix.second << "]" << ": " << min << endl;
    return indexMatrix;
}

pair<int, int> getMaxIndexUpSideDiag(int** matrix, int length, int width)
{
    pair<int, int> indexMatrix;
    indexMatrix.first = 0;
    indexMatrix.second = 1;
    int max = matrix[indexMatrix.first][indexMatrix.second];
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int index = width - 1 - j;
            if (index > i && max < matrix[i][j])
            {
                max = matrix[i][j];
                indexMatrix.first = i; 
                indexMatrix.second = j;
            }
        }
    }
    cout << "Max element["<< indexMatrix.first << "][" << indexMatrix.second << "]" << ": " << max << endl;
    return indexMatrix;
}
