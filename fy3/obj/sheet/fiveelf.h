// yiru@hero 2000.8.20

// 五行伤害计算函数
#include <condition.h>

// damage:  原伤害值
// attr:    攻击技能属性
// myattr:  自己的属性
// hisattr: 对方的属性

int fivedamage(int damage, int attr, int myattr, int hisattr)
{
    // 自己戴珠子的增益
    if( attr & myattr ) damage=damage*3/2;
    // 敌方相同属性的抵消
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
    // 超出三界外，不在五行中
    if(!hisattr) damage = -damage;

    return damage;
}
