import re
with open('C:/Users/Dilshan/Desktop/Battle-System/src/Defines/generation/get_attr') as f:
     lines = f.read().splitlines()
     
filler = []
for i in range(0, len(lines)):
     m = re.search('case .*', str(lines[i]))
     k = re.search('arg = .*', str(lines[i]))
     if m:
          filler.append(str(m.group(0)).strip("case ").strip(":"))
     if k:
          filler.append(str(lines[i]).split('arg = ')[1].strip(";"))

with open('C:/Users/Dilshan/Desktop/Battle-System/src/Defines/get_attr.h', "w") as f:
     # header guards     
     f.write("#ifndef GET_ATTRIBUTE" + "\n" + 
             "#define GET_ATTRIBUTE" + "\n" +
             '#include "types.h"' + "\n")     
     
     for i in range(0, len(filler)-1, 2):
          f.write("#define " + str(filler[i]) + " " + str(filler[i+1]) + "\n")
     
     #header guards end
     f.write("\n" + "#endif /* GET_ATTRIBUTE */" + "\n")
     