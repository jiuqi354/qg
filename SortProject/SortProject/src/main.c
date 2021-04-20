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
        printf("----------排序算法----------\n");
        printf("1.创建数组\n");
        printf("2.插入排序\n");
        printf("3.归并排序\n");
        printf("4.快速排序\n");
        printf("5.计数排序\n");
        printf("6.颜色排序\n");
        printf("7.查找第k大的数\n");
        printf("8.清空屏幕\n");
        printf("9.退出\n");
        printf("请输入你的选择所对应的数字（1-9）:\n");
        gets(str);
    if(strlen(str)>1){
        printf("请输入正确的数字！\n");
        strcpy(str,"");             //清空数组
        continue;
    }
    sscanf(str,"%d",&num);
    strcpy(str,"");
        switch (num) {
            case 1:
                if(num1!=0){
                    printf("已初始化数组，请勿重复初始化！\n");
                    break;
                }
                for(;;){
                    A:
                printf("请输入要输入数组的数据,要退出请直接按回车（数组长度最长为50）:\n");
                gets(array);
                if(strlen(array)>=10){
                    printf("数值过大，请重新输入！\n");
                    continue;
                }
                if(strlen(array)==0){
                    break;
                    }
                for(int i=0;i<strlen(array);i++){
                    if(!(array[i]>='0'&&array[i]<='9')){
                        printf("你输入有误，请重新输入！\n");
                        goto A;
                        }
                    }
                array1[num1]=atoi(array);
                strcpy(array,"");
                num1++;
                }
                printf("数组设置成功！你的数组为:[\n");
                for(int i=0;i<num1;i++){
                    printf("%d ",array1[i]);
                }
                printf("]\n");
                break;
            case 2:
                if(num1==0){
                    printf("未设置数组\n");
                    break;
                }
                insertSort(array1,num1);
                printf("数组排序成功！你的数组为:[\n");
                for(int i=0;i<num1;i++){
                    printf("%d ",array1[i]);
                }
                printf("]\n");
                break;
            case 3:
                if(num1==0){
                    printf("未设置数组\n");
                    break;
                }
                MergeSort(array1,0,num1-1,array2);
                printf("数组排序成功！你的数组为:[");
                for(int i=0;i<num1;i++){
                    printf("%d ",array1[i]);
                }
                printf("]\n");
                break;
            case 4:
                if(num1==0){
                    printf("未设置数组\n");
                    break;
                }
                QuickSort_Recursion(array1,0,num1-1);
                printf("数组排序成功！你的数组为:[");
                for(int i=0;i<num1;i++){
                    printf("%d ",array1[i]);
                }
                printf("]\n");
                break;
            case 5:
                if(num1==0){
                    printf("未设置数组\n");
                    break;
                }
                RadixCountSort(array1,num1);
                printf("数组排序成功！你的数组为:[\n");
                for(int i=0;i<num1;i++){
                    printf("%d ",array1[i]);
                }
                printf("]\n");
                break;
            case 6:
                if(num1==0){
                    printf("未设置数组\n");
                    break;
                }
                ColorSort(array1,num1);
                printf("数组排序成功！你的数组为:[\n");
                for(int i=0;i<num1;i++){
                    printf("%d ",array1[i]);
                }
                printf("]\n");
                break;
            case 7:
                if(num1==0){
                    printf("未设置数组\n");
                    break;
                }
                printf("你要查找第几大的数？\n");
                scanf("%d",&num);
                if(num>num1||num<=0){
                    printf("你的输入有误\n");
                    break;
                }
                num=FindK(array1,num1,num);
                printf("你要查找的数为:%d\n",num);
                break;
            case 8:
                system("cls");
                break;
            case 9:
                return 0;
            default:
                printf("你的输入有误！请重新输入！\n");
                break;
        }
        fflush(stdin);
    }
}