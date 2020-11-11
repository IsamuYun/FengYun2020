// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
	string *name = ({"��","��","ʱ","��","��","��","��","��","��","��","��","ʷ"});
        set_name("һ"+name[random(sizeof(name))], ({ "shaolin monk", "monk"}) );
        set("gender", "����" );
        set("age",random(20)+ 32);
	create_family("������", 18, "����");
        set("long", "���������µĺ���\n");
	set("vendetta_mark","shaolin");
        set("combat_exp", random(300000)+300000);
        set("attitude", "friendly");
        set_skill("hammer", 70+random(100));
	set_skill("liuxing-hammer",random(100)+150);
	set_skill("dodge",100);
        set("chat_chance", 2);
        set("chat_msg", ({
                name()+"˵������ʱ���˰ɣ�\n",
        }) );
	set_skill("move",80);
	set_skill("force",200);
	map_skill("hammer", "liuxing-hammer");
        set("chat_chance_combat", 10);
	set("force",500);
        set("chat_msg_combat", ({
		name()+"Ц��������������Ұ��\n",
                (: perform_action, "hammer.fanbei" :),
        }) );
        set("max_force",500);
	set("force_factor",15);
	setup();
	carry_object(__DIR__"obj/monk_cloth")->wear();
	carry_object(__DIR__"obj/hammer")->wield();
}
void init()
{
        add_action("do_get","get");
}

int do_get(string arg)
{
string what;
if(!arg) return 0;
if(sscanf(arg,"%s",what) !=1) return 0;
if(what== "all" || what== "gu" )
{
message_vision("$N��$n���һ�����󵨣����Ҵ������¶��������⣡\n",this_object(),this_player());
this_object()->kill_ob(this_player());
this_player()->start_busy(2);
return 1;
}
}
