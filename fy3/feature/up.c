// Room: /feature/up
inherit ROOM;

void create()
{
  set ("short", "����");
  set ("long", @LONG
$HIR$����һ�������ޱȵķ��꣬������̫�����ˣ����������Ҳ��ö�������˰ɣ�
LONG);

  set("no_magic", 1);
  set("exits", ([ /* sizeof() == 1 */
  "down" : "/d/wanmei/center",
]));
  set("no_fight", 1);
  set("no_clean_up", 1);
  setup();
  replace_program(ROOM);
}
