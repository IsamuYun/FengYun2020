// common_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("遥远的记事本", ({ "board" }) );
	set("location", "/zki/gongzs/workroom");
	set("board_id", "common_zki");
	set("long",	"这是一个可以留言给遥远的小本子。\n" );
	setup();
          set("capacity", 49);
	replace_program(BULLETIN_BOARD);
}

