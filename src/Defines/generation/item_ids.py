import re
with open('C:/Users/Dilshan/Desktop/Battle-System/src/Defines/generation/items') as f:
     lines = f.read().splitlines()

with open('C:/Users/Dilshan/Desktop/Battle-System/src/Defines/items.h', "w") as f:
     # header guards     
     f.write("#ifndef ITEM_IDS" + "\n" + "#define ITEM_IDS" + "\n"*3)  
     for line in lines:
          hex_val = hex(int(line.split("\t")[0]))
          new_str = ""
          for char in hex_val:
               if (char != "x"):
                    new_str += char.capitalize()
               else:
                    new_str += char
          f.write("#define " + (line.split("\t")[2]).upper().replace(" ", "_").replace("-", "_").replace(".", "").replace("'","")
                  + " " + new_str + "\n")

     #header guards end
     f.write("\n" + "#endif /* ITEM_IDS */" + "\n")