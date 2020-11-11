inherit ROOM;
void create()
{
        set("short", "СԺ");
        set("long", @LONG
СС��Ժ�䣬һ�����Ѽ���ס�˰�ߣ����Ƶ�����бб���������棬������
��Ҷ�����͸����Ժ���м���һ��ˮ��������ѽѽ��ҡ��������ڶ�����ʵ���
һ�Ƕ���һЩ��ɨ�þߡ�
LONG
        );
        set("exits", ([ 
	"east" : __DIR__"kitchen",
	"south" : __DIR__"anju",
	"north" : __DIR__"livingroom",
	"west" : __DIR__"cyard1",
	]) );

	set("objects", ([
	__DIR__"obj/corner": 1,
	]) );

	set("resource/water",1);
        set("outdoors","taoyuan");
        set("coor/x",210);
	set("coor/y",-20);
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
                                "name": "��ˮ",
                                "remaining": 15,
                                "drunk_apply": 0,
                        ]) );
                        write("���ˮ����װ���˾�ˮ�� \n");
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


void reset()
{
	object *inv;
        object item1, corner;
        ::reset();
        corner = present("corner", this_object());
        inv = all_inventory(corner);
        if( !sizeof(inv)) {
        item1 = new(__DIR__"obj/saoba");
        item1->move(corner);
        }
}

