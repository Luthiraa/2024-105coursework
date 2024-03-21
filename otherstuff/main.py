element = "FeCO3"
element_dict = {}
i = 0

while i < len(element):
    if i+1 < len(element) and element[i].isupper() and element[i+1].islower():
        temp = element[i:i+2]
        i += 2
    else:
        temp = element[i]
        i += 1

    num = ''
    while i < len(element) and element[i].isdigit():
        num += element[i]
        i += 1

    if num == '':
        num = '1'

    element_dict[temp] = int(num)

print(element_dict)