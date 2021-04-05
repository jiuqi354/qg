#include <stdio.h>
#include "../head/SqStack.h"
#include <stdlib.h>
#include <string.h>

int main(){
    char str[1024],num[1024];
    ElemType e=0;
    int length=0,data,size;
    SqStack s;
    s.top=-2;
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
        switch (str[0]) {
            case '0':
                system("cls");
                break;
            case '1':
                if(s.top==-2){
              A:    printf("��������Ҫ������ջ�Ĵ�С��\n");
                    int status=scanf("%d",&size);
                    if(status!=1){
                        printf("�������������������������\n");
                        fflush(stdin);
                        goto A;
                    }
                    if(initStack(&s,size)==SUCCESS){
                        printf("��ʼ���ɹ�\n");
                        break;}
                    printf("��ʼ��ʧ��\n");
                    break;
                }
                printf("�ѳ�ʼ��ջ�������ظ���ʼ��\n");
                break;
            case '2':
                if(s.top==-2){
                    printf("δ��ʼ��ջ�����ʼ����\n");
                    break;
                }
                if(isEmptyStack(&s)==ERROR){
                    printf("ջΪ�գ�\n");
                    break;
                }
                printf("ջ��Ϊ��\n");
                break;
            case '3':
                if(s.top==-2){
                    printf("δ��ʼ��ջ�����ʼ����\n");
                    break;
                }
                if(getTopStack(&s,&e)==SUCCESS){
                    printf("ջ��Ԫ��Ϊ%d\n",e);
                    break;}
                printf("��ȡջ��Ԫ��ʧ��\n");
                break;
            case '4':
                if(clearStack(&s)==SUCCESS){
                    printf("��ճɹ�\n");
                    break;}
                printf("���ʧ��\n");
                break;
            case '5':
                destroyStack(&s);
                printf("���ٳɹ�\n");
                break;
            case '6':
                if(stackLength(&s,&length)==SUCCESS){
                    printf("ջ����Ϊ%d\n",length);
                    break;
                }
                printf("��ȡ����ʧ��\n");
                break;
            case '7':
                if(s.top==-2){
                    printf("δ��ʼ��ջ�����ʼ����\n");
                    break;
                }
                for(int status;;){
                    printf("������Ҫ���������,Ҫ�˳���ֱ������a��\n");
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

                    if(pushStack(&s,data)==SUCCESS)
                        puts("��ӳɹ�");
                }
                break;
            case '8':
                if(popStack(&s,&data)==ERROR){
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


