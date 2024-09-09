#include <codecvt>
#include <iostream>
#include <string>

using namespace std;

class Array
{
private:
    int length, size;
    int *array;
    int *current;

public:
    Array(int arraySize)
    {
        array = new int[size];
        size = arraySize;
        length = 0;
        current = NULL;
    }

    void print()
    {
        start();
        cout << "[";
        for (int i = 0; i < length; i++)
        {
            if (i == 0)
            {
                cout << *(current);
            }
            else
            {
                cout << "," << *(current);
            }
            next();
        }
        cout << "]" << endl;
    };

    void start()
    {
        current = array;
    };
    void tail()
    {
        current = array + length;
    }
    void back()
    {
        current = current - 1;
    };
    void next()
    {
        current = current + 1;
    };
    bool isFull()
    {
        return length == size ? true : false;
    };

    void add(int value)
    {
        if (isFull())
        {
            cout << "Array is Full" << endl;
            return;
        }
        else if(length == 0){
            *array = value;
            ++length;
        }
        else{
            tail();
            next();
            *(current) = value;
            ++length;
        }
    };

    void copy(Array arr)
    {
        for (int i = 0; i < arr.get(); i++)
        {
            *(array + i) = *(arr.array + i);
        }
        length = arr.get();
    };

    void clear()
    {
        length = 0;
    };
    void insert(int value, int pos)
    {
        if (isFull())
        {
            cout << "Array is Full" << endl;
            return;
        }
        if (pos < 0 || pos >= length + 1)
        {
            cout << "Out of Index" << endl;
            return;
        }
        tail();
        for (int i = length; i > pos; i--)
        {
            *(current) = *(current - 1);
            back();
        }
        *(current) = value;
        ++length;
    };
    void update(int value, int pos)
    {
        if (pos < 0 || pos > length)
        {
            cout << "Out of Index" << endl;
            return;
        }
        *(array + pos) = value;
    };
    void remove(int pos)
    {
        if (pos < 0 || pos >= length + 1)
        {
            cout << "Out of index" << endl;
            return;
        }
        current = array + (pos);
        for (int i = pos; i <= length; i++)
        {
            *current = *(current + 1);
            next();
        }
        --length;
    };
    int get()
    {
        if (length == 0)
        {

            cout << "Empty" << endl;
            return 0;
        }
        return length;
    };
    int find(int value)
    {
        start();
        for (int i = 0; i < length; i++)
        {
            if (*current == value)
            {
                return i;
            }
            next();
        }
        return -1;
    };
};

int main()
{

    Array myarra(4);
    myarra.print();

    myarra.add(1);
    myarra.add(3);
    myarra.print();

    // myarra.insert(0, 0);
    // myarra.insert(2, 2);
    // myarra.print();

    // myarra.update(4, 0);
    // myarra.print();
    // myarra.remove(0);
    // myarra.remove(1);
    // myarra.print();
    // cout << myarra.get();

    // Array a2(4);
    // a2.copy(myarra);
    // a2.print();
    // cout << a2.find(3);

    return 0;
}
