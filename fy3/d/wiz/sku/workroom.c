//sku@00-11-19 
inherit ROOM;
void create ()
{
  set ("short", "[45m���ֵ���Ϣ��[0m");
  set ("long", @LONG
���ǿ��ֵĹ�����,������һ̨[42m����760[0m�ڷɿ��
��ת�š���������һ��С��������ԼԼ���������Ƴ�
��Ļ���Ц��ⶼ�ǿ��������Ͷ��Ľ��ѽ�� 
LONG);

  set("coor", ([ /* sizeof() == 3 */
  "z" : 1000000,
  "y" : 0,
  "x" : -10,
]));
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"midao.c",
]));
  set("valid_startroom", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/book" : 1,
]));
  set("no_magic", 1);

  setup();
  replace_program(ROOM);
}
