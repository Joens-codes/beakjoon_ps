#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static int N;
static vector<vector<int>> tree;
static int answer = 0;
static int deleteNode = 0;
static vector<bool> visited;
void DFS(int number);
int main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    cin >>N;
    visited.resize(N);
    tree.resize(N);
    int root = 0;

    for(int i = 0;i < N;i++)
    {
        int p;
        cin >> p;
        if(p != -1){
            tree[i].push_back(p);
            tree[p].push_back(i);
        }
        else
        {
            root = i;
        }
    }
    cin >> deleteNode;
    if(deleteNode == root){
        cout<<0<<"\n";
    }
    else {
        DFS(root);
        cout<< answer <<"\n";
    }
    return 0;
}

void DFS(int number) {
    visited[number] = true;
    int cNode = 0;
    for(int i: tree[number]){
        if(!visited[i] && i != deleteNode){
            cNode++;
            DFS(i);
        }
    }
    if(cNode == 0)
    {
        answer++;
    }
}