#include <ansi.h>
#include <mudlib.h>
#define CHINESE_MUD_NAME "�ҷ紫�����Ϻ�վ"
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
        str = HIC+MUD_NAME+NOR +"��ʦ�鱨��\n";
        str += "��������������������������������������\n";
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
                str += sprintf(" ���ţ�%s\t�ϴ�����ʱ�䣺%s\t����ʱ�䣺%s��" NOR "%s", list[i], 
                ctime(wiz->query("last_on")), 
                (time()-wiz->query("last_on"))/3600/24>28?
                RED+chinese_number((time()-wiz->query("last_on"))/3600/24) :
                chinese_number((time()-wiz->query("last_on"))/3600/24),
                wiz->restore() ? "\n" : "(�����Ѿ�ʧ��!)\n");
                destruct(wiz);
        }
        str += "\n��������������������������������������\n";
        str += sprintf("Ŀǰһ����: %d����ʦ\n",sizeof(list) );
        me->start_more(str);
        return 1;
}
string wiz_rank(string hood)
{	switch(hood) {
		case "(god)":
			return HIM "�� ��    �� ��\n" NOR;
		case "(leisure)":
			return HIG "�� ����Ұ�� ��\n" NOR;
		case "(programmer)":
			return HIM "�� �������� ��\n" NOR;
		case "(admin)":			
			return HIR "�� ϵͳ���� ��\n" NOR;
		case "(manager)":			
			return HIC "�� �����Ա ��\n" NOR;
		case "(arch)":			
			return HIY "�� �����Ա ��\n" NOR;
		case "(wizard)":		
			return HIG "�� ������Ա ��\n" NOR;
		case "(apprentice)":		
			return HIB "��ѧͽ����Ա��\n" NOR;
		case "(immortal)":		
			return HIC "����ҹ���Ա��\n" NOR;
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
        write("\nָ���ʽ : showwiz\n"
        "��; : �г�Ŀǰ���е���ʦ������\n"
        );
        return 1;
}

