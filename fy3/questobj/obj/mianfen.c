#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"面粉"NOR, ({ "mian" }) );
    set("forzen",5);
    set("have",0);
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "瓶");
            set("material", "wood");
            set("long", "这是一小瓶面粉。\n");
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
               return notify_fail("你要和什么？\n");
	    if(!objectp(con=present(arg, me)))
	       return notify_fail("你身上没有这样东西。\n");
	    if(!con->query("liquid"))
	       return notify_fail( con->name() +"不是液体，不能用来和浆糊。\n");
	    if(!con->query("liquid/remaining"))
	       return notify_fail( con->name() + "是空的。\n");
	    con->add("liquid/remaining", -1);
            message_vision("$N将" + con->name() + "的" +
	    con->query("liquid/name")  + "倒进面粉瓶里晃了几下。\n",me);
	    if(con->query("liquid/name") == "热水")	
	        {
	          tell_object(me,"好象水太少了！！\n");
                  add("forzen",-1);
	        }
            else
                tell_object(me,"好象没什么反应。\n");
                if( query("forzen") <= 0 )
                    {
	              tell_object(me,"你和出了一小瓶浆糊。\n");
                      set("have",1);
                      jade=new("questnew/obj/jianghu");
                      jade->move(me);
                      destruct(this_object());
                      return 1;
  	             }
          }
	return 1;
}
