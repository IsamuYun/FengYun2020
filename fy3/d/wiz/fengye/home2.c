//txf��С��
//ROOM: /d/wiz/home.c
//txf bye 2001/1/26
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", BLINK HIY"С���"NOR NOR);
  set ("long",@LONG
�����Ƿ��Լ�����Ϣ�ң�ֻ�����Լ���Ϣ�������
һ��ۻᡣ����������ܼ򵥣�ֻ��һ����ܣ�һ����ů��С
����һ��д��̨�ͼ������ӡ�ӭ��ǽ������һ��ʫ��
���˷���ȥ��������������й����������ѽ�ϥǰ�ᡣ
���Իӽ𴸣��������𾪡����������㣬��������Ӣ��
˭������£�����̫������ʮ��ɱһ�ˣ�ǧ�ﲻ���С�
LONG);

  set("valid_startroom", 1);
  set("exits",([
  "down":"/d/fy/fysquare",
  "up":"/d/wiz/jobroom",
  "out":"/open/wdl/myhome",
  "east":"/d/bat/secret",
  "north":"/d/shenshui/shufang",
  "westnorth":"/u/guanwai/tower",
  "westsouth":"/d/dali/dadian",
"west":"/d/chenxiang/cxcenter",
]) );
        set("no_fight",1);
        set("no_magic",1);
        set("no_dazuo",1);

  setup();
        call_other("/obj/board/wizard_b", "???");
}
