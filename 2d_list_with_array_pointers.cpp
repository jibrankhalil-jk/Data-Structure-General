#include <iostream>
#include <string>

using namespace std;

int main()
{

    int row = 2, column = 2;

    int **array = (int **)calloc(row, sizeof(int *));

    for (int i = 0; i < row; i++)
    {
        *(array + i) = (int *)calloc(column, sizeof(int));
    }
    cout << endl;

    // assigning values
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            *(*(array + i) + j) = 11;
        }
    }

    // printing values
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << *(*(array + i) + j) << ",";
        }
        cout << endl;
    }

    // deleting array
    for (int i = 0; i < row; i++)
    {
        free(*(array + i));
    }
    return 0;
}
