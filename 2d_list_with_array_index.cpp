#include <iostream>
#include <string>

using namespace std;

int main()
{

    int row = 2, column = 2;

    int **array = new int *[row];
    for (int i = 0; i < row; i++)
    {
        array[i] = new int[column];
    }

    // assigning values
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            array[i][j] = 10;
        }
    }

    // printing values
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << (array[i][j]) << ",";
        }
        cout << endl;
    }

    // deleting array
    for (int i = 0; i < row; i++)
    {
        delete[] (array[i]);
    }
    return 0;
}