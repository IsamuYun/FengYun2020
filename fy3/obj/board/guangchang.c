// guangchang.c
// ��̣���ɽ��ѧ  �����ᣨMicro��----Micro_Liang@Hotmail.Com

inherit BULLETIN_BOARD;

void create()
{
        set_name("����㳡���԰�", ({ "board" }) );
        set("location", "/d/center/guangchang");
        set("board_id", "guangchang");
        set("long", "����һ����������ͳ�����㳡�����԰塣\n" );
        setup();
        set("capacity", 50);			// ����Ϊ50�����ԣ�ͨ����30�ţ�
        replace_program(BULLETIN_BOARD);
}
