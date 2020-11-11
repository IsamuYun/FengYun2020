// master.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
#include <combat.h>
void create()
{
        set_name("��Ѱ��", ({ "master li", "master", "master li xunhuan" }) );
        set("nickname", RED"С��ɵ�"NOR);
        set("gender", "����" );
    set("reward_npc", 1);
    set("difficulty", 250); 
        set("age", 44);
        set("str", 80);
        set("cor", 80);
        set("cps", 80);
        set("agi", 80);
        set("int", 30);
        set("dur", 400);
        set("per", 30);
        set("class", "traveller");
        set("attitude","friendly");
        set("max_force", 15000);
        set("force", 150000000);
        set("courage",1000);
        set("force_factor", 420);

        set("rank_info/respect", "��̽��");

        set("long",
"��Ѱ�������̽�������н����º�С��ɵ���
һ�ַɵ��������ڰ������ı����������е�����
�������ѣ��������鷢��\n"                
        );
        create_family("����һ��", 2, "�˽�");
        set("student_title","�˽�");
        set("combat_exp", 50000000);
        set("score", 200000);

        set("chat_chance", 10);
        set("chat_msg", ({
                "��Ѱ����Ȼһ��һ�ڵĺ��Ź𻨾ơ�\n",
                "��Ѱ����ͣ���ڿȣ��������һ˿��Ѫ��\n",
                "��Ѱ������ɫԽ���԰��ˡ�\n",
"��Ѱ��̾���������������������ľ��\n",
        }) );
        set_skill("move", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("throwing", 300);
        set_skill("feidao", 220);
        set_skill("force", 40);
        set_skill("literate", 200);
        map_skill("throwing", "feidao");
        setup();
        carry_object(__DIR__"obj/whitecloth")->wear();
                carry_object(__DIR__"obj/guihua");
}

void attempt_apprentice(object ob)
{
        if(time()-(int) ob->query("last_time_app_master_li") < 899)
        {
                 message_vision("$NЦ��������ô��ô���ֻ����ˣ�����\n",
        this_object());
        return;
        }
        if((int) ob->query("force_factor") < 100)
        {
         message_vision("$NЦ��������书���˽⻹����������\n",
        this_object());
        return;

        }
        if( random(500) || random((int)ob->query("kar")) <  25 || query("already") || ob->query("baixiaoli"))
        {
        message_vision("$N����������˵������Ҫ����Ц���ҿɲ��������ӵܡ�\n",
        this_object());
        ob->set("last_time_app_master_li",time());
                return;
        }

        command("sigh");
        command("say �ܺã�" + RANK_D->query_respect(ob) + 
"�����в���Ϊ��������\n");
        command("recruit " + ob->query("id") );
        ob->delete("betrayer");
        ob->add("score",5000);
        ob->add("baixiaoli",1);
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "traveller");
        set("already",1);
}
void reset()
{
        set("already",0);
} 

object offensive_target(object me)
{
        int sz;
        object *enemy;

        enemy = me->query_enemy();
        if( !enemy || !arrayp(enemy) ) return 0;

        sz = sizeof(enemy);
        if( sz > 4 ) sz = 4;

        if( sz > 0 ) return enemy[random(sz)];
        else return 0;
}

void heart_beat()
{
        object feidao;
        object target;
        if(!query_temp("weapon") && is_fighting())
        {
                target = offensive_target(this_object());
            if(objectp(target))
            {
                target->receive_damage("kee",1000,this_object());
                        feidao = new(__DIR__"obj/xlfd_knife");
                        feidao->move(this_object());
                        command("wield flying blade");
                (CLASS_D("traveller") + "/feidao/xiaoli-feidao")->kill_him(this_object(),target);
                        WEAPON_D->throw_weapon(this_object(),target,feidao,0);
                }
                return;
        }
        else
   return ::heart_beat();  
}

void init()
{
    add_action("do_kill", "kill");
}

int do_kill(string arg)
{
        object feidao;
    object me;
    
    if(!arg)
    {
        return 0;       
    }
    
    if(strsrch(arg, "master") == -1)
    {
        return 0;       
    }
        
    me = this_player();
    message_vision("\n$N������Ѱ���ȵ�������ƥ�򣡽��ղ�������������������\n\n",me);

    this_object()->kill_ob(me);
    me->kill_ob(this_object());    
        if(objectp(me))
        {
                me->receive_damage("kee",1000,this_object());
                        feidao = new(__DIR__"obj/xlfd_knife");
                        feidao->move(this_object());
                        command("wield flying blade");
                (CLASS_D("traveller") + "/feidao/xiaoli-feidao")->kill_him(this_object(),me);
                        WEAPON_D->throw_weapon(this_object(),me,feidao,0);
        }
    return 1;
}

