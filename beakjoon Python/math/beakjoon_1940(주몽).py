import sys
input = sys.stdin.readline

N = int(input())
M = int(input())
items = list(map(int, input().split()))
items.sort()

count = 0
i, j = 0, N - 1

while i < j:
    current_sum = items[i] + items[j]
    if current_sum < M:
        i += 1
    elif current_sum > M:
        j -= 1
    else:
        count += 1
        i += 1
        j -= 1

print(count)