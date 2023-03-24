#include"heap.h"
int main()
{
	Hp p;
	HpInit(&p);
	HpPush(&p, 12);
	HpPush(&p, 25);
	HpPush(&p, 23);
	HpPush(&p, 29);
	HpPush(&p, 52);
	HpPush(&p, 112);
	HpPush(&p, 55);
	HpPush(&p, 266);
	HpPush(&p, 20);
	HpPush(&p, 2);

	while (!HpEmpty(&p))
	{
		printf("%d ", HpTop(&p));
		HpPop(&p);
	}
	printf("\n");
	return 0;
}