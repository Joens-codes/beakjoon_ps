#include<iostream>
#include<vector>
using namespace std;
static vector<vector<int> > A;
static vector<bool> visited;
void DFS(int node);

int main()
{
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int V,E;
    cin>>V>>E;
    A.resize(V+1);
    for(int i = 0;i < E;i++)
        {
            int u,v;
            cin>> u>>v;
            A[v].push_back(u);
            A[u].push_back(v);
        }
    visited = vector<bool>(V+1,false);
    int count = 0;
    for(int i = 1;i <= V;i++)
        {
            if(!visited[i]){
                count++;
                DFS(i);
            }
        }
 cout<< count <<"\n";
    return 0;
}
void DFS(int node)
{
    visited[node] = true;
    for(int i:A[node])
        {
            if(!visited[i])
            {
                DFS(i);
            }
        }
}