#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
        set_name("�ڰ�", ({ "chalkboard" }) );
        set("location", "/d/wiz/outjail");
        set("board_id", "heiban_b");
        set("long",     "����һ������ĺڰ壬����д�����������µ����ԡ�\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}

