//edit by xgchen
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void consider();
void create()
{
    set_name("��������", ({"dongfang bubai", "dongfang", "bubai"}));
    set("nickname", HIY "�����޵�" NOR );
    set("title", HIM"������̽���"NOR);
    set("gender", "����");
    set("shen_type", -1);
    set("age", 42);
    set("long",
        "������������̽������ų����˿ɵУ������һ�ƺ�Ϊ���������ܡ���\n");
    set("attitude", "peaceful");

    set("per", 21);
    set("str", 21);
    set("int", 30);
    set("con", 26);
    set("dex", 30);

    set("chat_chance", 1);
    set("chat_msg", ({
 "��������̾�˿����������� ���� �ҵ�����....����ô��������,�Һ�\n"
 "������ ������������������¶������ã��\n",
        }));
    set("inquiry", ([
        "����ͤ"   : "���ֱ���Ұ��˵�����,������ѽ�� \n",
        "��������" : "������ܰ���ȡ�ÿ������䣬��һ������л�㡣\n",
    ]));

    set("force_factor", 200);
        set("max_gin", 3000);
        set("max_kee", 3000);
        set("max_sen", 3000);
        set("eff_gin", 3000);
        set("eff_kee", 3000);
        set("eff_sen", 3000);
        set("gin", 3000);
        set("kee", 3000);
        set("sen", 3000);
        set("max_atman", 300);
        set("atman", 300);
        set("max_force", 3000);
        set("force", 3000);
        set("max_mana", 300);
        set("mana", 300);
        set("chat_chance", 1);
        set("combat_exp", 99999999);
        set("score", 90000);


    set_skill("force", 250);             // �����ڹ�
    set_skill("unarmed", 250);           // ����ȭ��
    set_skill("dodge", 250);             // ��������
    set_skill("parry", 250);             // �����м�
    set_skill("sword", 250);             // ��������
    set_skill("pixie-sword", 250);        // ��а����
    set_skill("literate", 100);          // ����ʶ��
    set_skill("kuihua-force", 250);      // ������

    map_skill("force", "kuihua-force");
    map_skill("sword", "pixie-sword");
    map_skill("dodge", "pixie-sword");
    map_skill("parry", "pixie-sword");

    create_family("�������", 2, "����");

    setup();
    carry_object("/d/obj/xiuhua")->wield();
    carry_object("/d//obj/qi-dress")->wear();

}

void attempt_apprentice(object ob)
{
    if (ob->query_int() < 30) {
        command("say �Ҳ������ʲ�ĵ��ӣ�����ذɣ�\n");
                return;
    }
    if (ob->query("gender") !="����" ) {
        command("say Ҫ���񹦣������Թ���");
              return;
    }
    if ((int)ob->query("shen") >100000 || (int)ob->query ("shen") < -100000 ) {
        command("say �Һ�ľ�������������������������ֳ�������򽻵�������ذɣ�;\n");
                return;
        }
    command("say �ܺã��ܺá�\n");
    command("recruit " + ob->query("id"));
}
int recognize_apprentice(object ob)
{
        mapping myfam;
        myfam = (mapping)ob->query("family");
        if ( myfam["family_name"] == "��ľ��") return 1 ;
        if ((int)ob->query_temp("tmark/��") == 1 )
        message_vision("�������ܿ��˿�$N��˵��������������˭Ҳ��Ƿ˭,\n"
                          "�㲻Ҫ������ѧϰ�����ˡ�\n", ob);
        if (!(int)ob->query_temp("tmark/��"))
                return 0;
        ob->add_temp("tmark/��", -1);
        return 1;
}



int accept_object(object who, object ob)
{

        if ( (string) ob->query("id") =="kuihua baodian1" ) {
                if (!(int)who->query_temp("tmark/��",)) who->set_temp("tmark/��",100);
                message_vision("�������ܿ��˿�$N�������ؼ������˵�ͷ��˵����\n"
                               "�ѵ��㽫�����ͻء������ҵĶ����Ҿ������ˡ�\n"
                               "��Ϊ����,����Դ�������ѧ�㹦��\n", who);
                who->add_temp("tmark/��", 100);
                return 1;

        }
        return 0;
}
