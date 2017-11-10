def ramanujan(exponent):
    summs = {}
    a = 0
    while(True):
        for b in range(a):
            key = (a**exponent) + (b**exponent)
            if key not in summs:
                summs[key] = [str(a) + " + " + str(b)]
            else:
                summs[key].append(str(a) + " + " + str(b))
                return summs[key] + [key]
        a += 1

print(ramanujan(3))