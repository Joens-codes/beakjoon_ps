#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

// 두 원의 관계를 계산하는 함수
int cal(int x1, int y1, double r1, int x2, int y2, double r2)
{
	int ans = 0;

	// 두 원이 동일한 경우
	if ((x1 == x2) && (y1 == y2) && (r1 == r2))
		return ans = -1;

	// 중심은 같지만 반지름이 다른 경우
	if ((x1 == x2) && (y1 == y2) && (r1 != r2))
		return ans = 0;

	// 두 원의 중심 거리와 반지름 비교
	double a = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	double ma = max({ r1, r2, a });
	double mi = min({ r1, r2, a });
	double md = r1 + r2 + a - ma - mi;

	if (ma == mi + md) return ans = 1; // 외접
	if (ma > mi + md) return ans = 0;  // 교점 없음
	if (ma < mi + md) return ans = 2;  // 두 점에서 교차
}

int main()
{
	int T;
	cin >> T; // 테스트 케이스 개수
	int x1, y1, x2, y2;
	double r1, r2;

	// 각 테스트 케이스 처리
	for (int i = 0; i < T; i++)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		cout << cal(x1, y1, r1, x2, y2, r2) << endl;
	}
	return 0;
}