inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
������б�������⻹�ǲ��ã������Ĵ��Ž�ʯ������һ������
��ɫ����ĭ������ֻ��Ÿ��ε��ɫ������£�ε��ɫ�ĺ����ϵͻء�
�մӺڰ����߳������ˣ���Ȼ�������⣬�����������۾���������
�Ƚ���������ů���ḧ��Ȼ����ܽ��������������Ĺ����� 
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"anbian2",
]));
        set("outdoors", "bat");
        set("coor/x",3310);
	set("coor/y",10);
	set("coor/z",10);
	set("no_magic",1);
        set("no_clean_up", 0);
        set("objects", ([
                __DIR__"npc/wang" :1,
                        ]) );
	setup();
}

