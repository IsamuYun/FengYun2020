// xgchen@zzfy
inherit ROOM;
void create ()
{
  set ("short", "ҵ����");
  set ("long", @LONG
������֣�ݷ�����ʦ��ҵ�������ｫ�Ὺ�Ÿ���ʦʹ�ù���
������MORE HERE!
LONG);
  set("coor", ([ /* sizeof() == 3 */
  "y" : 0,
  "z" : 10,
  "x" : -10,
]));
  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"hall",
  "enter" : __DIR__"outjail",
]));
        set("no_fight",1);
        set("no_magic",1);
        set("no_dazuo",1);
  setup();
  replace_program(ROOM);
}
