# 函數
`傳值呼叫`\
int f(int i)\
{\
&emsp;return i+1;\
}\
跟f(x)=x+1一樣\
`傳址呼叫`\
int f(*i);\
int f(int &i)\
{\
&emsp;return i+1;\
}
***
`遞迴`\
int f(int i)\
{\
&emsp;if(i>0)\
&emsp;{\
&emsp;&emsp;return f(i)+i;\
&emsp;}\
&emsp;else\
&emsp;{\
&emsp;&emsp;return 0;\
&emsp;}\
}\
類迴圈 自己回傳自己


