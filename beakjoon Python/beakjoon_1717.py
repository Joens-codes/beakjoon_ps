import time
import sys
input = sys.stdin.readline
start = time.time()

N, M = map(int,input().split())
A = list(map(int,input().split()))
B = list(map(int,input().split()))
C = A[:]
for j in range(len(B)):
    for i in range(len(A)):
        A[i] += B[j]
    # 7로 나누어 떨어지는 요소를 역순으로 제거
    A = [a for a in A if a % 7 != 0]

if(len(A)==0):
    print(N)
    for i in C:
        print(i%100000007,end=' ')
else:
    print(len(A))
    for i in A:
        print(i%100000007,end=' ')

end = time.time()
print(f"{end - start:.5f} sec")