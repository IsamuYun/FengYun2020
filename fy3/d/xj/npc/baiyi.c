#include <ansi.h>
inherit NPC;

void create()
{
        set_name("������", ({ "man in white" }) );
        set("gender", "����");
        set("age", 37);
        set("long","�������������Ƕ�ʮ��ǰ���Ѿ����������ģ�һ���ɻ��������죬��
����ȴվ������һ��������\n"); 
        set("title",HIW"һ������"NOR);
        set("combat_exp", 10000000);
	set("bellicosity" , 20);
	set("PKS" , 1);
        set_skill("sword", 150);
        set_skill("dodge", 100);
        set_skill("feixian-steps", 100);
        set_skill("feixian-sword", 120);
	set_skill("move", 50);
        map_skill("dodge", "feixian-steps");
        map_skill("move", "feixian-steps");
        map_skill("sword", "feixian-sword");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
		(: perform_action,       "sword.tianwaifeixian" :),
		(: perform_action,       "dodge.tianwaifeixian" :)
        }) );
        setup();
	carry_object("/obj/cloth")->wear();
	carry_object("/obj/weapon/sword")->wield();
}
