#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"��������"NOR, ({ "tianshu" }) );
    set("forzen",5);
    set("have",0);
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "����һ��û���ܿ��������飬���������飬�㾹Ȼ��һ���ֶ��Ҳ��š�
ͻȻ�����һ����Ӧ�õΣ���飩Щ��ˮ������������һ�ԡ�\n");
          }

    setup();
}


void init()
{
  if(this_player()==environment())
  add_action("do_di","di");
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
       return notify_fail( con->name() +"����Һ�壬������ֽ�ϵΡ�\n");
	    if(!con->query("liquid/remaining"))
	       return notify_fail( con->name() + "�ǿյġ�\n");
	    con->add("liquid/remaining", -1);
            message_vision("$N����" + con->name() + "���˼���" +
	    con->query("liquid/name")  + "�����������ϡ�\n",me);
	    if(con->query("liquid/name") == "��ˮ")	
	        {
	          tell_object(me,"���������ϳ����˼����֣���\n");
                  add("forzen",-1);
	        }
            else
                tell_object(me,"��������Խ��Խʪ��������ʲôҲû�з��֡�\n");
                if( query("forzen") <= 0 )
                    {
	              tell_object(me,"���������ϳ�����һ�����֣�����\n
����д�����������飬ͨ����������İ��أ���Ե����֮����֮��\n");
                      set("have",1);
                      jade=new("questobj/obj/tianshu");
                      jade->move(me);
                      destruct(this_object());
                      return 1;
  	             }
          }
	return 1;
}
