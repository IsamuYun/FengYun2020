inherit ROOM;
void create()
{
        set("short", "��Ȼ��");
        set("long", @LONG
�������С���޺Ͱ������¾��ˡ�ԭľΪ�飬�����������ִ�Χ��һ��Ժ�䡣
���Ų�����̣�����Ҳ�ƺ������ں�����֦���������٣����ƶ��ϣ�΢���������
���������Ը��飺��������Ե��ɨ  ���Ž�ʼΪ����  ���к��飺��Ȼ�ӡ�
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
  	"south" : __DIR__"road3",
  	"north" : __DIR__"cyard",
	]) );

	set("objects", ([
		__DIR__"npc/dog" : 1,
	]) );

   	set("outdoors","taoyuan");
        set("coor/x",210);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
        replace_program(ROOM);

}
