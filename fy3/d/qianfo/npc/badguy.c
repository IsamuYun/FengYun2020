// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("ɥ������������", ({ "pig" }) );
        set("gender", "����");
        set("age", 24);
	set("str",30);
        set("long",
                "��������ڹ��컯����ǿ����Ů������\n");
        set("combat_exp", 6000);
        set("score", 400);
        set("chat_chance", 50);
        set("chat_msg", ({
                "ɥ��������������Ц�Ű�����ǧ��С���Ь�ӣ���\n",
		"ɥ��������������Ц�Ű�����ǧ��С������ӣ���\n",
		"ɥ��������������Ц�Ű�����ǧ��С��ģ�������\n",
        }) );
        set_skill("unarmed", 100);
        set_skill("parry", 20);
        set_skill("dodge", 40);
        setup();
}
void init()
{
add_action("do_look","look");
}

int do_look(string arg)
{

if (arg == "pig" )
{
write("��������ڹ��컯����ǿ����Ů������\n");
write("��������Լ��ʮ���ꡣ\n");
write("�书������������ɲ⣬�����ƺ����ء�\n");
return 1;
}
return 0;
}

void die()
{
	object me;
	me=this_object()->query_temp("last_damage_from");
	if(objectp(me))
        me->set_temp("marks/lady",1);
::die();
}
