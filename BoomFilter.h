#include"BitSet.h"
typedef char* BFDataType;
typedef struct BloomFilter
{
	BitSet _bs;//λͼ
}BloomFilter;

void BloomFilterInit(BloomFilter* pbf, int keyN);//��ʼ����¡
void BloomFilterDestroy(BloomFilter* pbf);//���ٲ�¡
void BloomFilterSet(BloomFilter* pbf, BFDataType x);//��ǲ�¡
//void BloomFilterReSet(BloomFilter* pbf, int keyN);//ɾ����¡��
//�ر�ע����ǲ�¡��֧��ɾ������Ϊ���������������ܶ�����ݶ�Ӧ��ͬ��λ�ã�ɾ���ͻᵼ���������ݲ�������
int BloomFilterTest(BloomFilter* pbf, BFDataType x);//��Ⲽ¡�е������Ƿ����
void TestBloomFilter();//����
