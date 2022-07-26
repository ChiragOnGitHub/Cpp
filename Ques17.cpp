#include <iostream>
using namespace std;

class DirectedGraph{
    private:
        int **arr;
        int order;
    public:
        DirectedGraph(){
            cout << "Enter the number of nodes : ";
            cin >> order;

            arr=new int*[order];
            for(int i=0;i<order;i++){
                arr[i]=new int[order];
            }
        }
        ~DirectedGraph()
        {
            for (int i = 0; i < order; i++)
            {
                delete[] arr[i];
            }
            delete[] arr;
        }
        void input(){
            cout<<"Enter the elements of Directed Graph in form of Adjacency Matrices : "<<endl;
            for (int i = 0; i < order; i++)
            {
                for (int j = 0; j < order; j++)
                {
                    cin >> arr[i][j];
                }
            }
        }
        void outdegree(){
            int temp;
            for (int i = 0; i < order; i++)
            {   
                temp=0;
                for (int j = 0; j < order; j++)
                {
                    temp+=arr[i][j];
                }
                cout<<"Outdegree of node "<<(i+1)<<" is  : "<<temp<<endl;
            }
        }
        void indegree(){
            int temp;
            for (int i = 0; i < order; i++)
            {   
                temp=0;
                for (int j = 0; j < order; j++)
                {
                    temp+=arr[j][i];
                }
                cout<<"Indegree of node "<<(i+1)<<" is  : "<<temp<<endl;
            }
        }


};

int main(){
    DirectedGraph a;
    a.input();
    cout<<endl;
    a.outdegree();
    cout<<endl;
    a.indegree();

    return 0;
}