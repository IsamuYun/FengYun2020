
inherit ROOM;

void create()
{
        set("short", "�ż�����");
        set("long", @LONG
�������ٶ�ϲ�������������ֵ��������ӻ�¯��ð���Ļ�⽫ǽ
��ӳ��ͨ�죬���ӵĽ���������˸�ʽ���������Ʒ��δ���Ʒ�����ǳ�
ͷ�����������ӡ������ȣ����������������õ��������졣
�ſ���һ����ľ�ƣ�������
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"ecloud3",
]));

        set("objects", ([
              "/d/fy/obj/luzi":1,
                "/d/fy/npc/smith": 1 ]) );
        set("item_desc", ([
                "sign": @TEXT

����о�������֧�ˣ���ʱ���ṩ�������������ˣ��ͻ���������¯�Ӷ��죬

TEXT
        ]) );

        set("coor/x",30);
	set("coor/y",10);
	set("coor/z",0);
        set("no_fight",1);
         set("making",1);
        setup();
        replace_program(ROOM);
}
