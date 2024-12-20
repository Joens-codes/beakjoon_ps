#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> items;

void Greedysort(int S, int N) {
    int start = 0;
    while (S > 0 && start < N) {
        auto max_val = max_element(items.begin() + start, items.end());
        int max_index = distance(items.begin(), max_val);

        if (S >= max_index - start) {
            S -= (max_index - start);
            for (int i = max_index; i > start; i--) {
                swap(items[i], items[i - 1]);
            }
            start++;
        } else {
            auto max_val = max_element(items.begin() + start, items.begin() + min(start + S + 1, N));
            int max_index = distance(items.begin(), max_val);

            if (max_index == start) {
                start++;
                continue; // 더 이상 교환할 수 없으므로 start만 증가
            }

            S -= (max_index - start);
            for (int i = max_index; i > start; i--) {
                swap(items[i], items[i - 1]);
            }
            start++;
        }
    }
}

int main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int N;
    cin >> N;
    items.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> items[i];
    }
    int S;
    cin >> S;
    Greedysort(S, N);
    for (int i = 0; i < N; i++) {
        cout << items[i] << " ";
    }
    return 0;
}