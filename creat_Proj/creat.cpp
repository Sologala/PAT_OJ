#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <time.h>
#include <windows.h>
using namespace std;
std::ofstream out;

string getTime()
{
  time_t timep;
  time (&timep);
  char tmp[64];
  strftime(tmp, sizeof(tmp), "    %Y-%m-%d %H:%M:%S",localtime(&timep) );
  return tmp;
}


int main(int argc, char const *argv[])
{
    string s;    
    getline(cin,s);
    for(int i=0;i<s.length();i++){
        if(s[i]==' '){
            s[i]='_';
        }
        if(s[i]=='\''){
            s[i]='_';
        }
    }
    string folderPath = "md .\\"+ s;
    system(folderPath.c_str());
    string  _curtime= getTime();
    
    FILE *fp;
    string filename =".\\"+s+"\\"+s+".md";
    fp=fopen(filename.c_str(),"a");
    fclose(fp);
    //д���ļ�ͷ
    out.open(filename.c_str(), std::ios::app | std::ios::out);
    out<<"![](https://github.com/Sologala/SomeThings/blob/master/face.jpg?raw=true)"<<endl;
    out<<"/*"<<endl;
    out<<"    Sologala   @github    https://github.com/Sologala/PAT_OJ"<<endl;
    out<<"    PAT_oj No.**"<<s<<"**"<<endl;
    out<<_curtime<<endl;
    out<<"*/"<<endl;
    for(int i=0;i<10;i++){
        out<<endl;
    }
    out<<"### **"<<"ac_code"<<"**"<<endl;
    out<<"```c"<<endl;
    out<<"code++++++++++"<<endl;
    out<<"```"<<endl;
   
    out.close();
    string openmarkdown ="start "+filename;
    system(openmarkdown.c_str());
    filename =".\\"+s+"\\"+s+".cpp";
    fp=fopen(filename.c_str(),"a");
    fclose(fp);
    out.open(filename.c_str(), std::ios::app | std::ios::out);
    out<<"/*"<<endl;
    out<<"    Sologala   @github    https://github.com/Sologala/PAT_OJ"<<endl;
    out<<"    PAT_oj No."<<s<<endl;
    // out<<_curtime<<endl;

    out<<"*/"<<endl;
    out<<"#include <iostream>"<<endl;
    out<<"#include <cstdio>"<<endl;
    out<<"#include <string>"<<endl;
    out<<"#include <vector>"<<endl;
    out<<"#include <algorithm>"<<endl;
    out<<"using namespace std;"<<endl<<endl;
    out<<"int main(int argc, char const *argv[]){"<<endl<<endl<<endl;
    out<<" return 0;"<<endl;
    out<<"}"<<endl;
    out.close();
    
    return 0;
}
#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <time.h>
#include <windows.h>
#define MAXPATH 256


using namespace std;
std::ofstream out;
int main(int argc, char const *argv[])
{
   
    cout<<"请输入名字！	"<<endl;
    string s;
    getline(cin,s);
    for(int i=0;i<s.length();i++){
        if(s[i]==' '){
        }
        if(s[i]=='\''){
            s[i]='_';
        }
    }
    string folderPath = "mkdir .\\"+ s;
    system(folderPath.c_str());
    
    FILE *fp;
    string filename =".\\"+s+"\\"+s+".md";
    fp=fopen(filename.c_str(),"a");
    fclose(fp);
    //–¥»ÎŒƒº˛Õ∑
    out.open(filename.c_str(), std::ios::app | std::ios::out);
    out<<"![](https://github.com/Sologala/SomeThings/blob/master/face.jpg?raw=true)"<<endl;
    out<<"/*"<<endl;
    out<<"    Sologala   @github    https://github.com/Sologala/PAT_OJ"<<endl;
    out<<"    PAT_oj No.**"<<s<<"**"<<endl;
    out<<"*/"<<endl;
    for(int i=0;i<10;i++){
        out<<endl;
    }
    out<<"### **"<<"ac_code"<<"**"<<endl;
    out<<"```c"<<endl;
    out<<"code++++++++++"<<endl;
    out<<"```"<<endl;
    
    out.close();
    string openmarkdown ="start "+filename;
    system(openmarkdown.c_str());
    filename =".\\"+s+"\\"+s+".cpp";
    fp=fopen(filename.c_str(),"a");
    fclose(fp);
    out.open(filename.c_str(), std::ios::app | std::ios::out);
    out<<"/*"<<endl;
    out<<"    Sologala   @github    https://github.com/Sologala/PAT_OJ"<<endl;
    out<<"    PAT_oj No."<<s<<endl;
    // out<<_curtime<<endl;
    
    out<<"*/"<<endl;
    out<<"#include <iostream>"<<endl;
    out<<"#include <cstdio>"<<endl;
    out<<"#include <string>"<<endl;
    out<<"#include <vector>"<<endl;
    out<<"#include <algorithm>"<<endl;
    out<<"using namespace std;"<<endl<<endl;
    out<<"int main(int argc, char const *argv[]){"<<endl<<endl<<endl;
    out<<" return 0;"<<endl;
    out<<"}"<<endl;
    out.close();
    
    return 0;
}

