//gift's baotu by tiandi 20071229
#include <ansi.h>;
inherit ITEM;
string *gifts = ({
"/obj/weapons/banzhi",
"/obj/weapons/banzhi2",
"/obj/weapons/banzhi3",
"/obj/weapons/banzhi4",
"/obj/weapons/banzhi5",
"/obj/weapons/banzhi6",
"/obj/weapons/banzhi7",
"/obj/weapons/banzhi8",
"/obj/weapons/banzhi9",
"/obj/weapons/banzhi10",
"/obj/weapons/banzhi",
"/obj/weapons/banzhi2",
"/obj/weapons/banzhi3",
"/obj/weapons/banzhi4",
"/obj/weapons/banzhi5",
"/obj/weapons/banzhi6",
"/obj/weapons/banzhi7",
"/obj/weapons/banzhi8",
"/obj/weapons/banzhi9",
"/obj/weapons/banzhi10",
"/obj/weapons/banzhi",
"/obj/weapons/banzhi2",
"/obj/weapons/banzhi3",
"/obj/weapons/banzhi4",
"/obj/weapons/banzhi5",
"/obj/weapons/banzhi6",
"/obj/weapons/banzhi7",
"/obj/weapons/banzhi8",
"/obj/weapons/banzhi9",
"/obj/weapons/banzhi10",
"/obj/weapons/banzhi",
"/obj/weapons/banzhi2",
"/obj/weapons/banzhi3",
"/obj/weapons/banzhi4",
"/obj/weapons/banzhi5",
"/obj/weapons/banzhi6",
"/obj/weapons/banzhi7",
"/obj/weapons/banzhi8",
"/obj/weapons/banzhi9",
"/obj/weapons/banzhi10",
"/obj/weapons/banzhi",
"/obj/weapons/banzhi2",
"/obj/weapons/banzhi3",
"/obj/weapons/banzhi4",
"/obj/weapons/banzhi5",
"/obj/weapons/banzhi6",
"/obj/weapons/banzhi7",
"/obj/weapons/banzhi8",
"/obj/weapons/banzhi9",
"/obj/weapons/banzhi10",
"/obj/weapons/banzhi",
"/obj/weapons/banzhi2",
"/obj/weapons/banzhi3",
"/obj/weapons/banzhi4",
"/obj/weapons/banzhi5",
"/obj/weapons/banzhi6",
"/obj/weapons/banzhi7",
"/obj/weapons/banzhi8",
"/obj/weapons/banzhi9",
"/obj/weapons/banzhi10",
"/obj/weapons/banzhi",
"/obj/weapons/banzhi2",
"/obj/weapons/banzhi3",
"/obj/weapons/banzhi4",
"/obj/weapons/banzhi5",
"/obj/weapons/banzhi6",
"/obj/weapons/banzhi7",
"/obj/weapons/banzhi8",
"/obj/weapons/banzhi9",
"/obj/weapons/banzhi10",
"/obj/weapons/banzhi",
"/obj/weapons/banzhi2",
"/obj/weapons/banzhi3",
"/obj/weapons/banzhi4",
"/obj/weapons/banzhi5",
"/obj/weapons/banzhi6",
"/obj/weapons/banzhi7",
"/obj/weapons/banzhi8",
"/obj/weapons/banzhi9",
"/obj/weapons/banzhi10",
"/obj/weapons/swordbook",
"/obj/weapons/swordbook2",
"/obj/weapons/swordbook3",
"/obj/weapons/swordbook4",
"/obj/weapons/swordbook5",
"/obj/weapons/swordbook6",
"/obj/weapons/swordbook7",
"/obj/weapons/swordbook8",
"/obj/weapons/swordbook9",
"/obj/weapons/swordbook10",
"/obj/weapons/bladebook",
"/obj/weapons/bladebook2",
"/obj/weapons/bladebook3",
"/obj/weapons/bladebook4",
"/obj/weapons/bladebook5",
"/obj/weapons/bladebook6",
"/obj/weapons/bladebook7",
"/obj/weapons/bladebook8",
"/obj/weapons/bladebook9",
"/obj/weapons/bladebook10",
"/obj/weapons/staffbook",
"/obj/weapons/staffbook2",
"/obj/weapons/staffbook3",
"/obj/weapons/staffbook4",
"/obj/weapons/staffbook5",
"/obj/weapons/staffbook6",
"/obj/weapons/staffbook7",
"/obj/weapons/staffbook8",
"/obj/weapons/staffbook9",
"/obj/weapons/staffbook10",
"/obj/weapons/hammerbook",
"/obj/weapons/hammerbook2",
"/obj/weapons/hammerbook3",
"/obj/weapons/hammerbook4",
"/obj/weapons/hammerbook5",
"/obj/weapons/hammerbook6",
"/obj/weapons/hammerbook7",
"/obj/weapons/hammerbook8",
"/obj/weapons/hammerbook9",
"/obj/weapons/hammerbook10",
"/obj/weapons/ringbook",
"/obj/weapons/ringbook2",
"/obj/weapons/ringbook3",
"/obj/weapons/ringbook4",
"/obj/weapons/ringbook5",
"/obj/weapons/ringbook6",
"/obj/weapons/ringbook7",
"/obj/weapons/ringbook8",
"/obj/weapons/ringbook9",
"/obj/weapons/ringbook10",
"/obj/armors/headbook",
"/obj/armors/headbook2",
"/obj/armors/headbook3",
"/obj/armors/headbook4",
"/obj/armors/headbook5",
"/obj/armors/headbook6",
"/obj/armors/headbook7",
"/obj/armors/headbook8",
"/obj/armors/headbook9",
"/obj/armors/headbook10",
"/obj/armors/clothbook",
"/obj/armors/clothbook2",
"/obj/armors/clothbook3",
"/obj/armors/clothbook4",
"/obj/armors/clothbook5",
"/obj/armors/clothbook6",
"/obj/armors/clothbook7",
"/obj/armors/clothbook8",
"/obj/armors/clothbook9",
"/obj/armors/clothbook10",
"/obj/armors/neckbook",
"/obj/armors/neckbook2",
"/obj/armors/neckbook3",
"/obj/armors/neckbook4",
"/obj/armors/neckbook5",
"/obj/armors/neckbook6",
"/obj/armors/neckbook7",
"/obj/armors/neckbook8",
"/obj/armors/neckbook9",
"/obj/armors/neckbook10",
"/obj/armors/bootsbook",
"/obj/armors/bootsbook2",
"/obj/armors/bootsbook3",
"/obj/armors/bootsbook4",
"/obj/armors/bootsbook5",
"/obj/armors/bootsbook6",
"/obj/armors/bootsbook7",
"/obj/armors/bootsbook8",
"/obj/armors/bootsbook9",
"/obj/armors/bootsbook10",
"/obj/armors/waistbook",
"/obj/armors/waistbook",
"/obj/armors/waistbook2",
"/obj/armors/waistbook3",
"/obj/armors/waistbook4",
"/obj/armors/waistbook5",
"/obj/armors/waistbook6",
"/obj/armors/waistbook7",
"/obj/armors/waistbook8",
"/obj/armors/waistbook9",
"/obj/armors/waistbook10",
"/obj/armors/wristsbook",
"/obj/armors/wristsbook2",
"/obj/armors/wristsbook3",
"/obj/armors/wristsbook4",
"/obj/armors/wristsbook5",
"/obj/armors/wristsbook6",
"/obj/armors/wristsbook7",
"/obj/armors/wristsbook8",
"/obj/armors/wristsbook9",
"/obj/armors/wristsbook10",
"/obj/armors/fingerbook",
"/obj/armors/fingerbook2",
"/obj/armors/fingerbook3",
"/obj/armors/fingerbook4",
"/obj/armors/fingerbook5",
"/obj/armors/fingerbook6",
"/obj/armors/fingerbook7",
"/obj/armors/fingerbook8",
"/obj/armors/fingerbook9",
"/obj/armors/fingerbook10",
"/obj/armors/shieldbook",
"/obj/armors/shieldbook2",
"/obj/armors/shieldbook3",
"/obj/armors/shieldbook4",
"/obj/armors/shieldbook5",
"/obj/armors/shieldbook6",
"/obj/armors/shieldbook7",
"/obj/armors/shieldbook8",
"/obj/armors/shieldbook9",
"/obj/armors/shieldbook10",
"/obj/food/cj",
"/obj/food/cj2",
"/obj/food/cj3",
"/obj/food/cj4",
"/obj/food/cj5",
"/obj/food/cj6",
"/obj/food/cj7",
"/obj/food/cj8",
"/obj/food/cj9",
"/obj/food/cj10",
"/obj/food/dan1",
"/obj/food/dan2",
"/obj/food/dan3",
"/obj/food/dan4",
"/obj/food/dan5",
"/obj/food/dan6",
"/obj/food/dan7",
"/obj/food/dan8",
"/obj/food/dan9",
"/obj/food/dan10",
"/d/wiz/fyup/obj/qh1",
"/d/wiz/fyup/obj/qh2",
"/d/wiz/fyup/obj/qh3",
"/d/wiz/fyup/obj/qh4",
"/d/wiz/fyup/obj/qh5",
"/d/wiz/fyup/obj/sheet",
});

string *wheres = ({
"���",
 "���ַ�",
"�춼��",
"ʮ����",
 "������",
"��ĸʯ",
 "���",
"����ɽ",
"��ɽ��®",
});

void create()
{
set_name( HIW"�ر�ͼ"NOR, ({ "treasure" }));;
set_weight(10);
set("value", 10000);
set("unit", "��");
set("long", "һ�Ųر�ͼ������Բ鿴(checkmap)��������λ�ã�Ȼ��ָ���ĵص��ھ�(dig)���Ϳ��ܻᷢ�ֱ��ء�\n");
setup();
}
void init()
{
        add_action("do_dig", "dig");
        add_action("do_check", "checkmap");
}

int do_dig()
{
        object me,gift_give;
        int i,money;
        me = this_player();
        i = random(10);
	if(environment(me)->query("short") != this_object()->query_temp("place"))
	{
		return notify_fail("������ϸ����ͼ�ϵ�λ�ðɡ�\n");
	}
	else if(i == 0)
	{
	       tell_object(me,"\n���ó�һ��С���£�����������\n"NOR);
	       tell_object(me,"���ź��������ʲô��û�з��֡�\n"NOR);
	}
	else if( i == 1)
	{
                   tell_object(me,"\n���ó�һ��С���£�����������\n"NOR);
	       tell_object(me,"���ֻ�����һ�����㱻��֪��ʲô����ը���ˡ�\n"NOR);
	       me->move("/d/fy/church");
		   message("rumor", HIM"��ҥ�Ի��ڡ�ĳ�ˣ���˵"+me->query("name")+"�ڱ���ʱ�������˻��أ���ը���ˣ�\n" NOR,users());
	       me->unconcious();
	}
	else if( i == 2)
	{
                   tell_object(me,"\n���ó�һ��С���£�����������\n"NOR);
	       tell_object(me,"���������һЩ�ƽ�\n"NOR);
	       gift_give = new("/obj/money/gold");
		   money = random(100);
		   gift_give->set_amount(money);
	       message("rumor", HIM"��ҥ�Ի��ڡ�ĳ�ˣ���˵"+me->query("name")+"���ݲر�ͼ�ϵ������ڵ���"+chinese_number(money)+"��"+HIY+gift_give->query("name")+HIM"��\n" NOR,users());

                   gift_give->move(me);
	}
	else
	{
                   gift_give = new(gifts[random(sizeof(gifts))]);
                   gift_give->move(me);
	       tell_object(me,"\n���ó�һ��С���£�����������\n"NOR);
	       tell_object(me,"��ϲ�����ڵ���"+gift_give->query("name")+"��\n"NOR);
	       message("rumor", HIM"��ҥ�Ի��ڡ�ĳ�ˣ���˵"+me->query("name")+"���ݲر�ͼ�ϵ������ڵ���"HIY+gift_give->query("name")+HIM"��\n" NOR,users());

	}
                   destruct(this_object());
                   return 1;
}

int do_check()
{
            string where;
	if (query_temp("place"))
		return notify_fail("���ű�ͼ��ʾ��λ�ú�����"+query_temp("place")+"������\n");
	else
		{
		where = wheres[random(sizeof(wheres))];
		set_temp("place",where);
		set("value",0);
		return notify_fail("���ű�ͼ��ʾ��λ�ú�����"+query_temp("place")+"������\n");
		}
	return 1;
}

