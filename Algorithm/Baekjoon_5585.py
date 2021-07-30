price = int(input())

change = 1000 - price

money_list = [500, 100, 50, 10, 5, 1]

money_cnt = 0

for i in money_list:
    money_cnt += change // i
    change = change % i

print(money_cnt)
