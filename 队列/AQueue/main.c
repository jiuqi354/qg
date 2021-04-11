#include <string.h>
#include "../head/AQueue.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
    char str[1024];
    int num;
    char d[1024];
    AQueue queue;
    queue.front=queue.rear=-1;
    queue.length=-1;
    void *e=NULL;
    for(;;){
        printf("----------循环队列----------\n");
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
                InitAQueue(&queue);
                break;
            case 2:
                DestroyAQueue(&queue);
                break;
            case 3:
                if(IsEmptyAQueue(&queue)==TRUE){
                    printf("队列为空\n");
                    break;
                }
                break;
            case 4:
                GetHeadAQueue(&queue,e);
                puts((char *)e);
                break;
            case 5:
                if(LengthAQueue(&queue)==-1){
                    break;
                }
                printf("队列长度为%d\n",LengthAQueue(&queue));
                break;
            case 6:
                if(!queue.data[0]){
                    printf("未初始化，请先初始化！\n");
                }
                printf("请输入想入队的数据：\n");
                scanf("%s", d);
                EnAQueue(&queue, d);
                printf("入队成功！\n");
                break;
            case 7:
                if(DeAQueue(&queue)==TRUE){
                    printf("出队成功！\n");
                }
                break;
            case 8:
                ClearAQueue(&queue);
                break;
            case 9:
                TraverseAQueue(&queue,&APrint);
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