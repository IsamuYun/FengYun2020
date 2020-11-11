// skills.c
//by xgchen@fy
#include <ansi.h>

inherit F_CLEAN_UP;

string *skill_level_desc = ({
    BLU "初学乍练" NOR,
        BLU "粗通皮毛" NOR,
        HIB "半生不熟" NOR,
        HIB "马马虎虎" NOR,
        CYN "驾轻就熟" NOR,
        CYN "出类拔萃" NOR,
        HIC "初露锋芒" NOR,
        HIC "神乎其技" NOR,
        YEL "出神入化" NOR,
        YEL "登峰造极" NOR,
        HIY "一代宗师" NOR,
        HIY "空前绝后" NOR,
        HIG "深不可测" NOR,
        HIG "逆转乾坤" NOR,
        HIW "如梦似幻" NOR,
        HIR "返璞归真" NOR
});

string *knowledge_level_desc = ({
        BLU "初学乍用" NOR,
        BLU "一知半解" NOR,
        HIB "略知文理" NOR,
        HIB "初显文采" NOR,
        CYN "触类旁通" NOR,
        CYN "名列前茅" NOR,
        HIC "已有小成" NOR,
        HIC "心领神会" NOR,
        YEL "了然於胸" NOR,
        YEL "豁然贯通" NOR,
        HIY "心驰神往" NOR,
        HIY "举世无双" NOR,
        HIG "震古铄今" NOR,
        HIG "叹为观止" NOR,
        HIW "扑朔迷离" NOR,
        HIR "染指江山" NOR
});

string skill_level(string, int);

int main(object me, string arg)
{
        object ob, *list, couple_ob;
        mapping skl, lrn, map;
        string *sname, *mapped,target,cardname;
        int i, marry_flag, sd,ed;
        string *tmps;

        seteuid(getuid());

        if(!arg || arg == "1" || arg == "2" || arg == "3" 
            || arg == "4" || arg == "5" || arg == "6" 
            || arg == "7" || arg == "8" || arg == "9" || arg == "0")
                ob = me;
        else{
                ob = present(arg, environment(me));
//        if ( ob->query("SPSKILLS",1)  ) return ob->skills();           
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
                if (!ob) return notify_fail("你要察看谁的技能？\n");
        }
        target = (string) me->query("marry");   
        if(stringp(target)) couple_ob = find_player(target);
        if( ob!=me && !wizardp(me) && !ob->is_apprentice_of(me)
        && !me->is_apprentice_of(ob) && ob!=couple_ob && (ob->query("possessed")!=me)
        && !ob->query("skill_public") )
                return notify_fail("只有管理或有师徒关系的人能察看他人的技能。\n");

        skl = ob->query_skills();
        if(!sizeof(skl)) {
                write( (ob==me ? "你" : ob->name()) + "目前并没有学会任何技能。\n");
                return 1;
        }
        write((ob==me ? "你" : ob->name()) +"目前在风云里共学过"+chinese_number(sizeof(skl))+"种技能：\n\n");
        sname  = sort_array( keys(skl), (: strcmp :) );
        
        map = ob->query_skill_map();
        if( mapp(map) ) mapped = values(map);
        if( !mapped ) mapped = ({});

        lrn = ob->query_learned();
        if( !mapp(lrn) ) lrn = ([]);
    
        if(arg=="1") { sd=0; ed=10;
        }else if(arg=="2"){ sd=10; ed=20;
        }else if(arg=="3"){ sd=20; ed=30;
        }else if(arg=="4"){ sd=30; ed=40;
        }else if(arg=="5"){ sd=40; ed=50;
        }else if(arg=="6"){ sd=50; ed=60;
        }else if(arg=="7"){ sd=60; ed=70;
        }else if(arg=="8"){ sd=70; ed=80;
        }else if(arg=="9"){ sd=80; ed=90;
        }else if(arg=="0"){ sd=90; ed=100;
        }else{ sd=0;ed=sizeof(skl);
        }
    if(sizeof(skl)<sd) return notify_fail("你没有学过这么多技能。\n");

        for(i=sd; i<ed; i++) {
                if(i==sizeof(skl)) break;
                printf("%2d %s%s%-40s" NOR " - %-10s %3d/%5d\n", i+1,
                  //    (lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
		(SKILL_D(sname[i])->belong() == ob->query("class")||SKILL_D(sname[i])->belong() == "common")? HIG:"",
                        (member_array(sname[i], mapped)==-1? "  ": "＊"),
                        to_chinese(sname[i]) + " (" + sname[i] + ")",
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        skl[sname[i]], (int)lrn[sname[i]],
                );
        }
        return 1;
}

/*
string skill_level(string type, int level)
{
        int grade;

        grade = level / 30;

    if( grade >= 50 ) grade = 50;
    if( grade >= 10 )
       return knowledge_level_desc[grade/10-1];
        switch(type) {
                case "knowledge":
                        if( grade >= sizeof(knowledge_level_desc) )
                                grade = sizeof(knowledge_level_desc)-1;
                        return knowledge_level_desc[grade];
                default:
                        if( grade >= sizeof(skill_level_desc) )
                                grade = sizeof(skill_level_desc)-1;
                        return skill_level_desc[grade];
        }
}
*/
string skill_level(string type, int level)
{
        int grade;

        grade = level / 60;

        switch(type) {
                case "knowledge":
                        if( grade >= sizeof(knowledge_level_desc) )
                                grade = sizeof(knowledge_level_desc)-1;
                        return knowledge_level_desc[grade];
                default:
                        if( grade >= sizeof(skill_level_desc) )
                                grade = sizeof(skill_level_desc)-1;
                        return skill_level_desc[grade];
        }
}


string pet_skill(object ob)
{
        string desc;
        object  *list, couple_ob;
        mapping skl, lrn, map;
        string *sname, *mapped,target,cardname;
        int i, marry_flag;
        skl = ob->query_skills();
        if(!sizeof(skl)) {
                desc =  ob->name() + "目前并没有学会任何技能。\n";
                return desc;
        }
                desc =  ob->name() +"目前所学过的技能：\n\n";
        sname  = sort_array( keys(skl), (: strcmp :) );

        map = ob->query_skill_map();
        if( mapp(map) ) mapped = values(map);
        if( !mapped ) mapped = ({});

        lrn = ob->query_learned();
        if( !mapp(lrn) ) lrn = ([]);

        for(i=0; i<sizeof(skl); i++) {
              desc +=  sprintf("%s%s%-40s" NOR " - %-10s %3d/%5d\n",
                        (lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
		(member_array(sname[i], mapped)==-1? "  ": "＊"),
                        to_chinese(sname[i]) + " (" + sname[i] + ")",
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        skl[sname[i]], (int)lrn[sname[i]],
                );
        }
        return desc +"\n";
}

int help(object me)
{
        write(@HELP
指令格式 : skills [<某人>]

这个指令可以让你查询所学过的技能。

你也可以指定一个和你有师徒关系的对象，用 skills 可以查知对方的技能状况。

skills 1 看从  1-10 的技能，
skills 2 看从 10-20 的技能，
依此类推。


HELP
    );
    return 1;
}

