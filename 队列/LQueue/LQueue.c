#include "../head/LQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef Node* NodePtr;
/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q){
    if(Q->front){
        printf("已初始化，请勿重复初始化！\n");
        return;
    }
    Q->front = (NodePtr)malloc(sizeof(Node));
    if(!Q->front){
        printf("初始化失败\n");              //申请失败
        return;
    }
    Q->length=0;
    Q->rear=Q->front;//初始化为0
    printf("初始化成功\n");
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestroyLQueue(LQueue *Q){
    if(!Q->front){
        printf("未初始化，请先初始化！\n");
        return;}
    NodePtr ptr=Q->front;       //初始化一个指针做中间变量
    while(Q->front!=Q->rear){
    Q->front=Q->front->next;    //将头指针后移
    free(ptr);                  //释放结点
    ptr=Q->front;
    }
    free(Q->rear);              //释放尾结点
    Q->front=Q->rear=NULL;
    printf("销毁成功！\n");
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
    if(Q->length==0)
        return TRUE;
    return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void *e){
    if(!Q->front){
        printf("尚未初始化队列，请初始化！\n");
        return FALSE;
    }
    if(Q->length==0){
        printf("队列为空\n");
        return FALSE;}
    memcpy(e,Q->front->data,20);    //复制数据到e指向的位置里
    return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){                        //虽然注释里写着要返回是否成功，但是其他这么返回的都是Status开头的这个是int开头的
    if(!Q->front){
        printf("尚未初始化队列，请初始化！\n");
        return -1;
    }
    return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data){
    if(!Q->front){
        printf("尚未初始化队列，请初始化！\n");
        return FALSE;
    }
    NodePtr p=(NodePtr)malloc(sizeof(Node));
    if(!p)
        return FALSE;               //分配失败
    p->next=NULL;
    p->data=(void *)malloc(1024);
    memcpy(p->data,data,1024);
    if(Q->length==0){
        Q->front=Q->rear=p;
    }else{
        Q->rear->next=p;
        Q->rear=p;                      //队尾指针指向新结点
    }
    Q->length++;
    return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
    if(!Q->front){
        printf("未初始化队列，请先初始化！\n");
        return FALSE;
    }
    if(Q->length==0){
        printf("队列为空，无法出队\n");
        return FALSE;
    }
    if(Q->length==1){
        Q->length=0;
        return TRUE;
    }
    NodePtr p=Q->front->next;
    free(Q->front);
    Q->front=p;
    Q->length--;
    return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
    if(!Q->front&&Q->front==Q->rear){
        printf("未初始化队列，请先初始化！\n");
        return;
    }
    while(Q->length>1){
        DeLQueue(Q);
    }
    Q->length=0;
    printf("清空成功！\n");
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
    if(!Q->front){
        printf("未初始化队列，请先初始化！\n");
        return FALSE;
    }
    if(Q->length==0){
        printf("队列为空\n");
        return FALSE;
    }
    Node *p=Q->front;
    int i=0;
    for(i=0;i<Q->length;i++){
        foo(p->data);
        p=p->next;
    }
    printf("\n");
    return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q

 *  @notice      : None
 */
void LPrint(void *q){
            printf("%s->",(char *)q);
}
