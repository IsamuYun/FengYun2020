#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIG"���ƹ㳡������"NOR);
        set("long", @LONG
���ƳǵĹ㳡�������ǣ����Ϸ������Ľֵ��������γ�һ���޴�Ĺ㳡��
�㳡�������Ƿ�԰Լʮ�ɵ�ˮ�أ�������ββ���������е����Ρ���ɫ����������̵�
��Ƽ�໥��ӳ��������Ŀ����ˮ��������һ��ʯ����ʯ���Ͽ���һ����ͷ������������
����չ����ΰ׳�ۡ�ÿ�����죬����������ӿ�����ף�������֮�ᣬ����鳦��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
          "southeast" : "/d/fy/fysquare",
          			"south": __DIR__"fysq3",
          		"east":  __DIR__"fysq1",
]));
			
        set("outdoors", "fengyun");
      set("objects", ([
      __DIR__"npc/jobnpc" : 1,
   ]) );
	set("trade",1);
	set("NONPC",1);
        set("no_fight",1);
        set("no_magic",1);
        set("no_beg",1);
        set("no_du",1);
        set("no_sheet",1);
        set("no_dazuo",1);
        set("coor/x",0);
	set("coor/y",0);
        set("coor/z",0);
        setup();
}
void init()
{
add_action("do_look","look");
add_action("do_look","l");
}
int do_look(string arg)
{
	object *inv,ob,me,money;
	object price;
	string name;
	int i,j;
	me = this_player();
	if(!arg || sscanf(arg,"%s",name) != 1)
                     return notify_fail("��������ȷ�ĸ�ʽ��look <id>��\n");
          if( me->is_busy() )
                    return notify_fail("����һ��������û����ɣ�\n");
      if(me->query("combat_exp") < 1000000 )
		return notify_fail("��ľ���̫�͡�\n");
	if(!objectp(ob = present(name, environment(me))) || !living(ob))
		return notify_fail("����û������ˡ�\n");
	if (!userp(ob))
		return notify_fail("�Է�������ҡ�\n");
	if(!ob->query_temp("in_trade"))
		return notify_fail(ob->query("name")+"��û���ڰ�̯����\n");
 	if(me->is_ghost())
		   return notify_fail("�����û�а취���׵ġ�\n");
      if( me->is_fighting() )
             return notify_fail("ս���в��ܽ��н��ס�\n");
       printf(HIB"������������������������������������"HIY"̯λ�б�"HIB"������������������������\n"NOR);
	inv = all_inventory(ob);
	printf("Ŀǰ%s���۵Ļ����У�\n"NOR,ob->query("name"));
	for (i = 0 ;i < sizeof(inv);i++)
		{
		if (inv[i]->query_temp("trading"))
		        {
			if(inv[i]->query("selfmaking"))
				printf("��Ʒ  ��%s(%s) "+NOR+"ǿ���ȣ�%d �˺���%d ������%d �۸�%10d\n" NOR,inv[i]->query("name"),inv[i]->query("id"),inv[i]->query("leveled"),inv[i]->query("base_damage"),inv[i]->query("armor_prop/defense"),inv[i]->query_temp("price"));
			else
				printf("��Ʒ  ��%s(%s)"+NOR+"    �۸� �� %10d \n" NOR,inv[i]->query("name"),inv[i]->query("id"),inv[i]->query_temp("price"));
			j ++;
			}

		}
	if (j>0)
		printf("����"HIY"%d"NOR"����\n",j);
	else 
		printf(HIR"���ޡ�\n"NOR);
       printf(HIB"��������������������������������������������������������������������\n"NOR);
	return 1;
}

