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
        printf("----------��ʽ����----------\n");
        printf("1.��ʼ������\n");
        printf("2.���ٶ���\n");
        printf("3.�ж϶����Ƿ�Ϊ��\n");
        printf("4.�鿴��ͷԪ��\n");
        printf("5.ȷ�϶��г���\n");
        printf("6.���\n");
        printf("7.����\n");
        printf("8.��ն���\n");
        printf("9.��������\n");
        printf("10.�����Ļ\n");
        printf("11.�˳�\n");
        printf("���������ѡ������Ӧ�����֣�1-11��:\n");
        gets(str);
        if(strlen(str)>2){
            printf("��������ȷ�����֣�\n");
            strcpy(str,"");             //�������
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
                    printf("����Ϊ��\n");
                    break;
                }
                printf("���в�Ϊ��\n");
                break;
            case 4:
                GetHeadLQueue(&queue,e);
                puts((char *)e);
                break;
            case 5:
                if(LengthLQueue(&queue)==-1){
                    break;
                }
                printf("���г���Ϊ%d\n",LengthLQueue(&queue));
                break;
            case 6:
                if(!queue.front){
                    printf("δ��ʼ�������ȳ�ʼ����\n");
                }
                /*printf("�������ʲô���ͣ���\n");
                printf("1. ���� 2. �ַ��� 3. ������ 4. �ַ���\n");
                printf("���������ѡ������Ӧ�����֣�\n");
                gets(str);
                if(strlen(str)>1){
                    printf("��������ȷ�����֣�\n");
                    strcpy(str,"");             //�������
                    continue;
                }
                num=0;
                sscanf(str,"%d",&num);*/
                printf("����������ӵ����ݣ�\n");
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
                 printf("��������ȷ�����֣�\n");
         }*/
                printf("��ӳɹ���\n");
                break;
            case 7:
                if(DeLQueue(&queue)==TRUE){
                    printf("���ӳɹ���\n");
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