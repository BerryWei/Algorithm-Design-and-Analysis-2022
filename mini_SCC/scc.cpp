// REF::https://www.geeksforgeeks.org
#include <iostream>
#include <stack>
#include<list>
#include<vector>

#define int long long

using namespace std;

struct Graph
{
    int V; // from 1 to V 
    list<int> *adj; // array of adjacency list --> len(adj) = V+1
    Graph(int v){V = v; adj = new list<int> [v];};
    void addEdge(int u, int v);
    void fillOrdered(int v, bool *visited, stack<int> & stk);
    Graph inversed();
    void printGraph();
    int DFSUtil(int v, bool visited[]);
};

int Graph::DFSUtil(int v, bool visited[])
{
    int count = 1;
    // Mark the current node as visited and print it
    visited[v] = true;
    //cout << v << " ";
 
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            count += DFSUtil(*i, visited);
    return count;
}

void Graph::printGraph()
{
    for(int v = 1; v < V; v++)
    {
        for(auto iter = adj[v].begin(); iter != adj[v].end(); iter++)
        {
            int u = *iter;
            cout << v << "-->" << u << endl;
        }
    }
}


Graph Graph::inversed()
{
    Graph newgraph(V);
    for(int u = 1; u < V;u++)
    {
        for(auto it = adj[u].begin(); it != adj[u].end(); it++)
        {
            int v = *it;
            newgraph.adj[v].push_back(u);
        }
    }
    return newgraph;
}

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
}
void Graph::fillOrdered(int v, bool *visited, stack<int> & stk)
{
    visited[v] = true;
    for(auto iter = adj[v].begin(); iter != adj[v].end();iter++)
    {
        int u = *iter;
        if(visited[u] == false)
        {
            fillOrdered(u, visited, stk);
        }
    }
    stk.push(v);
}

signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // input
    int n, m, tempu, tempv;
    cin >> n >> m;
    Graph g(n + 1);
    for(int i = 0; i<m; i++)
    {
        cin >> tempu >> tempv;
        g.addEdge(tempu, tempv);
    }
    
    stack<int> stk;
    
    //g.printGraph();
    
    bool *visited = new bool[n];
    for(int i = 0; i < g.V; i++)
        visited[i] = false;

    // 第一次 dfs
    for(int i = 1; i< g.V; i++)
    {
        if(visited[i] == false)
            g.fillOrdered(i, visited, stk);
    }
    
    // 產生一個 inversed graph
    
    Graph newg = g.inversed();
    //newg.printGraph();
    for(int i = 0; i < g.V; i++)
        visited[i] = false;
    
    vector<int> pairs;

    while(stk.empty() == false)
    {
        int v = stk.top();
        stk.pop();

        if (visited[v] == false)
        {
            int c = newg.DFSUtil(v, visited);
            pairs.push_back(c);
            
        }
    }
    int ans = 0;
    for(auto it = pairs.begin(); it != pairs.end(); it++)
    {
        int val = *it;
        if(val >=2)
        {
            ans += val*(val-1)/2 ;
            
        }
    }
    cout << ans << '\n';





    return 0;
}