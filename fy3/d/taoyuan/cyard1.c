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
	"east" : __DIR__"cyard",
	]) );


        set("outdoors","taoyuan");
        set("coor/x",200);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
}


void init()
{
        add_action("do_look", "look");
        add_action("do_approach", "approach");
}

int do_look(string arg)
{
	object me;
	object room;
	me = this_player();
	if(!arg || arg != "��" && arg != "well" ) return 0;
	switch ( random (2)) {
		case 0:
tell_object(me,"ˮ������ʪ�����ģ���������˴��ˮ�����ǲ�Ҫ������������裩��̫����\n"); 
		break;
		case 1:
message_vision("$N̽ͷ��ˮ������ȥ�� \n", me); 
tell_object(me,"�ڲ�¡�˵�ˮ������ס� \n");
                break;
	}


        return 1;
}
int do_approach(string arg)
{
        object me;
        object room;
        me = this_player();
	if(!arg || arg != "��" && arg != "well" ) return 0;
	switch ( random (3)) {
		case 0:
message_vision("$N�߽�ˮ��̽ͷ������ȥ�� \n", me); 
tell_object(me,"ˮ������ף��������ƺ���������������ˮ�������� \n");
                break;
		case 1:
message_vision("$N�߽�ˮ��̽ͷ������ȥ����ѽ��һ��С�ĵ��˽�ȥ��\n", me); 
message_vision("$N��ͷײ�ھ����ϣ�һ���ӻ��˹�ȥ��\n", me);
		me->unconcious();
       		room = find_object(__DIR__"well");
		if(!objectp(room)) room=load_object(__DIR__"well");
		me->move(room);
		break;
		case 2:
message_vision("$N�߽�ˮ��̽ͷ������ȥ����ѽ��һ��С�ĵ��˽�ȥ��\n", me); 
       		room = find_object(__DIR__"well");
		if(!objectp(room)) room=load_object(__DIR__"well");
		me->move(room);
		break;
	}

        return 1;
}
