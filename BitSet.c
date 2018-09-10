#include"BitSet.h"
void BitSetInit(BitSet*pbs, size_t n)//位图的初始化,n表示位图位的个数
{
	assert(pbs);
	pbs->_bits = (char*)malloc((n >> 3) + 1);//开辟n/8+1个字节，一个字节等于八个比特位，n>>3==n/8。同时要注意优先级
	memset(pbs->_bits, 0, (n >> 3) + 1);//全部初始化位0
	pbs->_N = n;
}
void BitSetDestory(BitSet *pbs)//位图的销毁
{
	assert(pbs);
	free(pbs->_bits);//直接释放位图就ok
	pbs->_bits = NULL;//防止野指针的出现
	pbs->_N = 0;
	printf("销毁成功\n");
}
void BitSetSet(BitSet* pbs, size_t x)//位图的标记
{
	assert(pbs);
	//int index = x / 8;
	int index = x >> 3;//确定在位图的第几个字节里
	int num = x % 8;//确定在该字节里的哪个位置
	pbs->_bits[index] |= (1 << num);//让1左移num位，在或“|”，就把该位标记为1
}
void BitSetReSet(BitSet* pbs, size_t x)//位图的删除
{
	assert(pbs);
	int index = x >> 3;
	int num = x % 8;
	pbs->_bits[index] &= ~(1 << num);//“~”为取反符号，让1左移num位，取反之后num位为0，其他位为1。
	//& 一假则假，所以就可以删除这个数

}
int BitSetTest(BitSet *pbs, size_t x)//判断x是否存在
{
	assert(pbs);
	int index = x >> 3;
	int num = x % 8;
	return (pbs->_bits[index] & (1 << num)) == 0 ? 0 : 1;//不存在返回0，存在返回1
}
void TestBitSet()
{
	BitSet bs;
	BitSetInit(&bs, 10);
	BitSetSet(&bs, 12);
	BitSetSet(&bs, 8);
	BitSetSet(&bs, 62);
	BitSetSet(&bs, 15);

	printf("%d\n", BitSetTest(&bs, 12));
	printf("%d\n", BitSetTest(&bs, 8));
	printf("%d\n", BitSetTest(&bs, 62));
	printf("%d\n", BitSetTest(&bs, 15));
	printf("%d\n", BitSetTest(&bs, 25));
	printf("%d\n", BitSetTest(&bs, 100));
	BitSetDestory(&bs);
	BitSetReSet(&bs, 8);
	printf("%d\n", BitSetTest(&bs, 8));

}