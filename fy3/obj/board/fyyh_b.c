inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
        set_name( HIR "����Ӣ������" NOR, ({ "top-board" }) );
        set("location", "/d/fy/poemp");
        set("board_id", "top-board");
	set("long",	"����һ������ѪӢ�۽�����Ӣ�۰�\n" );
	setup();
        set("capacity", 1000);
	replace_program(BULLETIN_BOARD);
}
