import re
def count_words(d):
    words = re.sub(r'\W',' ', d)
    words = words.split()
    return count(words)

def count(elems):
    dic = {}
    for elem in elems:
        if elem in dic:
            dic[elem] += 1
        else:
            dic[elem] = 1
    return dic

def count_chars(d):
    words = re.sub(r'\W', '', d)
    words = list(words)
    return count(words)


d = open("text.txt").read()
