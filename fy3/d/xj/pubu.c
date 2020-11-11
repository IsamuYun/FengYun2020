#include <globals.h>
inherit ROOM;
void create()
{
        set("short", "�ٲ�");
        set("long", @LONG
�����ǹ��ľ�ͷ����ʮ�ɸߵ����¾����Ǳ���һ���������ġ�
һ�ɶ����ٲ�һк���£��������¾�������������ĳ�У���Ϊ
׳�ۡ��ٲ���һйǧ��֮�ƻ�����У�¡¡֮�������ڶ���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"goudi2",
  "eastup" : __DIR__"aiding",
]));
        set("objects", ([
                "/d/oldpine/npc/serpent" :1,
                        ]) );
	set("no_pk",1);
	set("no_spells",1);
	set("no_magic",1);
        set("outdoors", "xinjiang");
        set("resource/water",1);
        set("coor/x",-1090);
	set("coor/y",1020);
	set("coor/z",-10);
	setup();
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
                                "name": "������ˮ",
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
                write("��Ҫ��ʲô�������ˮ��\n");
        }
        return 1;
}
