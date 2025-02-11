N = int(input())
items = list(map(int,input().split()))
max_val = max(items)
sum_val = sum(items)
sum_val = sum_val / N
ans = sum_val / max_val
print(ans)
