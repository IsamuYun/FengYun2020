#include <globals.h>
inherit ROOM;
void create()
{
        set("short", "���");
        set("long", @LONG
��ر��������壬Ϊ��ɽ�ڶ��߷壬ɽ�������ѩ����ʹ��ʢ��������
��ˮ���¶�Ҳ�൱�͡�����������������״�������Σ���ˮ��Σ�
���������ģ����˾ͽ��˸е�ϲ����������ܵ�ɽ���ϣ��������ɼ�֣�
��ɼ���籦����ͦ�Ρ����룬�������ơ��峺��ˮ������ѩ��ʹ���ͦ
�ε������֣���������ص����˵ľ�ɫ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"tianshan",
]));
	set("no_pk",1);
	set("no_spells",1);
	set("no_magic",1);
        set("outdoors", "xinjiang");
        set("resource/water",1);
        set("coor/x",-1150);
	set("coor/y",1000);
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
                        write("��������װ���˱����ĺ�ˮ��\n");
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
