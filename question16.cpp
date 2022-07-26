#include <iostream>
using namespace std;

class Graph
{
private:
    int **arr;
    int order;

public:
    Graph()
    {
        cout << "Enter the number of nodes : ";
        cin >> order;

        arr = new int *[order];
        for (int i = 0; i < order; i++)
        {
            arr[i] = new int[order];
        }
    }
    ~Graph()
    {
        for (int i = 0; i < order; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }

    void input(){
        cout<<"Enter the elements of Adjacency Matrices : "<<endl;
        for (int i = 0; i < order; i++)
        {
            for (int j = 0; j < order; j++)
            {
                cin >> arr[i][j];
            }
        }
    }

    bool complete(){

        for (int  i = 0; i < order; i++)
        {
            for (int j = 0; j < order; j++)
            {
                if(i==j && arr[i][j]!=0){
                    return false;
                }  
                else if(arr[i][j]!=1 && i!=j){
                    return false;
                }
            }
        }
        return true;
        
    }
    
};

int main()
{
    Graph a;
    a.input();
    bool temp;
    temp=a.complete();
    if(temp)
        cout<<"Graph is complete !! ";
    else
        cout<<"Graph is not complete !!";

    return 0;
}