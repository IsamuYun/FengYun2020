//#include <ansi.h>
inherit NPC;
void create()
{
        set_name("������ʿ", ({ "wu shi"}) );
        set("gender", "����");
        set("age", 35);
        set("long",
"����λ���𵺵�����ǰ������ʿ�������ּף���ִ������˫Ŀ���⾼����
�����Ѳ�������ܵ����Ρ�\n"
               ); 

        set("attitude", "heroism");

        set("str", 50);
        set("int", 50);
        set("agi", 50);
        set("con", 50);

        set("max_gin", 1000);
        set("max_kee", 1000);
        set("max_sen", 629);
        set("eff_gin", 1000);
        set("eff_kee", 1000);
        set("eff_sen", 629);
        set("gin", 1000);
        set("kee", 1000);
        set("sen", 629);

        set("force", 1000);
        set("max_force", 800);
        set("force_factor", 30);

        set("combat_exp", 1500000);

        set_skill("unarmed", 180);
        set_skill("dodge", 180);
        set_skill("sword", 180);
        set_skill("parry", 180);
	set_skill("move", 180);

        setup();
	carry_object(__DIR__"obj/sword")->wield();
	carry_object(__DIR__"obj/gangjia")->wear();
}
