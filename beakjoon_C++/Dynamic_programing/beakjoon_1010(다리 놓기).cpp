#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false); // 입출력 속도 최적화
    int T;
    cin >> T; // 테스트 케이스 수 입력

    for (int i = 0; i < T; i++) {
        int N, M;
        cin >> N >> M; // N: 선택 수, M: 전체 수

        // 이항 계수를 저장할 배열 초기화
        vector<vector<int>> items(M + 1, vector<int>(N + 1, 0));

        // 초기값 설정
        for (int i = 0; i <= M; i++) {
            items[i][0] = 1; // 아무것도 선택하지 않는 경우
        }

        // 이항 계수 계산
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                if (i == j) {
                    items[i][j] = 1; // i == j인 경우
                } else {
                    items[i][j] = items[i - 1][j - 1] + items[i - 1][j]; // 조합 공식
                }
            }
        }

        cout << items[M][N] << "\n"; // 결과 출력
    }

    return 0;
}