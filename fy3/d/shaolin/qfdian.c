// Room: /d/shaolin/qfdian.c
// Date: YZC 96/01/19
#include <room.h>
inherit ROOM;
void create()
{
    set("short", "ǧ���");
    set("long", @LONG
����ǧ���������������ȣ��߱����硣���﹩�����
����𣬼��а��������Ľ�գ���ٰ��ޣ���ǧ���У�ʮһ���ף�
ʮ��٤�����Լ����������������ĵȡ�ֱ�������ۻ����ҡ�����
�е�Сľ�š�
LONG
    );
    set("exits", ([
        "south" : __DIR__"banruo",
        "north" : __DIR__"bamboo1",     
    ]));
/*
set("no_magic",1);
    set("objects",([
        CLASS_D("shaolin") + "/qing-guan" : 1,
    ]));
*/
    create_door("north","ľ��","south",DOOR_CLOSED);
    setup();
    
}
void init()
{
    add_action("do_push", "push");
}
void close_passage()
{
    object room;
    if( !query("exits/down") ) return;
    message("vision", "ǽ�ں�Ȼ�����������������������ƻ�ԭ����"
        "�����µĶ��ڸ�ס�ˡ�\n", this_object() );
    if( room = find_object(__DIR__"qfdian") ) {
        room->delete("exits/up");
        message("vision", "ͷ���ϵ�ʯ���Ȼ����������������"
            "ǽ�ϵ�ʯ���ֻ��������˻�ȥ��������ʧ�ˡ�\n", room );
    }
    delete("exits/down");
}
int do_push(string arg)
{
    object me;
    mapping my_fam;
    
    me = this_object();
    my_fam  = me->query("family");
    if( !arg || arg =="") return 0;
    if( (arg != "stone") || ( this_player()->query("class") != "shaolin" ))
    {
        message_vision("$NҪ��ʲô��\n",this_player());
        return 1;
    }
    else 
    {
        message("vision", "ǽ�ں�Ȼ������������������һ�໺���ƿ���"
            "����¶��һ���ڶ�������ڡ�\n", this_player());
        set("exits/down", __DIR__"damodong"); 
        remove_call_out("close_passage");
        call_out("close_passage", 1);
    }
    return 1;
}

