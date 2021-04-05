#include "../head/LinkStack.h"
#include <stdio.h>
#include <stdlib.h>


/**
 *@name : Status InitStack(LinkedList *s)
 *@description : initialize an empty stack
 * @param : s
 * @return : status
 */
Status initLStack(LinkStack *s){
    s->top = (LinkStackPtr)malloc(sizeof(LinkStackPtr));
    if(!s->top)
        return ERROR;//申请失败，返回错误
    s->count=0;
    s->top->data=0;//初始化为0
    s->top->next=NULL;
    return SUCCESS;
}

/**
 *@name : Status isEmptyLStack(LinkStack *s)
 * @description : determine whether the stack is empty
 * @param : s
 * @return : status
 */
Status isEmptyLStack(LinkStack *s){
    if(s->count==0){
        printf("栈为空\n");
        return ERROR;  }//空栈返回error
    printf("栈不为空\n");
    return SUCCESS;     //存在返回success
}

/**
 *@name Status getTopLStack(LinkStack *s,ElemType *e)
 * @description get the top elem of stack
 * @param s e
 * @return status
 */
Status getTopLStack(LinkStack *s,ElemType *e){
    if(!s->top)
        return ERROR;
    *e=s->top->data;
    return SUCCESS;
}

/**
 *@name Status clearLStack(LinkStack *s)
 * @description let the stack become empty
 * @param s
 * @return status
 */
Status clearLStack(LinkStack *s){
    if(!s->top)
        return ERROR;
    LinkStackPtr p;//创建指针做中间变量
    while(s->top->next){
        p=s->top;
        s->top=s->top->next;
        free(p);
    }
    s->count=0;
    return SUCCESS;
}

/**
 *@name Status destroyLStack(LinkStack *s)
 * @description destroy the stack
 * @param s
 * @return status
 */
Status destroyLStack(LinkStack *s){
    if(!s->top)
        return ERROR;
    LinkStackPtr p=s->top;
    while (s->top){
        s->top=s->top->next;
        free(p);
        p=s->top;
    }
    return SUCCESS;
}

/**
 *@name Status LStackLength(LinkStack *s,int *length)
 * @description get the stack's length
 * @param s length
 * @return status
 */
Status LStackLength(LinkStack *s,int *length){
    if(!s)
        return ERROR;
    *length=s->count;
    return SUCCESS;
}

/**
 *@name Status pushLStack(LinkStack *s,ElemType data)
 * @description push data to the stack
 * @param s data
 * @return status
 */
Status pushLStack(LinkStack *s,ElemType data){
    if(!s||!s->top)
        return ERROR;
    StackNode *node=(StackNode *)malloc(sizeof(StackNode));
    node->data=data;
    node->next=s->top;
    s->top=node;
    s->count++;
    return SUCCESS;
}

/**
 *@name Status popLStack(LinkStack *s,ElemType *data)
 * @description pop data from the stack
 * @param s data
 * @return status
 */
Status popLStack(LinkStack *s,ElemType *data){
    if(!s||!s->top)
        return ERROR;
    LinkStackPtr p;
    *data=s->top->data;
    p=s->top;
    s->top=s->top->next;
    free(p);
    s->count--;
    return SUCCESS;
}
