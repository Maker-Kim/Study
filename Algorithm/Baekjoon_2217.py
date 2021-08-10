N = int(input())
rope = []
value = []

for i in range(N):
    rope.append(int(input()))

rope.sort(reverse=True)

for j in range(N):
    value.append(rope[j] * (j + 1))
print(max(value))
