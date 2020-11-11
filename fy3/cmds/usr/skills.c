// skills.c
//by xgchen@fy
#include <ansi.h>

inherit F_CLEAN_UP;

string *skill_level_desc = ({
    BLU "��ѧէ��" NOR,
        BLU "��ͨƤë" NOR,
        HIB "��������" NOR,
        HIB "������" NOR,
        CYN "�������" NOR,
        CYN "�������" NOR,
        HIC "��¶��â" NOR,
        HIC "����似" NOR,
        YEL "�����뻯" NOR,
        YEL "�Ƿ��켫" NOR,
        HIY "һ����ʦ" NOR,
        HIY "��ǰ����" NOR,
        HIG "��ɲ�" NOR,
        HIG "��תǬ��" NOR,
        HIW "�����ƻ�" NOR,
        HIR "��豹���" NOR
});

string *knowledge_level_desc = ({
        BLU "��ѧէ��" NOR,
        BLU "һ֪���" NOR,
        HIB "��֪����" NOR,
        HIB "�����Ĳ�" NOR,
        CYN "������ͨ" NOR,
        CYN "����ǰé" NOR,
        HIC "����С��" NOR,
        HIC "�������" NOR,
        YEL "��Ȼ���" NOR,
        YEL "��Ȼ��ͨ" NOR,
        HIY "�ĳ�����" NOR,
        HIY "������˫" NOR,
        HIG "������" NOR,
        HIG "̾Ϊ��ֹ" NOR,
        HIW "��˷����" NOR,
        HIR "Ⱦָ��ɽ" NOR
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
                if (!ob) return notify_fail("��Ҫ�쿴˭�ļ��ܣ�\n");
        }
        target = (string) me->query("marry");   
        if(stringp(target)) couple_ob = find_player(target);
        if( ob!=me && !wizardp(me) && !ob->is_apprentice_of(me)
        && !me->is_apprentice_of(ob) && ob!=couple_ob && (ob->query("possessed")!=me)
        && !ob->query("skill_public") )
                return notify_fail("ֻ�й������ʦͽ��ϵ�����ܲ쿴���˵ļ��ܡ�\n");

        skl = ob->query_skills();
        if(!sizeof(skl)) {
                write( (ob==me ? "��" : ob->name()) + "Ŀǰ��û��ѧ���κμ��ܡ�\n");
                return 1;
        }
        write((ob==me ? "��" : ob->name()) +"Ŀǰ�ڷ����ﹲѧ��"+chinese_number(sizeof(skl))+"�ּ��ܣ�\n\n");
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
    if(sizeof(skl)<sd) return notify_fail("��û��ѧ����ô�༼�ܡ�\n");

        for(i=sd; i<ed; i++) {
                if(i==sizeof(skl)) break;
                printf("%2d %s%s%-40s" NOR " - %-10s %3d/%5d\n", i+1,
                  //    (lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
		(SKILL_D(sname[i])->belong() == ob->query("class")||SKILL_D(sname[i])->belong() == "common")? HIG:"",
                        (member_array(sname[i], mapped)==-1? "  ": "��"),
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
                desc =  ob->name() + "Ŀǰ��û��ѧ���κμ��ܡ�\n";
                return desc;
        }
                desc =  ob->name() +"Ŀǰ��ѧ���ļ��ܣ�\n\n";
        sname  = sort_array( keys(skl), (: strcmp :) );

        map = ob->query_skill_map();
        if( mapp(map) ) mapped = values(map);
        if( !mapped ) mapped = ({});

        lrn = ob->query_learned();
        if( !mapp(lrn) ) lrn = ([]);

        for(i=0; i<sizeof(skl); i++) {
              desc +=  sprintf("%s%s%-40s" NOR " - %-10s %3d/%5d\n",
                        (lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
		(member_array(sname[i], mapped)==-1? "  ": "��"),
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
ָ���ʽ : skills [<ĳ��>]

���ָ����������ѯ��ѧ���ļ��ܡ�

��Ҳ����ָ��һ��������ʦͽ��ϵ�Ķ����� skills ���Բ�֪�Է��ļ���״����

skills 1 ����  1-10 �ļ��ܣ�
skills 2 ���� 10-20 �ļ��ܣ�
�������ơ�


HELP
    );
    return 1;
}

