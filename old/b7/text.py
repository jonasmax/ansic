import re

lan = "de"

def chars(text):
    ch = re.findall("[a-zA-Z]", text)
    return len(ch)

def words(text):
    return len(text.split())

def lines(text):
    return len(text.splitlines())

def set_lan(l):
    if(l == "de" or l == "en"):
        global lan
        lan = l

def wc(file):
    text = open(file, "r").read()
    c = chars(text)
    w = words(text)
    l = lines(text)
    return { "letter":c, "words":w, "lines":l }

def wc_show(file):
    results = wc(file)
    if(lan == "de"):
        print("Buchstaben: " + str(results["letter"]))
        print("Woerter: " + str(results["words"]))
        print("Zeilen: " + str(results["lines"]))
    else:
        print("Letters: " + str(results["letter"]))
        print("Words: " + str(results["words"]))
        print("Lines: " + str(results["lines"]))

def count_words(d):
    d = d.read()
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
    d = d.read()
    words = re.sub(r'\W', '', d)
    words = list(words)
    return count(words)



