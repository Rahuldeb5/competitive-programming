t = int(input())
while(t > 0):
    lis = []
    n = int(input())
    for a in range(1, 10001):
        maxB = len(str(n))*a
        minB = max(1, len(str(n))*a - 5)

        for b in range(minB, maxB):
            x = n * a - b
            y = 0

            for i in range(len(str(n)) * a - b):
                y = y * 10 + int((str(n))[i % len(str(n))])
            if(x == y):
                lis.append((a, b))

    print(len(lis))
    for i in lis:
        print(*i)

    t -= 1
