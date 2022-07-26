#include <iostream>
using namespace std;

class Graph
{
    int n;
    int **arr;

public:
    Graph(int a)
    {
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

            // visit/mark the undirected edge b/w u and v
            visited[u][v] = 1;
            visited[v][u] = 1;
        }

        // check for any unvisited edges which were present in graph but were not visited
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
    Graph G(4);
    cout << "Enter graph" << endl;
    G.inputGraph();

    int path[] = {0,1,2,0};
    int s = sizeof(path) / sizeof(path[0]);
    cout << "Euler path : " << G.isEulerPath(path, s) << endl;
    cout << "Euler circuit : " << G.isEulerCircuit(path, s) << endl;
    return 0;
}
