n = int(input())
raw = []
for i in range(n):
    raw.append(input())



for i in range(n):
    quoteStart = [0]*3
    quoteEnd = [0]*3
    at = 0
    for c in range(len(raw[i])):
        if (raw[i][c] == "\""):
            if at % 2 == 0:
                quoteStart[at // 2] = c+1
            else:
                quoteEnd[at // 2] = c
            at += 1
            
    sections = []
    for k in range(at // 2):
        sections.append(raw[i][quoteStart[k]:quoteEnd[k]]) 

    words = raw[i][quoteEnd[0] + 1: quoteStart[1] - 1].strip().split(" ")

    if (words[0] == "Cut"):
        s = sections[0].replace(sections[1], "", 1)
        print("Command #%d: \"%s\"" % (i+1, s))
    
    if (words[0] == "Append"):
        print("Command #%d: \"%s\"" % (i+1,  sections[0] + sections[1]))
    
    if (words[0] == "Insert"):
        pos = int(words[1]) - 1
        print("Command #%d: \"%s\"" % (i+1, sections[0][:int(words[1])-1] + sections[1] + sections[0][int(words[1])-1:]))

    if (words[0] == "Replace"):
        print("Command #%d: \"%s\"" %(i + 1, sections[0].replace(sections[1], sections[2], 1)))
