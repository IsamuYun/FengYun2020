inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
һ�䲢�������鷿��ȴ��ʰ����ˬ���ˡ��ұ��������֮�£�����һ����
̴���������������һ�Ž�ľ���٣������ںڹ�����û�а��ҳ�����������һ
���ƻ�Ͳ��ȴ����һ֦ɽ�䳣������Ҷ�����Ҳ��һ����̴����������бб��̯
��������װ�飬һ����裬�������¡��ݵ����У�������һ��������ã�
���������������˶�˵���ɺã���ֻ��ԧ������
                                       ����С�����ױ���͡�
LONG
        );
        set("exits", ([ 
	"south" : __DIR__"cyard",
	"east" : __DIR__"grassland",
	]) );

	set("item_desc", ([
	"�������": "һ��ī�ʿ���鷨��������ˮ�����ư��磬����һ��˵�����������к��������м䣮��\n",
	"writing": "һ��ī�ʿ���鷨��������ˮ�����ư��磬����һ��˵�����������к��������м䣮��\n",
	]) );

        set("coor/x",210);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}

void init()
{
	add_action("do_search", "search");
}

int do_search(string arg)
{
	object me, obj;

	me = this_player();

        if(!arg || arg != "room" && arg != "�鷿") return 0; 
	if(me->query_temp("marks/marble")) {
		if(me->query_temp("marks/marble_y")) {
message_vision("$N���鷿�ڷ��䵹�������һ����\n", me);		
tell_object(me, "��һ����ȴû��ʲô�����κ��м�ֵ�Ķ�����\n");
			return 1;
		}
message_vision("$N���鷿�ڷ��䵹�������һ����\n", me);		
tell_object(me, "�������ڽ�ľ���ٵ������ҵ���һ��Сˮ����\n");
message("vision",me->name()+"͵͵�����شӽ�ľ�������ó��˸������ŵ����\n",environment(me), me);
		me->set_temp("marks/marble_y", 1);
		obj = new(__DIR__"obj/marble");
		obj->move(me);
		return 1;
	}
message_vision("$N���鷿�ڷ��䵹�������һ����\n", me);		
tell_object(me, "��ȴû����ʲô�м�ֵ�Ķ�����\n");
	return 1;	
}
