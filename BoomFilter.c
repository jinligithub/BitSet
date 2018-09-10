#include"BitSet.h"
#include"BoomFilter.h"

void BloomFilterInit(BloomFilter* pbf, int keyN)//��ʼ����¡
{
	assert(pbf);
	BitSetInit(&pbf->_bs, keyN*5);//��λͼ�Ŵ󣬼��ٹ�ϣ��ͻ
}
void BloomFilterDestroy(BloomFilter* pbf)//���ٲ�¡
{
	assert(pbf);
	BitSetDestory(&pbf->_bs);
}
//������ò�ͬ�Ĺ�ϣ�㷨����������ͬ��λ��
int BFPHHash1(BFDataType x)//��ϣ�㷨1
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
int BFPHHash2(BFDataType x)//��ϣ�㷨2
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

int BFPHHash3(BFDataType x)//��ϣ�㷨3
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
void BloomFilterSet(BloomFilter* pbf, BFDataType x)//��ǲ�¡,������ϣ�㷨ӳ�����ͬ��λ��
{
	int hash1 = BFPHHash1(x) % pbf->_bs._N;
	int hash2 = BFPHHash2(x) % pbf->_bs._N;
	int hash3 = BFPHHash3(x) % pbf->_bs._N;
	BitSetSet(&pbf->_bs, hash1);
	BitSetSet(&pbf->_bs, hash2);
	BitSetSet(&pbf->_bs, hash3);
}
//void BloomFilterReSet(BloomFilter* pbf, int keyN);//ɾ����¡��
//�ر�ע����ǲ�¡��֧��ɾ������Ϊ���������������ܶ�����ݶ�Ӧ��ͬ��λ�ã�ɾ���ͻᵼ���������ݲ�������
int BloomFilterTest(BloomFilter* pbf, BFDataType x)//��Ⲽ¡�е������Ƿ����
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