N = int(input())

bag = 0

while 0 <= N:
    if N % 5 == 0:
        bag += (N // 5)
        print(bag)
        break
    N -= 3
    bag += 1
else:
    print(-1)
