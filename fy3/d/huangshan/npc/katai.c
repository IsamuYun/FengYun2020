// TIE@FY3

#include <ansi.h>
inherit NPC;
inherit F_BANKOWNER;
void create()
{
        set_name("�̩", ({ "yang kaitai","yang" }) );
        set("title", RED "��Դ��ͨǮׯ�ϰ�" NOR);
        set("gender", "����" );
        set("age", 32);
        set("richness",5000000);
        set("str", 22);
        set("cor", 30);
        set("cps", 30);
        set("int", 26);
        set("per", 23);
        set("con", 24);
        set("spi", 30);
        set("kar", 25);
        set("no_arrest",1);
        set("long",
                "���ķ������������ż��ɸɾ����Ĳ��£������˾����ǿ�ճ�¯��Ӳ�����\n");
        set("combat_exp", 200000);
	set_skill("unarmed",100);
	set_skill("changquan",100);
        set("attitude", "friendly");

        set("max_force", 1000);         set("force", 1000);             
	set("force_factor", 30);
	set_skill("dodge",200);
        map_skill("unarmed", "changquan");
        
        set("inquiry", ([
                "������" : "���������ֺ���ʮһ����һ��ɣ�\n",
        ]) );

        setup();
        carry_object("/obj/cloth")->wear();
       // add_money("gold", 10);
}

void init()
{
	::init();
        add_action("do_convert", "convert");
        add_action("do_deposit", "deposit");
        add_action("do_balance", "balance");
        add_action("do_withdraw", "withdraw");
	add_action("do_loan","loan");
}
int accept_object(object who, object ob)
{
  object silk;
  if(ob->query("id") == "suanpans")
    {
command("say ��л��λ" + RANK_D->query_respect(who)+ "Զ���ѽ��������������Ǹ���ĸ�л��\n");
silk = new("/questobj/big");
silk->move(who);
tell_object(who,"�̩����һ��"+silk->query("name")+"��\n");
//silk->move(this_object());
//command("give jin-nang to " + who->query("id"));
who->add("bigtasks",1);
        return 1;
        }
}
