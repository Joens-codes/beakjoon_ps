import sys
input = sys.stdin.readline

N = int(input())  # 배열의 크기
items = list(map(int, input().split()))  # 배열 입력
items.sort()  # 배열 정렬

count = 0
for target_sum in range(2, N+1):  # 목표 합 범위
    start_index = 0
    end_index = N - 1
    while end_index > start_index:
        sum_val = items[start_index] + items[end_index]
        if sum_val == target_sum:
            count += 1
            break
        elif sum_val > target_sum:
            end_index -= 1
        else:
            start_index += 1

print(count)
