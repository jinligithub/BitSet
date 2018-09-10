#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>
#include<string.h>

typedef struct BitSet
{
	char *_bits;
	size_t _N;//λ�ĸ���
}BitSet;


void BitSetInit(BitSet*pbs, size_t n);//λͼ�ĳ�ʼ��
void BitSetDestory(BitSet*  pbs);//λͼ������
void BitSetSet(BitSet* pbs, size_t x);//λͼ�ı��
void BitSetReSet(BitSet* pbs, size_t x);//λͼ��
int BitSetTest(BitSet *pbs, size_t x);//�ж�x�Ƿ����
void TestBitSet();//���Ժ���