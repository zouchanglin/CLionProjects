#include <stdio.h>
#include <assert.h>


void PrintArray(const int *arr,int n)
{
    int i = 0;
    assert(arr);
    for(i=0; i<n; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

static void Swap(int *p1, int *p2)
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
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

//选择排序
void SelectSort(int *arr, int n)
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

//选择排序的优化
void SelectSort_OP(int *arr, int len)
{
    int start = 0;
    int end = len-1;
    assert(arr);

    for(start=0;start<end;start++,end--)
    {
        // 一次选出最大数据及最小数据
        int max = start;
        int min = start;

        int i = 0;
        for(i=start+1;i<=end;i++)
        {
            if(arr[min]>arr[i])
            {
                min = i;
            }
            if(arr[max]<arr[i])
            {
                max = i;
            }
        }
        Swap(&arr[start],&arr[min]);
        //注意这里最大的数据在开始的位置则需要修正
        if(max == start)
            max = min;
        Swap(&arr[end],&arr[max]);
    }
}

//老师讲的方式（推荐使用）
void SelectSort_OP2(int *arr, int n){
    int begin = 0;
    int end = n-1;

    assert(arr);
    while(begin < end){
            int minindex = begin;
            int maxindex = begin;
	    //分别找到最大和最小的下标
	    int i = 0;
	    for(i = begin;i <= end; ++i){
		if(arr[i]>arr[maxindex]){
		    maxindex = i;
		}
		if(arr[i]<arr[minindex]){
		    minindex = i;
		}
	    }
	    //把最小的放在前面，最大的放在后面
	    Swap(&arr[begin], &arr[minindex]);
	    if(begin == maxindex)//修正
		    maxindex = minindex;
	    Swap(&arr[end], &arr[maxindex]);
	    ++begin;
	    --end;
    }
}

void HeapAdjust(int *arr,int root,int len)
{
    //child是左孩子的下标
    int child = root*2+1;
    assert(arr);
    while(child<len)
    {
        // 比较左孩子和右孩子,child指向大的孩子
        if(child+1<len && arr[child+1]>arr[child])
        {
            child++;
        }
        // 1.若大的孩子节点大于根节点,则不再需要调整,跳出循环
        // 2.否则,交换孩子节点和根节点,将根节点继续往下调整
        if(arr[child] > arr[root])
        {
            Swap(&arr[child], &arr[root]);
            root = child;
            child = child*2 +1;
        }
        else
        {
            break;
        }

    }
}
//堆排序
void HeapSort(int *arr, int len)
{

    int i = 0;
    assert(arr);
    //建堆
    for(i=len/2-1;i>=0;i--)
    {
        HeapAdjust(arr,i,len);
    }
    //向下调整
    for(i = len-1;i>0;i--)
    {
        Swap(&arr[i], &arr[0]);
        HeapAdjust(arr,0,i);
    }
}

// 冒泡排序
void BubbleSort(int* arr, int len)
{
    int index = 0;
    int end = 0;
    assert(arr);
    for(end = len-1;end>0;end--)
    {
        int flag = 0;
        for(index=0;index<end;index++)
        {
            if(arr[index]>arr[index+1])
            {
                Swap(&arr[index], &arr[index+1]);
                flag = 1;
            }
        }
        if(flag == 0)
            break;
    }
}

//快速排序
//三数取中法
int GetMidIndex(int* array, int left, int right)
{
    int mid = ((left+right)>>2);
    assert(array);
    if(array[left]>array[right])
    {
        if(array[mid]<array[right])
            return mid;
        else
            return array[mid]>array[left] ? left:mid;
    }
    else //array[left] <= array[right]
    {
        if(array[left]>array[mid])
            return left;
        else //array[left] <= array[mid]
            return array[mid]>array[right] ? right:mid;
    }


}
void FastSort(int *arr,int left, int right)
{
    int mid = 0;
    int key = 0;
    int prev = left-1;
    int cur = left;
    assert(arr);
    mid = GetMidIndex(arr,left,right);
    if(mid != right)
    {
        Swap(&arr[mid], &arr[right]);
    }
    key = arr[right];
    while(cur<right)
    {
        // 找到比key的小的数据则与前面的数据进行交换

    }



}

int main(int argc, char* argv[]) {
    int array[]={20,6,18,3,5,11,19,4,2,6,1};
    int len = sizeof(array)/sizeof(int);
    PrintArray(array,len);

    //InsertSort(array,len);
    //ShellSort(array,len);
    //SelectSort(array,len);
    //SelectSort_OP(array,len);
    //HeapSort(array,len);
    // BubbleSort(array,len);
    SelectSort_OP2(array, len);


    PrintArray(array,len);
    return 0;
}
