
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("����", ({ "fengyun garrison", "garrison" }) );
        set("long",
"���Ǹ�����ִ���س���������䣬��Ȼ�������������������������ǵ��书\n"
"ʵ��ƽ����������������֯���м��ɵ�սʿ��˭Ҳ�����׵��������ǡ�\n"
"[31m�����Ҳ��Ҫ�������ǡ� [37m\n");
        set("attitude", "heroism");
        set("vendetta_mark", "authority");
        set("str", 27);
        set("cor", 26);
        	  set_temp("kf_tufei",12);
        set("pursuer", 1);
set("cps", 25);
        set("combat_exp", 100000+random(4000000));
        set("chat_chance_combat", 45);
        set("chat_msg_combat", ({
                "����ȵ�������������������־͸���\n",
                "����ȵ����󵨵��񾹸Ҿܲ������ˣ����ˣ�\n",
		(: perform_action, "spear.suomengpanhun" :),
        }) );
        set_skill("unarmed", 70+random(100));
        set_skill("spear", 10+random(50));
        set_skill("parry", 70+random(100));
        set_skill("dodge", 70+random(100));
        set_skill("move", 100+random(100));
	set_skill("duanhun-spear",151);
	map_skill("spear","duanhun-spear");
        set_temp("apply/attack", 70);
        set_temp("apply/defense", 70);
        set_temp("apply/armor", 70);
        set_temp("apply/damage", 30+random(200));
        set_temp("apply/move", 100);

        setup();

        carry_object(__DIR__"obj/kiujia")->wear();
        carry_object(__DIR__"obj/spear")->wield();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
	switch( random(10)){
				case 0:
say("�����������µش�����һ�����ֺ�ǽ�����Ĺٸ�ͨ�����˶ԣ������ֹ�������������ˣ�\n");
					break;
				case 1:
say("���俴����һ�ۣ������ֹ�������������һ���������\n");
					break;
				case 2:
say("��������ȵ���վס����������̧������\n");
					break;
				}
}

