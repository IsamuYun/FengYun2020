#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", BLINK BLU"����"NOR NOR);
  set ("long",@LONG
���Ƿ�ҵĳ������������ζ������Ʈ������
��һ�ڴ��������ð���̣����˾���ԡ�
LONG);

  set("valid_startroom", 1);
  set("exits",([
  "home":"/d/wiz/fengye/home",
]) );
        set("no_fight",1);
        set("no_magic",1);
        set("no_dazuo",1);

  setup();
}
void init()
{
       add_action("do_ponder","chi");
}
int do_ponder(string arg)
{
       object who;

       who = this_player();
        if((int) who->query("sen") <=10)
        return notify_fail("���������û�ˣ����Ը�ƨ��\n");
       message_vision("$N�����:�����ֶ��ˣ�͵��Եİѡ��\n" ,who);
       who->receive_damage("sen",10);
       if( (int)who->query("bellicosity") > 0)
           who->add("bellicosity", - (random((int)who->query("kar")) + 15 ) );
       message_vision("$N�����:͵�Ķ������Ǻóԡ� \n" , who);
    return 1;
}
