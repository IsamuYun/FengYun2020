inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
������û�б����ɫ��ֻ�кڣ���Ϧ���ս����������һ�ֲ����������ɫ��
��ɫ����ᣵʹ���û�����ܿ��ü����湩�����ʲô�����������аѵ�������
��ڣ�������ڡ���������һ�����ӣ�sign������������һ������look sign����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : "/d/laowu/road0",
  "northwest" : __DIR__"sichou5",
//  "west" : "/u/moon/zz2",
]));
	set("no_pk",1);
	set("no_spells",1);
	set("no_magic",1);
        set("outdoors", "xinjiang");
        set("coor/x",-1010);
	set("coor/y",1000);
	set("coor/z",0);
        set("item_desc", ([
                "sign": "
                        �Ӵ�����������ͼɱ��������

������������С�֣����˴������������������KILL�Ķ����ܵ�������˫ӥ����Χɱ��
��������������ǩ����
                        �ϳ��ӥ ������
                        ˫ͷͺӥ ����ľ\n",
		"blade": "������ز��ڵ����У�ֻ¶����ڵĵ���������������ز������С�����ҡҡ(shake)����\n"
        ]) );
        set("objects", ([
                __DIR__"npc/furen" :1,
                        ]) );
	setup();
}

void init()
{
	add_action("do_shake","shake");
}

int do_shake(string arg)
{
	write("��ץס��ڵĵ���������ҡ��ҡ��\n");
	if (present("old woman", this_object()))
		write("˫���缦צ���ϸ�������һ�ۣ������ã�����ұ��𣿣�ȥɱ���Ǹ������������ˣ�\n");
	return 1;
}
