
inherit ROOM;
string *names=({
	__DIR__"d7",
	__DIR__"d5",
	__DIR__"d1",
	__DIR__"d6",
} );
void create()
{
	set("short", "�ڰ�ɽ��");
	set("long", @LONG
����һ����ɭ�ɲ����������޹��ɽ����һ�߽������㵹����һ������������
һ����ѣ����ʲôҲ�벻�����ˡ�
LONG
	);
//(3270,40,-30)
	set("coor/x",3270);
	set("coor/y",40);
	set("coor/z",-30);set("no_dazuo",1);set("no_magic",1);

	setup();
}
void reset()
{
	int i,j;
	string temp;
	::reset();
	for (i=0;i<=3;i++)
	{
		j=random(4);
		temp=names[j];
		names[j]=names[i];
		names[i]=names[j];
		names[i]=temp;
	}
	set("exits", ([
		"north" : names[0],
		"south" : names[1],
		"east" : names[2],
		"west" : names[3],
	]));
}
