// mask.c
// From SZ-ES2

inherit ITEM;
varargs int move(mixed dest, int silently);

void create()
{
        set_name("���", ({ "mask", "mian ju"  }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "���ƺ���һ������Ƥ�Ƴɵ���ߡ�����pretend����ʹ������\n");
                // set("no_drop", "�������������뿪�㡣\n");
        }

        // by micro : �����ŵ� ����֮��
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
                return notify_fail("�����װ˭��\n");

        // if (userp(this_player()) && !wizardp(this_player()))
        //         return notify_fail("ʲô��\n");
        if (arg == "none" || arg == "cancel") {
                this_player()->delete_temp("apply/name");
//change by chance,ԭ����ע�͵��ġ�
                this_player()->delete_temp("apply/id");
                this_player()->delete_temp("apply/short");
                this_player()->delete_temp("apply/long");
                this_player()->delete_temp("apply/gender");
                message_vision("$N������ȡ����һ����Ƥ��ߡ�\n", this_player());
                return 1;
        }
        if(!objectp(who = present(arg, environment(this_player()))) 
        ||      !living(who))
                return notify_fail("�����װ˭��\n");
        write("�㿪ʼ��װ" + who->name() + "��\n");
        message_vision("$N������һ�������Ƴɵ���Ƥ��ߡ�\n", this_player());
        this_player()->set_temp("apply/name", ({who->name()}));
//change by chance,ԭ����ע�͵��ġ�
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

//change by micro, �����·����󣬾Ͳ���������֮move
                if(!me)  return;
                
               me->delete_temp("apply/name");
                me->delete_temp("apply/id");
                me->delete_temp("apply/short");
                me->delete_temp("apply/long");
                me->delete_temp("apply/gender");
                message_vision("$N���ϵ���Ƥ��������������������ԭ�Ρ�\n", me);

}


