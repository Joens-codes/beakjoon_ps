#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 간선 정보 저장용 타입
typedef pair<int,int> edge;

// 전역 변수 선언
static vector<vector<edge>> A; // 그래프를 인접 리스트로 표현
static vector<bool> visited;   // 방문 여부 저장
static vector<int> m_distance; // 각 노드까지의 거리 저장

// BFS 함수: 주어진 시작 노드에서 모든 노드까지의 거리 계산
void BFS(int node);

int main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false); // 입출력 속도 향상
    int N; // 노드의 개수
    cin>>N;

    A.resize(N+1); // 노드 번호 1부터 N까지 사용
    for(int i = 0; i < N; i++) {
        int S; // 시작 노드
        cin >> S;
        while(true) {
            int E, V; // 연결된 노드와 가중치
            cin >> E;
            if(E == -1) break; // 입력 종료 조건
            cin >> V;
            A[S].push_back(edge(E,V)); // 그래프 저장
        }
    }

    m_distance = vector<int>(N+1, 0); // 거리 초기화
    visited = vector<bool>(N+1, false); // 방문 여부 초기화
    BFS(1); // 1번 노드에서 BFS 실행

    int Max = 1; // 가장 먼 노드 찾기
    for(int i = 2; i <= N; i++) {
        if(m_distance[Max] < m_distance[i]) {
            Max = i; // 최대 거리 노드 갱신
        }
    }

    fill(m_distance.begin(), m_distance.end(), 0); // 거리 초기화
    fill(visited.begin(), visited.end(), false);   // 방문 여부 초기화
    BFS(Max); // 가장 먼 노드에서 다시 BFS 실행

    sort(m_distance.begin(), m_distance.end()); // 거리 정렬
    cout << m_distance[N] << "\n"; // 트리의 지름 출력
    return 0;
}

// BFS 함수 정의
void BFS(int node) {
    queue<int> q; // BFS에 사용할 큐
    q.push(node); // 시작 노드 삽입
    visited[node] = true; // 시작 노드 방문 처리

    while (!q.empty()) {
        int current = q.front(); // 현재 노드 가져오기
        q.pop(); // 큐에서 제거

        for (auto &neighbor : A[current]) { // 현재 노드의 모든 인접 노드 확인
            int next = neighbor.first;  // 인접 노드
            int weight = neighbor.second; // 가중치
            if (!visited[next]) { // 방문하지 않은 노드만 처리
                visited[next] = true; // 방문 처리
                m_distance[next] = m_distance[current] + weight; // 거리 갱신
                q.push(next); // 인접 노드 큐에 추가
            }
        }
    }
}