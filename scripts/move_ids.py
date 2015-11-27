import re
with open('C:/Users/Dilshan/Desktop/new.html') as f:
     lines = f.read().splitlines()
     
filler = []
for i in range(0, len(lines)):
     m = re.search('num: .*', str(lines[i]))
     k = re.search('name: .*', str(lines[i]))
     if m:
          filler.append(int(((str(m.group(0)).split("num: "))[1]).strip(",")))
     if k:
          filler.append(str(lines[i]).split('"')[1])

with open('C:/Users/Dilshan/Desktop/output.txt', "w") as f:
     for i in range(0, len(filler)-1, 2):
          f.write("#define " + str(filler[i+1]) + " " + str(filler[i]) + "\n")
