#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char destination, char auxi)
{

    if (n == 1)
    {
        cout << "From " << source << " to " << destination << endl;
        return;
    }

    towerOfHanoi(n - 1, source, auxi, destination);
    towerOfHanoi(1, source, destination, auxi);
    towerOfHanoi(n - 1, auxi, destination, source);
}

int main()
{

    int n;
    cout << "Enter number of discs : ";
    cin >> n;
    
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}
