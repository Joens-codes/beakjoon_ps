#include<iostream>
#include<cmath>
using namespace std;

// 두 점과 원이 포함되는지 여부를 판단하는 함수
bool inout(int x1, int x2, int y1, int y2, int x, int y, int r)
{
    double sdist, adist;

    // x1, y1에서 (x, y)까지의 거리 계산
    sdist = sqrt(pow((x1 - x), 2) + pow((y1 - y), 2));
    // x2, y2에서 (x, y)까지의 거리 계산
    adist = sqrt(pow((x2 - x), 2) + pow((y2 - y), 2));

    // 두 점이 원 안에 포함되면 false 반환, 그렇지 않으면 true 반환
    if ((adist < r) && (sdist < r))
        return false; // 두 점이 원 안에 포함됨
    else if ((adist < r) && (sdist > r))
        return true;  // 한 점만 원 안에 포함됨
    else if ((adist > r) && (sdist < r))
        return true;  // 한 점만 원 안에 포함됨
    else
        return false; // 두 점이 모두 원 밖에 있음
}

int main()
{
    int T;
    int x1, y1, x2, y2;
    cin >> T; // 테스트 케이스 개수 입력

    for (int i = 0; i < T; i++)
    {
        cin >> x1 >> y1; // 첫 번째 점 (x1, y1)
        cin >> x2 >> y2; // 두 번째 점 (x2, y2)

        int n;
        cin >> n; // 원의 개수 입력
        int count = 0;

        // 각 원에 대해 점이 포함되는지 검사
        for (int i = 0; i < n; i++)
        {
            int x, y, r;
            cin >> x >> y >> r; // 원의 중심 (x, y)와 반지름 r 입력
            if (inout(x1, x2, y1, y2, x, y, r)) // 점이 원에 포함되면 count 증가
            {
                count++;
            }
        }

        cout << count << endl; // 결과 출력
    }

    return 0;
}