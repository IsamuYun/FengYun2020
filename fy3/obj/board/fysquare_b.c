// swordsman_b.c

inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
        set_name( HIG "盘龙摩天柱" NOR, ({ "stone" }) );
	set("location", "/d/fy/fysquare");
	set("board_id", "fysquare_b");
	set("long",	"这是一条石柱，石柱上刻着一条九头龙。龙首
向四面伸展，宏伟壮观。\n" );
	setup();
        set("capacity", 149);
	replace_program(BULLETIN_BOARD);
}
