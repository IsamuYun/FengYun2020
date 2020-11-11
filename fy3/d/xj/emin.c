#include <globals.h>
inherit ROOM;
void create()
{
        set("short", "额敏塔");
        set("long", @LONG
全称为额敏和卓报恩塔，又称苏公塔。该塔建于清乾隆四十三年，
用一式的灰黄色砖砌成，呈向上均匀收缩的圆柱体形，下粗上细，塔身
砌砖表面装饰有菱格纹、水波纹、变体四瓣花纹、山纹等几何图形共十
多种。塔身又在不同高度和方向开出十多个窗口。构造精致，颇为壮观。
塔的内部结构，没有基石，也没有木料，是用砖砌出七十多级螺旋体中
心柱，既可加固塔身，又可作梯攀登直上塔顶。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "westdown" : __DIR__"tulufan",
  "eastdown" : __DIR__"butao",
  "southeast" : __DIR__"gumu",
]));
        set("objects", ([
                __DIR__"npc/ghost" :2,
                        ]) );
	set("no_pk",1);
	set("no_spells",1);
	set("no_magic",1);
        set("outdoors", "xinjiang");
        set("coor/x",-1060);
	set("coor/y",1030);
	set("coor/z",0);
	setup();
}
