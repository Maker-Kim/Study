N = int(input())
result = 0

while True:
    time = list(map(int, input().split()))
    if len(time) == N:
        break
    else:
        print("Try again")

time.sort(reverse=False)
result += time[0]

for i in range(1, len(time), 1):
    time[i] += time[i - 1]
    result += time[i]

print(result)
