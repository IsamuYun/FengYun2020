// referee.c

inherit NPC;
#include <ansi.h>;

//int do_bihua();
string ask_me();
//int do_halt();

void create()
{
        set_name("��ƽ��", ({ "gongping zi", "zi", "referee" }) );
        set("gender", "����");
        set("age", 35);
        set("long",
                "����һλ�ɷ���ǵ�������ˣ����������ķ����Ժ�������������˽��\n");
        set("combat_exp",9000000);
        set("shen_type", 1);
        set_temp("kf_tufei",60);
              set("attitude", "friendly");

        set("apply/attack", 50);
        set("apply/defense", 50);

        set("max_kee", 8000);
        set("max_gin", 8000);
        set("max_sen", 8000);
        set("max_force", 8000);

        set_skill("force", 180);
        set_skill("unarmed", 100);
        set_skill("sword",180);
        set_skill("parry",280);
        set_skill("dodge", 280);

        set("inquiry", ([
                "������"       : (: ask_me :),
        ]));

        setup();

        carry_object("/obj/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}


void init()
{
        ::init();
        add_action("do_bihua", "bihua");
        add_action("do_bihua", "bi");
        add_action("do_bihua", "fight");
        add_action("do_halt", "halt");
        add_action("do_halt", "h");
}

string ask_me()
{
        object* ob;
        int i;
        ob = users();

        if ( !wizardp(this_player()) ) return "����Ȩ�ٿ������ᣡ\n";

        for ( i=sizeof(ob); i>0; i-- ) {
                ob[i-1]->move("/d/fy/poemp");
        }

        return "�ã����ڱ�������ʽ��ʼ��ȫ�弯�ϣ�\n";
}

int do_bihua(string arg)
{
        object ob1, ob2;
        object old_target;

        ob1 = this_player();

        if( !arg || arg=="" ) return 0;

        if ( arg == "gongping zi" || arg == "zi" || arg == "referee" )
           {
             command("say " + "����书�������ʸ���ұ��䣡\n");
             command("smile");
             return 1;
            }

        if ( this_object()->query_temp("busy") )
                return notify_fail("�Ѿ����������ڱ����ˡ�\n");

        if (!ob2 = present(arg,environment(ob1)) )
                return notify_fail("�����˭���䣿\n");
        if (ob1 == ob2)    return notify_fail("�㲻�ܸ��Լ����䡣\n");


        if( userp(ob2) && (object)ob2->query_temp("pending/fight") !=ob1 ) {
                message_vision("\n$N����$n˵����"
                        + RANK_D->query_self(ob1)
                        + ob1->name() + "�����"
                        + RANK_D->query_respect(ob2) + "�ĸ��Т�\n\n", ob1, ob2);
                if( objectp(old_target = ob1->query_temp("pending/fight")) )
                        tell_object(old_target, YEL + ob1->name() + "ȡ���˺�����Ե���ͷ��\n" NOR);
                ob1->set_temp("pending/fight", ob2);
                tell_object(ob2, YEL "�����Ը��ͶԷ����б��Ԫ�����Ҳ��" + ob1->name() + "("+(string)ob1->query("id")+")"+ "��һ�� bihua ָ�\n" NOR);

                write(YEL "��춶Է�������ҿ��Ƶ����窱�����ȶԷ�ͬ����ܽ��б��ԡ�\n" NOR);
                return 1;
        }

        ob1->delete_temp("halted");
        ob2->delete_temp("halted");

        remove_call_out("check");
        call_out("check",0, ob1, ob2);

//      ob1->set("kee",(int)ob1->query("max_kee"));
//      ob2->set("kee",(int)ob2->query("max_kee"));

        remove_call_out("fighting");
        call_out("fighting",2, ob1, ob2);

        return 1;
}

void fighting(object ob1, object ob2)
{
        ob1->fight_ob(ob2);
        ob2->fight_ob(ob1);
}

void check(object ob1, object ob2)
{
        this_object()->set_temp("busy",1);
        command("chat " + ob1->query("name")
                + "��" + ob2->query("name") + "������̽��ʫ̨�Ͽ�ʼ�����۽���\n");
        call_out("observe",1,ob1,ob2);
}

int observe(object ob1,object ob2)
{
        object ob;

        if(ob1->is_fighting())
        {
                call_out("observe",1,ob1,ob2);
                return 1;
        }

        this_object()->delete_temp("busy");
        ob1->delete_temp("pending/fight");
        ob2->delete_temp("pending/fight");

        if ( !present(ob1, environment()) )
        {
                command("chat " + ob1->query("name") + "��Ķ����ˣ�\n");
                return 1;
        }

        if ( !present(ob2, environment()) )
        {
                command("chat " + ob2->query("name") + "��Ķ����ˣ�\n");
                return 1;
        }

        if (ob1->query_temp("halted"))
         {
               ob1->delete_temp("halted");
               command("chat " + ob1->query("name") +
                       "��;�������䣡\n");
                return 1;
         }
        if (ob2->query_temp("halted"))
         {
               ob2->delete_temp("halted");
               command("chat " + ob2->query("name") +
                       "��;�������䣡\n");
                return 1;
         }

        if ( ob1->query("kee")*2 > ob1->query("max_kee"))
        {
                if  (ob2->query("kee")*2 > ob2->query("max_kee")) {
                        command("chat " + ob1->query("name")
                                + "��" + ob2->query("name") + "���䲻��ʤ����\n");
                        return 1;
                }
                command("chat " + ob1->query("name")
                        + "����սʤ" + ob2->query("name") + "��\n");
                ob = new("clone/money/silver");
                ob->move(ob1);
        }
        else
        {
                command("chat " + ob2->query("name")
                        + "����սʤ" + ob1->query("name") + "��\n");
                ob = new("clone/money/silver");
                ob->set_amount(2);
                ob->move(ob2);
        }

        return 1;

}

int do_halt()
{
 object me = this_player();
if (me->is_fighting())
 me->set_temp("halted",1);
return 0;
}


