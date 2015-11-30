import re
with open('C:/Users/Dilshan/Desktop/Battle-System/src/Defines/generation/pokemon') as f:
     lines = f.read().splitlines()

with open('C:/Users/Dilshan/Desktop/Battle-System/src/Defines/pokemon.h', "w") as f:
     # header guards     
     f.write("#ifndef POKEMON_IDS_H" + "\n" + "#define POKEMON_IDS_H" + "\n"*3)  
     for line in lines:
          hex_val = hex(int(line.split("\t")[0]))
          new_str = ""
          for char in hex_val:
               if (char != "x"):
                    new_str += char.capitalize()
               else:
                    new_str += char
          poke_name = ((line.split("\t")[1]).upper().replace(" ","_")
                       .replace("-", "_").replace(".", "").replace("'","")
                       .replace("†", ""))
          m = re.search('.*[0-9*]]', poke_name)
          if m:
               #filler.append(str(m.group(0)).strip("case ").strip(":"))
               poke_name = m.group(0).split("[")[0]
          
          
          f.write("#define " + poke_name + " " + new_str + "\n")

     #header guards end
     f.write("\n" + "#endif /* POKEMON_IDS_H */" + "\n")