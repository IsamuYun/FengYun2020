//wdl��С��
//ROOM: /open/myhome.c
//wdl bye 2000/12/19
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", BLINK HIY"��ܰС��"NOR NOR);
  set ("long",@LONG
�����������ٿ��Լ�����Ϣ�ң�ֻ�����Լ���Ϣ�������
һ��ۻᡣ����������ܼ򵥣�ֻ��һ����ܣ�һ����ů��С
����һ��д��̨�ͼ������ӡ�ӭ��ǽ������һ��ʫ��
    ����̽���趼�ͣ��ŵ���������ҹ��
    ��յ�Ƶγ����ᣬ������ƽ���¡�
    ������������ѩ���һ���������ꡣ
    ��Ȼ��������أ���������κ�����
    �����������������įӢ�۹�ԭ�ݡ�
    ��̨��ɢʮ�ɺ죬�ж��Ѿ�����С��
LONG);

  set("exits",([
  "up":"/d/fy/fysquare",
  "txf":"/d/wiz/fengye/home",
]) );
        set("no_fight",1);
        set("no_magic",1);
        set("no_dazuo",1);

  set("objects",([
  __DIR__"girl.c":1,
]) );
  setup();
        call_other("/obj/board/wizard_b", "???");
}
void init()
{
object room;
if((this_player())->query("gender") != "Ů��")
{
if(!room = find_object("/d/wiz/fengye/home"))
room = load_object("/d/wiz/fengye/home");
this_player()->move(room);
}
}
