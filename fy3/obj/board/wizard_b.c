// wizard_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("���������", ({ "board" }) );
	set("location", "/d/wiz/hall");
	set("board_id", "wizard_b");
	set("long",
		"����һ����������Ա���໥���Եİ塣\n" );
	setup();
        set("capacity", 149);
	replace_program(BULLETIN_BOARD);
}
