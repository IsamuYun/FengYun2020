#include <ansi.h>
inherit NPC;
void create()
{
        set_name("��Ҷ��", ({ "zhuyeqing" }) );
        set("gender", "����");
    set("reward_npc", 1);
    set("difficulty", 20); 

        set("combat_exp", 1000000);
	set("age",47);
	set("env/wimpy",90);
        set("long",
		"��Ҷ����һ���ҾƵ����֣�����ȥ���������ܲ���ģ���Ҷ��Ҳ���ֶ��ߣ�����Ҫ����\n"
	);
	set_skill("move",100);
        set_skill("dodge", 50);
	set_skill("unarmed",50);
        set("chat_chance", 15);
        set("chat_msg", ({
	(: random_move :)
        }) );
        setup();
	carry_object("/obj/cloth")->wear();
}
