#include <iostream>
using namespace std;

class Array
{

    int n;
    int *arr;

    public:
        Array(int a)
        {
            n = a;
            arr = new int[a];
        }

        void input()
        {
            for (int i = 0; i < n; i++)
                cin >> arr[i];
        }

        void display()
        {
            for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
            cout << endl;
        }

        int binarySearch(int Start, int End, int key)
        {
            if (Start > End)
                return -1;

            int mid = (Start + End) / 2;

            if (arr[mid] == key)
                return mid;

            else if (arr[mid] < key)
                return binarySearch(mid + 1, End, key);

            else
                return binarySearch(Start, mid - 1, key);
        }
};

int main()
{
    int size, key, pos;
    cout << "Enter size of array : ";
    cin >> size;

    Array arr(size);

    cout << "Enter elements of array : " << endl;
    arr.input();

    cout << "Enter element to be searched : ";
    cin >> key;

    pos = arr.binarySearch(0, size - 1, key);

    if (pos == -1)
        cout << key << " not found" << endl;
    else
        cout << key << " found at index " << pos << endl;
    return 0;
}
