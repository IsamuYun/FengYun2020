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
            return notify_fail("�����˭һ��˯��\n");
       if( !obj->is_character() )
            return notify_fail("���Դ���ë���ˣ�\n");
        if( !living(obj) )
            return notify_fail(obj->name() + "û������˯�ˡ�\n");

        if(me->query("gender")=="����")

        {
            tell_object(me, HIY "\n\n��§��"+obj->query("name")+
                "��������壬���ɵ�" + YEL"�������ԣ�����\n\n\n" NOR);
            tell_object(obj, HIY "\n\n������"+me->query("name")+
                "�Ļ�����ɵ��������ԣ�����\n\n\n" NOR);
        }
        else
        {
            tell_object(obj, HIY "\n\n��§��"+me->query("name")+
                "��������壬���ɵ�" + YEL"��������\n\n\n" NOR);
            tell_object(me, HIY "\n\n������"+obj->query("name")+
                "�Ļ�����ɵ��������ԣ�����\n\n\n" NOR);
        }
        {
            tell_object(obj, HIY "\n\n��§��"+me->query("name")+
                "��������壬���ɵ�" + YEL"��������\n\n\n" NOR);
            tell_object(me, HIY "\n\n������"+obj->query("name")+
                "�Ļ�����ɵ��������ԣ�����\n\n\n" NOR);
        }
        {
            tell_object(obj, HIY "\n\n��§��"+me->query("name")+
                "��������壬���ɵ�" + YEL"��������\n\n\n" NOR);
            tell_object(me, HIY "\n\n������"+obj->query("name")+
                "�Ļ�����ɵ��������ԣ�����\n\n\n" NOR);
        }
        {
            tell_object(obj, HIY "\n\n��§��"+me->query("name")+
                "��������壬���ɵ�" + YEL"��������. . .\n\n\n" NOR);
            tell_object(me, HIY "\n\n������"+obj->query("name")+
                "�Ļ�����ɵ��������ԣ�����\n\n\n" NOR);
        }
        {
            tell_object(obj, HIY "\n\n��§��"+me->query("name")+
                "��������壬���ɵ�" + YEL"��������. . .\n\n\n" NOR);
            tell_object(me, HIY "\n\n������"+obj->query("name")+
                "�Ļ�����ɵ��������ԣ�����\n\n\n" NOR);
        }
        {
            tell_object(obj, HIY "\n\n��§��"+me->query("name")+
                "��������壬���ɵ�" + YEL"��������. . .\n\n\n" NOR);
            tell_object(me, HIY "\n\n������"+obj->query("name")+
                "�Ļ�����ɵ��������ԣ�����\n\n\n" NOR);
        }
        {
            tell_object(obj, HIY "\n\n��§��"+me->query("name")+
                "��������壬���ɵ�" + YEL"��������. . .\n\n\n" NOR);
            tell_object(me, HIY "\n\n������"+obj->query("name")+
                "�Ļ�����ɵ��������ԣ�����\n\n\n" NOR);
        }
        {
            tell_object(obj, HIY "\n\n��§��"+me->query("name")+
                "��������壬���ɵ�" + YEL"��������. . .\n\n\n" NOR);
            tell_object(me, HIY "\n\n������"+obj->query("name")+
                "�Ļ�����ɵ��������ԣ�����\n\n\n" NOR);
        }
        {
            tell_object(obj, HIY "\n\n��§��"+me->query("name")+
                "��������壬���ɵ�" + YEL"��������. . .\n\n\n" NOR);
            tell_object(me, HIY "\n\n������"+obj->query("name")+
                "�Ļ�����ɵ��������ԣ�����\n\n\n" NOR);
        }
        {
            tell_object(obj, HIY "\n\n��§��"+me->query("name")+
                "��������壬���ɵ�" + YEL"��������. . .\n\n\n" NOR);
            tell_object(me, HIY "\n\n������"+obj->query("name")+
                "�Ļ�����ɵ��������ԣ�����\n\n\n" NOR);
        }
        me->set("last_sleep",time());
        obj->set("last_sleep",time());
        me->set_temp("block_msg/all",1);
        obj->set_temp("block_msg/all",1);
        message_vision(HIY "$N��$n���뱻�У�§��һ��˯���ˣ�����\n\n\n" NOR,me,obj);
        me->disable_player("<˯����>");
        obj->disable_player("<˯����>");;

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

        if(me->query("gender")=="����")
        {
            message_vision(HIY "$N���˹������ƺ����������Ҹ�֮�С�\n" NOR,me);
            me->set_temp("block_msg/all", 0);
            write("�����˹������ƺ����������Ҹ�֮�С�\n");
            return 1;
        }
        else
        {
// add bearing function here.
            message_vision(HIY "$N���˹��������ϻ��������۵�Ц�ݡ�\n" NOR,me);
            me->set_temp("block_msg/all", 0);
            write("�����˹��������ϻ��������۵�Ц�ݡ�\n");
            obj=slept;
            if((int)(me->query("mud_age")/8) < 1 || (int)(me->query("mud_age")/8) < me->query("child"))
                return 1;
            if (obj!=slept )
            {
                if (!obj || !userp(obj) || !find_player(obj->query("id")))
                {
                    message_vision(HIY "\n$N�ƺ����ø���һ���ʹ������ҧҧ����������վ��������\n"NOR, me);
                    write("\n�ɷ򶼲��ڣ���ôҲ���ܰѺ���������������\n");
                }
                else
                {
                    message_vision(HIY "\n$N�ƺ����ø���һ���ʹ�������ߺ�������ҧҧ��վ��������\n"NOR, me);
                    write("\n�ɷ򶼲��ڣ���ôҲ���ܰѺ���������������\n");
                    write("\n��ô������ײ���ˣ�������\n");
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
                    message_vision(HIY "\n$N��������һ�����������������ƽ��������\n"NOR,me);
                    return 1;
                }
                me->set_temp("is_bearing",1);
                me->start(100);
                obj->start(100);
                message_vision(HIY "\n$N��������һ��������Ͻ���ס$n���֣�����˵����Ҫ����! \n" NOR, me,obj);
                call_out("birth1",15,me,obj);
                return 3;
            }
        }
}

int birth1(object me,object obj)

{
    message_vision(HIY "\n$N���Ǵ����죬һֱ���ں������أ�˫�ֽ�����ס$n���ֲ��š�\n"+
        "\nӤ���Ѿ�̽����ͷ������\n"NOR,me,obj);
    call_out("birth2",15,me,obj);
    return 1;
}

void birth2(object me,object obj)
{
    object baby;
    int number;
    message_vision(HIY "\n���ۡ���������Ӥ�������ˣ�\n"+
        "\n$N��ɫ�԰ף�б���ڴ�ͷ���������������¶��һ˿΢Ц��\n"NOR, me);
    me->start_busy(20);
    me->set("sen",0);
    me->set("kee",0);
    me->set("gin",0);
    baby=new("/obj/npc/baby");
    baby->set("long", baby->query("long")+"����"+obj->query("name")+"��"+me->query("name")+"�ĺ��ӡ�\n");
    if (random(100)<50)
    {
        baby->set("gender","����");
        baby->set_name("С"+obj->query("name"),({"xiao "+obj->query("id"),"baby"}));
    }
    else
    {
        baby->set("gender","Ů��");
       baby->set_name("С"+me->query("name"),({"xiao "+me->query("id"),"baby"}));
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
ָ���ʽ : sleepwith <����>

����˼�壬���ָ���������ɻ��µġ�
HELP
    );
    return 1;
}
