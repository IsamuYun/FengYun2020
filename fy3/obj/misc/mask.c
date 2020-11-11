// mask.c
// From SZ-ES2

inherit ITEM;
varargs int move(mixed dest, int silently);

void create()
{
        set_name("面具", ({ "mask", "mian ju"  }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "这似乎是一个由人皮制成的面具。请用pretend命令使用它。\n");
                // set("no_drop", "这样东西不能离开你。\n");
        }

        // by micro : 将它放到 份人之后
        // call_out("disappear", 600);
       
        setup();
}

void init()
{
        add_action("do_pretend", "pretend");

}

int do_pretend(string arg)

{
        object who;
        if (!arg)
                return notify_fail("你想假装谁？\n");

        // if (userp(this_player()) && !wizardp(this_player()))
        //         return notify_fail("什么？\n");
        if (arg == "none" || arg == "cancel") {
                this_player()->delete_temp("apply/name");
//change by chance,原来是注释掉的。
                this_player()->delete_temp("apply/id");
                this_player()->delete_temp("apply/short");
                this_player()->delete_temp("apply/long");
                this_player()->delete_temp("apply/gender");
                message_vision("$N从脸上取下了一个人皮面具。\n", this_player());
                return 1;
        }
        if(!objectp(who = present(arg, environment(this_player()))) 
        ||      !living(who))
                return notify_fail("你想假装谁？\n");
        write("你开始假装" + who->name() + "。\n");
        message_vision("$N戴上了一个精功制成的人皮面具。\n", this_player());
        this_player()->set_temp("apply/name", ({who->name()}));
//change by chance,原来是注释掉的。
        this_player()->set_temp("apply/id", ({who->query("id")}));
        this_player()->set_temp("apply/short", ({who->short()}));
        this_player()->set_temp("apply/long", ({who->long()}));
//add by chance.
        this_player()->set_temp("apply/gender",who->query("gender"));

        
// add by micro        
        call_out("disappear", 600, this_player());


        return 1;
}

varargs int move(mixed dest, int silently)
{
     object thisplayer;
     thisplayer=environment(this_object());
     if( thisplayer) {
     if (thisplayer->query_temp("apply/name"))
          thisplayer->delete_temp("apply/name");
     if (thisplayer->query_temp("apply/id"))
          thisplayer->delete_temp("apply/id");
     if (thisplayer->query_temp("apply/short"))
          thisplayer->delete_temp("apply/short");
     if (thisplayer->query_temp("apply/long"))
          thisplayer->delete_temp("apply/long");
     if (thisplayer->query_temp("apply/gender"))
          thisplayer->delete_temp("apply/gender");
          }
     return ::move(dest,silently);
}

void disappear( object me )
{
/*
    object player,obj;
    obj=this_object();
    player=environment(obj);
    if (player->is_character()) 
         obj->move(environment(player));
    destruct(obj);
*/

//change by micro, 用以下方法后，就不再用以上之move
                if(!me)  return;
                
               me->delete_temp("apply/name");
                me->delete_temp("apply/id");
                me->delete_temp("apply/short");
                me->delete_temp("apply/long");
                me->delete_temp("apply/gender");
                message_vision("$N脸上的人皮面具脱落下来，慢慢变回原形。\n", me);

}


