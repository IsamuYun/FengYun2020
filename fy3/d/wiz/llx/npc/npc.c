// /d/wiz/llx/npc/npc.c

inherit NPC;
#include <ansi.h>

void create()
{
        set_name(HIW"���滤��"NOR, ({ "wguard",}) );
        set("title", WHT"��ʦ�鱣��ͳ��"NOR);
        set("gender", "����");
        set("age", 34);
        set("long",
"���£���ѥ���׷��������棬��֪�������书�ж�ߣ���\n"
               ); 
        set("class", "guardman");
        set("attitude", "peaceful");
        set("combat_exp", 10000000);
        set("agi",25);
        set("int",40);
        set("chat_chance_combat", 180);
        set("chat_msg_combat", ({
                (: perform_action, "sword.xiangsiwuyong" :),
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
        set("max_kee",100000);
        set("max_gin",100000);
        set("max_sen",100000);
        set("force_factor", 300);
        set_temp("apply/damage",500);

        set_skill("unarmed", 100);
        set_skill("sword",100);
        set_skill("force",100);
        set_skill("parry",120);
        set_skill("dodge",100);
        set_skill("vivienforce",170);
        set_skill("move",80);
        set_skill("literate",200);
        set_skill("vivien-sword",200);
        set_skill("vivien-steps",200);
        set_skill("kongshoudao",100);
        map_skill("unarmed","kongshoudao");
        map_skill("dodge","vivien-steps");
        map_skill("force","vivienforce");
        map_skill("sword","vivien-sword");
        setup();
        
        carry_object("/obj/leafsword")->wield();
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
        message_vision(HIW "�����˱����۾�����Ϊһ����Ӱ�����ˡ���\n" NOR,this_object());
        destruct(this_object());
}
