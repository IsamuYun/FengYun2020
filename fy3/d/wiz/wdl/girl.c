//NPC: /open/girl.c
//wdl bye 2000/12/19
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("������Ů",({"jueshi meinv","meinv"}) );
        set("nickname", HIR "����ʴ��"NOR);
        set("gender","Ů��");
        set("age",18);
        set("per",80);
        set("str",18);
        set("cor",48);
        set("cps",48);
        set("int",48);
        set("long",
"�������ѳ�������������㿴����ʱ�̲�ס�����Ѫ��
��ʱ��������ֻ��һ���뷨������Ҫ�����ҵ����š���
"
        );
        set("combat_exp",500+random(500));
        set("attitude", "heroism");
        set("max_force", 5000);
        set("force", 5000);
        set("no_teach", 1);
        set("force_factor", 50);
        create_family("���̵�", 1, "����");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.yiqiguanriyue" :),
        }) );
        set("chat_chance",1);
        set("chat_msg",({
                "������Ů���������֣�Ц������ӭ����ӭ��\n",
                "������Ů�Ͻ���ס����ǣ���ӭ��ĵ�����\n",
        }) );

        set_skill("yiqiguanforce", 260);
        set_skill("yoga", 320);
        set_skill("buddhism", 320);
        set_skill("force",320);
        set_skill("unarmed",320);
        set_skill("vivien-sword",320);
        set_skill("parry",320);
        map_skill("unarmed", "yiqiguanforce");
        setup();
}

void attempt_apprentice(object me)
{
        if( !me->query("int"))
        {
        command("smile");
        command("recruit " + me->query("id") );
        }
        else
        command("say ��̫ǫ���ˣ���ô����������ѧʲô��\n");
                return ;
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) );
                ob->set("class", "yunyandao");

}
void re_rank(object student)
{
                student->set("title","���̵�Ⱥ��֮��");
                return ;

}
