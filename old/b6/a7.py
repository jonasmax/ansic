def unzip(zippt):
    return zip(*zippt)

print(list(unzip(list(zip((1,2,3,4), (5,6), (7,8))))) == [(1,2), (5,6), (7,8)])
print(list(unzip(list(unzip([(1,2), (3,4), (5,6)])))) == [(1,2), (3,4), (5,6)])