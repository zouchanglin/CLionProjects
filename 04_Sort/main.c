#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

void PrintArray(const int *arr,int n)
{
    int i = 0;
    assert(arr);
    for(i=0; i<n; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

//插入排序
void InsertSort(int *arr, int n)
{
    int index = 0;
    assert(arr);
    for(index=0;index<n;index++)
    {
        //将当前数据往前插入
        int end = index-1;
        int temp = arr[index];
        while(end>=0 && temp<arr[end])
        {
            arr[end+1] = arr[end];
            --end;
        }

        arr[end+1] = temp;
    }
}

//希尔排序
void ShellSort(int* arr,int len)
{
    int gap = len;
    assert(arr);
    while(gap>1)
    {
        gap = gap/3+1;
        int cur = 0;
        for(cur = gap;cur<len;++cur)
        {
            int end = cur-gap;
            int tmp = arr[cur];
            while(end>=0 && tmp<arr[end])
            {
                arr[end+gap] = arr[end];
                end -= gap;
            }
            arr[end+gap] = tmp;
        }
    }
}

void SelectSort(int* arr, int n)
{
    int index = 0;
    assert(arr);
    for(index=0;index<n;index++)
    {
        int min = index;
        int i = 0;
        for(i=index+1;i<n;i++)
        {
            if(arr[min]>arr[i])
            {
                min = i;
            }
        }
        if(min != index)
        {
            int tmp = arr[index];
            arr[index] = arr[min];
            arr[min] = tmp;
        }
    }
}


int main(int argc, char* argv[]) {
    int array[]={4,6,8,3,5,11,19,4,2,6,1};
    int len = sizeof(array)/sizeof(int);
    PrintArray(array,len);

    //InsertSort(array,len);

    ShellSort(array,len);

    PrintArray(array,len);
    return 0;
}