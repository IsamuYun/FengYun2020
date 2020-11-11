inherit ROOM;
void create()
{
        set("short", "风云布铺");
        set("long", @LONG
布铺里摆满了绫罗绸缎，这里专门订作，裁剪，改装各种鞋，帽，
衫．这里做的衣服不但款式新颖，而且经久耐用．风云老少们穿的大
部份都是这里出的．门口有一个大木牌（ｓｉｇｎ）．
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
这里是布铺，目前可以制作的东西请help lianzhi.

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
