def find_sequence(N, L):
    for length in range(L, 101):
        total_sum = length * (length - 1) // 2
        if (N - total_sum) % length == 0:
            start = (N - total_sum) // length
            if start >= 0:
                return [start + i for i in range(length)]
    return -1

# Input handling
N, L = map(int, input().split())

# Get the result
result = find_sequence(N, L)

# Print the result
if result == -1:
    print(result)
else:
    print(" ".join(map(str, result)))