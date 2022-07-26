#include <iostream>
#include <cmath>
using namespace std;

class Polynomial
{
    int degree;
    int *coefficients;

public:
    Polynomial(int d)
    {
        degree = d;
        coefficients = new int[d + 1];
    }

    void inputCoefficients()
    {
        for (int i = degree; i >= 0; i--){
            cout<<"Enter Coefficients of x^"<<i<<" : ";
            cin >>coefficients[i];

        }
    }

    void display()
    {
        for (int d = degree; d > 0; d--)
            cout << coefficients[d] << " x^" << d << " + ";
        cout << coefficients[0] << " x^0" << endl;
    }

    int f(int n)
    {
        int res = 0;
        for (int d = degree; d >= 0; d--)
            res += coefficients[d] * pow(n, d);
        return res;
    }
};

int main()
{
    int degre;
    cout << "Enter degree of polynomial : ";
    cin >> degre;
    Polynomial p(degre);

    p.inputCoefficients();
    cout<<endl;

    cout << "Polynomial : ";
    p.display();

    int value;
    cout << "Enter a number : ";
    cin >> value;
    cout << "Value of polynomial at x :  " << value << " : " << p.f(value);
    return 0;
}

