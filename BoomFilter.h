#include"BitSet.h"
typedef char* BFDataType;
typedef struct BloomFilter
{
	BitSet _bs;//位图
}BloomFilter;

void BloomFilterInit(BloomFilter* pbf, int keyN);//初始化布隆
void BloomFilterDestroy(BloomFilter* pbf);//销毁布隆
void BloomFilterSet(BloomFilter* pbf, BFDataType x);//标记布隆
//void BloomFilterReSet(BloomFilter* pbf, int keyN);//删除布隆，
//特别注意的是布隆不支持删除。因为可其他数不存在能多个数据对应相同的位置，删除就会导致其他数据不存在了
int BloomFilterTest(BloomFilter* pbf, BFDataType x);//检测布隆中的数据是否存在
void TestBloomFilter();//测试
