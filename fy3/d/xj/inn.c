inherit ROOM;
void create()
{
        set("short", "����С���ӻ���");
        set("long", @LONG
�ſ�һ��������Ʈ�������ﱾ����һ�������ĵط�,Զ��������
��½,���������ܷ�����һЩ����,�����ϵĸ��־������������
������С�Ŀռ��Ե���Щӵ���ˡ��ϰ�Ҳ��æ��ͣ���к����ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"bazha1",
]));
        set("objects", ([
        __DIR__"npc/seller2" : 1,
                        ]) );

        set("coor/x",-1100);
	set("coor/y",-1080);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
