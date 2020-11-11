// Tie@fy
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("李一摸", ({ "yimo" }) );
        set("gender", "男性" );
	set("title","一摸全");
        set("age", 32);
        set("long","一个疯疯癫癫的老头，不过他的＂一摸＂可神了．．．\n");
        set("combat_exp", 5000);
        set("chat_chance", 15);
        set("chat_msg", ({
     //          (: random_move :)
        }) );
        set("attitude", "friendly");
        setup();
        carry_object("/obj/cloth")->wear();

}

void init()
{	
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_train", "train");

}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
                        say( "李一摸说道：这位" + RANK_D->query_respect(ob)
                                + "，来让我摸一摸？\n");
                        break;
                case 1:
                        say( "李一摸笑道：这位" + RANK_D->query_respect(ob)
                                + "，来！让我再摸一把？\n");

                        break;
        }
}

int do_train(string arg)
{
	object me,pet,gold;
	int cost,exp;
	int j,lv,i;
	string which;
        me = this_player();
        if(me->is_busy())
        return notify_fail("你上一个动作还没有完成。\n");
	if(!arg || sscanf(arg,"%s %s",arg,which) != 2)
        return notify_fail("李一摸道：＂你只能用分配(train <pet id> <参数>)来给宠物分配参数点！＂\n");
	pet = present(arg,environment());
	if(!objectp(pet)) return notify_fail("李一摸道：＂你要分配什么宠物呀？＂\n");
	if(pet->query("possessed") != me )
		return notify_fail("李一摸道：＂那好象不是你的吧？＂\n");
	if(pet->query("is_pet") != 1)
		return notify_fail("李一摸道：这个是什么东西。\n");
	if(pet->query("gift_point")< 1)
		return notify_fail("李一摸道：还有参数点么？\n");
	switch(which) {
		case "str":
			pet->add("str",1);
			break;
		case "spi":
			pet->add("spi",1);
			pet->add("max_gin",pet->query("chengzhang")/2);
			pet->add("max_sen",pet->query("chengzhang")/2);
			break;
		case "agi":
			pet->add("agi",1);
			break;
		case "dur":
			pet->add("dur",1);
			break;
		case "con":
			pet->add("con",1);
			pet->add("max_kee",pet->query("chengzhang"));
			break;
		 default:
            return notify_fail("没有这个参数点。\n");
	}

	if((int)me->query("score") < 1)
		return notify_fail("你的评价不够一点。\n");

	me->add("score",-1);
	pet->add("gift_point",-1);
	pet->save();
	command("say 好了，你的宠物相关属性增加了一点！\n");
	return 1;
}
