#include<iostream>
using namespace std;

// 두 플레이어가 언제 만나는지 계산하는 함수
int prof(int N, int a, int b)
{
	int n = 0; 
	while (true)
	{
		// 두 플레이어가 바로 다음 라운드에서 만나는 조건 확인
		if (((b - a == 1) && (0 == b % 2)) || ((a - b == 1) && (0 == a % 2)))
		{
			break; 
		}

		// 플레이어 A의 다음 라운드 위치 계산
		if (0 == a % 2)
		{
			a = a / 2;
		}
		else
		{
			a = (a + 1) / 2;
		}

		// 플레이어 B의 다음 라운드 위치 계산
		if (0 == b % 2)
		{
			b = b / 2;
		}
		else
		{
			b = (b + 1) / 2;
		}

		n++; 

		// 최대 라운드를 초과하는 경우 종료
		if (N == n)
		{
			break;
		}
	}
	return n + 1; 
}

int main()
{
	int N = 0; 
	int a = 0; 
	int b = 0; 
	cin >> N; 
	cin >> a; 
	cin >> b; 

	int ans = 0;
	ans = prof(N, a, b); 
	cout << ans << endl; 
	return 0;
}