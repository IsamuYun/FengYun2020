// tianxie.c
// by zen

inherit BULLETIN_BOARD;

void create()
{
        set_name("��а�����԰�", ({ "board" }) );
        set("location", "/d/tianxie/tianxiepai/main-03");
        set("board_id", "tianxie");
        set("long", "������а�ɵ���ר�õ����԰塣\n" );
        setup();
        set("capacity", 50);                    // ����Ϊ30�����ԣ�ͨ����30�ţ�
        replace_program(BULLETIN_BOARD);
}
