#include"BitSet.h"
#include"BoomFilter.h"

void BloomFilterInit(BloomFilter* pbf, int keyN)//初始化布隆
{
	assert(pbf);
	BitSetInit(&pbf->_bs, keyN*5);//把位图放大，减少哈希冲突
}
void BloomFilterDestroy(BloomFilter* pbf)//销毁布隆
{
	assert(pbf);
	BitSetDestory(&pbf->_bs);
}
//这里采用不同的哈希算法，产生出不同的位置
int BFPHHash1(BFDataType x)//哈希算法1
{
	int hash = 0;
	char *p = x;
	while (*p)
	{
		hash = hash * 131 + *p;
		p++;
	}
	return hash;
}
int BFPHHash2(BFDataType x)//哈希算法2
{
	int hash = 0;
	char *p = x;
	while (*p)
	{
		hash = hash * 1313 + *p;
		p++;
	}
	return hash;
}

int BFPHHash3(BFDataType x)//哈希算法3
{
	int hash = 0;
	char *p = x;
	while (*p)
	{
		hash = hash * 13131 + *p;
		p++;
	}
	return hash;
}
void BloomFilterSet(BloomFilter* pbf, BFDataType x)//标记布隆,三个哈希算法映射出不同的位置
{
	int hash1 = BFPHHash1(x) % pbf->_bs._N;
	int hash2 = BFPHHash2(x) % pbf->_bs._N;
	int hash3 = BFPHHash3(x) % pbf->_bs._N;
	BitSetSet(&pbf->_bs, hash1);
	BitSetSet(&pbf->_bs, hash2);
	BitSetSet(&pbf->_bs, hash3);
}
//void BloomFilterReSet(BloomFilter* pbf, int keyN);//删除布隆，
//特别注意的是布隆不支持删除。因为可其他数不存在能多个数据对应相同的位置，删除就会导致其他数据不存在了
int BloomFilterTest(BloomFilter* pbf, BFDataType x)//检测布隆中的数据是否存在
{
	int hash1 = BFPHHash1(x) % pbf->_bs._N;
	if (BitSetTest(&pbf->_bs, hash1) == 0)
		return 0;
	int hash2 = BFPHHash2(x) % pbf->_bs._N;
	if (BitSetTest(&pbf->_bs, hash2) == 0)
		return 0;
	int hash3 = BFPHHash3(x) % pbf->_bs._N;
	if (BitSetTest(&pbf->_bs, hash2) == 0)
		return 0;
	return 1;
}
void TestBloomFilter()
{
	BloomFilter bf;
	BloomFilterInit(&bf, "char");
	BloomFilterSet(&bf, "sort");
	BloomFilterSet(&bf, "int");
	BloomFilterSet(&bf,"myop");
	BloomFilterSet(&bf, "fangtao");
	BloomFilterSet(&bf, "jinli");

	printf("%d\n", BloomFilterTest(&bf, "char"));
	printf("%d\n", BloomFilterTest(&bf, "int"));
	printf("%d\n", BloomFilterTest(&bf, "sort"));
	printf("%d\n", BloomFilterTest(&bf, "fangtao"));
	printf("%d\n", BloomFilterTest(&bf, "jinli"));
	BloomFilterDestroy(&bf);
}