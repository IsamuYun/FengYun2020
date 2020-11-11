// upemote.c
inherit F_CLEAN_UP;
#include <ansi.h>
int main(object me)
{
	mapping emote;
	string *str,arg="";
	int i;		
	str=sort_array(EMOTE_D->query_all_emote(), 1);
	for (i=0;i<sizeof(str);i++){
	emote = EMOTE_D->query_emote(str[i]);
//��ָ������ʹ����� emote ʱ�����Լ�������ѶϢ��
     if( stringp(arg = emote["myself"]) ) {
                arg = replace_string(arg, "$N", "$P");
                arg = replace_string(arg, "$p", "$P");
                arg = replace_string(arg, "��", "$P");
                arg = replace_string(arg, "����", "$S");
                arg = replace_string(arg, "��ү��", "$s");
		emote["myself"]=arg;
	}
//��ָ������ʹ����� emote ʱ�������˿�����ѶϢ��
     if( stringp(arg = emote["others"]) ) {
                arg = replace_string(arg, "$P", "$N");
                arg = replace_string(arg, "$p", "$N");
                arg = replace_string(arg, "����", "$S");
                arg = replace_string(arg, "��ү��", "$s");
		emote["others"]=arg;
	}
//���Լ�ʹ����� emote ʱ���Լ�������ѶϢ��
     if( stringp(arg = emote["myself_self"]) ) {
                arg = replace_string(arg, "$N", "$P");
                arg = replace_string(arg, "$p", "$P");
                arg = replace_string(arg, "��", "$P");
                arg = replace_string(arg, "����", "$S");
                arg = replace_string(arg, "��ү��", "$s");
		emote["myself_self"]=arg;
	}
//���Լ�ʹ����� emote ʱ�������˿�����ѶϢ��
     if( stringp(arg = emote["others_self"]) ) {
                arg = replace_string(arg, "$P", "$N");
                arg = replace_string(arg, "����", "$S");
                arg = replace_string(arg, "��ү��", "$s");
		emote["others_self"]=arg;
	}
//�Ա���ʹ����� emote ʱ���Լ�������ѶϢ��
     if( stringp(arg = emote["myself_target"]) ) {
                arg = replace_string(arg, "$N", "$P");
                arg = replace_string(arg, "$p", "$P");
                arg = replace_string(arg, "��", "$P");
                arg = replace_string(arg, "��", "$n");
                arg = replace_string(arg, "����", "$S");
                arg = replace_string(arg, "��ү��", "$s");
		emote["myself_target"]=arg;
	}
//�Ա���ʹ����� emote ʱ��ʹ�ö��󿴵���ѶϢ��
     if( stringp(arg = emote["target"]) ) {
                arg = replace_string(arg, "$n", "$p");
                arg = replace_string(arg, "$P", "$N");
                arg = replace_string(arg, "��", "$p");
                arg = replace_string(arg, "����", "$S");
                arg = replace_string(arg, "��ү��", "$s");
		emote["target"]=arg;
	}
//�Ա���ʹ����� emote ʱ�������Լ���ʹ�ö����⣬�����˿�����ѶϢ��
     if( stringp(arg = emote["others_target"]) ) {
                arg = replace_string(arg, "$P", "$N");
                arg = replace_string(arg, "$p", "$n");
                arg = replace_string(arg, "����", "$S");
                arg = replace_string(arg, "��ү��", "$s");
		emote["others_target"]=arg;
	}
        EMOTE_D->set_emote(str[i], emote);
	}
	return 1;
}
int help(object me)
{
write(@HELP
ָ���ʽ : upemote
 
���ָ������Զ����� emote �е�һЩ����
HELP
    );
    return 1;
}
