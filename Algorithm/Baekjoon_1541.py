equation = input().split("-")
num = []

for i in equation:
    total = 0
    s = i.split("+")

    for j in s:
        total += int(j)
    num.append(total)
result = num[0]
for i in range(1, len(num)):
    result -= num[i]
print(result)

