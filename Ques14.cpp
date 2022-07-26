#include <iostream>
using namespace std;

class Recurrence
{
public:
    // T(n) = T(n - 1) + n , T(0) = 1
    int relation_1(int n)
    {
        if (n == 0)
            return 1;
        return relation_1(n - 1) + n;
    }

    // T(n) = T(n - 1) + n^2 , T(0) = 1
    int relation_2(int n)
    {
        if (n == 0)
            return 1;
        return relation_2(n - 1) + n * n;
    }

    // T(n) = 2T(n/2) + n , T(1) = 1 , T(0) = 0
    int relation_3(int n)
    {
        if (n <= 1)
            return n;
        return 2 * relation_3(n / 2) + n;
    }
};

int main()
{
    int n;
    Recurrence R;

    cout << "Enter an integer : ";
    cin >> n;

    cout << "Recurrence 1 : " << R.relation_1(n) << endl;
    cout << "Recurrence 2 : " << R.relation_2(n) << endl;
    cout << "Recurrence 3 : " << R.relation_3(n) << endl;
    return 0;
}

