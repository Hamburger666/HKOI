inM, inD = input().split()
inD = int(inD)

mL = {
    "JAN": 31,
    "FEB": 29,
    "MAR": 31,
    "APR": 30,
    "MAY": 31,
    "JUN": 30,
    "JUL": 31,
    "AUG": 31, 
    "SEP": 30,
    "OCT": 31,
    "NOV": 30,
    "DEC": 31
}

nM = {
    "JAN": "FEB",
    "FEB": "MAR",
    "MAR": "APR",
    "APR": "MAY",
    "MAY": "JUN",
    "JUN": "JUL",
    "JUL": "AUG",
    "AUG": "SEP", 
    "SEP": "OCT",
    "OCT": "NOV",
    "NOV": "DEC",
    "DEC": "JAN"
}

inD += 14
if (inD > mL[inM]):
    inD -= mL[inM]
    inM = nM[inM]

print(inM, inD)