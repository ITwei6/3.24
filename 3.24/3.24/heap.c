#include "heap.h"
void HpInit(Hp* ps)//初始化
{
	  assert(ps);
     ps->a =(HPDataType*)malloc(sizeof(HPDataType)*4);
	if (ps->a == NULL)
	{
		perror("malloc");
	}
	ps->capacity = 4;
	ps->size = 0;
}
void Swap(HPDataType* a, HPDataType* b)
{
	HPDataType tmp = *a;
	*a = *b;
	*b = tmp;
}
void AdjustUp(HPDataType* a, int child)//向上调整的前提就是child之前的数是堆
{

	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child],&a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
	
}
void HpPush(Hp* ps, HPDataType x)//向堆里插入数据
{
	assert(ps);
	//插入数据之前需要判断一下，堆是否满了，是否需要扩容
	if (ps->size == ps->capacity)
	{
		HPDataType* tmp = realloc(ps->a, sizeof(HPDataType) * ps->capacity * 2);
		if (tmp == NULL)
		{
			perror("realloc");
		}
		ps->a = tmp;
		ps->capacity *= 2;
		
	}
	ps->a[ps->size] = x;
	//因为下标从0开始，先插入数据后，size再进行++
	ps->size++;//这时的size才是++后的size
	//插入一个数据很简单，但是要考虑是否满足规则；size-1就是要插入的位置 
	//向上调整
	AdjustUp(ps->a, ps->size - 1);
}
void AdjustDown(HPDataType* a, int n, int parent)//实现的前提是左右子树都是堆
{
	int child = parent * 2+1;
	while (child < n)
	{
		//选出左右孩子中比较大的孩子，假设child为左边，假设左边孩子比较大
		if (child+1<n&&a[child] < a[child + 1])//不过这里存在越界的风险，不能保证右边的孩子一定存在
		{//右边的孩子要存在的话也需要小于n才可以所以我们再加上去
			++child;//让右边的孩子成为比较大的child
		}
		//然后让根（父亲）与较大儿子比较，这里是大堆，父亲要大于儿子的
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			//交互完后，让parent跳到儿子位置上去，儿子继续往下找
			parent = child;
			child = parent* 2+1;
		}
		else
		{
			break;
		}


	}
}
void HpPop(Hp* ps)
{
	assert(ps);
	//当堆被删空时，需要判断下
	assert(!HpEmpty(ps));
	//交换堆头数据和子叶数据
	Swap(&ps->a[0], &ps->a[ps->size - 1]);
	ps->size--;
	//交换完后，需要使用向下调整：来调整堆
	AdjustDown(ps->a, ps->size, 0);

}
HPDataType HpTop(Hp* ps)//获取堆顶数据
{
	assert(ps);
	return ps->a[0];
}
bool HpEmpty(Hp* ps)//判断堆是否为空
{
	assert(ps);
	return ps->size == 0;
}
int HpSize(Hp* ps)//获取堆的有效数据的大小
{
	assert(ps);
	return ps->size;
}