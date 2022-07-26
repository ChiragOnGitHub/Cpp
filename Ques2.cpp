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
        arr= new int[size];
    }

    void input()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Enter element " << i + 1 << " of array : ";
            cin >> arr[i];
        }
        removeDuplicates();
    }

    void display()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
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

    bool isExists(int a)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == a)
                return true;
        }
        return false;
    }

    // check whether main set is a subset of temp or not
    bool Subset(Set temp)
    {   
        bool check=true;
        for (int i = 0; i < size; i++)
        {
            if (!(temp.isExists(arr[i]))){
                check=false;
                break;
            }
        }
        return check;
    }

    void Union(Set temp)
    {
        Set temp2(size + temp.size);

        int i;

        for (i = 0; i < size; i++)
        {
            temp2.arr[i] = arr[i];
        }
        for (int j = 0; i < size + temp.size, j < temp.size; i++, j++)
        {
            temp2.arr[i] = temp.arr[j];
        }

        temp2.removeDuplicates();
        temp2.display();
    }

    void Intersection(Set temp)
    {   
        for (int i = 0; i < temp.size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                    
                if(temp.arr[i]==arr[j]){
                    cout<<arr[j]<<" ";
                }
            }
        }
    }

    void Complement()
    {
        int univSize;
        cout << "Enter the size of Universal Set: ";
        cin >> univSize;

        Set temp(univSize);
        temp.input();


        // int *univ;
        // univ=new int[univSize];

        // cout << "Enter the elements of Universal Set: " << endl;
        // for (int i = 0; i < univSize; i++)
        // {
        //     cin >> univ[i];
        // }
        cout << "Complement of the set : ";
        for (int i = 0; i < temp.size; i++)
        {
            if (!isExists(temp.arr[i]))
                cout << temp.arr[i] << " ";
        }
        cout << endl;
    }

    void SetDifference(Set s)
    {
        for(int i=0;i<size;i++)
        {
            if(!s.isExists(arr[i]))
                cout<<arr[i]<<" ";
        }
    }

    void CartesianProduct(Set s){
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<s.size;j++)
                cout<<"("<<arr[i]<<","<<s.arr[j]<<")"<<" ";
        }
        cout<<endl;
    }

    void SymmetricDifference(Set s){
        for(int i=0;i<size;i++)
        {
            if(!s.isExists(arr[i]))
                cout<<arr[i]<<" ";
        }
        for(int i=0;i<s.size;i++)
        {   
            if(!isExists(s.arr[i]))
                cout<<s.arr[i]<<" ";
        }
    }
};

int main()
{
    cout<<"Enter size of Set 1 : ";
    int size1;
    cin>>size1;

    Set set1(size1);
    set1.input();
    cout<<"Set 1 : ";
    set1.display();
    cout<<endl;

    cout<<"Enter size of Set 2 : ";
    int size2;
    cin>>size2;

    Set set2(size2);
    set2.input();
    cout<<"Set 2 : ";
    set2.display();
    cout<<endl;

    cout<<endl;
    if(set1.Subset(set2))
        cout<<"Set 1 is a subset of Set 2 "<<endl;
    else
        cout<<"Set 1 is not a subset of Set 2 "<<endl;
    if(set2.Subset(set1))
        cout<<"Set 2 is a subset of Set  1 "<<endl;
    else
        cout<<"Set 2 is not a subset of Set 1 "<<endl;

    cout<<endl;
    cout<<"Union of Set 1 and Set 2 are : ";
    set1.Union(set2);
    cout<<endl;
    
    cout<<endl;
    cout<<"Intersection of Set 1 and Set 2 are : ";
    set1.Intersection(set2);
    cout<<endl;

    cout<<endl;
    cout<<"Set Differnece of Set 2 from Set 1 : ";
    set1.SetDifference(set2);
    cout<<endl;

    cout<<endl;
    cout<<"Set Differnece of Set 1 from Set 2 : ";
    set2.SetDifference(set1);
    cout<<endl;

    cout<<endl;
    cout<<"Symmetric Difference of Set 1 and Set 2 are : ";
    set1.SymmetricDifference(set2);
    cout<<endl;


    cout<<endl;
    cout<<"Cartesian Product of Set 1 and Set 2 are :";
    set1.CartesianProduct(set2);
    cout<<endl;

    cout<<endl;
    cout<<"Cartesian Product of Set 2 and Set 1 are :";
    set2.CartesianProduct(set1);
    cout<<endl;

    set1.Complement();
    cout<<endl;
    return 0;
}