#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

class Array
{
    int size;
    int *arr;

public:
    Array()
    {
        size = 0;
    }

    Array(int size)
    {
        this->size = size;
        arr = new int[size];
    }

    ~Array()
    {
        delete[] arr;
    }

    void setArray()
    {
        for (int i = 0; i < size; i++)
            arr[i] = rand()%250 + 1;
            //enter a random number between 1 to 250 in the array
    }


    int bubbleSort()
    {
        int comparisons = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                    comparisons++;
                }
            }
        }
        return comparisons;
    }
};

int main()
{

    ofstream out("ques8.csv");
    srand((unsigned)time(NULL));

    Array arr;
    int comp;

    for (int i = 1; i <= 300; i += 5)
    {
        arr = Array(i);
        arr.setArray();

        comp = arr.bubbleSort();
        
        cout << "Size of array : " << i << " No. of Comparisons : " << comp << endl;
        out << i << "," << comp << endl;
    }
    out.close();

    return 0;
}