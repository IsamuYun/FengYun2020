
inherit BULLETIN_BOARD;

void create()
{
        set_name("��ս����԰�", ({ "board" }) );
        set("location", "/d/tiankongjie/tiankongjie");
        set("board_id", "tiankongjie");
        set("long", "����һ���������ս�����԰塣\n" );
        setup();
        set("capacity", 50);                    // ����Ϊ50�����ԣ�ͨ����30�ţ�
        replace_program(BULLETIN_BOARD);
}
