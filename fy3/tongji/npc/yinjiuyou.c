inherit NPC;
#include <ansi.h>
void create()
{
        set_name(HIW"阴九幽" NOR, ({ "yinjiuyou" }) );
        set("no_arrest",1);
        set("gender", "男性");
  set("reward_npc", 1);
        set("difficulty", 80); 

        set("age", 46);
        set("long",
                "    这人虚虚的站在一团雾里,忽隐忽现,也不知是人是鬼。\n");
        set("attitude", "friendly");
        set("chat_chance", 1);
        set("chat_msg", ({
                "飘飘渺渺的传来一阵笑声....嘿....嘿....嘿．．．．\n",
        }) );

        set("score", -50000);
        
        set_skill("move", 200);
       set_skill("dodge",220);
        set_skill("dagger", 200);
        set_skill("force", 230);
        set_skill("iron-cloth", 190);
        set_skill("jin-gang", 230);
        set_temp("apply/damage",1000);
        map_skill("iron-cloth", "jin-gang");

        create_family("eren", 1, "十师傅");
        set("title", HIR "半人半鬼" NOR);
        setup();
        carry_object("/tongji/obj/lin")->wield();

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
	        obj=new("/tongji/obj/tou7");
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

