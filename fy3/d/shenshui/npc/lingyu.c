// XXDER

#include <ansi.h>

inherit NPC;
void create()
{
	set_name("������" , ({ "lingyu", "girl" }) );
	set("long", "���ߴ��϶�����һ��Ů����������徵�����û��һ˿���飬һϮ��ɴ��
������������ӣ��㲻�ɵþ���һ����ʹ����û���ɡ�\n\n");
	set("attitude", "friendly");
	set("max_gin", 500);
	set("max_kee", 500);
	set("max_sen", 500);
	set("age", 11);
        set("gender", "Ů��" );
        set("per", 50);
	set("combat_exp", 5000);
	set_skill("dodge", 50+random(50));
	setup();
	carry_object(__DIR__"obj/blackcloth")->wear();
}
