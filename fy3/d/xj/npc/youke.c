//

inherit NPC;

void create()
{
        set_name("�ο�", ({ "you ke" }) );
        set("gender", "����" );
        set("age", 42);
        set("long", "һ��Ľ��ǰ��������ο����ǧ�𶴵��ˡ�\n");
	setup();
        carry_object("/d/xj/npc/obj/cloth")->wear();
}
