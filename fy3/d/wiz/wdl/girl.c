//NPC: /open/girl.c
//wdl bye 2000/12/19
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("绝世美女",({"jueshi meinv","meinv"}) );
        set("nickname", HIR "消魂蚀骨"NOR);
        set("gender","女性");
        set("age",18);
        set("per",80);
        set("str",18);
        set("cor",48);
        set("cps",48);
        set("int",48);
        set("long",
"她的美已超出了你的想象，你看到她时忍不住狂喷鼻血。
这时的你心中只有一个想法，“我要她做我的老婆”！
"
        );
        set("combat_exp",500+random(500));
        set("attitude", "heroism");
        set("max_force", 5000);
        set("force", 5000);
        set("no_teach", 1);
        set("force_factor", 50);
        create_family("云烟岛", 1, "岛主");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.yiqiguanriyue" :),
        }) );
        set("chat_chance",1);
        set("chat_msg",({
                "绝世美女向你招招手，笑道：欢迎，欢迎！\n",
                "绝世美女赶紧抱住你狂吻，欢迎你的到来！\n",
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
        command("say 你太谦虚了，这么聪明还向我学什么！\n");
                return ;
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) );
                ob->set("class", "yunyandao");

}
void re_rank(object student)
{
                student->set("title","云烟岛群仙之首");
                return ;

}
