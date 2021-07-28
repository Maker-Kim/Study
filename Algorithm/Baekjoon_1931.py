n = int(input())
meeting_list = [[0] * 2 for i in range(n)]
meeting_cnt = 1

for i in range(n):
    meeting_list[i][0], meeting_list[i][1] = map(int, input().split())

meeting_list.sort(key=lambda x: (x[1], x[0]))

end_time = meeting_list[0][1]

for j in range(1, n):
    if meeting_list[j][0] >= end_time:
        meeting_cnt += 1
        end_time = meeting_list[j][1]
print(meeting_cnt)
