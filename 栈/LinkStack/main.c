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
    printf("-----------��ջ----------\n");
    printf("0.����\n");
    printf("1.��ʼ��ջ\n");
    printf("2.�ж�ջ�Ƿ�Ϊ��\n");
    printf("3.�õ�ջ��Ԫ��\n");
    printf("4.���ջ\n");
    printf("5.����ջ\n");
    printf("6.���ջ�ĳ���\n");
    printf("7.��ջ\n");
    printf("8.��ջ\n");
    printf("9.�˳�\n");
    puts("���������ѡ������Ӧ�����֣�0-9��:");
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
             printf("��ʼ���ɹ�\n");
                 break;}
             printf("��ʼ��ʧ��\n");
             break;
         }
         printf("�ѳ�ʼ��ջ�������ظ���ʼ��\n");
            break;
        case '2':
            if(!s.top){
                printf("δ��ʼ��ջ�����ʼ����\n");
                break;
            }
            isEmptyLStack(&s);
            break;
        case '3':
            if(!s.top){
                printf("δ��ʼ��ջ�����ʼ����\n");
                break;
            }
            if(getTopLStack(&s,&e)==SUCCESS){
            printf("ջ��Ԫ��Ϊ%d\n",e);
                break;}
            printf("��ȡջ��Ԫ��ʧ��\n");
            break;
        case '4':
            if(clearLStack(&s)==SUCCESS){
                printf("��ճɹ�\n");
                break;}
            printf("���ʧ��\n");
            break;
        case '5':
            destroyLStack(&s);
            printf("���ٳɹ�\n");
            break;
        case '6':
            if(LStackLength(&s,&length)==SUCCESS){
                printf("ջ����Ϊ%d\n",length);
                break;
            }
            printf("��ȡ����ʧ��\n");
            break;
        case '7':
            for(int status;;){
                printf("������Ҫ���������,Ҫ�˳���ֱ�Ӱ�a��\n");
                fflush(stdin);//��ջ�����
                strcpy(num,"");//�������
                scanf("%[0-9 a]",num);//��������������ַ�
                if(num[0]=='a'){           //���ֻ�лس�ֱ�ӽ���ѭ��
                    break;
                }
                status=sscanf(num,"%d",&data);//ֻ��������,�޷��жϷǷ�����
                if(status==0){
                    puts("���������������������\n");
                    continue;}
                if(status==EOF){
                    puts("�������,����������\n");
                    continue;
                }
                if(pushLStack(&s,data)==SUCCESS)
                puts("��ӳɹ�");
            }
            break;
        case '8':
            if(popLStack(&s,&data)==ERROR){
                printf("��ջʧ��\n");
                break;
            }
            printf("��ջԪ��Ϊ��%d\n",data);
            break;
        case '9':
            return 0;
        default:
            printf("�����������������\n");
            break;
        }
        strcpy(str,"");//�������
        fflush(stdin);
    }
}

