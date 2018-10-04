<<<<<<< HEAD
#ifndef __HEAP_H__
#define __HEAP_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef int HPDataType;

typedef struct Heap{
	HPDataType *_arr;
	int _size;
	int _capacity;
}Heap;

void HeapInit(Heap *hp, HPDataType *arr ,size_t n);
void HeapDestroy(Heap *hp,size_t n);
void HeapPush(Heap *hp, HPDataType x);
void HeapPop(Heap *hp);
HPDataType HeapTop(Heap *hp);
int HeapSize(Heap *hp);
int HeapEmpty(Heap *hp);
void HeapTest();

#endif //!__HEAP_H__

=======
#ifndef __HEAP_H__
#define __HEAP_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef int HPDataType;

typedef struct Heap{
	HPDataType *_arr;
	int _size;
	int _capacity;
}Heap;

void HeapInit(Heap *hp, HPDataType *arr ,size_t n);
void HeapDestroy(Heap *hp,size_t n);
void HeapPush(Heap *hp, HPDataType x);
void HeapPop(Heap *hp);
HPDataType HeapTop(Heap *hp);
int HeapSize(Heap *hp);
int HeapEmpty(Heap *hp);


#endif //!__HEAP_H__

>>>>>>> ef427b430dcf57d376f8f89be512434c62a6c2e3
