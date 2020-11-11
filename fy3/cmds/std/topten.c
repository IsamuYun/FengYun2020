// toptenadd.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string str,*astr,type;
	int i;
	seteuid(geteuid(me));
	if (!arg||arg=="")
		  return notify_fail("指令格式 : topten 排行类型
目前的排行类型有：\n
        【一世风云 】十大高手排行榜（gaoshou）
        【一世风云 】十大富翁排行榜（richman）
        【一世风云 】十大魔头排行榜（motou）
        【一世风云 】十大老手排行榜（laoshou）
        【一世风云 】十大悲情人物排行榜（beiqing）\n");
        if(arg=="gaoshou"||arg=="exp")
              type="exp";
        else if(arg=="richman"||arg=="rich")
              type="rich";
        else if(arg=="motou"||arg=="pker")
              type="pker";
        else if(arg=="laoshou"||arg=="age")
              type="age";
        else if(arg=="beiqing"||arg=="killed")
              type="killed";
        else if(arg=="task"||arg=="tasker")
              type="tasker";
        else 
              type=arg;   
        str=TOPTEN_D->topten_query(type);
	write(str+"\n");
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : topten 排行类型
目前的排行类型有:
gaoshou  十大高手
richman  十大富翁
motou    十大魔头
laoshou  十大老手
beiqing  十大悲情人物
tasker  十大使命能手
HELP
    );
    return 1;
}
