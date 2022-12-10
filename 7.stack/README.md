# 堆疊、佇列
`堆疊`\
`先進後出`\
`判斷是否為空堆疊`\
int isEmpty()\
{\
&emsp;if(top==-1)\
&emsp;{\
&emsp;&emsp;return 1;\
&emsp;}\
&emsp;else\
&emsp;{\
&emsp;&emsp;return 0;\
&emsp;}\
}\
`存放頂端資料`\
int push(int data)\
{\
&emsp;if(top>=MAXSTACK)\
&emsp;{\
&emsp;&emsp;`FALL`\
&emsp;&emsp;return 0;\
&emsp;}\
&emsp;else\
&emsp;{\
&emsp;&emsp;`ADD`\
&emsp;&emsp;return 1;\
&emsp;}\
}\
`堆疊`\
int pop()\
{\
&emsp;if(isEmpty())\
&emsp;{\
&emsp;&emsp;return -1;\
&emsp;}\
&emsp;else\
&emsp;{\
&emsp;&emsp;return stack[top--];\
&emsp;}\
}
***
`佇列`\
`先進先出`\
`新增`\
void enqueue(int item)\
{\
&emsp;if(rear==MAX_SIZE-1)\
&emsp;{\
&emsp;&emsp;`FALL`\
&emsp;}\
&emsp;else\
&emsp;{\
&emsp;&emsp;rear++;\
&emsp;&emsp;queue(rear)=item;\
&emsp;}\
}\
`刪除`\
void enqueue(int item)\
{\
&emsp;if(front==rear)\
&emsp;{\
&emsp;&emsp;`FULL`\
&emsp;}\
&emsp;else\
&emsp;{\
&emsp;&emsp;front++;\
&emsp;&emsp;item=Queue[front];\
&emsp;}\
}\
`回傳`\
void FRONT_VALUE(int *QUEUE)\
{\
&emsp;if(front==reer)\
&emsp;{\
&emsp;&emsp;`FULL`\
&emsp;}\
&emsp;else\
&emsp;{\
&emsp;&emsp;`輸出`\
&emsp;}\
}

