// wizard_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("��ʦ�����", ({ "fynews_board" }) );
	set("location", "/d/wiz/hall");
        set("board_id", "fynews_b");
	set("long",
                "����һ����������Ա�������ŵ����԰塣\n" );
	setup();
	set("capacity", 88);
	replace_program(BULLETIN_BOARD);
}
