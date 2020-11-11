//dian.c
//by ken 1999.11.30

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object obj;
        object room;
        object sellgold; 
        string *killer, callname;
        seteuid(getuid());
        if( !arg )
                return notify_fail("你想点谁的穴？\n");

        if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("这里没有这个人。\n");

        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("看清楚一点，那并不是活物。\n");

        if( !userp(obj))
                return notify_fail("报歉，你只可点玩家的穴。\n");

        if(obj==me)
                return notify_fail("你用手指在自己身上乱戳一气....\n");

        callname = RANK_D->query_rude(obj);
        message_vision(HIY"\n\n\n$N突然出手如风，连点$n周身十余处大穴！$n双腿一软，栽倒在地！\n"NOR, me, obj);
        message_vision(HIY"\n$n在惊恐与愤怒中嘶声喊叫，但是再没人听得见了!\n"NOR, me, obj);
         if (obj->query("gender") == "男性")
        message_vision(HIY"\n\n\n$N满面狞笑，对着$n慢慢地弯下腰来....\n\n"NOR, me, obj);

        obj->unconcious();

        if (obj->query("gender") == "女性")
     {  
       room = find_object("/d/qianjin/troom");
       if(!objectp(room)) room=load_object("/d/qianjin/troom");
            obj->move(room);
            obj->set("startroom",base_name(room));
     message_vision(HIW"\n千金楼的龟奴乐颠颠地从暗处跑了出来，大力地拍着$N的肩膀道：辛苦了!\n\n龟奴偷偷塞给$N一张银票!接着七手八脚地把$n塞进一只大布袋里，匆匆忙忙地抬走了.....\n\n"NOR, me, obj);           
            sellgold = new("obj/money/thousand-cash");
       sellgold->move(me);
       me->add("score",-50);
        return 1;
      }
        return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : dian <人物>
 
这个指令让你点中一个人物的穴道，并且如对方是女性，还可卖入千金楼。
HELP
    );
    return 1;
}
