// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�ؾ�¥");
        set("long", @LONG
���������ֵĲؾ�¥�Ķ�¥����˵���������еĳ��϶�ʱ��
�μ����ֵ���ʦ��Ħ��Ҳ�������������벻�����书������
����ÿ���˶������ֻ�Ե��
LONG
        );
        set("objects", ([
                __DIR__"npc/tongre" : 3,
       ]) );
        set("exits", ([ 
  "down": __DIR__"cj6",
]));
set("no_magic",1);
        set("coor/x",-210);
	set("coor/y",360);
	set("coor/z",120);
	setup();

}
