#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIG"���ƹ㳡"NOR NOR);
        set("long", @LONG
���Ƴǵķ�ֺ���·�������ʮ�ֽ��棬�����Ľֵ��������γ�һ���޴�Ĺ㳡��
�㳡�������Ƿ�԰Լʮ�ɵ�ˮ�أ�������ββ���������е����Ρ���ɫ����������̵�
��Ƽ�໥��ӳ��������Ŀ����ˮ��������һ��ʯ����ʯ���Ͽ���һ����ͷ������������
����չ����ΰ׳�ۡ�ÿ�����죬����������ӿ�����ף�������֮�ᣬ����鳦��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"nwind1",
  "south" : __DIR__"swind1",
        "up" : "/d/wiz/fyup/center",
  "east" : __DIR__"ecloud1",
  "west" : __DIR__"wcloud1",
 "northeast" :"/d/wiz/fyup/fysq1",
 "northwest" :"/d/wiz/fyup/fysq2",
 "southwest" :"/d/wiz/fyup/fysq3",
 "southeast" :"/d/wiz/fyup/fysq4",

]));
			
        set("outdoors", "fengyun");
        set("resource/water",1);
	set("liquid/name","���̵�ˮ");
	set("liquid/type", "alcohol");
	set("liquid/drunk_apply",3);
        set("objects", ([
                "/d/chenxiang/npc/half_god" : 1,
 //       "/d/wiz/xgchen/tongzi" : 1,
       ]) );
        set("no_fight",1);
        set("no_du",1);
        set("no_beg",1);
        set("no_sheet",1);
        set("no_magic",1);
             set("NONPC",1);
        set("no_dazuo",1);
        set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        // To "load" the board, don't ever "clone" a bulletin board.
        call_other( "/obj/board/fysquare_b", "???" );

}

void init()
{
        add_action("do_fillwater", "fillwater");
}
int do_fillwater(string arg)
{
        object *list, ob;
        int i, can_fillwater;
        string dir;

        if( !arg || arg=="" ) return 0;

        if( arg=="skin" || arg=="wineskin" ) {
                list = all_inventory(this_player());
                i = sizeof(list);
                can_fillwater = 0;
                while (i--) {
                  if (((string)list[i]->query("liquid/type") == "alcohol")
 || ((string)list[i]->query("liquid/type") == "water")         ) {
                        ob = list[i];
                        can_fillwater = 1;
                        ob->set("liquid", ([
                                "type": "water",
                                "name": "��ˮ",
                                "remaining": 15,
                                "drunk_apply": 6,
                        ]) );
                        write("���ˮ����װ������ˮ�� \n");
                        return 1;
                   }
                }
                if (can_fillwater ==0) {
                        write("��û��װˮ�Ķ�����....\n");
                        return 1;
                }
        }
        else {
                write("��Ҫ��ʲô�������ˮ��\n");
        }
        return 1;
}


