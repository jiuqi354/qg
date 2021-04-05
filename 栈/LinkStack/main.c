#include "../head/LinkStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str[1024],num[1024];
    ElemType e=0;
    int length=0,data;
    LinkStack s;
    s.top=NULL;
    for(;;){
    printf("-----------链栈----------\n");
    printf("0.清屏\n");
    printf("1.初始化栈\n");
    printf("2.判断栈是否为空\n");
    printf("3.得到栈顶元素\n");
    printf("4.清空栈\n");
    printf("5.销毁栈\n");
    printf("6.检测栈的长度\n");
    printf("7.入栈\n");
    printf("8.出栈\n");
    printf("9.退出\n");
    puts("请输入你的选择所对应的数字（0-9）:");
    fgets(str,2,stdin);
    /*int a=scanf("%*c%c",num);
    if(a==1){
        printf("1");
        continue;
    }*/
    switch (str[0]) {
        case '0':
            system("cls");
            break;
        case '1':
         if(!s.top){
             if(initLStack(&s)==SUCCESS){
             printf("初始化成功\n");
                 break;}
             printf("初始化失败\n");
             break;
         }
         printf("已初始化栈，请勿重复初始化\n");
            break;
        case '2':
            if(!s.top){
                printf("未初始化栈，请初始化！\n");
                break;
            }
            isEmptyLStack(&s);
            break;
        case '3':
            if(!s.top){
                printf("未初始化栈，请初始化！\n");
                break;
            }
            if(getTopLStack(&s,&e)==SUCCESS){
            printf("栈顶元素为%d\n",e);
                break;}
            printf("获取栈顶元素失败\n");
            break;
        case '4':
            if(clearLStack(&s)==SUCCESS){
                printf("清空成功\n");
                break;}
            printf("清空失败\n");
            break;
        case '5':
            destroyLStack(&s);
            printf("销毁成功\n");
            break;
        case '6':
            if(LStackLength(&s,&length)==SUCCESS){
                printf("栈长度为%d\n",length);
                break;
            }
            printf("获取长度失败\n");
            break;
        case '7':
            for(int status;;){
                printf("请输入要加入的数据,要退出请直接按a：\n");
                fflush(stdin);//清空缓存区
                strcpy(num,"");//清空数组
                scanf("%[0-9 a]",num);//接收输入的所有字符
                if(num[0]=='a'){           //如果只有回车直接结束循环
                    break;
                }
                status=sscanf(num,"%d",&data);//只接收数字,无法判断非法输入
                if(status==0){
                    puts("你的输入有误，请重新输入\n");
                    continue;}
                if(status==EOF){
                    puts("输入故障,请重新输入\n");
                    continue;
                }
                if(pushLStack(&s,data)==SUCCESS)
                puts("添加成功");
            }
            break;
        case '8':
            if(popLStack(&s,&data)==ERROR){
                printf("出栈失败\n");
                break;
            }
            printf("出栈元素为：%d\n",data);
            break;
        case '9':
            return 0;
        default:
            printf("输入错误，请重新输入\n");
            break;
        }
        strcpy(str,"");//清空数组
        fflush(stdin);
    }
}

