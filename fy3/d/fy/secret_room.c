
inherit ROOM;

void create()
{
	object silver;
	set("short", "��������");
	set("long", @LONG
������һ��խС�����ң������ǰֻ��һ���ƾɵ�С����һ
ЩǬ�ݡ�
LONG
	);

	set("objects", ([
		"/obj/money/silver": 1
	]) );

	set("coor/x",20);
	set("coor/y",50);
        set("coor/z",-20);
	setup();
	silver = present("silver",this_object());
	silver->set_amount(random(1000)+1000);	
	silver->set("name", "����");
}
