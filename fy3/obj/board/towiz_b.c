// towiz_b.c
// ��̣���ɽ��ѧ  �����ᣨMicro��----Micro_Liang@Hotmail.Com

inherit BULLETIN_BOARD;

void create()
{
        set_name("���������԰�", ({ "board" }) );
        set("location", "/d/wizard/guest_room");
        set("board_id", "towiz_b");
        set("long", "����һ��ר����Һ���ʦ���������԰塣\n" );
        setup();
        set("capacity", 50);			// ����Ϊ50�����ԣ�ͨ����30�ţ�
        replace_program(BULLETIN_BOARD);
}
