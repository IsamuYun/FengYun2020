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

  set("exits",([
  "chu":"/d/wiz/fengye/chu",
  "down":__DIR__"workroom",
  "nwc":"/d/wiz/fengye/wc1",
  "up":"/d/wiz/jobroom",
  "wdl":"/d/wiz/wdl/myhome",
  "manwc":"/d/wiz/fengye/wc",
]) );
        set("no_fight",1);
        set("no_magic",1);
        set("no_dazuo",1);

  setup();
}
int valid_leave(object me, string dir)
{
        if(  dir == "nwc" && me->query("gender") != "Ů��")
        return notify_fail("����Ů�˲���������ȥ��ʲô����̬����\n");
        if(  dir == "manwc" && me->query("gender") != "����")
        return notify_fail("�������˲���������ȥ��ʲô���׳հ�����Ů���֣�\n");
        return 1;
}
