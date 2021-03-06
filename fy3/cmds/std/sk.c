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
string *valid_types = ({
        "axe",
        "blade",
        "toxin",
        "dagger",
        "dodge",
        "force",
        "fork",
        "hammer",
        "chanting",
        "iron-cloth",
        "literate",
        "magic",
        "move",
        "parry",
        "perception",
        "scratching",
        "cursism",
        "spells",
        "staff",
        "stealing",
        "sword",
        "throwing",
        "unarmed",
        "whip",
      "duan-yiyangzhi",
        "herb",
        "spear",

});
int sort_skill(string sk1, string sk2, mapping spos);
int filter_for_enable(string skill, string skill1);
int filter_for_main(string skill, string skill1);
string skill_level(string, int);
int filter_for_combine(string skill, string skill1);

int main(object me, string arg)
{
        object ob;
        mapping skl, lrn, map;
        string *sname, *mapped, str, skill1;
        string skillname, skcolor;
        string *basic;
        mixed  *lists;
        string *others;
        int lvl;
        int i, k;

        seteuid(getuid());

        skill1 = 0;
        if (! arg)
                ob = me;
        else
        {
                string *temp;
                if (sscanf(arg, "%s of %s", skill1, arg) == 2)
                        ; else
                if (temp = explode(arg, " "))
                {
                        if (sizeof(temp) < 2)
                                arg = "me";
                        else
                                arg = implode(temp[0..sizeof(temp) - 2], " ");
                        skill1 = temp[sizeof(temp) - 1];

                        if (file_size(SKILL_D(skill1) + ".c") <= 0)
                        {
                                if (sizeof(temp) < 2)
                                        arg = skill1;
                                else
                                        arg += " " + skill1;
                                ob = present(arg, environment(me));
                                skill1 = 0;
                        }
                } else
                {
                        // if the user was not wizard, I will
                        // treat the arg as skill1, and the
                        // object he check is hiself.
                        if (! wizardp(me) && (! (ob = present(arg, environment(me))) ||
                            ! ob->is_character() ||
                            ! me->is_apprentice_of(ob)))
                        {
                                skill1 = arg;
                                arg = "me";
                        }
                }

                if (ob && ! ob->is_character())
                        ob = 0;

                if (skill1 && file_size(SKILL_D(skill1) + ".c") <= 0)
                {
                        if (objectp(ob))
                        {
                                arg = 0;
                                skill1 = 0;
                        } else
                                return notify_fail("没有(" + skill1 +
                                                   ")这种技能。\n");
                }

                if (! ob || ! ob->is_character())
                {
                        if (arg == "me")
                                ob = me;
                        else
                                ob = present(arg, environment(me));
        
                        if (! ob) ob = find_player(arg);
                        if (! ob) ob = find_living(arg);
                }

                if (! ob || ! ob->is_character())
                        return notify_fail("你要察看谁的技能？\n");
        }

        if (ob != me)
        {
                // call the player, if the player has override the
                // the function & return a nonzero valud, I will
                // return success.
                if ((int)ob->skills(me, skill1))
                        return 1;
        }
        if (ob != me && ! wizardp(me) && ! ob->is_apprentice_of(me) &&
            ! me->is_apprentice_of(ob) &&
            me->query("marry") != ob->query("id"))
                return notify_fail("只有巫师或有师徒/夫妻关系的人能察看"
                                   "他人的技能。\n");
        skl = ob->query_skills();
             if (sizeof(skl)>250) 
       return notify_fail("你的武功已经超过二百五十种，请使用help skills。\n");
       if (! sizeof(skl))
        {
                write((ob==me ? "你" : ob->name()) +
                      "目前并没有学会任何技能。\n");
                return 1;
        }
        // calucate spos to sort
        sname = keys(skl);
//        str = (ob == me ? "你" : ob->name()) + "目前所学到的";
        str = ( (ob==me ? "\n你" : ob->name()) +"目前在天下无敌共学过"+
chinese_number(sizeof(skl))+"种技能：\n\n");
        sname  = sort_array( keys(skl), (: strcmp :) );
        
        if (skill1)
        {
                // filter the skill array by skill1
                if (member_array(skill1, valid_types) != -1)
                {
                        // skill1 is a basic skill
                        sname = filter_array(sname, (: filter_for_enable :), skill1);
                        str += to_chinese(skill1) + "及相关技能";
                } else
                if (SKILL_D(skill1)->main_skill() &&
                    member_array(SKILL_D(skill1)->main_skill(), sname) == -1)
                {
                        // skill1 is a sub skill
                        skill1 = SKILL_D(skill1)->main_skill();
                        sname = filter_array(sname, (: filter_for_main :), skill1);
                        str += to_chinese(skill1) + "中的招式";
                } else
                {
                        sname = filter_array(sname, (: filter_for_combine :), skill1);
                        str += to_chinese(skill1) + "和可以装备的基础技能";
                }
        } else
                str += "技能列表";

        if (! sizeof(sname))
        {
                write("你目前还没有掌握该技能。\n");
                return 1;
        }

        // sort all the skills
        // select all the basic skill of the skill list
        basic = filter_array(valid_types, (: member_array($1, $(sname)) != -1 :));

        // allocate the string array for each basic skill
        lists = allocate(sizeof(basic));

        // allocate the other skill for none apply to all the basic skill
        others = ({ });

        // select out all the special skill & other skill
        sname -= basic;
        for (i = 0; i < sizeof(sname); i++)
        {
                // let's check every special skill & other skill
                if (! sname[i]) continue;

                // enable for basic skill
                for (k = 0; k < sizeof(basic); k++)
                {
                        string main_skill;

                        if (SKILL_D(sname[i])->valid_enable(basic[k]))
                        {
                                // yes, I record this special skill
                                if (! lists[k])
                                        lists[k] = ({ sname[i] });
                                else
                                        lists[k] += ({ sname[i] });

                                // Is this a sub skill ?
                                if (main_skill = SKILL_D(sname[i])->main_skill())
                                {
                                        // yes, I select out all the other sub skills
                                        int st;
                                        for (st = i + 1; st < sizeof(sname); st++)
           if (SKILL_D(sname[st]) &&
                 SKILL_D(sname[st])->main_skill() == main_skill)
                                                {
                                                        // record it
                                                        lists[k] += ({ sname[st] });
                                                        sname[st] = 0;
                                                }
                                }

                                break;
                        }
                }

                if (k == sizeof(basic))
                        // It can enable on basic skill, it must be a others skill
                        others += ({ sname[i] });
        }

        // let me combine all the skill in string array: sname
        sname = ({ });
        for (i = 0; i < sizeof(basic); i++)
        {
                sname += ({ basic[i] });
                if (lists[i]) sname += lists[i];
        }

        sname += others;

        // get the skill map
        map = ob->query_skill_map();
        if (mapp(map)) mapped = values(map);
        if (! mapped) mapped = ({});

        lrn = ob->query_learned();
        if (! mapp(lrn)) lrn = ([]);
        str += "\n\n";
        str += HIC "≡" HIY "───────────────────────────────" HIC "≡\n" NOR;
 
        for (i = 0; i < sizeof(sname); i++)
        {
                int percent;
                skillname = to_chinese(sname[i]);
                switch (strlen(skillname))
                {
                case 6:
                        skillname = sprintf("%c%c %c%c %c%c", skillname[0], skillname[1],
                                             skillname[2], skillname[3],
                                             skillname[4], skillname[5]);
                        break;
                case 4:
                        skillname = sprintf("%c%c    %c%c", skillname[0], skillname[1],
                                             skillname[2], skillname[3]);
                        break;
                }

                if (member_array(sname[i], valid_types) != -1)
                        skcolor = WHT;
                else
                        skcolor = CYN;

                if (! objectp(find_object(SKILL_D(sname[i]))) &&
                    ! objectp(load_object(SKILL_D(sname[i]))))
                {
                        write(HIR "Error(No such skill):" + sname[i] + "\n" NOR);
                        continue;
                }
                lvl = skl[sname[i]];
                percent = lrn[sname[i]] * 100 / ((lvl + 1) * (lvl + 1) + 1);
                if (percent > 100) percent = 100;
       str += sprintf("%s%s%s%-40s" NOR " - %-10s %4d/%3d%%\n" NOR, 
//   str += sprintf("%s%s%s%-40s" NOR WHT " - %-4s %4d/%3d%%\n" NOR, 
                       skcolor,
      (lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
                        (member_array(sname[i], mapped)==-1? "  ": "□"),
skillname + " (" + sname[i] + ")",skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),lvl, percent);
        }

        str += HIC "≡" HIY "───────────────────" HIW "□ 快乐风云 □" HIY "─────" HIC "≡\n" NOR;
        me->start_more(str);
        return 1;
}

int filter_for_enable(string skill, string skill1)
{
        return (skill == skill1) || (SKILL_D(skill)->valid_enable(skill1));
}

int filter_for_main(string skill, string skill1)
{
        return (SKILL_D(skill)->main_skill() == skill1);
}

int filter_for_combine(string skill, string skill1)
{
        return (SKILL_D(skill1)->valid_enable(skill)) ||
               (SKILL_D(skill)->valid_combine(skill1)) ||
               (skill == skill1);
}
string skill_level(string type, int level)
{
        int grade;

        grade = level / 20;

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
指令格式 : sk [<技能名> of <某人 | me >] | [<某人>]

这个指令可以让你(你)查询所学过的技能。

你也可以指定一个和你有师徒关系的对象，用 skills 可以查知对方的技能状况。
也可以查询某人某项技能的情况，比如skills taiji-shengong of song， 或者
是skills literate of me， 用这种方法查询时分以下几种情况：

1 如果查询的技能是一种基本武功，将同时返回所有在这种基本武功的基础上能
  够激发的武功技能。

2 如果查询的技能是一种普通的武技，则显示可以激发的基本武功.

使用该命令可以了解你学到的武功技能。玩家查询的时候不需要指明me参数，可
以直接输入<技能名>参数。

巫师可以查询任何人或 NPC 的技能状况。

HELP
    );
    return 1;
}
