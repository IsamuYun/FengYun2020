
#include "/doc/help.h"
#include <ansi.h>
inherit F_CLEAN_UP;
int help(object me);
int main(object me, string arg)
{
 mapping emote;
string *e, *loop;
string result="", msg;
int count=0;
  loop = ({ "others_target", "others_self", "others" });
if( !arg )
return help(me);
if (time()-me->query_temp("scan_time") < 20 )
return notify_fail("�ȵȣ�ϵͳ������......\n");
foreach( e in sort_array(EMOTE_D->query_all_emote(),1) ) {
 emote = EMOTE_D->query_emote(e);
  for ( int j=0; j<sizeof(loop); j++ ) {
 msg = emote[ loop[j] ];
if( msg && strsrch(msg, arg) >=0 ) {
result += sprintf(HIR "%s\n"+NOR+"����: %s\n", e, msg);
count ++;
}
}
}
 if(  result == "" )
return notify_fail(MUD_NAME" ���޷��ϲ�ѯ������ emote.\n");
else
result = "\n��ѯ���"
/* */"\n------------------------------------------------------------\n"
       + result;
 result = replace_string(result, "$n", "ĳ��");
result = replace_string(result, "$N", me->name(1));
result = replace_string(result, "$P", "��");
result = replace_string(result, "$p", "(��/��)");
result = replace_string(result, "$S", RANK_D->query_self(me));
result = replace_string(result, "$s", RANK_D->query_self_rude(me));
result = replace_string(result, "$R", "׳ʿ");
result = replace_string(result, "$r", "����");
result = replace_string(result, "$C", "������");
result = replace_string(result, "$c", "���");
result += "------------------------------------------------------------\n";
result += sprintf("��%s�У�������%s���� emote ���� %d ����\n",
 MUD_NAME, arg, count );
me->set_temp("scan_time",time());
me->start_more(result);
return 1;
}
int help(object me)
{
write(@HELP
ָ���ʽ : femote �ؼ������ܣ��г�Ŀǰ���к�ָ���ؼ��ֵ� emote.
HELP
 );
  return 1;
}
