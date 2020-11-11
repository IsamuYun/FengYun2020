// /d/wiz/llx/npc/npc.c

inherit NPC;
#include <ansi.h>

void create()
{
        set_name(HIG"���滤��"NOR, ({ "gguard",}) );
        set("title", GRN"��ʦ�鱣��ͳ��"NOR);
        set("gender", "����");
        set("age", 34);
        set("long",
"���£���ѥ���̷��������棬��֪�������书�ж�ߣ���\n"
               ); 
        set("class", "guardman");
        set("attitude", "peaceful");
        set("combat_exp", 10000000);
        set("agi",25);
        set("int",40);
        set("chat_chance_combat", 180);
        set("chat_msg_combat", ({
                (: perform_action, "blade.jichulianhuan" :),
                "���滤����ǹ��ŵ�һ˿��Ц����е�һ˿�־壬����ֽŶ��о������¶��ˡ���\n"
        }) );
        set("int", 50);
        set("cor", 50);
        set("con", 50);
        set("str", 80);
        set("cps", 50);
        set("agi",45);
        set("int",40);
        set("force", 4000);
        set("max_force", 2200);
        set("force_factor", 300);
        set("max_kee",100000);
        set("max_gin",100000);
        set("max_sen",100000);
        set_temp("apply/damage",500);

        set_skill("blade", 150);
        set_skill("move",200);
        set_skill("parry",200);
        set_skill("force",200);
        set_skill("cloudforce",80);
        set_skill("dodge", 300);
        set_skill("shenji-blade",150);
        set_skill("shenji-steps",150);
        map_skill("force","cloudforce");
        map_skill("blade","shenji-blade");
        map_skill("parry","shenji-blade");
        map_skill("dodge","shenji-steps");
        map_skill("move","shenji-steps");
        setup();
        
        carry_object("/d/songshan/npc/obj/dafeng")->wield();
}

void init()
{        
        object ob, me;
        object *inv;    
        int i;
        if( interactive(ob = this_player()) ) {
                me = this_player();
                if( userp(me) && me->query_temp("llx_marks/͵��")){      
                message_vision("$N��Ц�����㵨���治С������\n",this_object());
                kill_ob(ob);
                return;
                }
        }
        remove_call_out("leave");
        call_out("leave",1);
}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(HIC "�����˺���һ������Ϊһ����Ӱ�����ˡ���\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",10);
}

void killed_enemy(object who)
{
        command("say ����֮ͽ��������ϧ��\n");
        message_vision(HIG "�����˱����۾�����Ϊһ����Ӱ�����ˡ���\n" NOR,this_object());
        destruct(this_object());
}
