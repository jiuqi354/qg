#include "../head/LQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef Node* NodePtr;
/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q){
    if(Q->front){
        printf("�ѳ�ʼ���������ظ���ʼ����\n");
        return;
    }
    Q->front = (NodePtr)malloc(sizeof(Node));
    if(!Q->front){
        printf("��ʼ��ʧ��\n");              //����ʧ��
        return;
    }
    Q->length=0;
    Q->rear=Q->front;//��ʼ��Ϊ0
    printf("��ʼ���ɹ�\n");
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestroyLQueue(LQueue *Q){
    if(!Q->front){
        printf("δ��ʼ�������ȳ�ʼ����\n");
        return;}
    NodePtr ptr=Q->front;       //��ʼ��һ��ָ�����м����
    while(Q->front!=Q->rear){
    Q->front=Q->front->next;    //��ͷָ�����
    free(ptr);                  //�ͷŽ��
    ptr=Q->front;
    }
    free(Q->rear);              //�ͷ�β���
    Q->front=Q->rear=NULL;
    printf("���ٳɹ���\n");
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
    if(Q->length==0)
        return TRUE;
    return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q, void *e){
    if(!Q->front){
        printf("��δ��ʼ�����У����ʼ����\n");
        return FALSE;
    }
    if(Q->length==0){
        printf("����Ϊ��\n");
        return FALSE;}
    memcpy(e,Q->front->data,20);    //�������ݵ�eָ���λ����
    return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){                        //��Ȼע����д��Ҫ�����Ƿ�ɹ�������������ô���صĶ���Status��ͷ�������int��ͷ��
    if(!Q->front){
        printf("��δ��ʼ�����У����ʼ����\n");
        return -1;
    }
    return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data){
    if(!Q->front){
        printf("��δ��ʼ�����У����ʼ����\n");
        return FALSE;
    }
    NodePtr p=(NodePtr)malloc(sizeof(Node));
    if(!p)
        return FALSE;               //����ʧ��
    p->next=NULL;
    p->data=(void *)malloc(1024);
    memcpy(p->data,data,1024);
    if(Q->length==0){
        Q->front=Q->rear=p;
    }else{
        Q->rear->next=p;
        Q->rear=p;                      //��βָ��ָ���½��
    }
    Q->length++;
    return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
    if(!Q->front){
        printf("δ��ʼ�����У����ȳ�ʼ����\n");
        return FALSE;
    }
    if(Q->length==0){
        printf("����Ϊ�գ��޷�����\n");
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
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
    if(!Q->front&&Q->front==Q->rear){
        printf("δ��ʼ�����У����ȳ�ʼ����\n");
        return;
    }
    while(Q->length>1){
        DeLQueue(Q);
    }
    Q->length=0;
    printf("��ճɹ���\n");
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
    if(!Q->front){
        printf("δ��ʼ�����У����ȳ�ʼ����\n");
        return FALSE;
    }
    if(Q->length==0){
        printf("����Ϊ��\n");
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
 *    @description : ��������
 *    @param         q ָ��q

 *  @notice      : None
 */
void LPrint(void *q){
            printf("%s->",(char *)q);
}
