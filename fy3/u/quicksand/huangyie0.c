
inherit ROOM;

void create()
{
        set("short", "荒野");
        set("long",
"这是一个无边的沙砾地，山势到了这里突然间变的无影无踪。地\n"
"气极干燥，连风都是暖的。地上的石砾发出一种暗红的颜色，就\n"
"象是被鲜血染红的一样。一条布满车痕的官道向西方和东方伸展。\n"
);
        set("exits", ([ 
  "east" : "/d/songshan/dengfeng",
  "west" : __DIR__"huangyie4",
  "northwest" : __DIR__"huangyie2",
  "southwest" : __DIR__"huangyie3",
]));
        set("outdoors", "quicksand");

        set("coor/x",-1000);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",-1000);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	replace_program(ROOM);

}
