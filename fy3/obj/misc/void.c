// void.c
// From SZ-ES2
// �޸ģ���ɽ��ѧ  �����ᣨMicro��----Micro_Liang@Hotmail.Com

inherit ROOM;

void create()
{
        set("short","��������");
        set("long",@LONG

    ������Ǵ�˵�е��������硣���ƺ���������һƬ��ãã�ģ���ϸһ
����ȴ����ʲôҲû�У��������ղŵİ�Ҳ�������ڡ���ҡ��ҡͷ, ȴ��
��ס��������Щ���׿ɾ��������ǣ���޲������Ϸɵ����ǵ���ߣ�����
����һ�档
LONG
        );

        set("exits", ([
                "down" : "/d/center/guangchang",
        ]));

        setup();
        replace_program(ROOM);
}
