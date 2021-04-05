#include "../head/SqStack.h"
#include <stdlib.h>

/**
 * @name initStack(SqStack *s,int sizes)
 * @description initialize an empty stack
 * @param s sizes
 * @return status
 */
Status initStack(SqStack *s,int sizes){
    s->elem = (ElemType *)malloc(sizeof(ElemType *));//分配空间
    if(!(s->elem))
        return ERROR;//分配失败
    s->top = -1;
    s->size=sizes;
    return SUCCESS;
}

/**
 * @name Status isEmptyStack(SqStack *s)
 * @description determine whether the stack is empty
 * @param s
 * @return status
 */
Status isEmptyStack(SqStack *s){
    if(s->top==-1)
        return ERROR;
    return SUCCESS;
}

/**
 * @name Status getTopStack(SqStack *s,ElemType *e)
 * @description get the top stack elem
 * @param s,e
 * @return status
 */
Status getTopStack(SqStack *s,ElemType *e) {
    if(s->top<0)
        return ERROR;
    *e=(s->elem)[s->top];
    return SUCCESS;
}

/**
 * @name Status clearStack(SqStack *s)
 * @description let the stack become empty
 * @param s
 * @return status
 */
Status clearStack(SqStack *s){
    if(s->top==-2)
        return ERROR;
    s->top=-1;
    return SUCCESS;
}

/**
 * @name Status destroyStack(SqStack *s)
 * @description destroy the stack
 * @param s
 * @return status
 */
Status destroyStack(SqStack *s){
    if(s->top==-2)
        return ERROR;
    s->top=-2;
    s->size=0;
    free(s->elem);
    return SUCCESS;
}

/**
 * @name Status stackLength(SqStack *s,int *length)
 * @description get the stack's length
 * @param s ,length
 * @return status
 */
Status stackLength(SqStack *s,int *length){
    if(s->top==-2)
        return ERROR;
    *length=s->top+1;
    return SUCCESS;
}

/**
 * @name Status pushStack(SqStack *s,ElemType data)
 * @description push data to the stack
 * @param s data
 * @return status
 */
Status pushStack(SqStack *s,ElemType data){
    if(s->top==-2||s->top==(s->size)-1) //未创建栈或者栈满了
        return ERROR;
    (s->elem)[++(s->top)]=data;//top增加一的同时data赋值给elem
    return SUCCESS;
}

/**
 * @name Status popStack(SqStack *s,ElemType *data)
 * @description data push
 * @param s data
 * @return status
 */
Status popStack(SqStack *s,ElemType *data){
    if(s->top<0)
        return ERROR;
    *data=s->elem[s->top--];
    return SUCCESS;
}
