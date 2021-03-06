#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
       int  exp1;
	object ob;
	string obj,exp2;
        if( !arg )      return notify_fail("settop <某人> <exp/pot/score/atman/force/mana/int/dur/spi/str/kar/per/con/cor/cps/fle/tol/agi/gongxian/mud_age> <数量>。\n");
        if( !arg || sscanf(arg, "%s %s %d", obj, exp2, exp1)!=3 )
                        return notify_fail("settop <某人> <exp/pot/score/atman/force/mana/int/dur/spi/str/kar/per/con/cor/cps/fle/tol/agi/gongxian/mud_age> <数量>。\n");
	if( !ob )	ob = find_living(obj);
	if( !ob )	ob = present(obj, environment(me));
        if( !ob ) return notify_fail("找不到这个生物.\n");

	switch (exp2){
		case "mana":
			ob->set("max_mana",exp1);
			tell_object(ob,HIR"你的所作所为使巫师对你另眼相看,因此调整你法力为：\n" +
			chinese_number(exp1) + "点法力!\n"NOR);
			break;
		case "force":
			ob->set("max_force",exp1);
                        tell_object(ob,HIR"你的所作所为使巫师对你另眼相看,因此调整你内力为：\n" +                      
                        chinese_number(exp1) + "点内力!\n"NOR);
			break;
		case "atman":
			ob->set("max_atman",exp1);
			tell_object(ob,HIR"你的所作所为使巫师对你另眼相看,因此调整你灵力为：\n" +
			chinese_number(exp1) + "点灵力!\n"NOR);
			break;
                case "mud_age":
                        ob->set("mud_age",exp1);
                        tell_object(ob,HIR"你的所作所为使巫师对你另眼相看,因此调整你连线时间为：\n" +
                        chinese_number(exp1) + "秒!!\n"NOR);
                   	break;
		case "exp":
			ob->set("combat_exp",exp1);
			tell_object(ob,HIR"你的所作所为使巫师对你另眼相看,因此调整你实战经验为：\n" +
			chinese_number(exp1) + "点实战经验!\n"NOR);
			break;
		case "pot":
			ob->set("potential",exp1);
		       tell_object(ob,HIR"你的所作所为使巫师对你另眼相看,因此调整你潜能为：\n" +
			chinese_number(exp1) + "点潜能!\n"NOR);
			break;
		case "score":
			ob->set("score",exp1);
		       tell_object(ob,HIR"你的所作所为使巫师对你另眼相看,因此调整你评价为：\n" +
			chinese_number(exp1) + "点评价!\n"NOR);
			break;
                case "int":
			ob->set("int",exp1);
		       tell_object(ob,HIR"你的所作所为使巫师对你另眼相看,因此调整你才智为：\n" +
			chinese_number(exp1) + "点才智!\n"NOR);
			break;
                case "dur":
			ob->set("dur",exp1);
		       tell_object(ob,HIR"你的所作所为使巫师对你另眼相看,因此调整你耐力为：\n" +
			chinese_number(exp1) + "点耐力!\n"NOR);
			break;
                case "spi":
			ob->set("spi",exp1);
		       tell_object(ob,HIR"你的所作所为使巫师对你另眼相看,因此调整你灵性为：\n" +
			chinese_number(exp1) + "点灵性!\n"NOR);
			break;
                case "str":
			ob->set("str",exp1);
		       tell_object(ob,HIR"你的所作所为使巫师对你另眼相看,因此调整你力量为：\n" +
			chinese_number(exp1) + "点力量!\n"NOR);
			break;
                case "kar":
			ob->set("kar",exp1);
		       tell_object(ob,HIR"你的所作所为使巫师对你另眼相看,因此调整你运气为：\n" +
			chinese_number(exp1) + "点运气!\n"NOR);
			break;
                case "per":
			ob->set("per",exp1);
		       tell_object(ob,HIR"你的所作所为使巫师对你另眼相看,因此调整你魅力为：\n" +
			chinese_number(exp1) + "点魅力!\n"NOR);
			break;
                case "con":
			ob->set("con",exp1);
		       tell_object(ob,HIR"你的所作所为使巫师对你另眼相看,因此调整你体质为：\n" +
			chinese_number(exp1) + "点体质!\n"NOR);
			break;
                case "cor":
			ob->set("cor",exp1);
		       tell_object(ob,HIR"你的所作所为使巫师对你另眼相看,因此调整你勇气为：\n" +
			chinese_number(exp1) + "点勇气!\n"NOR);
			break;
                case "cps":
			ob->set("cps",exp1);
		       tell_object(ob,HIR"你的所作所为使巫师对你另眼相看,因此调整你气量为：\n" +
			chinese_number(exp1) + "点气量!\n"NOR);
			break;
                case "fle":
			ob->set("fle",exp1);
		       tell_object(ob,HIR"你的所作所为使巫师对你另眼相看,因此调整你韧性为：\n" +
			chinese_number(exp1) + "点韧性!\n"NOR);
			break;
                case "tol":
			ob->set("tol",exp1);
		       tell_object(ob,HIR"你的所作所为使巫师对你另眼相看,因此调整你定力为：\n" +
			chinese_number(exp1) + "点定力!\n"NOR);
			break;
                case "agi":
			ob->set("agi",exp1);
		       tell_object(ob,HIR"你的所作所为使巫师对你另眼相看,因此调整你速度为：\n" +
			chinese_number(exp1) + "点速度!\n"NOR);
			break;
                case "gongxian":
			ob->set("gongxian",exp1);
		       tell_object(ob,HIR"你的所作所为使巫师对你另眼相看,因此调整你贡献为：\n" +
			chinese_number(exp1) + "点贡献!\n"NOR);
			break;
			}
                     return 1;
       }
