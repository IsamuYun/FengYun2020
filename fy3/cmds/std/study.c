// study.c

#include <skill.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object ob;
	mapping skill;
	string	book,liter;
	int cost, sena;
	int amount=0;
	int my_skill;

	if( me->is_fighting() )
		return notify_fail("你无法在战斗中专心下来研读新知！\n");
       if( me->is_busy() )
                return notify_fail("你上一个动作还没有完成，不能研读新知。\n");

       if(!arg || sscanf(arg, "%s %d", book, sena)!=2 )
                return notify_fail("指令格式：study <物品> <神数量>\n");

	if(!objectp(ob = present(book, me)) )
	if(!objectp(ob = present(book, environment(me))))
		return notify_fail("你要读什麽？\n");

	if( !mapp(skill = ob->query("skill")) )
		return notify_fail("你无法从这样东西学到任何东西。\n");
// added by tie
	if(stringp(skill["literate"])) liter = skill["literate"];
	else liter = "literate";
	if( !me->query_skill(liter, 1) )
		return notify_fail("你看不懂耶．．，先学学"+to_chinese(liter)+"吧。\n");

	message("vision", me->name() + "正专心地研读" + ob->name()
		+ "。\n", environment(me), me);
	if( me->query_skill(skill["name"], 1) /10 >= me->query("level") ) {
		write("以你现在的等级，再怎麽读也没用。\n");
		return 1;
	}
	notify_fail("以你目前的能力，还没有办法学这个技能。\n");
	if( !SKILL_D(skill["name"])->valid_learn(me) ) return 0;

	cost = skill["sen_cost"] + skill["sen_cost"] 
		* (skill["difficulty"] - (int)me->query_int())/20;
	cost = cost /2;
        if(cost < 1) cost = 1;
	if( cost > sena)
	return notify_fail("以你目前的能力，你至少要花"+chinese_number(cost)+"点神\n");
	if( (int)me->query("sen") <= sena) {
		write("你现在过於疲倦，无法专心下来研读新知。\n");
		return 1;
	}

	if( me->query_skill(skill["name"], 1) > skill["max_skill"] ) {
		write("你研读了一会儿，但是发现上面所说的对你而言都太浅了，没有学到任何东西。\n");
		return 1;
	}
	me->receive_damage("sen", sena);

	if( !me->query_skill(skill["name"], 1) )
		me->set_skill(skill["name"], 0);

	amount +=(int)me->query_skill(liter, 1)/5+1;
	if( amount < 1) amount = 1;
	amount = amount*sena/cost;
	me->improve_skill(skill["name"], amount);
	write("你研读有关" + to_chinese(skill["name"]) + "的技巧，似乎有点心得。\n");
	return 1;
}

int help(object me)
{
   write( @HELP
指令格式: study <物品名称>

这个指令使你可以从秘笈或其他物品自学某些技巧,
但前提是: 你一定要懂秘笈上的文字。

see also : learn
HELP
   );
   return 1;
}
