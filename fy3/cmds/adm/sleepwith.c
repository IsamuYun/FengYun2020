// sleep.c;
// Dec.11 1997 by Venus
#include <ansi.h>;
void wakeup(object me, object where);
int wakeup2(object me,object slept,object where);
int birth1(object me,object obj);
void birth2(object me, object where);
void del_sleeped(object me);

int main(object me, string arg)
{
        object obj, old_target;
        int i;
        object *inv;
        mapping fam;
        object where = environment(me);

        seteuid(getuid());

       if(!objectp(obj = present(arg, where)))
            return notify_fail("你想跟谁一起睡？\n");
       if( !obj->is_character() )
            return notify_fail("？脑袋出毛病了？\n");
        if( !living(obj) )
            return notify_fail(obj->name() + "没法跟你睡了。\n");

        if(me->query("gender")=="男性")

        {
            tell_object(me, HIY "\n\n你搂着"+obj->query("name")+
                "温软的身体，不由得" + YEL"心醉神迷．．．\n\n\n" NOR);
            tell_object(obj, HIY "\n\n你躺在"+me->query("name")+
                "的怀里，不由得心醉神迷．．．\n\n\n" NOR);
        }
        else
        {
            tell_object(obj, HIY "\n\n你搂着"+me->query("name")+
                "温软的身体，不由得" + YEL"心醉神迷\n\n\n" NOR);
            tell_object(me, HIY "\n\n你躺在"+obj->query("name")+
                "的怀里，不由得心醉神迷．．．\n\n\n" NOR);
        }
        {
            tell_object(obj, HIY "\n\n你搂着"+me->query("name")+
                "温软的身体，不由得" + YEL"心醉神迷\n\n\n" NOR);
            tell_object(me, HIY "\n\n你躺在"+obj->query("name")+
                "的怀里，不由得心醉神迷．．．\n\n\n" NOR);
        }
        {
            tell_object(obj, HIY "\n\n你搂着"+me->query("name")+
                "温软的身体，不由得" + YEL"心醉神迷\n\n\n" NOR);
            tell_object(me, HIY "\n\n你躺在"+obj->query("name")+
                "的怀里，不由得心醉神迷．．．\n\n\n" NOR);
        }
        {
            tell_object(obj, HIY "\n\n你搂着"+me->query("name")+
                "温软的身体，不由得" + YEL"心醉神迷. . .\n\n\n" NOR);
            tell_object(me, HIY "\n\n你躺在"+obj->query("name")+
                "的怀里，不由得心醉神迷．．．\n\n\n" NOR);
        }
        {
            tell_object(obj, HIY "\n\n你搂着"+me->query("name")+
                "温软的身体，不由得" + YEL"心醉神迷. . .\n\n\n" NOR);
            tell_object(me, HIY "\n\n你躺在"+obj->query("name")+
                "的怀里，不由得心醉神迷．．．\n\n\n" NOR);
        }
        {
            tell_object(obj, HIY "\n\n你搂着"+me->query("name")+
                "温软的身体，不由得" + YEL"心醉神迷. . .\n\n\n" NOR);
            tell_object(me, HIY "\n\n你躺在"+obj->query("name")+
                "的怀里，不由得心醉神迷．．．\n\n\n" NOR);
        }
        {
            tell_object(obj, HIY "\n\n你搂着"+me->query("name")+
                "温软的身体，不由得" + YEL"心醉神迷. . .\n\n\n" NOR);
            tell_object(me, HIY "\n\n你躺在"+obj->query("name")+
                "的怀里，不由得心醉神迷．．．\n\n\n" NOR);
        }
        {
            tell_object(obj, HIY "\n\n你搂着"+me->query("name")+
                "温软的身体，不由得" + YEL"心醉神迷. . .\n\n\n" NOR);
            tell_object(me, HIY "\n\n你躺在"+obj->query("name")+
                "的怀里，不由得心醉神迷．．．\n\n\n" NOR);
        }
        {
            tell_object(obj, HIY "\n\n你搂着"+me->query("name")+
                "温软的身体，不由得" + YEL"心醉神迷. . .\n\n\n" NOR);
            tell_object(me, HIY "\n\n你躺在"+obj->query("name")+
                "的怀里，不由得心醉神迷．．．\n\n\n" NOR);
        }
        {
            tell_object(obj, HIY "\n\n你搂着"+me->query("name")+
                "温软的身体，不由得" + YEL"心醉神迷. . .\n\n\n" NOR);
            tell_object(me, HIY "\n\n你躺在"+obj->query("name")+
                "的怀里，不由得心醉神迷．．．\n\n\n" NOR);
        }
        me->set("last_sleep",time());
        obj->set("last_sleep",time());
        me->set_temp("block_msg/all",1);
        obj->set_temp("block_msg/all",1);
        message_vision(HIY "$N和$n钻入被中，搂在一起睡着了．．．\n\n\n" NOR,me,obj);
        me->disable_player("<睡梦中>");
        obj->disable_player("<睡梦中>");;

        call_out("wakeup2",random(4 - me->query("con")) + 1, me,obj, where);
        call_out("wakeup2",random(4 - obj->query("con")) + 1, obj, me,where);

        return 1;

}
int wakeup2(object me,object slept,object where)
{
        int kee_cost;
        object obj;

        me->set("kee",    me->query("max_kee"));
        me->set("gin",  me->query("max_gin"));
        me->add("sen", me->query("max_sen"));
        me->enable_player();
        kee_cost=500+5*((int)me->query("str")-(int)me->query("con"));
        if(kee_cost>(int)me->query("max_kee")/20)
            kee_cost=(int)me->query("max_kee")/20+1;
        me->add("kee", -kee_cost);
        if (me->query("kee") <= 0) me->set("kee", 10);

        while( environment(me)->is_character() )
        me->move(environment(environment(me)));

        if(me->query("gender")=="男性")
        {
            message_vision(HIY "$N醒了过来，似乎还沉浸在幸福之中。\n" NOR,me);
            me->set_temp("block_msg/all", 0);
            write("你醒了过来，似乎还沉浸在幸福之中。\n");
            return 1;
        }
        else
        {
// add bearing function here.
            message_vision(HIY "$N醒了过来，脸上还挂着甜蜜的笑容。\n" NOR,me);
            me->set_temp("block_msg/all", 0);
            write("你醒了过来，脸上还挂着甜蜜的笑容。\n");
            obj=slept;
            if((int)(me->query("mud_age")/8) < 1 || (int)(me->query("mud_age")/8) < me->query("child"))
                return 1;
            if (obj!=slept )
            {
                if (!obj || !userp(obj) || !find_player(obj->query("id")))
                {
                    message_vision(HIY "\n$N似乎觉得腹中一阵颤痛，旋即咬咬牙，弯着腰站了起来。\n"NOR, me);
                    write("\n丈夫都不在，怎么也不能把孩子生下来．．．\n");
                }
                else
                {
                    message_vision(HIY "\n$N似乎觉得腹中一阵颤痛，旋即羞红着脸，咬咬牙站了起来。\n"NOR, me);
                    write("\n丈夫都不在，怎么也不能把孩子生下来．．．\n");
                    write("\n怎么会让他撞上了？．．．\n");
                }
                me->set("sen", me->query("sen")/100);
                me->set("kee", me->query("kee")/100);
                me->set("gin", me->query("gin")/100);
                return 2;
            }
            else
            {
                if((int)(me->query("mud_age")/5) < 1 || (int)(me->query("mud_age")/5) < me->query("child"))
                {
                    message_vision(HIY "\n$N忽觉腹中一阵颤动，不过马上又平静下来。\n"NOR,me);
                    return 1;
                }
                me->set_temp("is_bearing",1);
                me->start(100);
                obj->start(100);
                message_vision(HIY "\n$N忽觉腹中一阵颤动，赶紧拉住$n的手，柔声说道：要生了! \n" NOR, me,obj);
                call_out("birth1",15,me,obj);
                return 3;
            }
        }
}

int birth1(object me,object obj)

{
    message_vision(HIY "\n$N已是大汗淋漓，一直都在呼天抢地，双手紧紧扣住$n的手不放。\n"+
        "\n婴儿已经探出了头．．．\n"NOR,me,obj);
    call_out("birth2",15,me,obj);
    return 1;
}

void birth2(object me,object obj)
{
    object baby;
    int number;
    message_vision(HIY "\n「哇」．．．，婴儿出世了！\n"+
        "\n$N面色苍白，斜倚在床头，看看孩子满意地露出一丝微笑。\n"NOR, me);
    me->start_busy(20);
    me->set("sen",0);
    me->set("kee",0);
    me->set("gin",0);
    baby=new("/obj/npc/baby");
    baby->set("long", baby->query("long")+"这是"+obj->query("name")+"和"+me->query("name")+"的孩子。\n");
    if (random(100)<50)
    {
        baby->set("gender","男性");
        baby->set_name("小"+obj->query("name"),({"xiao "+obj->query("id"),"baby"}));
    }
    else
    {
        baby->set("gender","女性");
       baby->set_name("小"+me->query("name"),({"xiao "+me->query("id"),"baby"}));
    }
    me->add("child",1);
    obj->add("child",1);
    baby->set("parents",({me->query("id"),obj->query("id")}));
    number=me->query("child");
    me->set("child_"+number+"/gender",baby->query("gender"));
    me->set("child_"+number+"/long",baby->query("long"));
    me->set("child_"+number+"/name",baby->query("name"));
    me->set("child_"+number+"/id",({baby->query("id"),"baby"}));
    me->set("child_"+number+"/parents",baby->query("parents"));
    number=obj->query("child");
    obj->set("child_"+number+"/gender",baby->query("gender"));
    obj->set("child_"+number+"/long",baby->query("long"));
    obj->set("child_"+number+"/name",baby->query("name"));
    obj->set("child_"+number+"/id",({baby->query("id"),"baby"}));
    obj->set("child_"+number+"/parents",baby->query("parents"));
    me->delete_temp("is_bearing");
    me->save();
    obj->save();
   //this needs to be put at the last since
   //can only move the baby after it's parameters are set.
    if(!baby->move(environment(me)))
        baby->move(environment(environment(me)));
}

void del_sleeped(object me)
{
        if (objectp(me) &&  me->query_temp("sleeped"))
                me->delete_temp("sleeped");
}
int help(object me)
{
  write(@HELP
指令格式 : sleepwith <人物>

顾名思义，这个指令是用来干坏事的。
HELP
    );
    return 1;
}
