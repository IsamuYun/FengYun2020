#include <ansi.h>
#include <mudlib.h>
#define CHINESE_MUD_NAME "烈风传－－上海站"
inherit F_CLEAN_UP;

int level(mixed, mixed);
string wiz_rank(string hood);

int main(object me, string arg)
{
        string *list, hood = "", str="";
        object wiz;
        int j = 0;

	seteuid(getuid());
        list = sort_array(SECURITY_D->query_wizlist(), (: level :) );
        str = HIC+MUD_NAME+NOR +"巫师情报：\n";
        str += "———————————————————\n";
        for(int i=0; i<sizeof(list); i++, j++) {
                if (hood!= wiz_rank(wizhood(list[i]))) {
                        hood = wiz_rank(wizhood(list[i]));
                        if (j%7) str += "\n";
                        str += hood;
                        str = replace_string(str,"(",HIG);
                        str = replace_string(str,")",": "NOR);
                        j = 0;
                }

		wiz = new(LOGIN_OB);
		wiz->set("id", list[i]);
		wiz->restore();
                str += sprintf(" 代号：%s\t上次连线时间：%s\t离线时间：%s天" NOR "%s", list[i], 
                ctime(wiz->query("last_on")), 
                (time()-wiz->query("last_on"))/3600/24>28?
                RED+chinese_number((time()-wiz->query("last_on"))/3600/24) :
                chinese_number((time()-wiz->query("last_on"))/3600/24),
                wiz->restore() ? "\n" : "(此人已经失踪!)\n");
                destruct(wiz);
        }
        str += "\n———————————————————\n";
        str += sprintf("目前一共有: %d个巫师\n",sizeof(list) );
        me->start_more(str);
        return 1;
}
string wiz_rank(string hood)
{	switch(hood) {
		case "(god)":
			return HIM "【 天    皇 】\n" NOR;
		case "(leisure)":
			return HIG "【 闲云野鹤 】\n" NOR;
		case "(programmer)":
			return HIM "【 程序主管 】\n" NOR;
		case "(admin)":			
			return HIR "【 系统主管 】\n" NOR;
		case "(manager)":			
			return HIC "【 大管理员 】\n" NOR;
		case "(arch)":			
			return HIY "【 大程序员 】\n" NOR;
		case "(wizard)":		
			return HIG "【 主程序员 】\n" NOR;
		case "(apprentice)":		
			return HIB "【学徒程序员】\n" NOR;
		case "(immortal)":		
			return HIC "【玩家管理员】\n" NOR;
	}
}
int level(mixed ob1, mixed ob2)
{
	if (wiz_level(ob1) != wiz_level(ob2))
                return wiz_level(ob1) - wiz_level(ob2);
        return ob1 < ob2?-1:1;
}

int help(object me)
{
        write("\n指令格式 : showwiz\n"
        "用途 : 列出目前所有的巫师名单。\n"
        );
        return 1;
}

