// feishi.c
// ��̣���ɽ��ѧ  �����ᣨMicro��----Micro_Liang@Hotmail.Com

inherit BULLETIN_BOARD;

void create()
{
        set_name("����Ա�����԰�", ({ "board" }) );
        set("location", "/d/feishijituan/2_office");
        set("board_id", "feishi");
        set("long", "���Ƿ��ϼ���ר�õ����԰塣\n" );
        setup();
        set("capacity", 30);                    // ����Ϊ30�����ԣ�ͨ����30�ţ�
        replace_program(BULLETIN_BOARD);
}
