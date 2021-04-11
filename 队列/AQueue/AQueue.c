#include <stdio.h>
#include <string.h>
#include "../head/AQueue.h"
#include <stdlib.h>


/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q){
    if(Q->data[0]){
        printf("�ѳ�ʼ���������ظ���ʼ��\n");
        return;
    }
    int i;
    Q->length = MAXQUEUE;
    for(i = 0; i < MAXQUEUE; i++){
        Q->data[i] = (void *)malloc(sizeof datatype);//��֪���ж���ȷ�������
    }
    Q->front = Q->rear = 0;
    printf("��ʼ���ɹ�\n");
}


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestroyAQueue(AQueue *Q){
    if(!Q->data[0]){
        printf("δ��ʼ�����У����ȳ�ʼ����\n");
        return;
    }
    for(int i = 0; i < MAXQUEUE; i++){
        free(Q->data[i]);
    }
    Q->data[0] = NULL;
    printf("���ٳɹ�\n");
}



/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : �������Ƿ�����
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q){
    if(!Q->data[0]){
        printf("δ��ʼ�������ȳ�ʼ������\n");
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
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q){
    if(!Q->data[0])
    {
        printf("δ��ʼ�������ȳ�ʼ������\n");
        return FALSE;
    }
    if(LengthAQueue(Q)==0)
        return TRUE;
    printf("���в�Ϊ��\n");
    return FALSE;
}



/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q ����ָ��Q�����Ԫ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadAQueue(AQueue *Q, void *e){
    if(Q->front==-1){
        printf("δ��ʼ�����У����ȳ�ʼ����\n");
        return FALSE;
    }
    if (IsEmptyAQueue(Q))
    {
        printf("����Ϊ��\n");
        return FALSE;
    }
    memcpy(e, Q->data[Q->front],20);
    return TRUE;
}



/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : ���г���count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q){
    if(Q->front==-1){
        printf("δ��ʼ�������ȳ�ʼ�����У�\n");
        return -1;
    }
    return (Q->rear-Q->front+Q->length)%Q->length;
}



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ����˻�Ϊ��
 */
Status EnAQueue(AQueue *Q, void *data){
    if (IsFullAQueue(Q))
    {
        printf("��������\n");
        return FALSE;
    }
    if (IsEmptyAQueue(Q)==TRUE)
    {
        memcpy(Q->data[Q->front], data, 20);   //ԭ�ⲻ�������ݸ��Ƶ�������
        Q->rear = (Q->rear + 1) % Q->length;        //���е�Ԫ��
        return TRUE;
    }
    memcpy(Q->data[Q->rear], data, 20);
    Q->rear = (Q->rear + 1) % Q->length;
    return TRUE;
}



/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q){
    if (LengthAQueue(Q)==0)
    {
        printf("����Ϊ��\n");
        return FALSE;
    }
    Q->front = (Q->front+1)%Q->length;
    return TRUE;
}



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q){
    if (IsEmptyAQueue(Q)==TRUE)
    {
        printf("������Ϊ��\n");
        return;
    }
    Q->front = Q->rear = 0;
}



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q)){
    if(!Q->data[0])
    {
        printf("δ��ʼ�������ȳ�ʼ������\n");
        return FALSE;
    }
    if (LengthAQueue(Q)==0)
    {
        printf("����Ϊ��\n");
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
 *    @description : ��������
 *    @param         q ָ��q
 *  @notice      : None
 */
void APrint(void *q){
    printf("%s->",(char*)q);
}