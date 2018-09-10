#include"BitSet.h"
void BitSetInit(BitSet*pbs, size_t n)//λͼ�ĳ�ʼ��,n��ʾλͼλ�ĸ���
{
	assert(pbs);
	pbs->_bits = (char*)malloc((n >> 3) + 1);//����n/8+1���ֽڣ�һ���ֽڵ��ڰ˸�����λ��n>>3==n/8��ͬʱҪע�����ȼ�
	memset(pbs->_bits, 0, (n >> 3) + 1);//ȫ����ʼ��λ0
	pbs->_N = n;
}
void BitSetDestory(BitSet *pbs)//λͼ������
{
	assert(pbs);
	free(pbs->_bits);//ֱ���ͷ�λͼ��ok
	pbs->_bits = NULL;//��ֹҰָ��ĳ���
	pbs->_N = 0;
	printf("���ٳɹ�\n");
}
void BitSetSet(BitSet* pbs, size_t x)//λͼ�ı��
{
	assert(pbs);
	//int index = x / 8;
	int index = x >> 3;//ȷ����λͼ�ĵڼ����ֽ���
	int num = x % 8;//ȷ���ڸ��ֽ�����ĸ�λ��
	pbs->_bits[index] |= (1 << num);//��1����numλ���ڻ�|�����ͰѸ�λ���Ϊ1
}
void BitSetReSet(BitSet* pbs, size_t x)//λͼ��ɾ��
{
	assert(pbs);
	int index = x >> 3;
	int num = x % 8;
	pbs->_bits[index] &= ~(1 << num);//��~��Ϊȡ�����ţ���1����numλ��ȡ��֮��numλΪ0������λΪ1��
	//& һ����٣����ԾͿ���ɾ�������

}
int BitSetTest(BitSet *pbs, size_t x)//�ж�x�Ƿ����
{
	assert(pbs);
	int index = x >> 3;
	int num = x % 8;
	return (pbs->_bits[index] & (1 << num)) == 0 ? 0 : 1;//�����ڷ���0�����ڷ���1
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