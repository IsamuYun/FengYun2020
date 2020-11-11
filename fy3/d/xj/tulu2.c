#include <globals.h>
inherit ROOM;
void create()
{
        set("short", "��·");
        set("long", @LONG
��ԭ�ϵ�һ���������۵���·������һ��ĬĬ��Ϫ�����ңɣ֣ţң���
�峺��Ϫˮ��ʹ�˸е�һ��������Ϣ����ΧȺɽ�������ˮ���ѣ����������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"nanmen",
  "south" : __DIR__"tulu3",
  "east" : __DIR__"tulu4",
]));
        set("item_desc", ([
                "river": "���峺��Ϫ�������滹��С�㣨������裩Ү����\n",
                "Ϫ��": "���峺��Ϫ�������滹��С�㣨������裩Ү����\n"
        ]) );
	set("no_pk",1);
	set("no_spells",1);
	set("no_magic",1);
        set("resource/water",1);
        set("outdoors", "xinjiang");
        set("coor/x",-1120);
	set("coor/y",1050);
	set("coor/z",0);
	setup();
}

void init()
{
        add_action("do_fillwater", "fillwater");
        add_action("do_catch", "catch");
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
                                "name": "�峺��Ϫˮ",
                                "remaining": 15,
                                "drunk_apply": 6,
                        ]) );
                        write("���Ϫ����װ������ˮ��! \n");
                        return 1;
                   }
                }
                if (can_fillwater ==0) {
                        write("��û��װˮ�Ķ�����....\n");
                        return 1;
                }
        }
        else {
                write("��Ҫ��ʲô�������ˮ��");
        }
        return 1;
}

int do_catch()
{
	write("��һ���֣�ץסһ��С����������У�������\n��������ζ������������е������Ⱦͺ�ඣ�����\n");
//�����������ץ��ץ�����ʲôҲûץ����
//combat_exp^Qmax_food_capacity^Dfood^CaddX��һ���֣�ץסһ��С��������
        return 1;
}
