#include "REG51.H"

// ���жϳ�ʼ������
void EX0_init()
{
    IT0 = 1;    // �½��ش���
    PX0 = 1;    // �����ȼ�
    EX0 = 1;    // �����ж�����
    EA = 1;     // ���ж�����
}