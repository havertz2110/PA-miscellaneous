import random
import math

randomN = random.randint(1, 1000000)  # Giá trị tối thiểu và tối đa của N (~10^6)
randomNumber = random.randint(1, 10000000)  # Giá trị tối thiểu và tối đa của các phần tử trong cây

with open("logNand145logN.txt", "w") as fo:
    for i in range(1, 11):
        filename = "filedata" + str(i) + ".txt"
        with open(filename, "w") as file:
            N = randomN
            file.write(str(N) + '\n')

            if i < 3:
                uniqueNumbers = random.sample(range(1, 10000001), N)
                if i == 1:  # tăng dần / ascending
                    file.write(' '.join(map(str, sorted(uniqueNumbers))))
                else:  # giảm dần / descending
                    file.write(' '.join(map(str, sorted(uniqueNumbers, reverse=True))))
            else:  # ngẫu nhiên / random
                uniqueNumbers = random.sample(range(1, 10000001), N)
                file.write(' '.join(map(str, uniqueNumbers)))

            fo.write(str(math.log2(N)) + ' ' + str(1.45 * math.log2(N)) + '\n')
