// XXDER@fy
inherit ROOM;
#include <command.h>
#include <ansi.h>
void create()
{
        set("short", "������");
        set("long", @LONG
�㷢���������Ծ������ڴ������ϣ�����������Ҳ͸����ï�ܵ����ڡ�վ����
�ϣ�����Ұ��㣬����Զ����������ð��Ũ��......
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
   "down" : __DIR__"garden",
   ]));

   set("item_desc", ([
   "tiao" : "һ���ϵ��������������Ѿ�����ʹ���ˡ�\n",
   "����" : "һ���ϵ��������������Ѿ�����ʹ���ˡ�\n",

   ]) );
        set("coor/x",0);
        set("coor/y",-610);
        set("coor/z",50);
        setup();
}

