// gaibang_a.c

inherit BULLETIN_BOARD;
void create()
{
	set_name("ؤ��������԰�", ({ "board" }) );
	set("location", "/u/gaibang/fotang");
	set("board_id", "gaibang_a");
	set("long",	"����һ��ר�Ÿ�ؤ����ӵ�����塣\n" );
	setup();
        set("capacity", 49);
        replace_program(BULLETIN_BOARD);
}
