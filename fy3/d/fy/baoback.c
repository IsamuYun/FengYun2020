
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����ںڵģ�ʲô����������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"baozipu",
  
]));
        set("objects", ([
 "/d/yingou/obj/shiti": 1,
        ]) );
        set("coor/x",-20);
	set("coor/y",50);
	set("coor/z",0);
	set("coor/x",-20);
	set("coor/y",50);
	set("coor/z",0);

        setup();
}
void init()
{
        add_action("do_open", "open");
}
int do_open(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("��Ҫ��ʲô��\n");
                return 1;
        }
        if( arg == "picture" || arg == "����" || arg == "tiao")
        {
        me = this_player();
        message_vision("$N����ǽ�ϵ�������������һ�����š�\n", me);
        if( !query("exits/westup") ) {
        set("exits/westup", __DIR__"backwest");
        call_out("close_path", 1);
        }
        return 1;
        }
        else
        {
                write("�㲻���Դ�"+arg+"\n");
                return 1;
        }
}
void close_path()
{
        if( !query("exits/westup") ) return;
        message("vision",
"�������˻���������ס�˰��š�\n",
                this_object() );
                delete("exits/westup");
}

