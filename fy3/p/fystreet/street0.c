#include <ansi.h>
inherit ROOM;
void create()
{	set("short",HIG"�����콾��"NOR);
	set("long",HIC"
                     ____________
                ____/            \\____
         ___   /    ^ "+HIY"��  ��  ��"+HIC" ^    \\   ___
        /^^^**^^ _"+HIY"��              ��"+HIC"_ ^^**^^^\\
       /        /      _------_      \\        \\"NOR+"

    ����һ�����϶���ʥ�Ĵ���ʯ�ţ���Լ���ڰ���ǰ�����ϰ߰ߵ�㣬
�绯��������˵������ʴ���ٷ��ѽ����¶�ŮӢ�۵ĵط������Ǳ���
����Ӣ�۶���Ϊ����֮��
      ��ȥ���Ƿ��ƽ��ˡ������Ƿ����̳��������򵽷��ܴ���\n"  
	);
	set("exits",([
        "south" : "/d/fy/ecloud5",
	"north": __DIR__"street1",
	"east" : __DIR__"masteroom",
	"west" : __DIR__"shop",
		]));
	set("coor/x",50);
	set("coor/y",20);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
int valid_leave(object me, string dir)
{ object ob;
  if(dir=="south"&&objectp(ob=present("room builder",this_object())))
    if(ob->query("owner")==me->query("id"))
      { message_vision("$N˵���������ô��\n",ob);
        destruct(ob);}
return 1;}
   
