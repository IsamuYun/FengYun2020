#include <ansi.h>

inherit F_CLEAN_UP;
int main(object me, string arg)
{
	object ob;
            string target,obj,familys;
	if( !arg )	return notify_fail("bangtitle <某人> <名号>。\n");
        if( !arg || sscanf(arg, "%s %s", obj,target)!=2 )
                return notify_fail("bangtitle <某人> <名号>。\n");
	ob = find_player(obj);
	familys=me->query("family/family_name");
if( !ob )	ob = find_living(obj);
	if( !ob )	ob = present(obj, environment(me));
       if( !ob ) return notify_fail("你的弟子不在线上不能给他改名号。\n");
       if( me->query("family/privs") == 0) return notify_fail("你不是掌门不能用这个指令。\n");
       if( ob->query("family/master_id") != me->query("id")) return notify_fail("你只能给自己的弟子改名号。\n");
	if( strlen(target) > 20 )
return notify_fail("名号太长了，想一个短一点的、响亮一点的。\n");
	target = replace_string(target, "$BLK$", BLK);
	target= replace_string(target, "$RED$", RED);
	target= replace_string(target, "$GRN$", GRN);
	target= replace_string(target, "$YEL$", YEL);
	target= replace_string(target, "$BLU$", BLU);
	target= replace_string(target, "$MAG$", MAG);
	target= replace_string(target, "$CYN$", CYN);
	target= replace_string(target, "$WHT$", WHT);
	target= replace_string(target, "$HIR$", HIR);
	target= replace_string(target, "$HIG$", HIG);
	target= replace_string(target, "$HIY$", HIY);
	target= replace_string(target, "$HIB$", HIB);
	target= replace_string(target, "$HIM$", HIM);
	target= replace_string(target, "$HIC$", HIC);
	target= replace_string(target, "$HIW$", HIW);
	target= replace_string(target, "$NOR$", NOR);
	ob->set("title",familys+target+ NOR);
	write("Ok.\n");
	return 1;
}
int help(object me)
{
        write(@HELP
指令格式 : bangtitle <弟子> <名号，头衔>
 
这个指令可以让你的帮派的弟子有创意的名号或头衔。
使用 ANSI 的控制字元改变颜色，可以用以下的控制字串：

$BLK$ - 黑色		$NOR$ - 恢复正常颜色
$RED$ - 红色		$HIR$ - 亮红色
$GRN$ - 绿色		$HIG$ - 亮绿色
$YEL$ - 土黄色		$HIY$ - 黄色
$BLU$ - 深蓝色		$HIB$ - 蓝色
$MAG$ - 浅紫色		$HIM$ - 粉红色
$CYN$ - 蓝绿色		$HIC$ - 天青色
$WHT$ - 浅灰色		$HIW$ - 白色
 
其中系统自动会在字串尾端加一个 $NOR$。

HELP
        );
        return 1;
}
