n, k = map(int, input().split())

coin = []
coin_cnt = 0

for i in range(n):
    coin.append(int(input()))

coin.sort(reverse=True)

for i in coin:
    if k == 0:
        break
    coin_cnt += k // i
    k %= i

print(coin_cnt)
