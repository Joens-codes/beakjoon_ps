#include <iostream>
#include <vector>
#include <queue>
using namespace std;
static vector<vector<int>> A;
static vector<bool> visited;
static vector<int> ans;
void BFS(int node);
int main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int N;
    cin >> N;
    A.resize(N+1);
    ans.resize(N+1,0);
    visited = vector<bool>(N+1,false);
    for(int i = 1;i < N+1;i++)
        {
            int u,v;
            cin>>u>>v;
            A[u].push_back(v);
            A[v].push_back(u);
        }
    BFS(1);
    for(int i = 0;i < N+1;i++)
        {
            if(ans[i]!=0)
            {
                cout<<ans[i]<<"\n";
            }
        }
    return 0;
}
void BFS(int node)
{
  queue<int> pq;
    visited[node] = true;
    pq.push(node);

    while(!pq.empty())
        {
            int now_node = pq.front();
            pq.pop();
            for(int i:A[now_node])
                {
                    if(!visited[i])
                    {
                        visited[i] = true;
                        pq.push(i);
                        ans[i] = now_node;
                        
                    }
                }
        }
    
}