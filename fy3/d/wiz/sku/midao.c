//sku@00-11-19 
inherit ROOM;
void create ()
{
  set ("short", "�ܵ�");
  set ("long", @LONG
���ǿ���Ϊ��͵�����Լ��޵�����ͨ����
     [45m��� A  ���� B  ���� C  ���� D  ���� E  ��ɽ F[0m
     [42mħ�� G  ��÷ H  �䵱 I  ��ˮ J  ���� K  ���� L[0m
     [43m�� M  ��� N  ��ɽ O  �˹� P  ���� Q  ���� R[0m
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "down" : "/d/fy/fysquare",
  "west" : __DIR__"workroom",
]));
  set("coor", ([ /* sizeof() == 3 */
  "z" : 1000000,
  "x" : 0,
  "y" : 0,
]));
  set("no_magic", 1);

  setup();
  replace_program(ROOM);
}
