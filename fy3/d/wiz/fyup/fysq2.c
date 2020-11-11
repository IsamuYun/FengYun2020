#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIG"风云广场西北角"NOR);
        set("long", @LONG
风云城的广场的西北角，东南方宽阔的街道在这里形成一个巨大的广场。
广场的中央是方园约十丈的水池，池中有尾尾金鱼在悠闲的漫游。金色的鱼鳞与碧绿的
浮萍相互辉映，赏心悦目。池水的中央是一条石柱，石柱上刻着一条九头龙。龙首向四
面伸展，宏伟壮观。每当雨天，潺潺雨珠涓涓涌出龙首，如情人之泪，落断情肠。
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
                     return notify_fail("请输入正确的格式，look <id>。\n");
          if( me->is_busy() )
                    return notify_fail("你上一个动作还没有完成！\n");
      if(me->query("combat_exp") < 1000000 )
		return notify_fail("你的经验太低。\n");
	if(!objectp(ob = present(name, environment(me))) || !living(ob))
		return notify_fail("这里没有这个人。\n");
	if (!userp(ob))
		return notify_fail("对方不是玩家。\n");
	if(!ob->query_temp("in_trade"))
		return notify_fail(ob->query("name")+"并没有在摆摊啊。\n");
 	if(me->is_ghost())
		   return notify_fail("鬼魂是没有办法交易的。\n");
      if( me->is_fighting() )
             return notify_fail("战斗中不能进行交易。\n");
       printf(HIB"──────────────────"HIY"摊位列表"HIB"────────────\n"NOR);
	inv = all_inventory(ob);
	printf("目前%s出售的货物有：\n"NOR,ob->query("name"));
	for (i = 0 ;i < sizeof(inv);i++)
		{
		if (inv[i]->query_temp("trading"))
		        {
			if(inv[i]->query("selfmaking"))
				printf("物品  ：%s(%s) "+NOR+"强化度：%d 伤害：%d 防御：%d 价格：%10d\n" NOR,inv[i]->query("name"),inv[i]->query("id"),inv[i]->query("leveled"),inv[i]->query("base_damage"),inv[i]->query("armor_prop/defense"),inv[i]->query_temp("price"));
			else
				printf("物品  ：%s(%s)"+NOR+"    价格 ： %10d \n" NOR,inv[i]->query("name"),inv[i]->query("id"),inv[i]->query_temp("price"));
			j ++;
			}

		}
	if (j>0)
		printf("共计"HIY"%d"NOR"件：\n",j);
	else 
		printf(HIR"暂无。\n"NOR);
       printf(HIB"──────────────────────────────────\n"NOR);
	return 1;
}

