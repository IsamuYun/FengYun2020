inherit NPC;

void create()
{
        set_name("С¹", ({ "little deer" }) );
        set("race", "Ұ��");
        set("age", 5);
        set("long", "һͷǳǳ��ë��С¹��\n");
        set("max_kee", 120);
        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite" }) );

        set_skill("dodge", 80);
	set("combat_exp", 100);

        setup();
}

