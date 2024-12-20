#include <iostream>
#include <vector>
using namespace std;
int main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K; // 동전 종류와 목표 금액 입력
    vector<int> items(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> items[i]; // 각 동전의 금액 입력
    }
    int count = 0;
    for (int i = N - 1; i >= 0; i--) { // 큰 동전부터 사용
        if (items[i] <= K) {
            int subcnt = K / items[i]; // 현재 동전으로 만들 수 있는 개수
            K %= subcnt * items[i];    // 남은 금액 계산
            count += subcnt;          // 사용한 동전 개수 추가
        }
        if (K == 0) break; // 목표 금액이 완성되면 종료
    }
    cout << count << endl; // 최소 동전 개수 출력
    return 0;
}