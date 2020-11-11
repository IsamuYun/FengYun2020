// teacher.c

inherit NPC;

void create()
{
	set_name("梦焕", ({ "meng huan", "huan" }) );
        create_family("少林寺", 20, "弟子");
	set("title", "笔下生花");
        set("vendetta_mark","shaolin");
	set("int",1);
	set("gender", "男性" );
	set("age", 57);
        set("chat_chance", 10);
        set("chat_msg", ({
                "梦焕道：＂大江东去，浪淘尽千古风流人物！＂\n",
        }) );
	set("long",
		"梦焕是个风趣的和尚，他年轻时曾经中过秀才，但是\n"
		"因为后来仕途坎坷，出家为僧，如果你愿学读书和佛法\n"
		"梦焕总是会教的．\n");
	set("attitude", "peaceful");
	set_skill("literate", 140);
	set_skill("buddhism",100);
	setup();
}

int recognize_apprentice(object ob)
{
	return 1;
}
int accept_object(object who, object ob)
{
  object silk;
  if(ob->query("id") == "tianshus")
{
           command("smile");
           command("say 这位" + RANK_D->query_respect(who)+ "，谢谢你了我一直想找到它，这是给你的奖励！\n");
silk = new("/questobj/big");
silk->move(who);
tell_object(who,"梦涣给你一个"+silk->query("name")+"。\n");
//silk->move(this_object());
//command("give jin-nang to " + who->query("id"));
who->add("bigtasks",1);
        return 1;
        }
        tell_object(who,"梦涣道：想骗我，这不是我要的东西。\n");
        return 0;
}
