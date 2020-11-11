//edit by xgchen@zzfy
inherit NPC;
#include <ansi.h>
object cart;
mapping default_dirs = ([
        "north":                "��",
        "south":                "��",
        "east":                 "��",
        "west":                 "��",
        "northup":              "����",
        "southup":              "�ϱ�",
        "eastup":               "����",
        "westup":               "����",
        "northdown":            "����",
        "southdown":            "�ϱ�",
        "eastdown":             "����",
        "westdown":             "����",
        "northeast":            "����",
        "northwest":            "����",
        "southeast":            "����",
        "southwest":            "����",
        "up":                   "��",
        "down":                 "��",
        "enter":                "��",
        "out":                  "��",
]);
void give_reward();
int ask_arrived();
void to_rob();
void create()
{
        object ob;
        set_name("����ͷ", ({ "biaotou" }) );
        set("gender", "����" );
        set("age", 25);
        set("combat_exp", 100000);
        set("attitude", "friendly");
        set("vendetta_mark", "authority");
        set("no_get",1);
        set("per",2);
        set("inquiry", ([
                               "�ִ�" : (: ask_arrived :),
        ]));
                set("chat_chance", 15);
    set("chat_msg",({
        "����ͷ�ȵ����������˵������ˡ���\n",
        "����ͷ�ȵ��������߿��ߣ���͵������\n",
    }) );
    set("chat_chance_combat",90);
    set("chat_msg_combat", ({
        "����ͷ�󺰵����������ˣ����˽����ˡ���\n",
    }) );
        
        set("force",500);
        set("max_force",500);
        set("force_factor",2);
        set_skill("blade",150);
        set_skill("shenji-blade",150);
        set_skill("force",140);
        set_skill("parry",150);
          set_skill("unarmed",200);
      set_skill("dodge",150);
        set_skill("iron-cloth",120);
        map_skill("blade","shenji-blade");
        map_skill("parry","shenji-blade");
        setup();
        add_money("silver", 50);
    carry_object(__DIR__"obj/jinzhuang")->wear();
    carry_object("/obj/weapon/blade")->wield();
        carry_object("/obj/example/wineskin");

}
void init()
{
        add_action("do_move","move");
}
int do_move(string arg)
{
        object me, ob, env;
        mapping exit;
        int busy, kar,i;
        me = this_player();
        ob = this_object();
        env = environment(me);
        kar = me->query("kar");

        if( !living(ob) )
              return notify_fail("��....����Ȱ�" + ob->name() + "Ū����˵��\n");

        if (ob->query_temp("owner/id") != me->query("id")) {
                command("? " + me->query("id"));
                return notify_fail("\n");
                }
        
        if (!arg) {
                command("kick " + me->query("id"));
                command("say ��Ҫ�Ҹϵ��Ķ�ȥ��");
                return notify_fail("\n");
                }

        if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) ) {
                command("?");
                command("say �������û��·����");
                return notify_fail("\n");
                }

        if (ob->is_busy()) {
                command("say �������æ���أ�");
                return notify_fail("\n");
                }

        if (me->is_busy()) {
                command("say ���Լ���æ�������������Ҹ�ʲô��");
                return notify_fail("\n");
                }

if (present("gangster", environment(this_object()))){
                command("say �����Ȱ�����ɱ���ɣ�\n");
                     return notify_fail("\n");
                        }
        if (me->is_fighting()) {
                command("say �����Ȱ��ҵĶ��������˰ɣ�\n");
                     return notify_fail("\n");
                        }
/*
        if (ob->is_fighting()) {
                command("say �����Ȱ��ҵĶ��������˰ɣ�\n");
                     return notify_fail("\n");
                        }
*/
        if (me->query_temp("quest/biao_b")!=1) {
                command("say ��ֻ����һ����!");
                return notify_fail("\n");
             }

        command("go " + arg); 
        ob->start_busy(3 + random(3));
        me->move(environment(ob));
        message_vision(HIC "��ͷ�þ�����۹�۲������ܡ�\n" NOR,me);
        busy = 2 + random(10);
               me->start_busy(busy);
if (!present("gangster", environment(this_object())))
           for (i=0;i<=random(5)+1;i++)
       {        ob=new(__DIR__"gangster2");
                ob->move(environment());
                ob->kill_ob(this_player());
                ob->kill_ob(this_object());
                this_player()->kill_ob(ob);
                ob->set_leader(this_object());
        }       
        message_vision(HIC"��Ȼ������һȺ�ٷˣ�\n"NOR,this_object());
               
        return 1;
}
int ask_arrived()
{
        object me, ob;
        int exp, pot, kar, ggold, score;
        
        me = this_player();
        ob = this_object();
        kar = me->query("kar");

        if (ob->query_temp("owner/id") != me->query("id")) {
                command("say " + me->query("name") + "��ð�����˹��ͣ�");
                command("grin " + me->query("id"));
                return 1;
                }
                     if (me->query_temp("quest/biao_b")!=1) {
                command("say ��ֻ����һ����!");
                return notify_fail("\n");
                     }
        if (ob->is_busy()) {
                command("say �������æ���أ�");
                return notify_fail("\n");
                }

        if (me->is_busy()) {
                command("say ���Լ���æ�������������Ҹ�ʲô��");
                return notify_fail("\n");
                }

                if (present("gangster", environment(this_object())))
                {
                command("say �����Ȱ�����ɱ���ɣ�\n");
                return notify_fail("\n");
        }

        if (me->is_fighting()) {
                command("say �����Ȱ��ҵĶ��������˰ɣ�\n");
                return notify_fail("\n");
                }

        if (file_name(environment(ob)) !="/d/chenxiang/nanbank") {
                         command("say �����;���ϣ�");
                       return 1;
                       }
        if (!present("nangong", environment(ob))) {
                       command("say �Ϲ����ڣ����ý����");
                       return 1;
                       }
  

        me->set("quest/yunbiao",0);
        me->set("quest/biao_b",0);
        exp = (6000 + random(6000));
        pot = (1000 + random(1000));
        ggold = (400000+random(500000));
        score = (random(7));
        message_vision(HIW "$N�������ˣ�\n"
                + HIG + chinese_number(exp) + "��ʵս���飬\n"  
                + HIC + chinese_number(pot) + "��Ǳ�ܣ�\n"
                + HIY + chinese_number(ggold / 10000) + "���ƽ�\n" 
                + HIR + chinese_number(score) + "�����ۡ� \n"NOR,me);
         me->add("combat_exp",exp);
        me->add("potential",pot);
        me->set("quest/yunbiao",0);
        me->add("deposit",ggold);
        me->add("score",score);

        message_vision(CYN "��ͷ��Ǯׯ�����ȥ�ˡ�\n" NOR,me);
        destruct(ob);

        return 1;
}
   void die()
{
        object killer,goldd;
        killer=query_temp("last_damage_from");
                if (objectp(killer))
                {
                        command("chat ������"+killer->name()+"�����ˣ�");
               message_vision("$N��������ͷ���ϣ����������е�������\n",killer);

                                
                                goldd = new("obj/money/gold");
                                goldd->set_amount(100+random(100));
                                goldd->set("name",HIY" �Ϲ���Ʊ"NOR);
                                goldd->move(killer);
                                killer->add("vendetta/authority",1);
                                killer->add("score",-100);
                        }
                ::die();
}

