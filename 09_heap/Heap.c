<<<<<<< HEAD
#include <Heap.h>

void Swap(HPDataType *x1, HPDataType *x2){
	HPDataType tmp = *x1;
	*x2 = *x2;
	*x2 = tmp;
}

//向下调整
void AdjustDown(HPDataType *arr, int n, int root){
	int parent = root;
	int child = parent*2+1;
	while(child < n){
		//选左右孩子中较大的
		if(arr[child+1]>arr[child]){
			child++;
		}
		//如果父节点不是最大的则交换
		if((child+1< n) &&
		(arr[parent]<arr[child])){
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child  = parent*2+1;
		}else{
			break;
		}
	}
}
void HeapInit(Heap *hp, HPDataType *arr ,size_t n){
	size_t i = 0;
	assert(hp);
	hp->_arr = (HPDataType*)malloc(sizeof(HPDataType) * n);
	hp->_size = n;
	hp->_capacity = n;
	for(i = 0;i<n;i++){
		hp->_arr[i];
	}
	//调堆
	for(i = (n-2)/2; i>=0;--i){
		AdjustDown(hp->_arr,hp->_size,i);
	}
}
void HeapDestroy(Heap *hp,size_t n)
{
	assert(hp);
	free(hp->_arr);
	hp->_capacity = 0;
	hp->_size = 0;
	hp->_arr = NULL;
}
void HeapPush(Heap *hp, HPDataType x)
{


}
void HeapPop(Heap *hp);
HPDataType HeapTop(Heap *hp);
int HeapSize(Heap *hp);
int HeapEmpty(Heap *hp);

void HeapPrint(Heap * hp){
	for(int i = 0;i<hp->_size;i++){
		printf("%d ",hp->_arr[i]);
	}
	printf("\n");
}

void HeapTest()
{
	Heap hp;
	int arr[] = {53, 17, 78, 9, 45, 65, 87, 23, 31};
	HeapInit(&hp,arr,sizeof(arr)/sizeof(int));
	HeapPrint(&hp);

	system("pause");
}
=======
#include <Heap.h>

void Swap(HPDataType *x1, HPDataType *x2){
	HPDataType tmp = *x1;
	*x2 = *x2;
	*x2 = tmp;
}

//向下调整
void AdjustDown(HPDataType *arr, int n, int root){
	int parent = root;
	int child = parent*2+1;
	while(child < n){
		//选左右孩子中较大的
		if(arr[child+1]>arr[child]){
			child++;
		}
		//如果父节点不是最大的则交换
		if((child+1< n) &&
		(arr[parent]<arr[child])){
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child  = parent*2+1;
		}else{
			break;
		}
	}
}
void HeapInit(Heap *hp, HPDataType *arr ,size_t n){
	size_t i = 0;
	assert(hp);
	hp->_arr = (HPDataType*)malloc(sizeof(HPDataType) * n);
	hp->_size = n;
	hp->_capacity = n;
	for(i = 0;i<n;i++){
		hp->_arr[i];
	}
	//调堆
	for(i = (n-2)/2; i>=0;--i){
		AdjustDown(hp->_arr,hp->_size,i);
	}
}
void HeapDestroy(Heap *hp,size_t n);
void HeapPush(Heap *hp, HPDataType x);
void HeapPop(Heap *hp);
HPDataType HeapTop(Heap *hp);
int HeapSize(Heap *hp);
int HeapEmpty(Heap *hp);

>>>>>>> ef427b430dcf57d376f8f89be512434c62a6c2e3
