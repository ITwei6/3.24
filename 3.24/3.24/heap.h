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
void HpInit(Hp* ps);//��ʼ��
void HpPush(Hp* ps, HPDataType x);//��������
void HpPop(Hp* ps);//��ɾ�����ݣ�������ɾ���Ѷ������ݣ�������ʲô��ɾ�������϶������ҵ����϶�ɾ�������������ҵ��������ڿ����ҵ�ǰ����
//���ŵ㡿���µ���--��һ�������һ������������Ӱ��ѵĴ�ṹ�ֵܻ����ֵܣ����ӻ��Ǹ���
//�������Ѷ����ݺ����һ�����ݡ�
//��ɾ�����ݡ�--���� 
//�����µ�����--�ĸ����Ӵ�ͺ��ĸ����ӱ�
//��������־����Ҷ���ǽ�����־����Ϊ��Ҷû�ж��ӣ���Ϊ�����±곬�������С��
HPDataType HpTop(Hp* ps);//��ȡ�Ѷ�����
bool HpEmpty(Hp* ps);//�ж϶��Ƿ�Ϊ��
int HpSize(Hp* ps);//��ȡ�ѵ���Ч���ݵĴ�С