#pragma once
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}Hp;
void HpInit(Hp* ps);//初始化
void HpPush(Hp* ps, HPDataType x);//插入数据
void HpPop(Hp* ps);//堆删除数据，规则是删除堆顶的数据：意义是什么？删除最大的老二才能找到，老二删除，老三才能找到，有助于快速找到前几名
//【优点】向下调整--第一个和最后一个交换，不会影响堆的大结构兄弟还是兄弟，父子还是父子
//【交换堆顶数据和最后一个数据】
//【删除数据】--即可 
//【向下调整】--哪个儿子大就和哪个儿子比
//【结束标志】子叶就是结束标志，因为子叶没有儿子，因为儿子下标超出数组大小了
HPDataType HpTop(Hp* ps);//获取堆顶数据
bool HpEmpty(Hp* ps);//判断堆是否为空
int HpSize(Hp* ps);//获取堆的有效数据的大小