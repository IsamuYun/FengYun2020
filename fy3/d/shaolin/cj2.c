// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�ؾ�¥");
        set("long", @LONG
����ֻ��һ������ӣ����඼��������ʮ���������������׿����
��ʱ��ע�Լ����о��ĵ����ϣ�������ר���о������书��Ѱ������
���ڣ���Щ���������֮����Ѱ���ƽ���ɾ���֮�����������ֵ���
�������ֱ�ռ���Ȼ�������һС¥�ݣ�ͨ����¥��
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"cj3",
  "down": __DIR__"cj",
]));
        set("objects", ([
                __DIR__"npc/monk20b" : 3,
       ]) );
	set("coor/x",-210);
	set("coor/y",360);
	set("coor/z",80);
	setup();
	replace_program(ROOM);

}
