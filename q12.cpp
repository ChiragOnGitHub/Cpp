#include <iostream>
using namespace std;

class LinearEquation
{
    int n, C;
    int *arr;

public:
    LinearEquation(int term, int Constant)
    {
        n = term;
        C = Constant;
        arr = new int[term];
        // solutionsCount = 0;
    }

    void display()
    {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    void solve(int index)
    {
        if (index == 0)
        {
            arr[index] = C;
            display();
            return;
        }

        for (int i = 0; i <= C; i++)
        {
            arr[index] = i;
            C -= i;
            solve(index - 1);
            C += i;
        }
    }
};

int main()
{
    int n, C;
    cout << "Enter n : " << endl;
    cin >> n;
    cout << "Enter C :" << endl;
    cin >> C ;

    LinearEquation l(n, C);
    l.solve(n - 1);
    return 0;
}