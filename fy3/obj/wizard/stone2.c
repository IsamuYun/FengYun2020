// /obj/wizard/stone.c 石头一块。

#include <ansi.h>

inherit ITEM;

int do_ask(string arg);
int do_look(string arg);

int accept_object(object who, object item);

void create()
{
        set_name( MAG "石头" NOR, ({ "stone" }) );
        
        set("ask_time",0);        
        if( clonep()) 
                set_default_object(__FILE__);
        else {  

                set("long",
"一块浅绿色的$MAG$石头$NOR$，在北方的路边，山上，到处都是，没有什么特别的。\n"
                );
                
                set("unit", "块");
                set("value", 0 );
        }


        setup();
}

void init()
{       
//        add_action("do_ask", "ask");
        add_action("do_look","look");
}
int do_look(string arg)
{
     object obj;
     if( !arg ) return 0;
     obj=present(arg,this_player());
     if (obj !=this_object() ) return 0;
     else {
         if (random(3)==1)
            {
              tell_object(this_player(),"只见这块石头泛出淡淡的绿光，你心念一动：这会不会就是传说中的和氏璧？\n"
                             "不如先问问有经验的人吧。\n");
              return 1;
             }
          }
     return 0;
}

/*
int do_ask(string arg)
{
       string dest,topic;
       object obj;

       if( !arg || sscanf(arg, "%s about %s", dest, topic)!=2 )
              return notify_fail("你要问谁什麽事？\n");

       if( !objectp(obj = present(dest, environment(this_player()))) )
		return notify_fail("这里没有这个人。\n");
       if (topic=="和氏璧" && (obj->query("name")!="古玩店掌柜")) 
              {
              this_object()->add("ask_time",1);
               }
       return 0;

}
*/
