//gift's hongbao by tiandi 20071229
#include <ansi.h>;
inherit ITEM;
string *gifts = ({
"/obj/food/double",
"/obj/food/heiyiauto",
"/d/wiz/fyup/obj/baotu",
});
void create()
{
set_name( HIR"���պ��"NOR, ({ "gift-hongbao" }));;
set_weight(10);
set("value", 0);
set("unit", "��");
set("long", "������ַ��ƵĽ��������ʦ�����ҹ�����յ�ϲ�ã�ͬʱҲ\nϣ�����Խ��Խ֧�ֱ�վ������Դ�(open)������\n");
set("no_get",1);
set("no_drop",1);
setup();
}
void init()
{
        add_action("do_open", "open");
}

int do_open(string arg)
{
        object me,gift_give;
        int exp,pot,i;
        me = this_player();
        exp = me->query("level")*500;
        pot = exp/4;
        if( !arg || arg=="" ) return 0;
        if( arg=="gift-hongbao" || arg =="���" ) {
                   if (!me->query_skill("idle-force"))
                               return notify_fail("�������ɫ�Ǹս����İɣ�������Ϸ�﷢�����˵��\n");

	   if(this_object()->query_temp("giftowner")!=this_player()->query("name"))
			return notify_fail("��������"+this_object()->query_temp("giftowner")+"�Ĳ�����ġ�\n");

/*
                   if (me->query("yuandangift") > 20087 )
                               {message_vision("$N�Ѿ��ù������ˣ������ã��������һ�����̷�������ա�\nֻ����$N���ڵ��Ϸ������૵�:�����һ�����ﶼ���С�����\n",me);
                               return 1;
                               }
*/
                   me->add("combat_exp",exp);
                   me->add("potential",pot);
                   tell_object(me,HIY"�㱻�����ˣ�\n" +
                   chinese_number(exp) + "��ʵս����\n"+chinese_number(pot) + "��Ǳ��\n"+NOR);
                    i = random(100);
                   if (i<50) {
                     tell_object(me,HIY"��л��Ϊ���ַ��������Ĺ��ס�\n"+NOR);
                }else  {
                   gift_give = new(gifts[random(sizeof(gifts))]);
                   gift_give->move(me);
                   tell_object(me,HIW"\n��ϲ��������"+gift_give->query("name")+"��\n"NOR);
				    message("channel:rumor",HIM"��ҥ�Ի��ڡ�ĳ�ˣ�"+"��˵"+me->query("name")+"�����������л����"+gift_give->query("name")+HIM"��\n"NOR,users());
                   }
                   tell_object(me,HIW"\nף�����տ���!\n"NOR);
                   destruct(this_object());
                   return 1;
                   }
        return 1;
        }
