// lifeskills.c written by Tiandi
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob;
        seteuid(getuid());
        if(!arg)
                    ob = me;
        else{
                    ob = present(arg, environment(me));
                    if (!ob) ob = find_player(arg);
                    if (!ob) ob = find_living(arg);
                    if (!ob) return notify_fail("你要察看谁的生活技能？\n");
         }
        if( ob!=me && !wizardp(me) )
                    return notify_fail("只有管理员能察看他人的生活技能。\n");
    if (me->query("lifecook"))
		{
		if (!me->query("lifecombine"))
			{
			me->set("lifecombine",1);
			me->set("lifexiang",1);
			}
		}
        write( (ob==me ? "你" : ob->name()) +"目前掌握的生活技能程度如下：\n\n");
        write( "【烹饪技巧】：    "  + ob->query("lifecook") + "/" + ob->query("lifecook_exp") );
        write( "\n【炼丹技巧】：    "  + ob->query("lifedoctor") + "/" + ob->query("lifedoctor_exp") );
        write( "\n【锻造技巧】：    "  + ob->query("lifeweapon") + "/" + ob->query("lifeweapon_exp") );
        write( "\n【炼制技巧】：    "  + ob->query("lifearmor") + "/" + ob->query("lifearmor_exp") );
	if (ob->query("stoneok")||ob->query("stonefail"))
        		write( "\n【合成技巧】：    "  + ob->query("lifecombine") + "/" + ob->query("lifecombine_exp") +"     成功率:     "+ ob->query("stoneok")*100/(ob->query("stoneok")+ob->query("stonefail"))+"%");
      	else
		write( "\n【合成技巧】：    "  + ob->query("lifecombine") + "/" + ob->query("lifecombine_exp") );
	if (ob->query("xiangok")||ob->query("xiangfail"))
	 	write( "\n【镶嵌技巧】：    "  + ob->query("lifexiang") + "/" + ob->query("lifexiang_exp") +"     成功率:     "+ ob->query("xiangok")*100/(ob->query("xiangok")+ob->query("xiangfail"))+"%");
       	else
		write( "\n【镶嵌技巧】：    "  + ob->query("lifexiang") + "/" + ob->query("lifexiang_exp") );
	 write( "\n\n 活力:" + ob->query("lifetili") + "/" + ob->query("max_lifetili") + "\n\n");
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : lifeskills 

这个指令可以让你查询自己的生活技能程度。

HELP
    );
return 1;
}
