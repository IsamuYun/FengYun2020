//sku@00-11-19 
inherit ROOM;
void create ()
{
  set ("short", "�����������Ϣ��");
  set ("long", @LONG
һƬ�ڰ��������������� 
LONG);

  set("coor", ([ /* sizeof() == 3 */
  "z" : 1000000,
  "y" : 0,
  "x" : -10,
]));
  set("exits", ([ /* sizeof() == 1 */
  "down" : "/d/fy/fysquare",
]));
  set("valid_startroom", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/book" : 1,
]));
  set("no_magic", 1);

  setup();
  replace_program(ROOM);
}
