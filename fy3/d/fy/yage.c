inherit ROOM;
void create()
{
        set("short", "֪���鷿�Ÿ�");
        set("long", @LONG
�����ղ������Ϣ�ĵط�,���õķǳ�����,���й�һ������ɽˮ����һ��
��ͭ��¯��¯������Ʈ�졣�����һ�ź�ľ��齣��ұ߼��϶�������ͼ�顣��
��һֻ���ϣ������ķ��ı��������,ͥ����ֲ��໨ľ��
LONG
        );
        set("exits", ([ 
  "down" : __DIR__"zt",
]));

        set("no_fight",1);
        set("no_beg",1);
        set("no_sheet",1);
        set("no_magic",1);
        set("no_dazuo",1);
        set("NONPC",1);

        set("objects", ([
           "/tongji/npc/zhuge" : 1,
                        ]) );

        set("coor/x",-19);
	set("coor/y",-10);
	set("coor/z",20);
	setup();
}
