kubik = [x**3 for x in range(1,10) if x**3 % 2 != 0]
teiler = lambda z: [x for x in range(2,z-1) if z%x == 0]
primzahlen = [x for x in range(10000, 10100) if teiler(x) == []]
print(primzahlen)