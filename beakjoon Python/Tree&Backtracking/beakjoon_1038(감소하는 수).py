# 한 자리씩 쪼개어 리스트로 변환하는 함수
def inp_list(n):
    return [int(digit) for digit in str(n)]

# 입력값 N (찾으려는 N번째 감소하는 수)
N = int(input())
x = 0  # 감소하는 수 후보
cnt = 0  # 현재 감소하는 수를 찾은 개수
t = True  # 마지막 두 자릿수의 차이를 확인하기 위한 플래그

while True:
    # 목표 개수만큼 감소하는 수를 찾았다면 종료
    if cnt == N:
        break
    
    br = True  # break 조건
    
    if x < 10:  # x가 한 자리 수일 때
        x += 1  # 그냥 다음 숫자로 증가
        cnt += 1  # 감소하는 수 카운트 증가
        br = False
    else:
        # x를 리스트로 변환하여 각 자리수로 확인
        items = inp_list(x)
        for i in range(len(items) - 1):
            # 감소하는 순서를 만족하는지 확인
            if items[i] > items[i + 1]:
                continue
            else:
                # 감소 순서를 만족하지 않으면 자릿수를 맞추고 증가
                pul = 10 ** (len(items) - i - 1)
                x += pul
                x = x // pul
                x = x * pul
                br = False
                break
    
    if br:
        if t:
            x += 1  # 감소 조건을 만족하지 않으면 숫자 증가
        # 새로운 숫자를 자릿수 리스트로 변환
        h = items = inp_list(x)
        g = len(h)
        t = True
        # 마지막 두 자리의 차이를 확인
        if h[g - 1] - h[g - 2] == 0:
            t = False  # 차이가 0이면 플래그 변경
        else:
            cnt += 1  # 감소하는 수로 인정하고 카운트 증가
    
    # 감소하는 수가 가능한 최대값을 초과하면 종료
    if x > 9876543210:
        print('-1')  # 불가능한 경우
        break

# x가 유효한 감소하는 수라면 출력
if x <= 9876543210:
    print(x)