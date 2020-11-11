// waiter.c

inherit NPC;
int give_him();
inherit F_VENDOR;
#include <ansi.h>
void create()
{
        set_name("��ǧ��", ({ "duqianli" }) );
        set("gender", "����" );
        set("age", 81);
        set("title", CYN "�Ÿ߰˶�" NOR);
        set("long",
                "��λ�ϰ岻���Ÿ߰˶������һ��ǵ����̫�ӵ���ʦ��\n");
        set("combat_exp", 500000);
        	  set_temp("kf_tufei",5);
        set("pursuer", 1);
set("attitude", "friendly");
        set("per",30);
        set("vendor_goods", ([
                __DIR__"obj/book" : 10,
                __DIR__"obj/book3" : 20,
                __DIR__"obj/book4" : 20,
                __DIR__"obj/book5" :33,
                __DIR__"obj/book6": 22,
                __DIR__"obj/book7":22,
                __DIR__"obj/book8":11,
                __DIR__"obj/book9":10,
        "/obj/weapons/swordbook":5,
        "/obj/weapons/bladebook":5,
        "/obj/weapons/staffbook":5,
		"/obj/weapons/ringbook":5,
		"/obj/weapons/hammerbook":5,
		"/obj/armors/headbook":5,
		"/obj/armors/clothbook":5,
		"/obj/armors/neckbook":5,
		"/obj/armors/shieldbook":5,
		"/obj/armors/waistbook":5,
		"/obj/armors/wristsbook":5,
		"/obj/armors/fingerbook":5,
		"/obj/armors/bootsbook":5,
        "/d/bat/npc/obj/qfbook":10,

        ]) ); 
        set_skill("unarmed",50);
        set_skill("dodge",50);
        set("inquiry", ([
                "ī" : (: give_him :),
                "mo" : (: give_him :),
        ]));
        setup();
        carry_object(__DIR__"obj/fycloth")->wear();
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
message_vision("$Nҡͷ���Եص���������ʱ���������������������Ӫ��·�࣮����\n",this_object(),ob);
                        break;
                case 1:
message_vision("$N����$nһ�ۣ��ͺߵ����ᷢΪ���ޣ����������ɡ������ڽ�Ϧ������\n",this_object(),ob);
                        break;
        }
}
int give_him()
{
        object me , obj;
        me = this_player();
        if( !query("given")) {
        obj = new(__DIR__"obj/mo");
        message_vision("$N˵������Ȼ����������Ȥ���Ҿͳ�ȫ���ˣ���ǧ�����$nһ����⡣\n",this_object(), me);
        obj->move(me);
        set("given",1);
        return 1;
        }
        return 0;
}

void reset()
{
delete("given");
}
int accept_object(object who, object ob)
{
  object silk;
if(ob->query("id") == "qypu")
        {
command("say ��л��λ" + RANK_D->query_respect(who)+ "����һֱ���ҵ��Ȿ�飬���Ǹ���Ľ�����\n");
silk = new("/questobj/big");
silk->move(who);
        tell_object(who,"��ǧ�����һ��"+silk->query("name")+"��\n");
//silk->move(this_object());
//command("give jin-nang to " + who->query("id"));
who->add("bigtasks",1);
        return 1;
        }
        tell_object(who,"��ǧ��˵�����ⲻ������Ҫ�ġ�\n");
        return 0;
}
