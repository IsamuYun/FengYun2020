#include <ansi.h>
inherit ITEM;

void init()
{
       add_action("do_qu","qu");
}
void create()
{
      set_name( MAG"李熙的邀请函"NOR, ({ "yaoqing han" }) );
        set_weight(1);
        set("unit", "个");
        set("long",HIG"这是巫师李熙的邀请函，有了这个，你就可以直接去（qu）李熙那里了！\n" + "不过先提醒大家，去那里不要带贵重物品，不要乱拿东西，否则一切后果自负！\n"NOR);
        
        setup();
}
int do_qu()
{
        object me; 
        me = this_player();
        me->move("/d/fy/poemp");
        message_vision(HIY + "\n$N大声吆喝道：" + "我去赴李熙的邀请了！\n\n" + NOR + "你只觉得眼前狂风大作，转眼之间你就来到了李熙的工作间" + NOR + "！\n\n",me);
        destruct(this_object());
        message_vision(YEL"邀请函神奇般的消失了\n"NOR,me);
        return 1;
}
