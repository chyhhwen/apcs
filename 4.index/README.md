# 指標與結構與串列
`int *a;`指標宣告\
`&a` a的記憶體位址
***
`結構宣告`\
struct a\
{\
`宣告成員`\
&emsp;int id;\
&emsp;char name[max];\
}\
`struct a obj;`宣告物件\
`obj.id;`引用物件
***
`單向節點`
新節點插入第一個節點前，成為此串首節點\
`newnode->next=first;`\
`first-=newnode;`\
新節點插入最後一個節點\
`ptr->next=newnode;`\
`newnode->next=NULL;`\
新節點插入中間位置\
`newnode->next=x->next;`\
`x->next=newnode;`\
刪除第一節點\
`top=head;`\
`head=head->next;`\
`free(top);`\
刪除最後節點\
`ptr->next=tail;`\
`ptr->next=NULL;`\
`free(tail);`\
刪除中間節點\
`Y=ptr->next;`\
`ptr->next=Y->next;`\
`free(Y);`
***
`環狀串列`\
新節點插入第一個節點前，成為此串首節點\
`x->next=head;`\
`CurNode=head;`\
`while(CurNode->next!=head)`\
`CurNode=CurNode->next;`\
`CurNode->next=x;`\
`head=x;`\
新節點X插入任意節點I\
`X->next=I->next;`\
`I->=X;`\
刪除節點\
`CurNode=head;`\
`while(CurNode->next!=head)`\
`CurNode=CurNode->next;`\
`TaiNode=CurNode;`\
`head=head->next;`\
`TailNode->next=head;`
***
不懂 找打雜工畫圖






