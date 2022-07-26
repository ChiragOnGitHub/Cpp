#include <iostream>
using namespace std;

class Graph
{
    int n;
    int **arr;

public:
    Graph(int a)
    {
        //creating an 2-D array
        n = a;
        arr = new int *[n];
        for (int i = 0; i < n; i++)
            arr[i] = new int[n];
    }

    void inputGraph()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        }
    }

    bool isEulerPath(int path[], int pathSize)
    {
        int visited[n][n];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                visited[i][j] = 0;
        }

        int u, v;
        for (int i = 0; i < pathSize - 1; i++)
        {
            u = path[i];
            v = path[i + 1];

            if (!arr[u][v] || !arr[v][u])
                return false;

            else if (visited[u][v])
                return false;

            visited[u][v] = 1;
            visited[v][u] = 1;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                bool isEdge = arr[i][j] && arr[j][i];
                bool isVisited = visited[i][j] && visited[j][i];
                if (isEdge && !isVisited)
                    return false;
            }
        }

        return true;
    }

    bool isEulerCircuit(int path[], int pathSize)
    {
        return isEulerPath(path, pathSize) && (path[0] == path[pathSize - 1]);
    }
};

int main()
{   
    int n;
    cout<<"Enter the size of adjacency matrix : ";
    cin>>n;
    Graph G(n);

    cout<<"Enter adjacency martix : ";
    G.inputGraph();

    int pathsize;
    cout<<"Enter size of set of vertices : ";
    cin>>pathsize;

    int *path=new int[pathsize];

    cout<<"Enter Set of vertices : ";
    for (int i = 0; i < pathsize; i++)
    {
        cin>>path[i];
    }
    
    bool temp = G.isEulerPath(path, pathsize);
    if(temp==true)
        cout << "Given set of vertices forms an euler path!!" << endl;
    else
        cout << "Given set of vertices do not form an euler path!!" << endl;
    
    temp = G.isEulerCircuit(path, pathsize);
    if(temp==true)
        cout << "Given set of vertices forms an euler circuit!!" << endl;
    else
        cout << "Given set of vertices do not form an euler circuit!!" << endl;
    

    return 0;
}

/*
input-

5
0 1 0 0 1
1 0 1 1 1
0 1 0 1 0
0 1 1 0 1
1 1 0 1 0
6
0 1 2 3 4 0


*/