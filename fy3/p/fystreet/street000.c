#define ID 100
#include <ansi.h>
inherit ROOM;
void create()
{	set("short",HIG"�յ�"NOR);
	set("long",@LONG
������һƬ���Ŀյأ���ӵ���Ĵ�����Ｘ���ǲ��ɼ����ˡ��ⲻ�����
ҲҪ���Ͼͱ�ɾ�ס���ˡ�ֻ��û�������£���Ϊ�������ｨ���ӣ������Ƹ�Ҫ
�㹻����ͷ�����������ڷ��Ƴ��ںպ��������У���Ϊ�����ǡ������ƽ֣�
LONG	);
	set("roomid",ID);
  if(ID%2) set("exits",(["east":__DIR__"street"+(string)(ID/100),]));
  else set("exits",(["west":__DIR__"street"+(string)(ID/100),]));
	set("coor/x",40+(ID%2)*20);
	set("coor/y",20+(ID/100)*10);
	set("coor/z",0);
	setup();
}