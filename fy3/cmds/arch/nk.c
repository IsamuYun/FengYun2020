
//xgchen@zzfy

#include <ansi.h>

int main(object me, string arg)
{
        object obj,dest;
        string sb1, sb2;

        if( !arg || arg=="" )
                return notify_fail("指令格式：nk sb1 sb2\n");

        if( !(sscanf(arg, "%s %s", sb1, sb2)==2) ) 
                return notify_fail("指令格式：nk sb1 sb2\n");

        if( sscanf(arg, "%s %s", sb1, sb2)==2 ) 
        dest=(present(sb1, environment(me)));
        obj=(present(sb2, environment(me)));

        if(sb1 == sb2)
                return notify_fail("请用两个不同的人名。\n");

        if(!objectp(obj = present(sb1, environment(me))) || 
                !objectp(dest = present(sb2, environment(me))))
        return notify_fail("这里没有这两人。\n");

        if( !obj->is_character() || obj->is_corpse() || !dest->is_character() || dest->is_corpse() )
                return notify_fail("看清楚一点，那并不是活物。\n");

        if( !living(obj) || !living(dest) )
                return notify_fail("已经有人不能战斗了。\n");

        message_vision(CYN "$N对$n说道："+ RANK_D->query_self(obj) + obj->query("name") + "，领教"
                + RANK_D->query_respect(dest) + "的高招！\n"NOR, obj,dest);
        message_vision(CYN"$N一拱手，说道："+ RANK_D->query_self(dest) +"领教了。\n"NOR, dest);

        obj->delete_temp("halted");
        dest->delete_temp("halted");

        remove_call_out("check");
        call_out("check",2, obj, dest);

        dest->set("kee",(int)dest->query("max_kee"));
        obj->set("kee",(int)obj->query("max_kee"));

        dest->set("eff_kee",(int)dest->query("max_kee"));
        obj->set("eff_kee",(int)obj->query("max_kee"));

        remove_call_out("fighting");
        call_out("fighting",2, obj, dest);

        return 1;

}

void fighting(object dest, object obj)
{
            dest->set("biwu_fighter",1);
            obj->set("biwu_fighter",1);
        dest->fight_ob(obj);
        dest->fight_ob(obj);
}

void check(object obj, object dest)
{
        string name1, name2;
        if (!obj->query("family/family_name") && dest->query("family/family_name")){
        name1 ="无门派的" + obj->query("name");
        name2 = dest->query("family/family_name")+"的"+dest->query("name");
        }
        else if (!dest->query("family/family_name") && obj->query("family/family_name")){
        name1 = obj->query("family/family_name")+"的"+obj->query("name");
        name2 ="无门派的" + dest->query("name");
        }
        else if (!dest->query("family/family_name") && !obj->query("family/family_name")){
        name1 ="无门派的" + obj->query("name");
        name2 ="无门派的" + dest->query("name");
        }
        else {
        name1 = obj->query("family/family_name")+"的"+obj->query("name");
        name2 = dest->query("family/family_name")+"的"+dest->query("name");
        }
        message("channel:gab",HIR"【比武场】"+
                name1+"与"+name2+"在比武台上较量高低！\n\n"NOR,users());
//      shout( HIR"〖比武大会〗比武正式开始，由" + name1 + "对" + name2 + "！\n"NOR);
//      write( HIR"〖比武大会〗比武正式开始，由" + name1 + "对" + name2 + "！\n"NOR);
}

int help(object me)
{
        write(@HELP
指令格式 : nk <人物1> <人物2>
 
这个指令可以让两个NPC或玩家或NPC与玩家互相攻击。
HELP
        );
        return 1;
}

