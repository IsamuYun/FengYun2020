#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("��Ħ����", ({ "damo-jianpu" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����Ƥ��,����д���κε��ӽ�ֹ�Ķ�(yuedu)��\n");
        }
}

int is_container() { return 1; }

void init()
{
  add_action("do_combine","yuedu");
}

int do_combine(string arg)
{
              int sscore;
       if (this_player()->query("class") != "shaolin"){
              message_vision(HIR"$N�����Ķ��Ȿ�����ؼ���\n"NOR,this_player());
                return 1;
        }
    if (( arg == "damo-jianpu")){
        sscore = 50 + random(50);
        message_vision("$N͵͵���Ȿ����,��������ʲô��û�У�\n",this_player());
        this_player()->set("m_success/͵������",1);
        tell_object(this_player(),HIY"����������ֵĲ��ң�������۽�����!\n"NOR);
        this_player()->add("score",-sscore);
        destruct(this_object());
return 1;
}
     return 0; 
}
