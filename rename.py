
import re
import os
getName =input("请输入需要创建的工程名字");
realName =getName
getName =getName.replace(' ','_')
print(getName)
pathname =os.getcwd()+'/'+getName
print("将在建立以下目录：")
print(pathname)
os.mkdir(pathname)
filename =pathname+'/'+getName+'.cpp'
F =open(filename,'x')
F.write("/*\n")
F.write("    Sologala   @github    https://github.com/Sologala/PAT_OJ\n")
F.write("    PAT_oj No.")
F.write(realName)
F.write("\n*/\n")
F.write("#include <iostream>\n#include <cstdio>\n#include <algorithm>\n#include <string>\n#include <vector>\nusing namespace std;\n\n\n\n\n\nint main(){\n\n\n\n    return 0;\n}\n")


F.close()
filename =pathname+'/'+getName+'.md'
F =open(filename,'x')
F.write("![](https://github.com/Sologala/SomeThings/blob/master/face.jpg?raw=true)\n")
F.write("/*\n")
F.write("    Sologala   @github    https://github.com/Sologala/PAT_OJ\n")
F.write("    PAT_oj No.**")
F.write(getName)
F.write("**\n*/\n")
F.write("\n\n\n\n\n\n\n\n\n### **ac_code**\n```c\n           \n```")
F.close()

