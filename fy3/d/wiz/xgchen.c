inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "���ﱤ");
        set("long", @LONG
�����ǳ�������ĳ��ﱤ����ȴ��������,�����ڴ������Ŀ����˾��
ҵ����!ǽ�����۴�����һ���ʾ(gaoshi)��
LONG);
        set("item_desc", ([
                "gaoshi" : "�������벻Ҫ���ߡ� 

                            ���������֡�\n",

]));
        set("sleep_room", 1);
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        set("exits", ([ /* sizeof() == 18 */
  "south" :__DIR__"hall",
  "gc" :"/d/fy/fysquare",
]));
//         set("objects", ([ /* sizeof() == 1 */
//              "/u/chen/npc/xiaocui" : 1,
//                ]));
        set("no_steal", "1");
        set("no_fight", "1");
        setup();
        replace_program(ROOM);
}
void init()
{
      add_action("do_push","push");
}
int do_push(string arg)
{
object me,ob;
me=this_player(); 
if (me->query("id") != "chen") return 0;

 //       if( !(ob = present(arg, environment(me))) || !ob->is_character() )
  //               return notify_fail("����û������ˣ�\n");
        ob->move("d/fy/fysquare");
        message_vision(HIW"$N��$n���˳�ȥ��\n"NOR,me,ob);
        tell_room("/d/fy/fysquare","ͻȻ��"+ob->query("name")+"�������������˳���!\n");
        return 1;
       }