// jiesheng_room.c
// xgchen@zzfy
#include <room.h>
inherit ROOM;
string look_sign(object me);
void create()
{
        set("short", "������");
        set("long", @LONG
��������վ�ڽ������������ר������Ϊ�������ӽ����ĵط���
�������еķ򸾶��������������ӵģ�������д�ż�Ǯ��������
LONG
        );
        set("exits", ([
                "out"          : __DIR__"marry_room", 
         ]) );
             set("no_magic",1);
             set("no_fight",1);
             set("no_beg",1);
             set("no_du",1);
             set("no_perform",1);
        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        set("objects", ([
                __DIR__"npc/jiesheng2" : 1,
        ]) );
 
        set("coor/x",10);
        set("coor/y",-1);
        set("coor/z",10);
        setup();

}

string look_sign(object me)
{
        return "�����۸�Ϊ(1000���ƽ�)��\n";
}


