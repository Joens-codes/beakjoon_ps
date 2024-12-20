N, K = map(int, input().split())
temp = N
additional_bottles = 0

while True:
    bin_representation = bin(temp)  # 이진 문자열로 변환
    count = bin_representation.count('1')  # '1'의 개수 세기
    if count <= K:
        break
    temp += 1
    additional_bottles += 1

print(additional_bottles)