#include <iostream>
using namespace std;

class Relation
{
    int n;
    int **arr;

public:
    Relation(int s)
    {
        n = s;
        arr = new int* [n];
        for (int i = 0; i < n; i++)
            arr[i] = new int[n];
    }

    void takeInput()
    {
        cout<<"Enter elements of matrix : "<<endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++){
                cin >> arr[i][j];
            }
        }
    }

    bool isReflexive()
    {
        for (int i = 0; i < n; i++)
        {
            if (!arr[i][i])
                return false;
        }
        return true;
    }

    bool isSymmetric()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (arr[i][j] != arr[j][i])
                    return false;
            }
        }
        return true;
    }

    bool isAntiSymmetric()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i][j] == arr[j][i] && arr[i][j]) // ignore where arr[i,j] = arr[j,i] = 0
                    return false;
            }
        }
        return true;
    }

    bool isTransitive()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // Check if i,j = 1 go for j,k to check for 1 then i,k
                if (arr[i][j])
                {
                    for (int k = 0; k < n; k++)
                    {
                        if (arr[j][k] && !arr[i][k])
                            return false;
                    }
                }
            }
        }
        return true;
    }

    bool isPartiallyOrdered()
    {
        return isReflexive() && isAntiSymmetric() && isTransitive();
    }

    bool isEquivalence()
    {
        return isReflexive() && isSymmetric() && isTransitive();
    }
};

int main()
{   
    int size;
    cout<<"Enter size of square matrix :";
    cin>>size;
    Relation R(size);

    R.takeInput();
    cout<<endl;
    cout<<endl;

    if(R.isReflexive())
        cout<<"Relation is Reflexive "<<endl;
    else
        cout<<"Relation is not Reflexive "<<endl;
    if(R.isSymmetric())
        cout<<"Relation is Symmetric "<<endl;
    else
        cout<<"Relation is not Symmetric "<<endl;
    if(R.isAntiSymmetric())
        cout<<"Relation is Anti Symmetric "<<endl;
    else
        cout<<"Relation is not Anti Symmetric "<<endl;
    if(R.isTransitive())
        cout<<"Relation is Transitive "<<endl;
    else
        cout<<"Relation is not Transitive "<<endl;

    if(!R.isPartiallyOrdered() and !R.isEquivalence()){
        cout<<"Relation is neither Equivalence nor Partially Ordered!!";
    }
    else{
        if(R.isPartiallyOrdered())
            cout<<"Relation is Partially Ordered "<<endl;
        else
            cout<<"Relation is not Partially Ordered "<<endl;
        if(R.isEquivalence())
            cout<<"Relation is Equivalence "<<endl;
        else
            cout<<"Relation is not Equivalence "<<endl;
    }

    return 0;
}