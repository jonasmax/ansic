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



#set_lan("de")
#wc_show("text.txt")