import random

# ai와 가위바위보 하기
# 마르코프 행렬 이용

array = [[0 for col in range(3)] for row in range(3)]

me = None
computer = random.randrange(1, 4)

win = 0
Lose = 0

#loop = 0

count = [0, 0, 0]


while True:
    try:
        print("------------------------------------------------")
        print("내가 이긴 횟수 : ", win, "컴퓨터가 이긴 횟수 :", Lose)

        Sciss = [array[0][0], array[0][1], array[0][2]]
        Rock = [array[1][0], array[1][1], array[1][2]]
        paper = [array[2][0], array[2][1], array[2][2]]

        df = me

        print("================================================")
        me = int(input("가위(1) 바위(2) 보(3) 중 하나를 입력하세요 : "))
        #me = random.randrange(1, 4)
        print("------------------------------------------------")

        if me > 3:
            print("잘못 입력 하였습니다.")
            continue

        if df == 1:
            cm = max(Sciss)

            if cm == 0:
                computer = random.randrange(1, 4)

            elif cm == array[0][0]:
                computer = 2

            elif cm == array[0][1]:
                computer = 3

            elif cm == array[0][2]:
                computer = 1

            if me == 1:
                array[0][0] += 1
                count[0] += 1

            elif me == 2:
                array[0][1] += 1
                count[0] = 0

            elif me == 3:
                array[0][2] += 1
                count[0] = 0

            if count[0] > 2:
                computer = 2

        # 이전에 바위를 냄
        elif df == 2:

            cm = max(Rock)

            if cm == 0:
                computer = random.randrange(1, 4)
            elif cm == array[1][0]:
                computer = 2
            elif cm == array[1][1]:
                computer = 3
            elif cm == array[1][2]:
                computer = 1

            if me == 1:
                array[1][0] += 1
                count[1] = 0

            elif me == 2:
                array[1][1] += 1
                count[1] += 1

            elif me == 3:
                array[1][2] += 1
                count[1] = 0

            if count[1] > 2:
                computer = 3

        # 이전에 보를 냄
        elif df == 3:

            cm = max(paper)

            if cm == 0:
                computer = random.randrange(1, 4)

            elif cm == array[2][0]:
                computer = 2

            elif cm == array[2][1]:
                computer = 3

            elif cm == array[2][2]:
                computer = 1

            if me == 1:
                array[2][0] += 1
                count[2] = 0

            elif me == 2:
                array[2][1] += 1
                count[2] = 0

            elif me == 3:
                array[2][2] += 1
                count[2] += 1

            if count[2] > 2:
                computer = 1

        if me == 1:
            if computer == 1:
                print("")
                print("무승부")
            elif computer == 2:
                print("")
                print("패배")
                Lose += 1
            else:
                print("")
                print("승리")
                win += 1

        elif me == 2:
            if computer == 1:
                print("")
                print("승리")
                win += 1
            elif computer == 2:
                print("")
                print("무승부")
            else:
                print("")
                print("패배")
                Lose += 1

        elif me == 3:
            if computer == 1:
                print("")
                print("패배")
                Lose += 1
            elif computer == 2:
                print("")
                print("승리")
                win += 1
            else:
                print("")
                print("무승부")

        # loop +=1
        # if loop == 1000000:
        #     break



    except:
        print("------------------------------------------------")
        print("오류, 올바른 값을 입력 하세요")
