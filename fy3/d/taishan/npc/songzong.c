#include <ansi.h>
inherit NPC;
void create()
{
        set_name("����", ({ "songzong" }) );
        set("gender", "����");
        set("combat_exp", 100000);
        set("title", HIR "һ������" NOR);
        set("long",
		"���У���һ�����գ���Ҷ���Ϊ���ν��Ķ����Ѿ��ȵ��Ͼ�������\n"
	);
        set_skill("move", 50);
        set_skill("dodge", 50);
	set_skill("sword",50);
	set_skill("sharen-sword",20);
	map_skill("sword","sharen-sword");
        set("chat_chance", 15);
        set("chat_msg", ({
                (: random_move :)
        }) );
        setup();
	carry_object("/obj/cloth")->wear();
	carry_object("/obj/longsword")->wield();
}
