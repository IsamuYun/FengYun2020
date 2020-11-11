// Tie@fy
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("高人", ({ "gaoren" }) );
        set("gender", "男性" );
	set("title","半仙兽");
        set("age", 32);
        set("long","一个得半道的老道士，对改善动物的体质别有妙技。\n");
        set("combat_exp", 5000);
        set("attitude", "friendly");
        set("chat_chance", 15);
        set("chat_msg", ({
   //             (: random_move :)
        }) );
				set("inquiry", (["训练" : "我可以帮助你训练(train)你的宠物等级，前提是你有足够的潜能。",   
				]));
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
                        say( "高人说道：这位" + RANK_D->query_respect(ob)
                                + "，来陪我聊一聊？\n");
                        break;
                case 1:
                        say( "高人笑道：这不，生意来了！\n");
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
	if(!arg) return notify_fail("高人道：＂你只能训练(train <pet id>)来转换自身的潜能给宠物！＂\n");
	pet = present(arg,environment());
	if(!objectp(pet)) return notify_fail("高人道：＂你要训练什么宠物呀？＂\n");
	if(pet->query("possessed") != me )
	return notify_fail("高人道：＂那好象不是你的吧？＂\n");
	if(pet->query("is_pet") != 1)
		return notify_fail("高人道：这个是什么东西。\n");
	j=100;
	lv = pet->query("level");
//okey we identified the target, now the cost:
	cost = (int) pet->query("level") * 10;
	gold = present("gold_money", me);
        if(!gold) return notify_fail("你身上没有金子。\n");
        if((int) gold->query_amount() < cost)
        return notify_fail("你身上没有"+chinese_number(cost)+"两金子。\n");
	if((int)me->query("score") < cost)
	return notify_fail("你的评价不够"+chinese_number(cost)+"点。\n");
	if((int)me->query("level") < pet->query("level"))
		return notify_fail("你的宠物等级只能比你的等级高一级。\n");
	for(i=0;i<lv;i++)
		j=j+j/9;
	exp = j - pet->query("combat_exp");
	if (exp>0)
	{
	if( (int)me->query("potential") - (int)me->query("learned_points") < exp )
		return notify_fail("你的潜能还不够"+j+"点，宠物不能升级。\n");
	me->add("potential",-exp);
	pet->set("combat_exp",0);
	pet->add("level",1);
	pet->add("gift_point",12);
	gold->add_amount(-cost);
	me->add("score",-cost);
	command("say 你花费了"+chinese_number(cost)+"两黄金，"+chinese_number(exp)+"点潜能和"+chinese_number(cost)+"点评价，你的宠物升到了"+chinese_number(pet->query("level"))+"级了！\n");
	if (random(pet->query("chengzhang")>35))
		pet->add("gift_point",1);
	}
	else {
	pet->add("combat_exp",-j);
	pet->add("level",1);
	pet->add("gift_point",12);
	gold->add_amount(-cost);
	me->add("score",-cost);
	command("say 你花费了"+chinese_number(cost)+"两黄金，"+chinese_number(exp)+"点潜能和"+chinese_number(cost)+"点评价，你的宠物升到了"+chinese_number(pet->query("level"))+"级了！\n");
	if (random(pet->query("chengzhang")>35))
		pet->add("gift_point",1);
	}
	if (!pet->query_skill("petfangyu",1) && pet->query("title")=="乌龟" && random(20) == 1)
	{
		pet->set_skill("petfangyu",1);
		command("ack");
		command("say 恭喜你的宠物领悟了防御术。\n");
	}
	if (!pet->query_skill("petgedang",1) && pet->query("title")=="肥猪" && random(20) == 1)
	{
		pet->set_skill("petgedang",1);
		command("ack");
		command("say 恭喜你的宠物领悟了格挡术。\n");
	}
	if (!pet->query_skill("petfire",1) && pet->query("title")=="猫咪" && random(20) == 1)
	{
		pet->set_skill("petfire",1);
		command("ack");
		command("say 恭喜你的宠物领悟了纵火术。\n");
	}
	if (!pet->query_skill("petbisha",1) && pet->query("title")=="猴子" && random(20) == 1)
	{
		pet->set_skill("petbisha",1);
		command("ack");
		command("say 恭喜你的宠物领悟了必杀术。\n");
	}
	if (!pet->query_skill("petqiangji",1) && pet->query("title")=="野牛" && random(20) == 1)
	{
		pet->set_skill("petqiangji",1);
		command("ack");
		command("say 恭喜你的宠物领悟了强击术。\n");
	}
	pet->save();
	return 1;
}
