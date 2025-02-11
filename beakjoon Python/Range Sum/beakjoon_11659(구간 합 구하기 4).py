import sys # sys를 통한 입력
input = sys.stdin.readline
N,M = map(int,input().split())
# 들어올 숫자의 갯수, 쿼리의 수
items = list(map(int,input().split()))

sum_items = [0] #구간합 범위때문에 
sum_val = 0 # 부분 합 계산할 변수수
for i in range(len(items)):
    sum_val += items[i]
    sum_items.append(sum_val)
# M번 쿼리 처리리
for _ in range(M):
    i, j = map(int,input().split())
    print(sum_items[j] - sum_items[i - 1])
    