inherit ROOM;
void create()
{
        set("short", "���Ʋ���");
        set("long", @LONG
�������������޳�У�����ר�Ŷ������ü�����װ����Ь��ñ��
�������������·�������ʽ��ӱ�����Ҿ������ã����������Ǵ��Ĵ�
���ݶ���������ģ��ſ���һ����ľ�ƣ�������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"ecloud2",
]));
        set("objects", ([
        "/d/fy/npc/caifeng" : 1,
			 "/d/fy/obj/luzi2" : 1,
			]) );
		set("makearmor",1);
        set("item_desc", ([
                "sign": @TEXT
�����ǲ��̣�Ŀǰ���������Ķ�����help lianzhi.

TEXT
        ]) );

        set("coor/x",20);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);

}
