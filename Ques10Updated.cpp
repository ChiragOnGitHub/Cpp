#include <iostream>
using namespace std;

class ArraySet
{
    int *arr;
    int n;

public:
    ArraySet(int a)
    {
        n = a;
        arr = new int[a];
    }

    void takeInput()
    {
        for (int i = 0; i < n; i++)
            cin >> arr[i];
    }

    void displaySet()
    {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    void permutationsWithoutRepetition(int pos)
    {
        if (pos == n)
        {
            displaySet();
            return;
        }

        for (int i = pos; i < n; i++)
        {
            swap(arr[pos], arr[i]);
            permutationsWithoutRepetition(pos + 1);
            swap(arr[pos], arr[i]);
        }
    }

    void permutationsWithRepetition(int permute[], int index)
    {
        // base case
        if (index == n)
        {
            for (int i = 0; i < n; i++)
                cout << permute[i] << " ";
            cout << endl;
            return;
        }
        for (int i = 0; i < n; i++)
        {
            permute[index] = arr[i];
            permutationsWithRepetition(permute, index + 1);
        }
    }
};

int main()
{
    int n;
    cout << "Enter size of set: ";
    cin >> n;

    // declaring array set
    ArraySet A(n);
    cout << "Enter elements of set" << endl;
    A.takeInput();

    int arr[n];
    cout << "-------------Permutations With Repetition-------" << endl;
    A.permutationsWithRepetition(arr, 0);
    cout << "-------------Permutations Without Repetition-------" << endl;
    A.permutationsWithoutRepetition(0);
    return 0;
}