

inherit ROOM;

void create()
{
	set("short", "ӥ���̺�");
	set("long", @LONG
ӥ��һ��������׿�������ⶦʢ���̺š��Ӳض����Ĳ��㣬�ӹ������Ĵ�
����˿�У��Ӵ��¯���Ĳ�ש������ʲô��ֻҪ��ֵǮ�Ķ�����������������
��������̨�Ϸ���һ������(sign)��
LONG
	);
	set("item_desc", ([
		"sign": @TEXT
���̺Ų����ۺ񡣿��Ŀ��������
convert     �һ�Ǯ�ҡ�
withdraw    ��ȡ��
deposit     ����Ǯ�ҡ�
balance     ��Ѱ��
loan        ��Ǯׯ��Ǯ��
pawn	    �䵱��
sell	    ���ϡ�
value	    ���ۡ�
redeem	    ��ء�
TEXT
	]) );
	set("exits", ([
		"west" : __DIR__"octo15",
	]));
        set("objects", ([
                __DIR__"npc/puying": 1, 
		"/obj/xiaotong" : 3 ,
		__DIR__"npc/petowner" : 1,
		]));
	set("coor/x",-1190);
	set("coor/y",20);
	set("coor/z",5);
	set("coor/x",-1190);
	set("coor/y",20);
	set("coor/z",5);
	setup();

}
