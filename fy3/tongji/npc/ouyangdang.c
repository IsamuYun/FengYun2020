inherit NPC;
#include <ansi.h>
void create()
{
        set_name(HIB"欧阳当" NOR, ({ "ouyangdang" }) );
        set("gender", "男性");
        set("age", 46);
        set("long",
                "    此人瘦骨嶙峋…双颧凸出，手里拿着本帐簿，穿着打扮，虽像是买卖做
得极为发达的富商大贾，模样神情，却像是刚从地狱逃出来的恶鬼。\n");
        set("attitude", "friendly");
  set("reward_npc", 1);
        set("difficulty", 80); 

        set("no_arrest",1);
        set("chat_chance", 1);
        set("chat_msg", ({
                "欧阳当把手中的帐本翻的哗哗直响．．．．\n",
        }) );

        set("score", -50000);
        
        set_skill("move", 220);
       set_skill("dodge",220);
        set_skill("unarmed", 200);
        set_skill("force", 220);
        set_skill("iron-cloth", 200);
        set_skill("jin-gang", 200);
        set_skill("tigerstrike", 230);
        set_temp("apply/damage",1000);
        map_skill("iron-cloth", "jin-gang");
        map_skill("unarmed", "tigerstrike");

        create_family("eren", 1, "九师傅");
        set("title", HIC "拼命占便宜" NOR);
        setup();
        carry_object("/tongji/obj/zhangben");

}

void init()
{
        object ob;
        
        ::init();

        ob = this_player();

        if (userp(ob) && interactive(ob) && ob->query("tongji") && query_temp("owner/id") == ob->query("id"))
        {
                command("heihei");
                command("say 十大恶人你也敢抓，好吧，我就成全了你！\n");
        this_object()->kill_ob(ob);
        ob->kill_ob(this_object());
        }
        else 
        {
        call_out("leave",300);
        }

}

void leave()
{        
        if (!this_object()->is_fighting()) 
        {
        	command("rumor "+this_object()->query("name")+"返回恶人谷去了。");
            destruct(this_object());
        }
        else
        {
        	call_out("leave",20);
        }
}

void die()
{
	object me = this_object()->query_temp("last_damage_from");
    if (!objectp(me))
    {
        ::die();
        return;
    }
    // 如果是用其他如大内等杀的，要做如此转换
    if (!userp(me))
        me = find_player(geteuid(me));
//		message("vision", name() + "死了。\n" NOR, environment(), this_object() );
		message_vision(this_object()->query("name")+"死了。\n",me);
        destruct(this_object());
}

