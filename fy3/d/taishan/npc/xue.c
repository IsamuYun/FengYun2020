#include <ansi.h>
inherit NPC;
void create()
{
        set_name("ѩ����", ({ "xue yi ren" }) );
        set("gender", "Ů��");
    set("reward_npc", 1);
    set("difficulty", 30); 

	set("age",25);
	set("env/wimpy",90);
        set("combat_exp", 1000000);
        set("long",
		"һ����Ư����Ů�ˣ�������ȥ������һ��磬һ���ƣ�һƬѩ����\n"
	);
	set_skill("move",300);
        set_skill("dodge", 50);
	set_skill("unarmed",30);
        set("chat_chance", 15);
        set("chat_msg", ({
	(: random_move :),
	name()+"Ц��Ц������������һ�������������Ը���ġ�\n",
	name()+"������������һ�У�Ϊ���ǶԸ�л������ү��\n"
        }) );
        setup();
}
