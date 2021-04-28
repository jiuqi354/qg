#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/binary_sort_tree.h"
#include "tree.c"

int main() {
    char str[1024];
    int num,e;
    BinarySortTreePtr ptr=NULL;
    void (*visit)(NodePtr);
    visit=Visit;
    for(;;){
        printf("----------二叉排序树----------\n");
        printf("1.创建树\n");
        printf("2.插入数字\n");
        printf("3.查找数字\n");
        printf("4.删除数字\n");
        printf("5.递归前序遍历\n");
        printf("6.迭代前序遍历\n");
        printf("7.递归中序遍历\n");
        printf("8.迭代中序遍历\n");
        printf("9.递归后序遍历\n");
        printf("10.迭代后序遍历\n");
        printf("11.清空屏幕\n");
        printf("12.退出\n");
        printf("请输入你的选择所对应的数字（1-12）:\n");
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
                if(BST_init(ptr)==failed){
                    printf("创建失败\n");
                    break;
                }
                break;
            case 2:
                if(!ptr){
                    printf("未创建树\n");
                    break;
                }
                printf("请输入你要插入的数字\n");
                scanf("%d",&e);
                BST_insert(ptr,e);
                break;
            case 3:
                if(!ptr){
                    printf("未创建树\n");
                    break;
                }
                printf("请输入你要查找的数字\n");
                scanf("%d",&e);
                BST_search(ptr,e);
                break;
            case 4:
                if(!ptr){
                    printf("未创建树\n");
                    break;
                }
                printf("请输入你要删除的数字\n");
                scanf("%d",&e);
                if(BST_delete(ptr,e)==succeed){
                    printf("删除成功\n");
                } else{
                    printf("操作失败\n");
                }
                    break;
            case 5:
                if(!ptr){
                    printf("未创建树\n");
                    break;
                }
                BST_preorderI(ptr,visit);
                break;
            case 6:
                if(!ptr){
                    printf("未创建树\n");
                    break;
                }
                BST_preorderR(ptr,visit);
                break;
            case 7:
                if(!ptr){
                    printf("未创建树\n");
                    break;
                }
                BST_inorderI(ptr,visit);
                break;
            case 8:
                if(!ptr){
                    printf("未创建树\n");
                    break;
                }
                BST_inorderR(ptr,visit);
                break;
            case 9:
                if(!ptr){
                    printf("未创建树\n");
                    break;
                }
                BST_postorderI(ptr,visit);
                break;
            case 10:
                if(!ptr){
                    printf("未创建树\n");
                    break;
                }
                BST_postorderR(ptr,visit);
                break;
            case 11:
                system("cls");
                break;
            case 12:
                return 0;
            default:
                printf("你的输入有误！请重新输入！\n");
                break;
        }
        fflush(stdin);
    }
}
