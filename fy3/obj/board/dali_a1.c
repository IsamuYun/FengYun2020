#include <ansi.h>
// swordsman_b.c

inherit BULLETIN_BOARD;
void create()
{
        set_name( GRN "����ʯ��" NOR, ({ "stone" }) );
	set("board_id", "dali_a");
	set("long",	"����һ�����ɸߵ�ʯ���������������������������
��򥣬������ˮ��������ӿ����ԶԶ��ȥ��ΰ׳�ۡ�\n" );
	setup();
	set("capacity", 49);
	replace_program(BULLETIN_BOARD);
}
