// yiru@hero 2000.8.20

// �����˺����㺯��
#include <condition.h>

// damage:  ԭ�˺�ֵ
// attr:    ������������
// myattr:  �Լ�������
// hisattr: �Է�������

int fivedamage(int damage, int attr, int myattr, int hisattr)
{
    // �Լ������ӵ�����
    if( attr & myattr ) damage=damage*3/2;
    // �з���ͬ���Եĵ���
    if( attr & myattr ) damage=0;

    switch (attr){
    case NA_FENG:
        if(hisattr & NA_LEI) damage*=3;
        break;
    case NA_LEI:
        if(hisattr & NA_SHUI) damage*=3;
        break;
    case NA_SHUI:
        if(hisattr & NA_HUO) damage*=3;
        break;
    case NA_HUO:
        if(hisattr & NA_TU) damage*=3;
        break;
    case NA_TU:
        if(hisattr & NA_FENG) damage*=3;
        break;
    }
    // ���������⣬����������
    if(!hisattr) damage = -damage;

    return damage;
}
