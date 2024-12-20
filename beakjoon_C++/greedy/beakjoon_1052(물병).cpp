#include <iostream>
#include <bitset>
using namespace std;

int minBottlesToBuy(int N, int K) {
    int count = 0;
    while (__builtin_popcount(N) > K) {
        // N에 1을 추가하여 이진수에서 1의 개수를 줄이기
        N += 1;
        count += 1;
    }
    return count;
}

int main() {
    int N, K;
    cin >> N >> K;

    // 최소 추가 물병 개수 출력
    cout << minBottlesToBuy(N, K) << endl;

    return 0;
}