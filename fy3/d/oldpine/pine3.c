// Room: /d/oldpine/pine1.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
��������վ��һ�����������....����һ��������....����֪��
����࣬ï�ܵ������ڱ���������գ�ʹ��������Ū������������
���֮ǰ�Ͻ��ҵ�·����ȥ�ɡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
          "south" : __DIR__"pine" + (random(6)+1),
          "north" : __DIR__"pine" + (random(6)+1),
          "west" : __DIR__"pine" + (random(6)+1),
          "east" : __DIR__"epath3",
        ]));
        set("outdoors", "oldpine");

        set("coor/x",-240);
	set("coor/y",-360);
	set("coor/z",90);
	setup();
}

int valid_leave(object me, string dir)
{
        write("��ʵ��Ū���������....");
        switch(dir) {
                case "north":   write("����....�����������أ�....");    break;
                case "east":    write("����....����....");      break;
                case "south":   write("�ϱ�....�������ϱߣ�....");      break;
                case "west":    write("����....��....");        break;
                default:
                        write("������������....");
        }
        write("�����������ɡ�\n");
        return 1;
}

