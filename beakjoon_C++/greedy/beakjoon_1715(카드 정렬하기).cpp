#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int N;
    cin >> N; // 카드 묶음 개수 입력
    priority_queue<int, vector<int>, greater<int>> q; // 최소 힙 선언
    for (int i = 0; i < N; i++) {
        int card;
        cin >> card; // 각 카드 묶음 크기 입력
        q.push(card);
    }
    int sum = 0;
    while (q.size() != 1) { // 카드 묶음이 하나가 될 때까지 반복
        int data1 = q.top(); q.pop(); // 가장 작은 두 묶음 선택
        int data2 = q.top(); q.pop();
        sum += (data1 + data2); // 합친 비용 누적
        q.push(data1 + data2); // 새로 합친 묶음을 힙에 추가
    }
    cout << sum << "\n"; // 총 비용 출력
    return 0;
}