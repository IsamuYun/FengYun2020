inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
��·������ɾ������������Ƿ����˼䣬��ϡ�Ǵ�˵��������Ӱ��ߣ�
һ��ѩ�׵�ʯͷ������һ�꾧Ө��͸��ҡҷ���˵�С�ݣ�ʯ�Ͽ������֣�����
����ʯ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"anbian1",
]));
        set("outdoors", "bat");
        set("coor/x",3320);
	set("coor/y",10);
	set("coor/z",10);
        set("no_clean_up", 0);
        set("objects", ([
                "/obj/paper_seal" :3,
                        ]) );
	setup();
        
}

