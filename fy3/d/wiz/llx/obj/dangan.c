// /d/wiz/llx/obj/dangan.c

inherit ITEM;
void create()
#include <ansi.h>

{
        set_name(HIR"������ʵ���ϣ��Ų������㣩"NOR, ({ "dangan" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
WHT"���� �� ���� ���Ⱥ� �� 77��7��1�ճ������־Ӻ���ʡƽ��ɽ�С�
    ������Լ10�����࣬97�꿪ʼ�Ӵ�����Mud����ʱ�����������ߣ�����������
һ�µ���Mud���˵����޵�������ȴ�����������ҵ��Ժ��2000�����ʡ���Ŵ�
���ȱ���ȫʡһƬ����֮�������۵�����������ȼ�������е�Mud֮���������
���¶����ղ��ܡ��������Lpc���߻���ħ������Wiz���С�
    ���˳�Mud�⣬�ᰮStarcraft�����������ϱ��˶��������ܲ����԰Ρ�
    �����ᰮ����ͬ��Ϊ�ѣ���ͬ���䡭��
    ������ϵ��ʽ
    E-mail : foxxh@371.net   Oicq : 157605\n"NOR  
);    
                set("value", 1);
                set("no_drop", 1);
                set("material", "paper");
                }
}
