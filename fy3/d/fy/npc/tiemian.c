inherit NPC;
 
#include <ansi.h> 
void create()
{
        set_name("����", ({"wuqing", "wu", "qing"}));
        set("long",
                "һ�������ܸɣ��书��ǿ���ͷ�������\n");
        set("gender","����");
    set("reward_npc", 1);
    set("difficulty", 100); 

	set("title", HIR "��Ǯ���ͷ�������" NOR);
        set("max_atman", 300);
        set("atman", 300);
        set("max_force", 300);
        set("force", 300);
        	  set_temp("kf_tufei",62);
        set("pursuer", 1);
set("max_mana", 300);
        set("mana", 300);
        set("force_factor", 20);
        set("combat_exp", 9999999);
	set("can_carry", 1);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("force", 130);
        set_skill("literate", 70);

        set_skill("qidaoforce", 100);
        set_skill("meihua-shou", 10);
        set_skill("fall-steps", 100);

        map_skill("unarmed", "meihua-shou");
        map_skill("dodge", "fall-steps");


        setup();
        carry_object(__DIR__"obj/tangfu")->wear();
}
 
int accept_object(object who, object ob)
{
            command("grin");
            command("say Ϲ���۵Ĺ��ţ����һ�¸�ң���");
	    kill_ob(who);
            return 0;
}
 
