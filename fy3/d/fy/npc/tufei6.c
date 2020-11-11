
// add by atu for LSFY 2000/01/10
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�ɺ׻���", ({ "xlidxhe"}) );
        set("gender", "����" );
        set("age", 34);
        set("long",
                "����ȫ�����ں�ɴ�е������ˣ�ȫ��ɢ����һ����ɭ����Ϣ��\n");
        set("max_kee", 550000);
        set("max_gin", 35000);
        set("max_sen", 35000);
        set("combat_exp", 4000000);
        set("attitude", "friendly");
        set("title", "");

       set("cps", 100);
       set("agi", 100);
       set("cor", 100);

       set("no_see", 1);

        set_skill("dodge", 500);
        set_skill("move", 500);
        set_skill("unarmed",500);
        set_skill("iron-cloth",500);
        set_skill("parry", 500);
        set_skill("force",500);
        set_skill("literate", 500);
        set_skill("wuzheng-force", 500);
        set_skill("bat-blade", 150);
        set_skill("blade", 150);
        set_skill("meng-steps", 500);

       map_skill("force", "wuzheng-force");
       map_skill("dodge", "meng-steps");
       map_skill("move", "meng-steps");
       map_skill("blade", "bat-blade");
       map_skill("parry", "bat-blade");

       set("chat_chance_combat", 90);
       set("chat_msg_combat", ({
                (: perform_action, "blade.shiwanshenmo" :),
                (: perform_action, "blade.shiwanshenmo" :),
                (: perform_action, "dodge.huanyingqianchong" :),
        }) );
        setup();
        carry_object("/obj/weapon/blade")->wield();
}

void init()
{
	add_action("do_souxun", "souxun");
}

void do_souxun()
{
	object me = this_player();
	object obj = this_object();
	object ob1 = present("ling pai",me);
	
	if (interactive(me) && objectp(ob1) && me->query("kf_working") 
		&& obj->query_temp("owner/id") == me->query("id"))
	{
		message_vision (HIR"$n���һ���ҿ�αװ��¶��������Ŀ��\n"NOR,me,obj);
		message_vision (HIM"$N�����ҵ���$n����������ȥ������\n"NOR,me,obj);
		obj->delete("no_see");
        obj->kill_ob(me);
        me->kill_ob(obj);
	}
}

int heal_up()
{
        if( environment()) 
        {
                call_out("leave", 700);
                return 1;
        }
        
        return ::heal_up() + 1;
}

void leave()
{
	command("rumor "+this_object()->query_temp("owner/name")+"������Ѱ������"+this_object()->query("name")+"�����ˡ�");
    destruct(this_object());
}
// int active_died()
void die()
{
    object me = this_object()->query_temp("last_damage_from");
        	
    if (!objectp(me))
    {
        ::die();
        return;
    }
    // ���������������ڵ�ɱ�ģ�Ҫ�����ת��
    if (!userp(me))
        me = find_player(geteuid(me));

		message_vision(HIC+""+this_object()->query("name")+"���ڵ��ϣ����ˡ�\n"NOR,me);

        if (me->query("kf_working") && this_object()->query_temp("owner/id") == me->query("id")) 
        {
	        me->set_temp("kf_finish",1);
        }
		else
		{
            message_vision(HIC "\n����$N����ɱ�ˣ��ٸ����������㣺\n"
                + chinese_number(500) + "��ʵս���飬\n"
                + chinese_number(200) + "��Ǳ�ܣ�\n"
               + chinese_number(10) + "��������Ϊ�ͷ���\n" NOR, me);
            me->add("combat_exp", -500);
            me->add("potential", -200);
            me->add("pot_deposit", -200);
            me->add("score",-10);			
		}

        me->add("MKS", 1);
        destruct(this_object());
}
