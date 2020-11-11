inherit NPC;
#include <ansi.h>
void create()
{
        set_name("士兵", ({ "soldier"}) );
        set("age", 30);
	set("long",
"这是守卫紫禁城的士兵。\n");
        set("attitude", "peaceful");
        set("no_arrest", 1);
        set("can_carry", 1);
        set("hit_always_on", 1);
        set("str", 80);
        set("combat_exp", 10000000);
        set("limbs", ({ "ＰＰ" }) );
        set_skill("unarmed", 400);
        set_skill("dodge",400);
        set_skill("parry",400);
        create_family("朝廷三品", 1, "兵");
	setup();
}


int accept_object(object who, object ob)
{
object room;
if(ob->query("name") == "七彩丝缎带" && environment()->query("accept_in"))
{
        command("emote 点了点头,说:你可以通过了！\n");
        environment()->add("accept_in",-1);
    room = find_object("/obj/wall");
      if(!objectp(room)) room = load_object("/obj/zijinmen");
    who->move(room);
	return 1;
}

if(ob->query("name") == "七彩丝缎带" && environment()->query("accept_intwo"))
{
        command("emote 现出很奇怪的表情,看了看丝带,摸了摸。\n");
        command("emote 用那种表情打量了你好久,叹了口气。\n");
    room = find_object("/obj/wall");
      if(!objectp(room)) room = load_object("/obj/zijinmen");
    who->move(room);
        environment()->add("accept_intwo",-1);
	return 1;
}

if(ob->query("name") == "七彩丝缎带")
{
        command("emote 现出很奇怪的表情,看了看丝带,摸了摸。\n");
        command("emote 骂道:他妈的！今天老子见到鬼了！\n");
        command("emote 喝道:不许通过！\n");
	return 1;
}
}
