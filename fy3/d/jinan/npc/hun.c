// TIE@FY3
#include <ansi.h>
inherit NPC;
void create()
{
	set_name( "�����", ({ "leng qiuhun", "qiuhun" }) );
	set("long", "
��ɰ������Ŵ���ӣ�ɱ����������ǧ��ͽ�ܡ�
\n");
	set("attitude", "friendly");
	set("title", HIM "�����ϳ�" NOR);
	set("max_gin", 500);
	set("max_kee", 500);
	set("max_sen", 500);
	set("age", 17);
        set("gender", "����" );


	set("str", 35);
	set("cor", 30);
	set("cps", 25);
	set("per", 40);
	set("combat_exp", 50000);
        set("chat_chance", 10);
        set("chat_msg", ({
"������૵�����ʦһ�յ����ž�һȥ������Ī����ʲô���⣿\n",
"����������ʵ����ɷ�������������˼ң�\n"
        }) );

	set_skill("unarmed", 100+random(200));
	setup();
        carry_object("/obj/cloth")->wear();
        add_money("gold", 5);

}
