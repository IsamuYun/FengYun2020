#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"���"NOR, ({ "mian" }) );
    set("forzen",5);
    set("have",0);
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "ƿ");
            set("material", "wood");
            set("long", "����һСƿ��ۡ�\n");
          }
    setup();
}


void init()
{
 if(this_player()==environment())
 add_action("do_di","huo");
}

int do_di(string arg)
{

        object me,jade;
	object con;
 	me = this_player();
        if(!query("have"))
          {
	    if(!arg) 
               return notify_fail("��Ҫ��ʲô��\n");
	    if(!objectp(con=present(arg, me)))
	       return notify_fail("������û������������\n");
	    if(!con->query("liquid"))
	       return notify_fail( con->name() +"����Һ�壬���������ͽ�����\n");
	    if(!con->query("liquid/remaining"))
	       return notify_fail( con->name() + "�ǿյġ�\n");
	    con->add("liquid/remaining", -1);
            message_vision("$N��" + con->name() + "��" +
	    con->query("liquid/name")  + "�������ƿ����˼��¡�\n",me);
	    if(con->query("liquid/name") == "��ˮ")	
	        {
	          tell_object(me,"����ˮ̫���ˣ���\n");
                  add("forzen",-1);
	        }
            else
                tell_object(me,"����ûʲô��Ӧ��\n");
                if( query("forzen") <= 0 )
                    {
	              tell_object(me,"��ͳ���һСƿ������\n");
                      set("have",1);
                      jade=new("questnew/obj/jianghu");
                      jade->move(me);
                      destruct(this_object());
                      return 1;
  	             }
          }
	return 1;
}
