// common_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("ңԶ�ļ��±�", ({ "board" }) );
	set("location", "/zki/gongzs/workroom");
	set("board_id", "common_zki");
	set("long",	"����һ���������Ը�ңԶ��С���ӡ�\n" );
	setup();
          set("capacity", 49);
	replace_program(BULLETIN_BOARD);
}

