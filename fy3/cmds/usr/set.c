// set.c
//xgchen@zzfy
#define MAX_ENV_VARS	20
 
inherit F_CLEAN_UP;
 
int help();
 
int main(object me, string arg)
{
    int i;
    string term, *terms, *wiz_only;
	mixed data;
	mapping env;
 
    wiz_only = ({"invisibility", "immortal"});
   	if( me != this_player(1) ) return 0;
 
	env = me->query("env");
 
	if( !arg || arg=="" ) {
		write("你目前设定的环境变数有：\n");
		if( !mapp(env) || !sizeof(env) )
			write("\t没有设定任何环境变数。\n");
		else {
			terms = keys(env);
			for(i=0; i<sizeof(terms); i++)
				printf("%-20s  %O\n", terms[i], env[terms[i]]);
		}
		return 1;
	}
        if(strsrch(arg,"/")>=0) return notify_fail("你也来找麻烦?省省吧!\n");
if(strsrch(arg, "conjure")>=0)
            return notify_fail("这种参数是不能使用，详细情况请news all查看。\n");
if (strsrch(arg, "perform iron-cloth")>=0)
            return notify_fail("这种参数是不能使用，详细情况请news all查看。\n");
if(strsrch(arg, "perform move.wuhuankongling")>=0)
            return notify_fail("这种参数是不能使用，详细情况请news all查看。\n");
if(strsrch(arg, "perform dodge.wuhuankongling")>=0)
            return notify_fail("这种参数是不能使用，详细情况请news all查看。\n");

	if( sscanf(arg, "%s %s", term, data)!=2 ) {
		term = arg;
		data = "YES";
	}
        if(term == "wimpy") return notify_fail("请用WIMPY这个指令。\n"); 
        if(term == "savemyass" || term == "no_pk" || term == "no_tell" || term == "report" || term == "brief" ||  term == "brief2" || term == "brief3" || term == "invisibility" || term == "immortal" || term == "no_more"|| term == "prompt"|| term == "no_accept"|| term == "no_follow") {
			if( mapp(env) && undefinedp(env[term]) && sizeof(env) >= MAX_ENV_VARS )
                        return notify_fail("你设的环境变数太多了，请先用 unset 删掉几个吧。\n");
 
                sscanf(data, "%d", data);
        if((wiz_level(me) == 0) && (member_array(term, wiz_only) != -1))
            return notify_fail("只有管理能用这个设定。\n");
        me->set("env/" + term, data);
		printf("设定环境变数：%s = %O\n", term, data);
		return 1;
	}
        else { return notify_fail("你只能使用help settings.txt介绍的参数。\n");
               return 1;
             } 
	return help();
}
 
int help()
{
	write(@TEXT
指令格式：set <变数名> [<变数值>]
 
这个指令让你设定一些环境变数，不加参数时会显示你目前设定的环境变数，不指定
变数值，则内定值为 "YES"。
 
取消变数设定请用 unset 指令。
 
至於有哪些环境变数可以设定，请见 help settings。
TEXT
	);
	return 1;
}
