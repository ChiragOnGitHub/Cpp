#include <iostream>
using namespace std;

int nCr(int n, int r)
{
    if (r == n || r == 0)
        return 1;
    return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

int nPr(int n, int r)
{
    if (r == 0)
        return 1;
    // if(r==1)
    //     return n;
    if (r > n)
        return 0;

    return nPr(n - 1, r) + r * nPr(n - 1, r - 1);
}

int main()
{
    int n, r;

    cout << "Enter values of n " << endl;
    cin >> n;
    cout << "Enter values of r " << endl;
    cin >> r;
    
    cout << n << "P" << r << " : " << nPr(n, r) << endl;
    cout << n << "C" << r << " : " << nCr(n, r) << endl;
    return 0;
}
