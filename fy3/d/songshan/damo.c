// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��Ħ��");
        set("long", @LONG
���ѵ�ɽ��С·��������·��ҡҷ����Ӱ���͵��������Ĵ�
Ħ�������ڳ������ϣ�����������ʯ����������⡰Ĭ����������
�����ڳ����Ħ�ڴ���ھ����������������Ϊ����ʥ�أ�������
ɮ��֮ٮٮ�߰��ش˵ء�����������Ƭ�̣���������嶥��
LONG
        );
        set("exits", ([ 
  "southeast" : __DIR__"talin",
  "westup" : __DIR__"wuru",
]));
        set("objects", ([
               __DIR__"obj/bei" : 1,
]));
        set("coor/x",-230);
	set("coor/y",420);
	set("coor/z",70);
	setup();
        replace_program(ROOM);
}
