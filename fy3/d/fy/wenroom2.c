inherit ROOM;
void create ()
{
  set ("short", "���������");
  set ("long", @LONG
������֣�ݷ�����ҵ�����ݡ�����������д�����Ҳ��ħͷ��Ҳ��
���Ǵ�������ħͷ����ҡ���������һλ�������ھ�һʱ������һ������
�����Ķ��ǵĹ��£�ÿһ�����¶�������Զ��Ӱ����һ���������������
����Ȼ���Ƕ�����������������������ķ��꣬���������Ҳ�����ڽ�
�������ˡ����Ƕ��Ѿ��˳������������ǵ���Ӱħ�ٺܳ�ʱ���Ժ�����һ
����˵��Ϊ�˼�����������,�����������⽨���������ݼ���ǰ�ˡ�
LONG);

  set("no_death_penalty", 1);
  set("watch_fight_room2", 1);
  set("watch_fight_room", 1);
  set("no_perform", 1);
  set("no_exert", 1);
  set("no_du", 1);
  set("no_fight", 1);
  set("no_beg", 1);
  set("no_magic", 1);
  set("objects", ([ /* sizeof() == 3 */
//   "/d/shaolin/npc/baixiaoshen" : 1,
]));
  set("coor", ([ /* sizeof() == 3 */
  "y" : 0,
  "z" : 20,
  "x" : -10,
]));
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"wenroom",
]));
  setup();
}


