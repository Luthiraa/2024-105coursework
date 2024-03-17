element = "FeCO3"
alphabet = ['A','B','C','D','E','F','G']
key = {}
count = 0 
numbers = []

for i in range(len(element) - 1):
    if element[i].isupper() and element[i+1].islower():
        temp = element[i] + element[i+1]
        key[temp] = count
        count += 1
    elif element[i].isupper() and element[i+1].isnumeric():
        temp = element[i]
        key[temp] = count
        count += 1

if element[-1].isupper():
    temp = element[-1]
    key[temp] = count

for i in range(len(element)-1):
    if element[i].isnumeric() and element[i+1].isnumeric():
        numbers.append(str(element[i])+str(element[i+1]))
    elif element[i].isnumeric():
        numbers.append(str(element[i]))

print(numbers)
print(key)