// added by atu for LSFY 2000/01/18

#include <ansi.h>
#define QUEST_LETTER "/questnew/quest_letter.c"  
inherit NPC;
inherit F_MASTER;

int time_period(int timep, object me);

void create()
{
        set_name(HIG"�����ʲ�"NOR,({"post man","post"}));
        set("long","����һ��������ר���������ȵ��ʲ��������ż���Χ�ţ���������ü���������ӡ�\n");

        set("gender", "����");
        set("attitude", "friendly");
        set("class", "bonze");
        set("age", 40);
        set("shen_type", 0);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);

        set("max_kee", 4500);
        set("max_gin", 3000);
        set("force", 2500);
        set("max_force", 2500);
        set("force_factor", 50);
        set("combat_exp", 3000000);
        set("score", 10000);
        set("env/wimpy", 10000);
        set("inquiry", ([
                "����": "�����ڷ�����ô������Щ�ż�������������! \n",
        ]) );
        set("no_get", 1);

        set_skill("force", 170);
        set_skill("dodge", 170);
        set_skill("unarmed", 175);
        set_skill("parry", 170);
        setup();
        carry_object("/obj/cloth")->wear();
}

void init()
{
        add_action("give_quest", "work");

}

int accept_object(object who, object ob)
{
        if (ob->query("money_id"))
        {
             if(!who->query("quest_letter") || ( ob->value() < 5000))
             {
                   message_vision("����ȱǮ�ã���л���ˣ�\n",who);
                   return 1;
             }
             else
             {
message_vision("�ʲ�̾�˿��������ðɣ�������������,��ȥ���������\n",who);
                   who->set("quest_letter",0);
                   return 1;
             }
         }
return 0;
}

int give_quest()
{
        mapping quest ;
        object me,letter;
        int combatexp, timep, factor;

        me = this_player();
        combatexp = (int)(me->query("combat_exp"));

if(combatexp > 2000000)
        {
                message_vision("�ʲ��$N˵�����������ĳ��������ˣ�����С������������ݣ���\n",me);
                return 1;
        }
 
// Let's see if this player still carries an un-expired task
        if((quest =  me->query("quest_letter")))
        {
                if( ((int)me->query("task_time")) >  time() ){
                message_vision("�ʲ��$N˵����ð��Ű����͵�ѽ��\n", me);
                        return 1;
                }
        }
                if (((int)time() - (int)me->query("last_task_time")) < 10)
                 {
                   message_vision("�ʲ��$N˵���������Ҷ��е÷��ţ��㻹�ǵȻ������ɡ�\n",me);

                   return 1;
                 }
                else
                {
                   message_vision("�ʲ��$N˵�����������ã�������պ���һ���ż�Ҫ�ͳ�ȥ��\n",me);
}
        quest = QUEST_LETTER->query_quest();
        timep = random(100) + 300;
        time_period(timep, me);
        tell_object(me, "�����͸���" + quest["quest"] + "��������������ˡ�\n" NOR);
        message_vision("$N����$nһ���š�\n",this_object(),me);
        letter = new("/questnew/obj/letter");
        letter->move(me);
        quest["quest_type"] = "�����͸�";
        quest["exp_bonus"] = 10;
        quest["pot_bonus"] = 1;
        quest["score"] = 0;

        me->set("quest_letter", quest);
        me->set("task_time", (int)time() + timep);
//        me->set("quest_factor", factor);
        me->set("last_task_time", time());
        return 1;
}

int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d)
                time = chinese_number(d) + "��";
        else
                time = "";
        if(h)
                time += chinese_number(h) + "Сʱ";
        if(m)
                time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";

        tell_object(me, HIW "�ʲ�˵����\n��" + time + "��");

                return 1;
}
