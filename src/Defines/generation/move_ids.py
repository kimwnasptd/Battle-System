import re
with open('C:/Users/Dilshan/Desktop/Battle-System/src/Defines/generation/moves') as f:
     lines = f.read().splitlines()
     
filler = []
for i in range(0, len(lines)):
     m = re.search('num: .*', str(lines[i]))
     k = re.search('name: .*', str(lines[i]))
     if m:
          filler.append(int(((str(m.group(0)).split("num: "))[1]).strip(",")))
     if k:
          filler.append(str(lines[i]).split('"')[1])

with open('C:/Users/Dilshan/Desktop/Battle-System/src/Defines/moves.h', "w") as f:
     # header guards     
     f.write("#ifndef MOVE_IDS" + "\n" + 
             "#define MOVE_IDS" + "\n" +
             "\n" + "\n")  
     
     for i in range(0, len(filler)-1, 2):
          try: 
               string = hex(filler[i])
               new_str = ""
               for char in string:
                    if (char != "x"):
                         new_str += char.capitalize()
                    else:
                         new_str += char
               f.write("#define " + str(filler[i+1]) + " " + new_str + "\n")
          except (TypeError):
               pass
    
     #header guards end
     f.write("\n" + "#endif /* MOVE_IDS */" + "\n")