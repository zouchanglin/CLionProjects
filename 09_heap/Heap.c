#include <Heap.h>


void HeapInit(Heap *hp, HPDataType *arr ,size_t n)
{
	assert(hp);
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	hp->;
}
void HeapDestroy(Heap *hp,size_t n);
void HeapPush(Heap *hp, HPDataType x);
void HeapPop(Heap *hp);
HPDataType HeapTop(Heap *hp);
int HeapSize(Heap *hp);
int HeapEmpty(Heap *hp);


#endif //!__HEAP_H__

