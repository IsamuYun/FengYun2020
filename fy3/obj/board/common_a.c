// common_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("һ����;���԰�", ({ "board" }) );
	set("location", "/u/guanwai/inn");
	set("board_id", "common_a");
	set("long",	"����һ���������Լ��µ����԰塣\n" );
	setup();
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}
