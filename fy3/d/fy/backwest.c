
inherit ROOM;

void create()
{
        set("short", "��ظ�");
        set("long", @LONG
�����������ȣ���ֱ������֮�𡣸��ڰ���װ�궼�������֮����
һ����֪��֮����֮�֡����棬��������Ŀ��������幬���ļ�λ
С�ɹá�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "eastdown" : __DIR__"baoback",
  
]));
        set("objects", ([
        __DIR__"npc/tiandi" : 1,
                        ]) );
        set("coor/x",-30);
	set("coor/y",50);
	set("coor/z",10);
	set("coor/x",-30);
	set("coor/y",50);
	set("coor/z",10);

setup();
}

