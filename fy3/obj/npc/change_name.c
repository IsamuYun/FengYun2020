// dazhuang.c ������״
#include <ansi.h>
#include <login.h>
inherit NPC;

void create()
{
        set_name("������״", ({ "jinya_dazhuang", "jingya", "dazhuang" }));
        // set("title", "С����Ĵ�");
        set("nickname", "��������");
        set("shen_type", 1);

        set("str", 50);
        set("gender", "����");
        set("age", 55);

        set("long", @LONG
���������״�����ķ���������ɫ�����뷢���ס�
��˵���ܸı��˵����ˡ��������������������ûǮ
����������㡣
LONG
        );

        set("combat_exp", 95000000);

        set("attitude", "friendly");
        set("inquiry", ([
                "����" : "�㿼��������𣿸�����Ҫ��Ǯ�ġ�",
        ]));

        setup();
        carry_object("/obj/cloth/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

        add_action("do_name","��");
}
void greeting(object ob)
{
        if (!ob || environment(ob) != environment())
                return;
        switch(random(2)) {
        case 0 :
                say("������״Ц���е�˵������λ" + RANK_D->query_respect(ob) +
                        "�������ȱ���ɣ�\n");
                break;
        case 1 :
                say("������״���ֵĵ���Ӵ����λ" + RANK_D->query_respect(ob) +
                        "������������\n");
                break;
        }
}

int accept_object(object who, object ob)
{

        if (ob->query("money_id") && ob->value() >= 20000000)
        {
                tell_object(who, "������״���˵�˵�����ðɣ�������ȡ��ʲô��������\n");
                tell_object(who, "�����Լ����룺�� �µ���������\n");
                who->set_temp("fee_paid",1);
                return 1;
        }
        else if (ob->query("money_id") && ob->value() < 20000000)
        {
                tell_object(who, "������״�ٺٵļ�Ц,��������ЩǮ���ҲŲ��ɣ��㻹��ȥ�ɡ�\n");
                return 0;
        }

        return 0;
}

int do_name(string target)
{
        object me;
        string old_name;
        me = this_player();
        old_name = me->query("name");

        if( !me->query_temp("fee_paid") )
                return notify_fail("������״�����˵��������Ҫ����ʲ�ᣬ����Ҫϸ���ѽ��\n");

        if( !target || target==" ") return notify_fail( @TEXT
������״�����㣬������Ҫ�����򣺸� <������>
TEXT
        );

        if( old_name == target )
                return notify_fail("������׳���ȵض���˵��������Ǯ�ǲ������͸��ң�\n");

        command("chat " + old_name + "�����ڿ�ʼ����Ϊ��" + target + "������Ժ���ϴ����ˣ�����......\n");
        me->delete_temp("fee_paid");
        me->set("name", target);

        return 1;
}
