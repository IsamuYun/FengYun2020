#include <globals.h>
inherit ROOM;
void create()
{
        set("short", "���ݱ���");
        set("long", @LONG
ˮƽ�羵����ɼ��ˣ�ʢ����з����Щ�ط��ĺ�ˮ�����
���Կ������׵�ʯͷ����ʯ���д����С�㣬ż�����м�����
ð��ˮ�棬���������࣢һ����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"tulu3",
  "south" : __DIR__"baiyang",
]));
        set("objects", ([
                "/u/palace/npc/fish" :2,
                "/u/palace/npc/shrimp" :2,
                        ]) );
        set("no_pk",1);
        set("no_spells",1);
        set("no_magic",1);
        set("outdoors", "xinjiang");
        set("resource/water",1);
        set("coor/x",-1120);
        set("coor/y",1030);
        set("coor/z",0);
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
                                "name": "�����ĺ�ˮ",
                                "remaining": 15,
                                "drunk_apply": 6,
                        ]) );
                        write("��Ӳ��ݱ�����װ���������ĺ�ˮ��\n");
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
