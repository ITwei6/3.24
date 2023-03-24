#include "heap.h"
void HpInit(Hp* ps)//��ʼ��
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
void AdjustUp(HPDataType* a, int child)//���ϵ�����ǰ�����child֮ǰ�����Ƕ�
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
void HpPush(Hp* ps, HPDataType x)//������������
{
	assert(ps);
	//��������֮ǰ��Ҫ�ж�һ�£����Ƿ����ˣ��Ƿ���Ҫ����
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
	//��Ϊ�±��0��ʼ���Ȳ������ݺ�size�ٽ���++
	ps->size++;//��ʱ��size����++���size
	//����һ�����ݺܼ򵥣�����Ҫ�����Ƿ��������size-1����Ҫ�����λ�� 
	//���ϵ���
	AdjustUp(ps->a, ps->size - 1);
}
void AdjustDown(HPDataType* a, int n, int parent)//ʵ�ֵ�ǰ���������������Ƕ�
{
	int child = parent * 2+1;
	while (child < n)
	{
		//ѡ�����Һ����бȽϴ�ĺ��ӣ�����childΪ��ߣ�������ߺ��ӱȽϴ�
		if (child+1<n&&a[child] < a[child + 1])//�����������Խ��ķ��գ����ܱ�֤�ұߵĺ���һ������
		{//�ұߵĺ���Ҫ���ڵĻ�Ҳ��ҪС��n�ſ������������ټ���ȥ
			++child;//���ұߵĺ��ӳ�Ϊ�Ƚϴ��child
		}
		//Ȼ���ø������ף���ϴ���ӱȽϣ������Ǵ�ѣ�����Ҫ���ڶ��ӵ�
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			//���������parent��������λ����ȥ�����Ӽ���������
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
	//���ѱ�ɾ��ʱ����Ҫ�ж���
	assert(!HpEmpty(ps));
	//������ͷ���ݺ���Ҷ����
	Swap(&ps->a[0], &ps->a[ps->size - 1]);
	ps->size--;
	//���������Ҫʹ�����µ�������������
	AdjustDown(ps->a, ps->size, 0);

}
HPDataType HpTop(Hp* ps)//��ȡ�Ѷ�����
{
	assert(ps);
	return ps->a[0];
}
bool HpEmpty(Hp* ps)//�ж϶��Ƿ�Ϊ��
{
	assert(ps);
	return ps->size == 0;
}
int HpSize(Hp* ps)//��ȡ�ѵ���Ч���ݵĴ�С
{
	assert(ps);
	return ps->size;
}