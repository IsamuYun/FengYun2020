//txf��wc
//ROOM: /d/wiz/fengye/wc.c
//txf bye 2001/1/26
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", BLINK BLU"�в���"NOR NOR);
  set ("long",@LONG
���Ƿ�ҵĲ�������Ҫ����ҷ����õġ�����Ҫ�շѵİ���1goldһ�Ρ�
��һ������С��Ͱ������һ��ԡ�裬������������
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
       add_action("do_ponder","poop");
}
int do_ponder(string arg)
{
       object who;

       who = this_player();
        if((int) who->query("sen") <=50)
        return notify_fail("����񲻹���\n");
       message_vision("$N�����:�����۲��ǲ���һ��ϡʺû������һƨ��������Ͱ�ϡ��\n" ,who);
       who->receive_damage("sen",50);
       if( (int)who->query("bellicosity") > 0)
           who->add("bellicosity", - (random((int)who->query("kar")) + 15 ) );
       message_vision("$N�ƺ��о�������ˬ��@#$%#$%�������������ó��� \n" , who);
    return 1;
}
