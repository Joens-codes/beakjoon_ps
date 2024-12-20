#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long min, max;
    cin >> min >> max;
    
    long long range = max - min + 1;
    
    // min ~ max 범위에서 소수의 제곱수를 제외할 배열, 처음엔 모두 false
    vector<bool> pos(range, false);
    
    // 소수 저장 벡터
    vector<long long> primes;
    
    // 에라토스테네스의 체로 소수 구하기 (1000000까지)
    char items[1000001];
    fill_n(items, 1000001, 'o');
    
    items[0] = 'x'; // 0은 소수가 아님
    items[1] = 'x'; // 1도 소수가 아님
    
    for (int i = 2; i < 1000001; i++) {
        if (items[i] != 'x') {   // i가 소수이면
            primes.push_back(i); // 소수를 저장
            for (int j = i * 2; j < 1000001; j += i) {
                items[j] = 'x';  // i의 배수들은 소수가 아님
            }
        }
    }

    // 소수의 제곱수를 찾아서 min ~ max 범위에서 제외
    for (long long i = 0; i < primes.size(); i++) {
        long long square = (long long)primes[i] * primes[i];
        
        if (square > max) {
            break;  // 제곱수가 max를 초과하면 중단
        }
        
        // min 이상에서 제곱수의 첫 배수를 찾음
        long long start = (min % square == 0) ? min : (min / square + 1) * square;
        
        // 범위 내에서 제곱수 배수를 모두 제외
        for (long long j = start; j <= max; j += square) {
            pos[j - min] = true;
        }
    }
    
    // 제곱수 배수를 제외한 수의 개수를 셈
    long long cnt = 0;
    for (long long i = 0; i < range; i++) {
        if (!pos[i]) {
            cnt++;
        }
    }
    
    long long ans = cnt;
    cout << ans << endl;
    
    return 0;
}