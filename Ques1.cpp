#include <iostream>
using namespace std;

class Set
{
    private:
        int *arr;
        int size;

    public:
        Set(int num)
        {
            size = num;
            arr = new int[num];
        }

        void input()
        {
            for (int i = 0; i < size; i++){
                cout << "Enter element "<<i+1<<" of array : ";
                cin >> arr[i];
            }
            removeDuplicates();
        }

        void display()
        {
            cout << "Set : ";
            for (int i = 0; i < size; i++)
                cout << arr[i] << " ";
            cout << endl;
        }

        void removeDuplicates()
        {
            for (int i = 0; i < size - 1; i++)
            {
                for (int j = i + 1; j < size; j++)
                {
                    if (arr[i] == arr[j])
                    {
                        for (int k = j; k < size - 1; k++)
                            arr[k] = arr[k + 1];
                        size--;
                        j--;
                    }
                }
            }
        }

        bool ismember(int a)
        {
            for (int i = 0; i < size; i++)
            {
                if (arr[i] == a)
                    return true;
            }
            return false;
        }

        //check bitnum bit of num{return true for 1 and false for 0}
        bool checkBit(int num, int bitnum)
        {
            int mask = 1 << bitnum;
            return (num & mask) != 0;
        }

        void powerset()
        {
            int n = 1 << size; // 2**size subsets

            cout << "Power Set : { ";
            for (int i = 0; i < n; i++)
            {   
                cout<<"{ ";
                for (int j = 0; j < size; j++)
                {
                    if (checkBit(i, j))
                        cout << arr[j] << " ";
                }
                cout << "}  ";
            }
            cout<<"} ";

        }
};

int main()
{
    Set set1(8);
    set1.input();
    set1.display();
    set1.powerset();
    return 0;
}