
inherit ROOM;

void create()
{
	set("short", "������վ");
	set("long", @LONG
ÿ�������ƥ���������������������Ρ����ƳǵĹٸ����ۺ���ͨ���ն�������
�����Ѻ�������������������������Ҫ�ĵ����ֻҪ�ŵ��������֮�ھ�
�Կ����͵���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"wcloud2",
	]));
	set("objects", ([
		__DIR__"npc/officer": 1
	]) );

	set("coor/x",-20);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir)
{
	object mbox;

	if( mbox = me->query_temp("mbox_ob") ) {
		tell_object(me, "�㽫���佻����վ��\n");
		destruct(mbox);
	}
	return 1;
}