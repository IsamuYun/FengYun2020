// xuelong1.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("���԰�", ({ "board" }) );
        set("location", "/d/xuelongshanzhuang/piaoxueting");
        set("board_id", "xuelong1");
        set("long", @LONG
����Ѫ��ɽׯ����罻������Ҫ�ֶΣ�����ɽ��·�գ�ɽׯ�ص���
��Ϊ����׼�������԰塣
LONG
	);
	setup();
        set("capacity", 50);                    // ����Ϊ50�����ԣ�ͨ����30�ţ�
        replace_program(BULLETIN_BOARD);
}
