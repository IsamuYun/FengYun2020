#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short", "����ͤ");
        set("long", @LONG
���ǳ�����ĵ���ͤ������Ǹ������ĵط��������������˵
��ú��ѵã����������������ͨ������(diao)����þ����Ǳ
�ܣ��������õ������㻻��Ǯ��
LONG
        );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);

        set("exits", ([
"east":__DIR__"cx4",
]));
        setup();
}

void init()
{
        add_action("do_diao","diao");
}

int do_diao(string arg)
{
        object me = this_player();
        int bonus,exp,pot;
        object mon,dan;

        if( me->query("level") < 3 )
              return notify_fail("��ĵȼ������ʺϵ��㡣\n");
        if (!arg)
              return notify_fail("��Ҫ��ʲô��\n");
        if (arg != "fish")
              return notify_fail("����ֻ�ܵ��㡣\n");
        if( (int)me->query_temp("fishing") ) 
              return notify_fail("���Ѿ��ڵ����ˡ�\n");
        if ((int)(me->query("sen")) < 16)        
              return notify_fail("�ٵ����İ�С���͵����㻹����Ϣһ�°ɡ�\n");

        message_vision("
$N��������ڹ��ϣ�����һ����ͣ�������ӽ�ˮ�\n\n",me);
        me->set_temp("fishing",1);
        me->add("sen",-15);
		if (me->query("longstory") == 1)
		{
			me->set("longstory",2);
			write( YEL"������Ի�ò������ӣ������Ļ���ʡ�õ㻨��ȥ��ʦѧϰ��������Ӧ�û��ǹ��ġ�\n");
			write( "����4���Ļ����������ҷ��Ƴǵ���̫�Ŵ���׬Ǯ��\n");
			write( "�Ժ�Ļ�������ȼ�������ʮ�����Ϳ��Խ������������ˣ�����׬Ǯ�Ǻܿ�ġ�\n"NOR);
		}
		if( me->query("workforfish") > 100 )
              return notify_fail("�������Ѿ����ܵ����ˡ�\n");
        call_out("del_fishing", 6, me, mon, bonus, exp, pot);
        return 1;
}

void del_fishing(object me, object mon, int bonus, int exp, int pot)
{
        me->delete_temp("fishing");
        if (random (10) < 2)
{
       message_vision(HIY"
ֻ����Ư����������£�$N�Ͻ�������ͣ�������һ�����װ׵��㹳��
ʲôҲû�У�ԭ����̫�ļ��ˡ�û������ѹ��Խ�ȥ����������ˡ�\n"NOR,me);
        me->start_busy(6);
        return ;
}
        else
{
        exp = 20 + random(8);
        pot = exp/7	;
		message_vision(HIW"
   ��Ư�ڶ��ˣ�$N��Ϣ������������ס��Ư��������˽�����⣬ֻ
����Ư�͵�����һ����$Nץסʱ��һ��ͣ�$N������һ��" + chinese_number(exp) + "���ص��㡣\n\n"NOR
"$N����ͻȻ���һ���㷷��һ�ѽ�$N�����н�����ߣ�˳���Ӹ�$Nһ�����ӡ�\n",me);
        bonus = (int) me->query("combat_exp");
        bonus += exp;
        me->set("combat_exp", bonus);
		write("������\n"+chinese_number(exp)+"�㾭�顣\n");
        bonus = (int) me->query("potential");
        bonus += pot;
		write(chinese_number(pot)+"��Ǳ�ܡ�\n");
		me->add("workforfish",1);
        me->set("potential", bonus);
        mon = new("/obj/money/silver");
        mon->set_amount(exp / 4);
		write(chinese_number(exp/4)+"�����ӡ�\n");
        mon->move(me);
        me->start_busy(6);
        return;
}
}