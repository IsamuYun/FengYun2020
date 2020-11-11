inherit NPC;
#include <ansi.h>
void create()
{
        set_name(HIG "铁战" NOR, ({ "tiezhan" }) );
        set("no_arrest",1);
        set("gender", "男性");
  set("reward_npc", 1);
        set("difficulty", 80); 

        set("age", 79);
        set("long",
                "    这人身材也不太高，最多也只不过有六、七尺，但横著来量，竟也有五尺六七，一个人
看来竟是方的，就像是一块大石头。他的头更大得出奇，头砍下来称一称，最少也有三
五十斤，满头乱蓬蓬的生著鸡窝般的一头乱发，头发连著胡子，胡子连著头发，也分不
清什么是胡子，什么是头发了，鼻子嘴巴，更是连找都找不到。远远望去，这人就像是
一块大石块上蹲著一头刺猬，又像是一头被什么东西压得变了形的雄狮。\n");
        set("attitude", "friendly");
        set("chat_chance", 1);
        set("chat_msg", ({
                "铁战吼道：想打架吗？找我就对了．．．．\n",
        }) );

        set("score", -50000);
        
        set_skill("move", 220);
        set_skill("parry",250);
        set_skill("lianxin-blade", 200);
       set_skill("dodge",220);
        set_skill("unarmed", 200);
        set_skill("force", 250);
        set_skill("iron-cloth", 220);
        set_skill("jin-gang", 230);
        set_skill("blade", 200);
        set_temp("apply/damage",1000);
        map_skill("iron-cloth", "jin-gang");
       map_skill("blade", "lianxin-blade");
        map_skill("parry", "lianxin-blade");

        create_family("eren", 1, "二师傅");
        set("title", HIR "狂狮" NOR);
        setup();
        carry_object("/tongji/obj/blade")->wield();

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
//        object ob = find_object("/tongji/npc/zhuge.c");
        
        if (!this_object()->is_fighting()) 
        {
//        	if(ob && ob->query_temp("gtongji")>0)
//        	{
//        		ob->add_temp("gtongji",-1);	
//        	}
        	command("rumor "+this_object()->query("name")+"返回恶人谷去了。");
            destruct(this_object());
        }
        else
        {
        	call_out("leave",10);
        }
}

void die()
{
	object obj;
        object me = this_object()->query_temp("last_damage_from");
//        object ob = find_object("/tongji/npc/zhuge.c");
//        object ob = this_object()->query_temp("owner");
//        if(ob && ob->query_temp("gtongji")>0)
//        {
//        	ob->add_temp("gtongji",-1);	
//        }

    if (!objectp(me))
    {
        ::die();
        write("\n谢谢你为人民群众除了一大害！\n\n");
        return;
    }
    // 如果是用其他如大内等杀的，要做如此转换
    if (!userp(me))
        me = find_player(geteuid(me));
//		message("vision", name() + "死了。\n" NOR, environment(), this_object() );
		message_vision(this_object()->query("name")+"死了。\n",me);
        if (me->query("tongji") && this_object()->query_temp("owner/id") == me->query("id")) 
        {
	        message_vision("\n$N割下人头，揣入自己的怀中！\n\n",me);
	        obj=new("/tongji/obj/tou2");
	        obj->set_temp("owner/id",me->query("id"));
	        obj->move(me);
        }
        else 
        {
			message_vision("\n谢谢你为人民群众除了一大害！\n\n",me);
		}

        me->add("MKS", 1);

        destruct(this_object());
}
