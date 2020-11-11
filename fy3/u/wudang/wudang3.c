
inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
Ժ���ĽǸ�����һ�����������������һ��ˮ������ʯ���̳ɵ�
���棬û���κ��Ӳ���Ҷ��Ժ��������һ���᷿������������������
ʱ�������������ȭ���������洫������
LONG
	);
	set("exits", ([ 
  		"out" : __DIR__"wuroad4",
  		"north" : __DIR__"wudang4",
  		"south" : __DIR__"wudang5",
	]));
        set("item_desc", ([
                "jing": "�䵱�����ճ��õ�ˮ�������ƺ�����������(enter)��ȥ��\n",
                "well": "�䵱�����ճ��õ�ˮ�������ƺ�����������(enter)��ȥ��\n",
                "��": "�䵱�����ճ��õ�ˮ�������ƺ�����������(enter)��ȥ��\n",
	]) );
        set("resource/water",1);
	set("outdoors", "wudang");
	set("coor/x",150);
	set("coor/y",-110);
	set("coor/z",50);
	set("coor/x",150);
	set("coor/y",-110);
	set("coor/z",50);
	set("coor/x",150);
	set("coor/y",-110);
	set("coor/z",50);
	set("coor/x",150);
	set("coor/y",-110);
	set("coor/z",50);
	set("coor/x",150);
	set("coor/y",-110);
	set("coor/z",50);
	setup();
}

void init()
{
        add_action("do_enter", "enter");
        add_action("do_fillwater", "fillwater");
}

int do_enter(string arg)
{
        object obj;
        object me;

        if(!arg || arg=="")
        {
                write("��Ҫ�������ꣿ\n");
                return 1;
        }
        me = this_player();
        if( arg == "jing" || arg == "well" || arg == "��")
        {
                message_vision("$N�����ܿ���һ������û��ע�⣬����һ��������˾��\n", me);
                me->move(__DIR__"jing.c");
                return 1;
        }
        else
        {
                write("�㲻������"+arg+"���꣡\n");
                return 1;
        }
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
                        write("��Ӿ���װ������ˮ! \n");
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

