inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
	set_name( HIR "��ѪӢ�۰�" NOR, ({ "yingxongbang" }) );
	set("location", "/u/residence/xiaoqi");
	set("board_id", "paiboard");
	set("long",	"����һ������ѪӢ�۽�����Ӣ�۰�\n" );
	setup();
	set("capacity", 20);
	replace_program(BULLETIN_BOARD);
}
