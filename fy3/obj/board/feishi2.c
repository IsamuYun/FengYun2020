// feishi.c
// ��̣���ɽ��ѧ  �����ᣨMicro��----Micro_Liang@Hotmail.Com

inherit BULLETIN_BOARD;

void create()
{
        set_name("���ϼ���Ա��������", ({ "book" }) );
        set("location", "/d/feishijituan/6_danganshi");
        set("board_id", "feishi2");
        set("long", "���Ƿ��ϼ��ż�¼Ա�������ĵط���\n" );
        setup();
        set("capacity", 100);                    // ����Ϊ30�����ԣ�ͨ����30�ţ�
        replace_program(BULLETIN_BOARD);
}
