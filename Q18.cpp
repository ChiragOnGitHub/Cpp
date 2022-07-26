#include <iostream>
using namespace std;

class Path{
    private:
        int **arr;
        int order;
    public:
        Path(int num){

            order=num;
            arr=new int*[num];
            for(int i=0;i<num;i++){
                arr[i]=new int[num];
            }
        }
        ~Path()
        {
            for (int i = 0; i < order; i++)
            {
                delete[] arr[i];
            }
            delete[] arr;
        }
        void input(){
            cout<<"Enter the element in the form of Adjacency Matrices : "<<endl;
            for (int i = 0; i < order; i++)
            {
                for (int j = 0; j < order; j++)
                {
                    cin >> arr[i][j];
                }
            }
        }
        void print(){
            for (int i = 0; i < order; i++)
            {
                for (int j = 0; j < order; j++)
                {
                    cout << arr[i][j]<< " ";
                }
                cout<<endl;
            }

        }

        void copyContent(Path a){
            for (int i = 0; i < order; i++)
            {
                for (int j = 0; j < order; j++)
                {
                    arr[i][j]=a.arr[i][j];
                }
                
            }
            
        }
        void matrixMultiply(Path a,Path b){
            for (int j = 0; j < order; j++)
                {
                    for (int k = 0; k < order; k++)
                    {
                        arr[j][k]=0;
                        for (int l = 0; l < order; l++)
                        {
                            arr[j][k]+=a.arr[j][l]*b.arr[l][k];
                        }
                    }
                    
                }
        }

        Path powerMatrix(int num){
            Path temp(order);
            Path mul(order);

            mul.copyContent(*this);
            

            for (int i = 0; i < num-1; i++)
            {
                temp.matrixMultiply(mul,*this);
                mul.copyContent(temp);
 
            }
            return mul;
            
        }

        void path(int length,int source,int terminating){

            cout<<"Number of paths of length "<<length<<" between "<<source<<" and "<<terminating<<" nodes is : ";
            cout<<arr[source-1][terminating-1];
        }


};



int main()
{   
    int num;
    cout << "Enter the number of nodes : ";
    cin >> num;
    
    Path a(num);
    a.input();

    int length,source,terminating;
    cout<<"Enter the length of path : ";
    cin>>length;
    cout<<endl;

    Path b(num);
    b=a.powerMatrix(length);

    cout<<"Enter the source node : ";
    cin>>source;

    
    cout<<"Enter the terminating node : ";
    cin>>terminating;
    cout<<endl;

    b.path(length,source,terminating);
    
    return 0;
}