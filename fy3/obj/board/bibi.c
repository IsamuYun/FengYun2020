// bibi.c
// ��̣���ɽ��ѧ  �����ᣨMicro��----Micro_Liang@Hotmail.Com

inherit BULLETIN_BOARD;

void create()
{
        set_name("������԰�", ({ "board" }) );
        set("location", "/d/player/bibi");
        set("board_id", "bibi");
        set("long", "����һ�������С�����������԰塣\n" );
        setup();
        set("capacity", 50);                    // ����Ϊ50�����ԣ�ͨ����30�ţ�
        replace_program(BULLETIN_BOARD);
}
