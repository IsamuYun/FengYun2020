// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��Ϊ¥");
        set("long", @LONG
һ���ľС¥����ǰ�Ҷ��ϡ���Ϊ�������뱱����徲¥ң���Ӧ��
¥��ֻ��һ�Ų輸��һֻС��¯���������˱��ǲ�����֣���ǽ������
��һ�ѣ����ʹ�ɫ���㣬һ����֪���Ƿ�Ʒ����ǽ��һ�������

			��������

LONG
        );
        set("exits", ([ 
  "north" : __DIR__"diyuan",
]));
        set("objects", ([
                __DIR__"npc/girlfy": 1,
       ]) );
	set("coor/x",-230);
	set("coor/y",370);
	set("coor/z",70);
	setup();
        replace_program(ROOM);
}
