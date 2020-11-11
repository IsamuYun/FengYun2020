#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"无字天书"NOR, ({ "tianshu" }) );
    set("forzen",5);
    set("have",0);
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "本");
            set("material", "paper");
            set("long", "这是一本没人能看懂的天书，翻完整本书，你竟然连一个字都找不着。
突然你灵机一动，应该滴（ｄｉ）些热水在它的上面试一试。\n");
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
               return notify_fail("你要滴什么？\n");
	    if(!objectp(con=present(arg, me)))
	       return notify_fail("你身上没有这样东西。\n");
	    if(!con->query("liquid"))
       return notify_fail( con->name() +"不是液体，不能往纸上滴。\n");
	    if(!con->query("liquid/remaining"))
	       return notify_fail( con->name() + "是空的。\n");
	    con->add("liquid/remaining", -1);
            message_vision("$N拿起" + con->name() + "滴了几滴" +
	    con->query("liquid/name")  + "在无字天书上。\n",me);
	    if(con->query("liquid/name") == "热水")	
	        {
	          tell_object(me,"无字天书上出现了几个字！！\n");
                  add("forzen",-1);
	        }
            else
                tell_object(me,"无字天书越来越湿，不过你什么也没有发现。\n");
                if( query("forzen") <= 0 )
                    {
	              tell_object(me,"无字天书上出现了一段文字．．．\n
上面写道：无字天书，通晓宇宙万物的奥秘，有缘者慎之，谨之。\n");
                      set("have",1);
                      jade=new("questobj/obj/tianshu");
                      jade->move(me);
                      destruct(this_object());
                      return 1;
  	             }
          }
	return 1;
}
