// xuelong2.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("���԰�", ({ "board" }) );
        set("location", "/d/xuelongshanzhuang/dating");
        set("board_id", "xuelong2");
        set("long", @LONG
����Ѫ��ɽׯ�ڲ���ͨ��Ϣ�����԰塣
LONG
	);
	setup();
        set("capacity", 50);                    // ����Ϊ50�����ԣ�ͨ����30�ţ�
        replace_program(BULLETIN_BOARD);
}
