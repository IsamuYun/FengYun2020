
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
��ˮ�峺͸������ʱ���Կ�����β������ˮ�档��ˮ��ͷ
��һ�����ٲ�����������������ٲ���ɽ��ֱ����£�������
�������������ϡϡ�����վ�ż������ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  		"west" : "/u/taoguan/grassland2",
  		"south" : "/u/taoguan/lake1",
]));
        set("objects", ([ /* sizeof() == 2 */
  		"/u/taoguan/npc/reg_taoist" : 3,
]));
        set("resource/water",1);
	set("outdoors", "taoguan");
	set("coor/x",-10);
	set("coor/y",2080);
	set("coor/z",80);
	setup();
}

void init()
{
        add_action("do_fillwater", "fillwater");
        add_action("do_swim", "swim");
}

int do_swim(string arg)
{
   return 1;
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
                                "remaining": 30,
                                "drunk_apply": 6,
                        ]) );
                        write("��Ӻ���װ������ˮ! \n");
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
