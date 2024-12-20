#include <iostream>
#include <queue>
using namespace std;

// 그래프, 방문 여부, 거리 저장
static vector<vector<int>> A;
static vector<bool> visited;
static vector<int> ans;

// 입력 변수
static int N, M, K, X;

void BFS(int node);

int main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    cin >> N >> M >> K >> X;

    // 배열 초기화
    A.resize(N + 1);
    visited = vector<bool>(N + 1, false);
    ans.resize(N + 1, -1);

    // 간선 정보 입력
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        A[u].push_back(v);
    }

    BFS(X); // BFS 탐색

    bool found = false;
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] == K) { // 거리 K인 노드 출력
            cout << i << endl;
            found = true;
        }
    }

    if (!found) cout << "-1" << endl; // 없으면 -1 출력
    return 0;
}

void BFS(int node) {
    queue<int> pq;
    pq.push(node);
    visited[node] = true;
    ans[node] = 0;

    while (!pq.empty()) {
        int now = pq.front();
        pq.pop();

        for (int next : A[now]) {
            if (!visited[next]) {
                visited[next] = true;
                pq.push(next);
                ans[next] = ans[now] + 1;
            }
        }
    }
}