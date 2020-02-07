a = int(input())
s = ""
if (a % 10 == 1):
    s = "st"
elif (a % 10 == 2):
    s = "nd"
elif (a % 10 == 3):
    s = "rd"
else:
    s = "th"

if (a % 100 == 11 or a % 100 == 12 or a % 100 == 13):
    s = "th" 
print(str(a) + s)