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
        printf("----------ѭ������----------\n");
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
                InitAQueue(&queue);
                break;
            case 2:
                DestroyAQueue(&queue);
                break;
            case 3:
                if(IsEmptyAQueue(&queue)==TRUE){
                    printf("����Ϊ��\n");
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
                printf("���г���Ϊ%d\n",LengthAQueue(&queue));
                break;
            case 6:
                if(!queue.data[0]){
                    printf("δ��ʼ�������ȳ�ʼ����\n");
                }
                printf("����������ӵ����ݣ�\n");
                scanf("%s", d);
                EnAQueue(&queue, d);
                printf("��ӳɹ���\n");
                break;
            case 7:
                if(DeAQueue(&queue)==TRUE){
                    printf("���ӳɹ���\n");
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