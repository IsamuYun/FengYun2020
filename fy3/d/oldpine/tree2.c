// Room: /d/oldpine/tree2.c

inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
���������ʸ���һ��������������ϣ�����������Ѿ����ߡ�����
�ߣ������С�ĵ�����ȥ����������Ҳ��ȥ�������������Ͻ��������
���������󲿷ֶ������ɺ�Զ���㹻������
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "up" : "/d/oldpine/tree3",
  "down" : "/d/oldpine/tree1",
]));

        set("coor/x",-280);
	set("coor/y",-330);
	set("coor/z",120);
	setup();
        replace_program(ROOM);
}
