text = input("Escribe el texto: ")
n = len(text)
output = ""
for i in range(n):
    c = ord(text[i]) - 96
    c = (c*2) % 26
    if(c == 0):
        c += 1
    output += chr(c+96)

print(output)
