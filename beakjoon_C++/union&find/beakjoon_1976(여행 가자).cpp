#include <iostream>
#include <vector>
using namespace std;

static vector<int> parent; // 각 노드의 부모를 저장하는 Union-Find 구조

// 두 노드를 연결하는 함수 (Union 연산)
void Union(int a, int b);
// 특정 노드의 루트 노드를 찾는 함수 (Find 연산)
int find(int a);

int main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false); // 입력 속도 최적화

    int N, M;
    cin >> N >> M; // N: 도시 수, M: 여행 계획에 포함된 도시 수

    vector<vector<int>> node(N + 1, vector<int>(N + 1, 0)); // 인접 행렬 저장
    parent.resize(N + 1); // 부모 배열 크기 설정

    // 부모 배열 초기화 (자기 자신이 부모)
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    vector<int> travel(M); // 여행 계획을 저장할 배열

    // 인접 행렬 입력
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> node[i][j];
        }
    }

    // 여행 계획 입력
    for (int j = 0; j < M; j++) {
        cin >> travel[j];
    }

    // 인접 행렬로 Union-Find 연산 수행 (도시 연결 처리)
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (node[i][j] == 1) { // 두 도시가 연결되어 있으면
                Union(i, j);       // Union 연산 수행
            }
        }
    }

    // 여행 계획의 도시들이 같은 집합에 속해 있는지 확인
    bool is_true = true;
    for (int i = 0; i < M - 1; i++) {
        if (find(travel[i]) != find(travel[i + 1])) { // 집합이 다르면 NO
            is_true = false;
            break;
        }
    }

    // 결과 출력
    if (is_true) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}

// 두 노드 a, b를 같은 집합으로 묶는 함수
void Union(int a, int b) {
    a = find(a); // a의 루트 찾기
    b = find(b); // b의 루트 찾기
    if (a != b) {
        parent[b] = a; // 루트를 병합
    }
}

// 특정 노드의 루트를 찾는 함수 (경로 압축 사용)
int find(int a) {
    if (a == parent[a]) { // 자기 자신이 루트인 경우
        return a;
    } else {
        return parent[a] = find(parent[a]); // 경로 압축
    }
}