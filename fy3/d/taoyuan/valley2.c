inherit ROOM;
void create()
{
        set("short", "ɽ��");
        set("long", @LONG
���ֵ��˴˴��𽥱��ϡ����������ǰ��Ȼ����һ��ǧ����䡢�����Ե�ɽ�壬
Χ��һ���Ĺȣ�����һ����̶��Ȫˮ�ӷ�䱼�����£�����й��ֱ����̶����ֻ��β
�͵�Ұ�ã�����̶�����еĺ�ˮ���˴���������ʪ�������ķΣ�����ȴ�������κ���
�Եĳ�·����������ֻ���Ĵ�תת���ˡ�
LONG
        );

	set("item_desc", ([
	"pond" : "̶ˮ�������ף�����С��СϺ����������������\n",
	"��̶" : "̶ˮ�������ף�����С��СϺ����������������\n",
	]) );

        set("outdoors","taoyuan");
        set("coor/x",160);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
}

void init()
{
	add_action("do_around", "around");

}

int do_around(string arg)
{
	object me, room;

	me = this_player();
tell_object(me, "��ת��תȥ��Ҳû�ҵ����ڣ�������·����\n\n");
        room = find_object(__DIR__"valley");
	if(!objectp(room)) room=load_object(__DIR__"valley");
	me->move(room);

	return 1;
}

