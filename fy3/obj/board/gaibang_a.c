// gaibang_a.c

inherit BULLETIN_BOARD;
void create()
{
	set_name("丐帮弟子流言板", ({ "board" }) );
	set("location", "/u/gaibang/fotang");
	set("board_id", "gaibang_a");
	set("long",	"这是一个专门给丐帮弟子的意见板。\n" );
	setup();
        set("capacity", 49);
        replace_program(BULLETIN_BOARD);
}
