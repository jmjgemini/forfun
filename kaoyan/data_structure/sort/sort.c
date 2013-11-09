#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

#define ARRAY_LEN(array,type) (sizeof(array)/sizeof(type))
#define SWAP(a,b) ((a)^=(b),(b)^=(a),(a)^=(b))
#define EQ(a,b) ((a)==(b))

#define YELLOW "\033[93m"
#define RED  "\033[91m"
#define BLUE "\033[36m"
#define ENDC "\033[0m"


void insert_sort(int *a,int n)
{
	for (int i = 1;i < n;i++)
	{
		int j = i-1;
		int temp = a[i];

		while(j>=0 && temp <= a[j])
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = temp;
	}
}

void bubble_sort(int *a,int n)
{
	for (int i = n-1;i>0;i--)
	{
		int flag = 0;
		for (int j = 0;j<i;j++)
		{
			if (a[j] > a[j+1])
			{
				SWAP(a[j],a[j+1]);
				flag = 1;
			}
		}
		if (EQ(flag,0))
			return ;
	}
}

void quick_sort(int *a,int n)
{
	if (n <= 1)
		return;
	int front = 0;
	int rear  = n-1;
	int flag = a[0];
	while(!EQ(front,rear))
	{
		while (a[rear] >= flag && rear > front)
			rear--;
		if (front != rear)
			SWAP(a[front],a[rear]);
		while (a[front] < flag && rear > front)
			front++;
		if (front != rear)
			SWAP(a[front],a[rear]);
	}
	quick_sort(a,front);
	quick_sort(a+front+1,n-front-1);
}

void select_sort(int *a,int n)
{
	for (int i = 0;i<n-1;i++)
	{
		int min_index = i;
		for (int j = i+1;j<n;j++)
		{
			min_index = a[j]<a[min_index]?j:min_index;	
		}
		SWAP(a[min_index],a[i]);
	}
}

void max_heap_fix_down(int *heap,int i,int n)
{
	int parent = i;	
	int child  = i*2+1; /* get left child */
	int temp = heap[parent];
	while (child < n)
	{
		if (child+1<n &&heap[child+1] > heap[child])
			child++;
		if (temp >=heap[child])
			break;
		heap[parent] = heap[child];
		parent = child;
		child = parent*2 + i;
	}
	heap[parent] = temp;
}

void heap_sort(int *a,int n)
{
	/* create the heap */
	for (int i = n/2-1;i>=0;i--)
		max_heap_fix_down(a,i,n);

	for (int i = n-1;i>=1;i--)
	{
		SWAP(a[0],a[i]);
		max_heap_fix_down(a,0,i);
	}
}
void merge(int *a,int first,int mid,int last,int *temp)
{
	int i = first;
	int j = mid+1;
	int k = 0;
	while (i <= mid && j <= last)
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	if (i > mid)
		memcpy(temp+k,a+j,(last-j+1)*sizeof(int));
	else
		memcpy(temp+k,a+i,(mid-i+1)*sizeof(int));
	memcpy(a+first,temp,(last-first+1)*sizeof(int));
}


void merge_sort_from_to(int *a,int first,int last,int *temp)
{
	if (first < last)
	{
		int mid = (first + last)/2;
		merge_sort_from_to(a,first,mid,temp);
		merge_sort_from_to(a,mid+1,last,temp);
		merge(a,first,mid,last,temp);
	}
}

void merge_sort(int *a,int n)
{
	int *temp = malloc(sizeof(int)*n);
	merge_sort_from_to(a,0,n-1,temp);
	free(temp);
}

//typedef void (*sort_func)(int *,int);

int main(void)
{
	//insert_sort(a,ARRAY_LEN(a,int));
	//bubble_sort(a,ARRAY_LEN(a,int));
	//quick_sort(a,ARRAY_LEN(a,int));
	//select_sort(a,ARRAY_LEN(a,int));
	//heap_sort(a,ARRAY_LEN(a,int));
	//merge_sort(a,ARRAY_LEN(a,int));
	struct sort_func
	{
		void (*func)(int*,int);
		const char *name;
	};
	struct sort_func sort_funcs[] = 
		       {
			{insert_sort,"insert_sort"},
			{bubble_sort,"bubble_sort"},
			{quick_sort,"quick_sort"},
			{select_sort,"select_sort"},
			{heap_sort,"heap_sort"},
			{merge_sort,"merge_sort"}
		       };

	for (int i = 0;
	     i<ARRAY_LEN(sort_funcs,struct sort_func);
	     i++)
	{
		int unsorted[] = {49,38,65,97,76,13,27,49};
		printf("%ssort function%s:%s%s\n",
				BLUE,YELLOW,sort_funcs[i].name,ENDC);
		sort_funcs[i].func(unsorted,ARRAY_LEN(unsorted,int));
		printf("output:\n");
		for (int j = 0;
		         j<ARRAY_LEN(unsorted,int);
			 j++)
			printf("%d ",unsorted[j]);
		printf("\n\n");

	}
	
	return 0;
}
