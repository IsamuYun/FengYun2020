// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����С¥");
        set("long", @LONG
����¥����ֻ�����ܳ����Ϊ��ɫ�������ϱ���һ�ȴ���΢΢��Щ��
ɫ�⣬��ֻ�����������ϵ��͵Ʒ���΢���Ĺ⣬��������һ��齣�������
�ż򵥵ı��졣
LONG
        );
   set("exits", ([ 
      "north" : __DIR__"ruanhong",
   ]));
   set("objects", ([
      __DIR__"npc/lingyu" : 1,
   ]) );
  
   set("item_desc", ([
      "window": "�ٴ��¿���ֻ��Σ�°ٳߣ���ɫ�ĺ����Ĵ��Ű��ߵ���ʯ�� \n",
      "��": "�ٴ��¿���ֻ��Σ�°ٳߣ���ɫ�ĺ����Ĵ��Ű��ߵ���ʯ�� \n",
   ]) );
   set("coor/x",200);
	set("coor/y",12310);
	set("coor/z",-10);
	setup();
}

void init()
{
   add_action("do_climb", "climb");
}

int do_climb(string arg)
{
   object me, room;
   int ml, cl;

   me = this_player();
   cl = (int)me->query_cor();
   ml = (int)me->query_skill("move");
   if(!arg || (arg != "window" && arg != "��")) return 0;
   if (cl >= 20) {
      message_vision("$N�������ڣ�����������ȥ��\n\n", me);
      if (ml >= 100)
         tell_object(me, "��ֻ������������׹�䣬������������ҽ�̤��һ�Ŵ��ҷ��г�����С
��������һ��С�����ˣ����½�������Ҳ���˻�����ͨһ����������ˮ�С���\n\n");
      else {
         tell_object(me, "��ֻ������������׹��...׹��....�ƺ�׹���޵׵���Ԩ��������ͨһ
����������ˮ�С�\n");
         me->unconcious();
      }
      room = find_object(__DIR__"yadi");
      if(!objectp(room)) room = load_object(__DIR__"yadi");
      me->move(room);
      message("vision", "�������һ�źں�����������������£���ͨһ�����������Ե�ˮ�С�\n", environment(me), me);
      return 1;
   }
   else {
      tell_object(me, "���������ڣ����⿴�˿�������������\n\n", me);
      message("vision", me->name()+"�������ڣ����⿴�˿�����ɫɷ�׵�������������\n\n", environment(me), me);
      return 1;
   }
} 
