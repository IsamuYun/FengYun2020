// wiz_b.c
// ��̣���ɽ��ѧ  �����ᣨMicro��----Micro_Liang@Hotmail.Com

inherit BULLETIN_BOARD;

void create()
{
        set_name("��ʦ���԰�", ({ "board" }) );
       
        set("board_id", "wiz_b");
        set("long", "����һ��ר����ʦʹ�õ����԰塣\n" );
        setup();
        set("capacity", 30);			// ����Ϊ30������
        replace_program(BULLETIN_BOARD);
}
