#include "../inc/qgsort.h"
#include <stdlib.h>

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序算法
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int *a,int n){
    int i,j,temp;
    for (i=1;i<n;i++){
        for (j=i;j>0;j--){
            if (a[j]<a[j-1]){//如果遇到比它本身大的数，就交换，即后移
                temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
    }
}


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp){//归并的并
    int i=begin,j=mid+1,k=0;//设左右数组的头部和temp头部
    while((i<=mid)&&(j<=end)){
        if(a[i]<a[j]){    //筛选两数组中较小的元素放到承载数组中
            temp[k]=a[i];
            i++;
        }
        else{
            temp[k]=a[j];
            j++;
        }
        k++;
    }
    while(i<=mid){
        temp[k]=a[i];
        k++;
        i++;
    }
    while(j<=end){
        temp[k]=a[j];
        k++;
        j++;
    }
    for(i=begin,j=0;i<=end;i++,j++)
        a[i]=temp[j];
}


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int *a,int begin,int end,int *temp){
    int mid;
    if(begin>=end)
        return;
    else
    {
        mid=(begin+end)/2;
        MergeSort(a,begin,mid,temp);    //递归
        MergeSort(a,mid+1,end,temp);    //拆成一个个的
        MergeArray(a,begin,mid,end,temp);    //调用函数将前两部分归并
    }
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int *a, int begin, int end){
        if(begin>=end)
            return;
        int temp=a[begin];
        a[begin]=a[(begin+end)/2];
        a[(begin+end)/2]=temp;
        int last=begin;
        for(int i=begin+1;i<=end;i++){
            if(a[i]<a[begin]){
                temp=a[last+1];
                a[last+1]=a[i];
                a[i]=temp;
            }
        }
        temp=a[begin];
        a[begin]=a[last];
        a[last]=temp;
        QuickSort_Recursion(a,begin,last-1);
        QuickSort_Recursion(a,last+1,end);
}


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int *a,int size){

}


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int *a, int begin, int end){

}


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int *a, int size , int max){
    int *coutArray,*temp;
    coutArray=(int*)malloc(sizeof(int)*(max+1));
    temp=(int*)malloc(sizeof(int)*size);
    for(int i=0;i<max+1;i++)
        coutArray[i]=0;//本来想直接第一个元素为0其他都为0的，怕出问题qaq
    for(int i=0;i<size;i++)
        coutArray[a[i]]++;//计数出现几次
    for (int i=0,j=0;i<size;i++) {
        for (int k=0;k<coutArray[i];k++) {
            temp[j++]=i;
        }
    }
    free(coutArray);
    free(temp);
}


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int *a,int size){
    int t[10][size],i,j,k,temp1[10],temp2[size],m=0,n=0,s=1;
    for(i=0;i<size;i++){
        temp2[i]=a[i];
        if(a[i]>m)	m=a[i];
    }
    while(m!=0){
        m=m/10;
        n++;
    }//最大值n位数
    for(i=0;i<n;i++){
        for(j=0;j<10;j++)		temp1[j]=0;
        k=0;
        for(m=0;m<10;m++){
            for(j=0;j<size;j++)
                t[m][j]=0;
        }//初始化
        for(j=0;j<size;j++){
            t[temp2[j]/s%10][temp1[temp2[j]/s%10]]=temp2[j];
            temp1[temp2[j]/s%10]++;
        }
        for(m=0;m<10;m++){
            for(j=0;j<temp1[m];j++){
                temp2[k]=t[m][j];
                k++;
            }
        }
        s=s*10;
    }
    for(i=0;i<size;i++)
        a[i]=temp2[i];
}

/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int *a,int size){
    int p=0,p1=0,p2=size-1,tem;
    while(p<p2){
        if(a[p]==0){
            tem=a[p];
            a[p]=a[p1];
            a[p1]=tem;
            p1++;
            if(p<p1)
                p++;
            continue;
        }
        if(a[p]==2){
            tem=a[p];
            a[p]=a[p2];
            a[p2]=tem;
            p2--;
            continue;
        }
        p++;
    }
}


/**
 *  @name        : 自拟
 *  @description : 在一个无序序列中找到第K大/小的数
 *  @param       : 数组指针a，数组长度size
 */
int FindK(int *a,int size,int k){//返回第k大的数
    int b[size];
    insertSort(b,size);
    return b[k-1];
}