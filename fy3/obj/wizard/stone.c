// /obj/wizard/stone.c ʯͷһ�顣

#include <ansi.h>

inherit ITEM;

int do_ask(string arg);
int do_look(string arg);

int accept_object(object who, object item);

void create()
{
        set_name( MAG "ʯͷ" NOR, ({ "stone" }) );
        
        set("ask_time",0);        
        if( clonep()) 
                set_default_object(__FILE__);
        else {  

                set("long",
"һ��ǳ��ɫ��$MAG$ʯͷ$NOR$���ڱ�����·�ߣ�ɽ�ϣ��������ǣ�û��ʲô�ر�ġ�\n"
                );
                
                set("unit", "��");
                set("value", 0 );
        }


        setup();
}

void init()
{       
        add_action("do_ask", "ask");
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
              tell_object(this_player(),"ֻ�����ʯͷ�����������̹⣬������һ������᲻����Ǵ�˵�еĺ���赣�\n"
                             "�����������о�����˰ɡ�\n");
              return 1;
             }
          }
     return 0;
}


int do_ask(string arg)
{
       string dest,topic;
       object obj;

       if( !arg || sscanf(arg, "%s about %s", dest, topic)!=2 )
              return notify_fail("��Ҫ��˭ʲ���£�\n");

       if( !objectp(obj = present(dest, environment(this_player()))) )
		return notify_fail("����û������ˡ�\n");
       if (topic=="�����" && (obj->query("name")!="������ƹ�")) 
              {
              this_object()->add("ask_time",1);
               }
       return 0;

}
