// garrison.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("������͵���̫��", ({ "taipo", "po" }) );
        set("long",
                "���Ƴ������ϵ���̫�ţ�������С����������\n");

	set("gender","Ů��");
        set("str", 27);
        set("cor", 26);
        set("cps", 25);
		  set_temp("kf_tufei",60);
        set("pursuer", 1);
set("age", 99);
        set("combat_exp", 0);
        setup();
        carry_object("obj/cloth")->wear();
}

void init()
{
        ::init();
        add_action("do_work", "work");

}
int do_work(string arg)
{
        object ob;
        object me;
		int exp,pot;
        me = this_player();
if(me->is_busy()) return notify_fail("��Ķ�����û����ɣ����ܹ�����\n");
        if( me->query("level") < 4 )
              return notify_fail("��ĵȼ����ʺ���������ˡ�\n");



		if (me->query("longstory") == 2)
		{
			me->set("longstory",3);
			write( YEL"���������ô�������ĵĻ����Ի���������������򹤣���Ȼ����ͬ�������ġ�\n");
			write( "�����弶�Ļ����Ϳ��Ե�����ȥ��ʦ���������������Ҫ���ƿ����ҷ��Ƴǵ�������\n"NOR);
		}
		        if( me->query("workfortaipo") > 100 )
              return notify_fail("���˹��ˣ���̫�Ų�����Ҫ���æ�ˡ�\n");

message_vision("$N����Ĺ������ڽ����ˣ�����Ҳ�۵�Ҫ��\n",me);
me->add("gin",-30);
me->add("sen",-30);
 exp = 30 + random(20);
        pot = exp/7	;
		me->add("combat_exp",exp);
		me->add("potential",pot);
		me->add("workfortaipo",1);
		write("������\n"+chinese_number(exp)+"�㾭�顣\n");
		write(chinese_number(pot)+"��Ǳ�ܡ�\n");

ob = new("/obj/money/silver");
ob->move(me);
message_vision("������͵���̫�Ŷ�$N˵��������Ĺ�Ǯ��\n", me);
me->start_busy(5);
return 1;
}