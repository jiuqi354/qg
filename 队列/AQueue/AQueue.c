#include <stdio.h>
#include <string.h>
#include "../head/AQueue.h"
#include <stdlib.h>


/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q){
    if(Q->data[0]){
        printf("已初始化，请勿重复初始化\n");
        return;
    }
    int i;
    Q->length = MAXQUEUE;
    for(i = 0; i < MAXQUEUE; i++){
        Q->data[i] = (void *)malloc(sizeof datatype);//不知道有多大，先分配个大的
    }
    Q->front = Q->rear = 0;
    printf("初始化成功\n");
}


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestroyAQueue(AQueue *Q){
    if(!Q->data[0]){
        printf("未初始化队列，请先初始化！\n");
        return;
    }
    for(int i = 0; i < MAXQUEUE; i++){
        free(Q->data[i]);
    }
    Q->data[0] = NULL;
    printf("销毁成功\n");
}



/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : 检查队列是否已满
 *    @param         Q 队列指针Q
 *    @return         : 满-TRUE; 未满-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q){
    if(!Q->data[0]){
        printf("未初始化，请先初始化队列\n");
        return FALSE;
    }
    if(IsEmptyAQueue(Q)==TRUE)
        return FALSE;
    if(LengthAQueue(Q)==MAXQUEUE-1){
        return TRUE;
    }
    else
        return FALSE;
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q){
    if(!Q->data[0])
    {
        printf("未初始化，请先初始化队列\n");
        return FALSE;
    }
    if(LengthAQueue(Q)==0)
        return TRUE;
    printf("队列不为空\n");
    return FALSE;
}



/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q 队列指针Q，存放元素e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadAQueue(AQueue *Q, void *e){
    if(Q->front==-1){
        printf("未初始化队列，请先初始化！\n");
        return FALSE;
    }
    if (IsEmptyAQueue(Q))
    {
        printf("队列为空\n");
        return FALSE;
    }
    memcpy(e, Q->data[Q->front],20);
    return TRUE;
}



/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q){
    if(Q->front==-1){
        printf("未初始化，请先初始化队列！\n");
        return -1;
    }
    return (Q->rear-Q->front+Q->length)%Q->length;
}



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
 */
Status EnAQueue(AQueue *Q, void *data){
    if (IsFullAQueue(Q))
    {
        printf("队列已满\n");
        return FALSE;
    }
    if (IsEmptyAQueue(Q)==TRUE)
    {
        memcpy(Q->data[Q->front], data, 20);   //原封不动将数据复制到数组中
        Q->rear = (Q->rear + 1) % Q->length;        //空闲单元法
        return TRUE;
    }
    memcpy(Q->data[Q->rear], data, 20);
    Q->rear = (Q->rear + 1) % Q->length;
    return TRUE;
}



/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q){
    if (LengthAQueue(Q)==0)
    {
        printf("队列为空\n");
        return FALSE;
    }
    Q->front = (Q->front+1)%Q->length;
    return TRUE;
}



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q){
    if (IsEmptyAQueue(Q)==TRUE)
    {
        printf("队列已为空\n");
        return;
    }
    Q->front = Q->rear = 0;
}



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q)){
    if(!Q->data[0])
    {
        printf("未初始化，请先初始化队列\n");
        return FALSE;
    }
    if (LengthAQueue(Q)==0)
    {
        printf("队列为空\n");
        return FALSE;
    }
    int i = 0;
    while (i < (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE) {
        foo(Q->data[Q->front+i]);
        i = (i + 1) % MAXQUEUE;
    }
    printf("\n");
    return TRUE;
}



/**
 *  @name        : void APrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 *  @notice      : None
 */
void APrint(void *q){
    printf("%s->",(char*)q);
}