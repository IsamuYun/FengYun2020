// board.c

inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
        set_name( HIY "���԰�" NOR, ({ "board"}) );
        set("location", "/p/fystreet/room/chen_room.c");
        set("board_id", "chen_board");
        set("no_post",1);
        set("long",     "����һ���������԰壬����������˲��ڣ���������������ԡ�\n");
	setup();
        set("capacity", 99);
	replace_program(BULLETIN_BOARD);
}
