// shanlu1.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
����ɽ·����ɽ������ϣ�ɽ·����ʯ������ֻ��һ�˿ɹ���
���Ƽ�Ϊ�վ�����Զ����ȥ��Ⱥɽ���ƣ���춽��£���������������
�ף���ʱ���˺�����������Ҫ��Хһ������������һƬ�յء�������
�����ƻ�С����
LONG
        );
        set("outdoors", "songshan");
        set("exits", ([
                "southdown" : "/d/songshan/junji",
                "northup"   : __DIR__"shanlu2",
        ]));

        setup();
        replace_program(ROOM);
}
