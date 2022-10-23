# 函數
`傳值呼叫`\
int f(int i)\
{\
return i+1;\
}\
跟f(x)=x+1一樣\
`傳址呼叫`\
int f(*i);\
int f(int &i)\
{\
return i+1;\
}
***
`遞迴`\
int f(int i)\
{\
if(i>0)\
{\
return f(i)+i;\
}\
else\
{\
return 0;\
}\
}\
類迴圈 自己回傳自己


