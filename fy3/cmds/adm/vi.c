#pragma save_binary
// edit.c

#include "/doc/help.h"

inherit F_CLEAN_UP;
inherit "/feature/vi";

int main(object me, string file)
{
        if( !file ) return notify_fail("ָ���ʽ��edit <����>\n");

        if( in_edit(me) ) return notify_fail("���Ѿ���ʹ�ñ༭���ˡ�\n");

if( me!=this_player(1) ) return 0;
        seteuid(geteuid(me));
        start_edit(resolve_path(me->query("cwd"), file));
        return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : edit <����>, edit here

���ô�һָ���ֱ�������ϱ༭������
�� LPMud ȫөĻ�༭�� ��1.3 �� 3/25/1998  by л����(Kenny Hsieh), ��Ȩ����.

a            ���α��������               d  Ctrl-D    ɾ������
f  Ctrl-Z    ���»���                     g  Ctrl-G    �����ض���ȥ
h  Ctrl-J    �α�������һ��               i            ���α�ǰ�����
j  Ctrl-K    �α�������һ��               k  Ctrl-O    �α�������һ��
l  Ctrl-L    �α�������һ��               m            �����¹��ܼ�
n  Ctrl-N    ��Ѱ/�滻�¸������ִ�        o            ���α���¼�һ����
q  Ctrl-Q    �뿪�༭��                   r  Ctrl-R    �ִ��滻
s  Ctrl-S    �ִ���Ѱ                     u            ȡ��ĳ���ܼ�����
w  Ctrl-W    ���浵��                     x  Ctrl-X    ɾ���α��ϵ���
A  Ctrl-A    ���α��Ƶ�����               B  Ctrl-B    ���Ͼ�һҳ��22 �У�
E  Ctrl-E    ���α��Ƶ���β               F  Ctrl-F    ���¾�һҳ��22 �У�
J  Ctrl-P    ���������ֽӵ���������       O            ���α��Ϸ���һ����
U  Ctrl-U    ���α��Ƶ���ͷ               V  Ctrl-V    ���α��Ƶ���β
.            �ظ��ϸ�ָ��                 ?  Ctrl-Y    �������棨�˻��棩
~  Ctrl-T    ���α�ǰ�����һ����!����Ԫ

�Ϸ��Ķ�����ǿ�ӡ��ĸ�� ESC��F1��F12��BACKSPACE��TAB��ENTER��INSERT��DELETE��
HOME��END��PAGEUP��PAGEDOWN��UP��DOWN��LEFT��RIGHT��Ctrl-A��Ctrl-Z��

��ӭ�����˱༭�������뱣����Ȩ���棬���κ�����ͽ����������ң�
kenny@cindy.cis.nctu.edu.tw��
���ʹ��Netterm�༭�ļ���
HELP
    );
    return 1;
}
