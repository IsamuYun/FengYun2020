inherit ROOM;
void create()
{
        set("short", "�ʹ�");
        set("long", @LONG
�����ǵ��������Ϣ�ĵط������ܻԻ���̣�����������һ�����񣬲�
֪��˭�ġ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
    "south" : __DIR__"poemp",
  
]));
	
			set("no_magic",1);
        set("outdoors", "fengyun");
  set("coor", ([ /* sizeof() == 3 */
  "y" : 2,
  "z" : 0,
  "x" : -10,
]));
        set("objects", ([
       ]) );
setup();
        replace_program(ROOM);


}

