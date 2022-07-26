#include <iostream>
using namespace std;


class M_AryTree
{
    int internalNodes, leaf, M;

public:
    M_AryTree(int m,int i)
    {
        internalNodes = i;
        M = m;
        leaf = (m - 1) * i + 1;
    }

    int getLeaves()
    {
        return leaf;
    }
};

int main()
{
    int m;
    cout << "Enter The value of m (of m-ary tree) " << endl;
    cin >> m ;

    int i;
    cout<<"Enter the number of internal nodes : ";
    cin>>i;

    M_AryTree tree(m,i);

    cout << "Number of leaves : " << tree.getLeaves();
    return 0;
}