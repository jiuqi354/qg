#include "../inc/qgsort.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char str[1024],array[1024];
    int num,num1=0;
    int array1[50],array2[50];
    array1[0]=0;
    for(;;){
        printf("----------�����㷨----------\n");
        printf("1.��������\n");
        printf("2.��������\n");
        printf("3.�鲢����\n");
        printf("4.��������\n");
        printf("5.��������\n");
        printf("6.��ɫ����\n");
        printf("7.���ҵ�k�����\n");
        printf("8.�����Ļ\n");
        printf("9.�˳�\n");
        printf("���������ѡ������Ӧ�����֣�1-9��:\n");
        gets(str);
    if(strlen(str)>1){
        printf("��������ȷ�����֣�\n");
        strcpy(str,"");             //�������
        continue;
    }
    sscanf(str,"%d",&num);
    strcpy(str,"");
        switch (num) {
            case 1:
                if(num1!=0){
                    printf("�ѳ�ʼ�����飬�����ظ���ʼ����\n");
                    break;
                }
                for(;;){
                    A:
                printf("������Ҫ�������������,Ҫ�˳���ֱ�Ӱ��س������鳤���Ϊ50��:\n");
                gets(array);
                if(strlen(array)>=10){
                    printf("��ֵ�������������룡\n");
                    continue;
                }
                if(strlen(array)==0){
                    break;
                    }
                for(int i=0;i<strlen(array);i++){
                    if(!(array[i]>='0'&&array[i]<='9')){
                        printf("�������������������룡\n");
                        goto A;
                        }
                    }
                array1[num1]=atoi(array);
                strcpy(array,"");
                num1++;
                }
                printf("�������óɹ����������Ϊ:[\n");
                for(int i=0;i<num1;i++){
                    printf("%d ",array1[i]);
                }
                printf("]\n");
                break;
            case 2:
                if(num1==0){
                    printf("δ��������\n");
                    break;
                }
                insertSort(array1,num1);
                printf("��������ɹ����������Ϊ:[\n");
                for(int i=0;i<num1;i++){
                    printf("%d ",array1[i]);
                }
                printf("]\n");
                break;
            case 3:
                if(num1==0){
                    printf("δ��������\n");
                    break;
                }
                MergeSort(array1,0,num1-1,array2);
                printf("��������ɹ����������Ϊ:[");
                for(int i=0;i<num1;i++){
                    printf("%d ",array1[i]);
                }
                printf("]\n");
                break;
            case 4:
                if(num1==0){
                    printf("δ��������\n");
                    break;
                }
                QuickSort_Recursion(array1,0,num1-1);
                printf("��������ɹ����������Ϊ:[");
                for(int i=0;i<num1;i++){
                    printf("%d ",array1[i]);
                }
                printf("]\n");
                break;
            case 5:
                if(num1==0){
                    printf("δ��������\n");
                    break;
                }
                RadixCountSort(array1,num1);
                printf("��������ɹ����������Ϊ:[\n");
                for(int i=0;i<num1;i++){
                    printf("%d ",array1[i]);
                }
                printf("]\n");
                break;
            case 6:
                if(num1==0){
                    printf("δ��������\n");
                    break;
                }
                ColorSort(array1,num1);
                printf("��������ɹ����������Ϊ:[\n");
                for(int i=0;i<num1;i++){
                    printf("%d ",array1[i]);
                }
                printf("]\n");
                break;
            case 7:
                if(num1==0){
                    printf("δ��������\n");
                    break;
                }
                printf("��Ҫ���ҵڼ��������\n");
                scanf("%d",&num);
                if(num>num1||num<=0){
                    printf("�����������\n");
                    break;
                }
                num=FindK(array1,num1,num);
                printf("��Ҫ���ҵ���Ϊ:%d\n",num);
                break;
            case 8:
                system("cls");
                break;
            case 9:
                return 0;
            default:
                printf("��������������������룡\n");
                break;
        }
        fflush(stdin);
    }
}