inherit NPC;
#include <ansi.h>
void create()
{
        set_name("�����ܹ�", ({ "soldier"}) );
        set("age", 30);
	set("long",
"���������Ͻ��ǵ�ʿ����\n");
        set("attitude", "peaceful");
        set("no_arrest", 1);
        set("can_carry", 1);
        set("hit_always_on", 1);
        set("str", 80);
        set("combat_exp", 10000000);
        set("limbs", ({ "�У�" }) );
        set_skill("unarmed", 400);
        set_skill("dodge",400);
        set_skill("parry",400);
        create_family("��͢��Ʒ", 1, "��");
	setup();
}
