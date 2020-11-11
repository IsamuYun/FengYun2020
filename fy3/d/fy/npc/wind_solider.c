
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("���", ({ "fengyun garrison", "garrison" }) );
        set("long",
"���Ǹ�����ִ���س�����ķ������Ȼ������������������������ǵ��书\n"
"ʵ��ƽ����������������֯���м��ɵ�սʿ��˭Ҳ�����׵��������ǡ�\n"
"[31m�����Ҳ��Ҫ�������ǡ� [37m\n");
        set("attitude", "heroism");
        set("pursuer", 1);
        	  set_temp("kf_tufei",68);
        set("pursuer", 1);
set("vendetta_mark", "authority");
        set("str", 27);
        set("cor", 26);
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
        set_temp("apply/damage", 30+random(200));
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100);

        setup();

        carry_object(__DIR__"obj/kiujia")->wear();
        carry_object(__DIR__"obj/spear")->wield();
}

int accept_object(object who, object ob)
{
                if( (int)ob->value() >= 500000 ) {
                        say("����Ǻǵ�Ц������˵����˵...\n");
                        who->set("vendetta/authority", 0);
                        who->remove_all_killer();
                        return 1;
                } else {
                    say("���˵�������Ǯ��������ү�ȾƵ��أ�\n");
                        return 0;
                }
        return 0;
} 
