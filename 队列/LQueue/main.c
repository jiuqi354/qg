#include "../head/LQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*enum {
    CHAR=1,
    INT=2,
    DOUBLE=3,
    STRING=4
};*/
int main(){
    char str[1024];
    int num;/*,a;
    double b;
    char c;*/
    char d[1024];
    LQueue queue;
    queue.front=queue.rear=NULL;
    void *e=NULL;
    for(;;){
        printf("----------链式队列----------\n");
        printf("1.初始化队列\n");
        printf("2.销毁队列\n");
        printf("3.判断队列是否为空\n");
        printf("4.查看队头元素\n");
        printf("5.确认队列长度\n");
        printf("6.入队\n");
        printf("7.出队\n");
        printf("8.清空队列\n");
        printf("9.遍历队列\n");
        printf("10.清空屏幕\n");
        printf("11.退出\n");
        printf("请输入你的选择所对应的数字（1-11）:\n");
        gets(str);
        if(strlen(str)>2){
            printf("请输入正确的数字！\n");
            strcpy(str,"");             //清空数组
            continue;
        }
        sscanf(str,"%d",&num);
        strcpy(str,"");
        switch (num) {
            case 1:
                InitLQueue(&queue);
                break;
            case 2:
                DestroyLQueue(&queue);
                break;
            case 3:
                if(IsEmptyLQueue(&queue)==TRUE){
                    printf("队列为空\n");
                    break;
                }
                printf("队列不为空\n");
                break;
            case 4:
                GetHeadLQueue(&queue,e);
                puts((char *)e);
                break;
            case 5:
                if(LengthLQueue(&queue)==-1){
                    break;
                }
                printf("队列长度为%d\n",LengthLQueue(&queue));
                break;
            case 6:
                if(!queue.front){
                    printf("未初始化，请先初始化！\n");
                }
                /*printf("你想入队什么类型？：\n");
                printf("1. 整型 2. 字符型 3. 浮点型 4. 字符串\n");
                printf("请输入你的选择所对应的数字：\n");
                gets(str);
                if(strlen(str)>1){
                    printf("请输入正确的数字！\n");
                    strcpy(str,"");             //清空数组
                    continue;
                }
                num=0;
                sscanf(str,"%d",&num);*/
                printf("请输入想入队的数据：\n");
                /*switch (num) {
                    case 1:*/
                        scanf("%s", d);
                        EnLQueue(&queue, d);
                /* datatype[queue.length-1]=INT;
             case 2:
                 scanf("%s", d);
                 EnLQueue(&queue, d);
                 datatype[queue.length-1]=DOUBLE;
                 break;
             case 3:
                 scanf("%s", d);
                 EnLQueue(&queue, d);
                 datatype[queue.length-1]=CHAR;
                 break;
             case 4:
                 scanf("%s", d);
                 EnLQueue(&queue, d);
                 datatype[queue.length-1]=STRING;
                 break;
             default:
                 printf("请输入正确的数字！\n");
         }*/
                printf("入队成功！\n");
                break;
            case 7:
                if(DeLQueue(&queue)==TRUE){
                    printf("出队成功！\n");
                }
                break;
            case 8:
                ClearLQueue(&queue);
                break;
            case 9:
                TraverseLQueue(&queue,&LPrint);
                break;
            case 10:
                system("cls");
                break;
            case 11:
                return 0;
            default:
                break;
        }
        fflush(stdin);
    }
}