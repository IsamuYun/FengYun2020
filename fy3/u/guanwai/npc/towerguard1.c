
inherit NPC;

void create()
{
	set_name("��ɮ", ({ "tower guard", "guard" }) );
	set("gender", "����" );
	set("age", 35);
	set("str", 30);
	set("long", @LONG
һ�����𿴹��������Ĳ�ɮ��
LONG
);
	set("attitude", "heroism");

        set("force", 300);
        set("max_force", 300);
        set("force_factor", 2);


        set("combat_exp", 6000);

        set_skill("unarmed", 50);
        set_skill("bloodystrike", 50);
        set_skill("force", 40);
        set_skill("parry", 50);
	map_skill("unarmed", "bloodystrike");
	set_skill("iron-cloth", 150);
	set_skill("jin-gang", 50);
	map_skill("iron-cloth", "jin-gang");
	setup();

        carry_object(__DIR__"obj/redcloth")->wear();
}
