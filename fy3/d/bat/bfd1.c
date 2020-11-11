#include <room.h>
inherit ROOM;

void create()
{
  set("short","海边");
  set("long",@LONG
东边是一望无际的大海，海上翻腾着白色的浪花，一群群的海鸥
在空中盘旋着，时而不时地俯冲向海面，在浪涛中掠食。离海边不远
的浪涛中停泊着一艘高桅大帆船（boat）。
LONG
  );
  set("item_desc", ([
            "boat": "这是一条巨大的海船，坚固、轻捷、光滑、华丽、甲板上
也洗刷得一尘不染，就像是面镜子，映出了天光。
好船就正和美人与名马一样，就算停泊在那里不动，也自有
一种动人的风姿神采，令人不饮自醉。 \n",
            "高桅大帆船": "这是一条巨大的海船，坚固、轻捷、光滑、华丽、甲板上
也洗刷得一尘不染，就像是面镜子，映出了天光。
好船就正和美人与名马一样，就算停泊在那里不动，也自有
一种动人的风姿神采，令人不饮自醉。 \n"

    ]) );

//(1120,-250,-10)
    set("outdoors", "bat");
	set("no_magic",1); set("no_dazuo",1);

    set("objects",([
        	__DIR__"npc/dingfeng" : 1,			
       	]) );

    set("coor/x",1120);
	set("coor/y",-250);
	set("coor/z",-10);

	setup();
    replace_program(ROOM);
}

