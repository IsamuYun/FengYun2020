// board.c

inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
        set_name( HIY "���԰�" NOR, ({ "board"}) );
        set("location", "/p/fystreet/room/axiuluo_room.c");
        set("board_id", "axiuluo_board");
        set("long",     "����һ���������԰壬����������˲��ڣ���������������ԡ�\n");
	setup();
        set("capacity", 99);
	replace_program(BULLETIN_BOARD);
}
