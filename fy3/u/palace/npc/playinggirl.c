// thousand_hand.c

#include <ansi.h>

inherit NPC;
void create()
{
	int i,amun;
	string *name= ({"����", "�Ϸ�", "����", "����", "����"});
	set_name( name[random(5)] , ({ "playing girl", "girl" }) );
	set("long", "����һλ�����ȵ�СѾͷ��ר��������壮\n");
	set("attitude", "friendly");
	set("max_gin", 500);
	set("max_kee", 500);
	set("max_sen", 500);
	set("age", 13);
        set("gender", "Ů��" );
        set("chat_chance", 1);
        set("chat_msg", ({
                "СѾͷ���Ե�����˵Ҫ��������ʱ�����������ſϣ�\n",
        }) );


	set("str", 35);
	set("cor", 30);
	set("cps", 25);

	set("combat_exp", 50000);
	set_skill("throwing",250+random(100));
	set_skill("dodge", 50+random(50));
	setup();
	carry_object("/obj/cloth")->wear();
	carry_object(__DIR__"obj/pai");
}
