#include <ansi.h>
inherit ITEM;

void init()
{
       add_action("do_qu","qu");
}
void create()
{
      set_name( MAG"���������뺯"NOR, ({ "yaoqing han" }) );
        set_weight(1);
        set("unit", "��");
        set("long",HIG"������ʦ���������뺯�������������Ϳ���ֱ��ȥ��qu�����������ˣ�\n" + "���������Ѵ�ң�ȥ���ﲻҪ��������Ʒ����Ҫ���ö���������һ�к���Ը���\n"NOR);
        
        setup();
}
int do_qu()
{
        object me; 
        me = this_player();
        me->move("/d/fy/poemp");
        message_vision(HIY + "\n$N����ߺ�ȵ���" + "��ȥ�������������ˣ�\n\n" + NOR + "��ֻ������ǰ��������ת��֮����������������Ĺ�����" + NOR + "��\n\n",me);
        destruct(this_object());
        message_vision(YEL"���뺯��������ʧ��\n"NOR,me);
        return 1;
}
