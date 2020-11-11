#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����", ({ "youling npc" }) );
        set("gender", "����");
        set("env/invisibility", 3);    
        set_skill("dodge", 500);
        set_skill("longfeng-xiang", 500);
        map_skill("dodge", "longfeng-xiang");       
        set("attitude", "friendly");
        set("location", 1);
        set_temp("apply/id", ({ "" }));
        set_temp("apply/short", ({""}));
        setup();
}

void do_setup(object me, object target)
{
        set("master", me);
        set("target", target);
        this_object()->set_leader(target);  
        this_object()->move(environment(target));  
        "/cmds/std/look"->look_room(this_object(), environment(target));  
        call_out("checking", 1, target);          
}

void do_remove()
{ 
   destruct(this_object());  
}

int checking(object target)
{
       object where, me;
       
       if(!objectp(me = query("master"))){
           destruct(this_object());  
           return 0;
        }
        
       if(!objectp(target) || !objectp(where = environment(target))){
       	   message("vision", BLU"\n�����顿��Ȼ�䣬һ���紵����������ε���Ӱ���٣�\n"NOR, environment(me));
           me->delete_temp("shenyou_npc");
           destruct(this_object());  
           return 0;
        }

       if(where != environment())
              this_object()->move(where);
       call_out("checking", 1, target);
       return 1;
}


void relay_message(string msgclass, string msg)
{
        object player, room;
        string *ary;
        int i;

        msg = "1\n"+ msg;
        ary = explode(msg, "\n");
        if(objectp(player = query("master")))
           room = environment(player);
        for (i=1;i<sizeof(ary);i++){
        	if( ary[i] == "" ||  ary[i] == " ") continue;
        	if (room) message("vision", BLU"�����顿"NOR+ary[i]+NOR+"\n", room);
        }
        
}
