#include <globals.h>
inherit ROOM;
void create()
{
        set("short", "白杨沟");
        set("long", @LONG
白杨沟位于天山支脉喀拉乌成山北麓中底山过渡带，沟中古树葱郁，
长满高大挺拔的榆树、杨树、槐树及说不出名字的灌木、鲜花。就是在
阳光下，这里还是清凉无比，令人感到无限舒畅。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"chairong",
  "south" : __DIR__"bingchuan",
  "east" : __DIR__"goudi",
]));
        set("item_desc", ([
                "灌木": "一从不知名的灌木，长的正茂密。\n",
                "guanmu": "一从不知名的灌木，长的正茂密。\n",
                "杨树": "灰白色的杨树干上结满了一个个象眼睛似的疤痕，有的象在笑，有\n的似在哭．．其中的一个，目光似乎正落在一丛灌木上。\n",
                "yangshu": "灰白色的杨树干上结满了一个个象眼睛似的疤痕，有的象在笑，有\n的似在哭．．其中的一个，目光似乎正落在一丛灌木上。\n"
        ]) );
	set("no_pk",1);
	set("no_spells",1);
	set("no_magic",1);
        set("outdoors", "xinjiang");
        set("coor/x",-1120);
	set("coor/y",1020);
	set("coor/z",-10);
	setup();
}

int dig_notify()
{
	object ob;
	if(!query("already"))
	{
	message_vision("锵．．得一声，再看地上的盐巴以被$N砸下一小块。\n",this_player());
	ob = new(__DIR__"obj/salt");
	ob->move(this_object());
	set("already",1);
	return 1;	
	}
	else
	return 0;

}

/*
do_look^Dlook^Omarks/foundjade^Hset_temp^Galready^Ckar^Equery^Hiron box-铛．．得一声，$N的镐似乎敲在了一个铁东西上。
:!低头一看，土坑里露出了一个铁盒。
:
^S/d/xinjiang/obj/box^Dmove7地上出现了一个土坑，除了腐朽的枝叶，$N什么都没有发现。
:
^Fcreate^Dinit^Gdo_look

:dig_notify
*/