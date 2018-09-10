#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>
#include<string.h>

typedef struct BitSet
{
	char *_bits;
	size_t _N;//位的格数
}BitSet;


void BitSetInit(BitSet*pbs, size_t n);//位图的初始化
void BitSetDestory(BitSet*  pbs);//位图的销毁
void BitSetSet(BitSet* pbs, size_t x);//位图的标记
void BitSetReSet(BitSet* pbs, size_t x);//位图的
int BitSetTest(BitSet *pbs, size_t x);//判断x是否存在
void TestBitSet();//测试函数