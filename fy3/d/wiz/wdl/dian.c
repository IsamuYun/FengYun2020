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
                return notify_fail("�����˭��Ѩ��\n");

        if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("����û������ˡ�\n");

        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

        if( !userp(obj))
                return notify_fail("��Ǹ����ֻ�ɵ���ҵ�Ѩ��\n");

        if(obj==me)
                return notify_fail("������ָ���Լ������Ҵ�һ��....\n");

        callname = RANK_D->query_rude(obj);
        message_vision(HIY"\n\n\n$NͻȻ������磬����$n����ʮ�ദ��Ѩ��$n˫��һ���Ե��ڵأ�\n"NOR, me, obj);
        message_vision(HIY"\n$n�ھ������ŭ��˻�����У�������û�����ü���!\n"NOR, me, obj);
         if (obj->query("gender") == "����")
        message_vision(HIY"\n\n\n$N������Ц������$n��������������....\n\n"NOR, me, obj);

        obj->unconcious();

        if (obj->query("gender") == "Ů��")
     {  
       room = find_object("/d/qianjin/troom");
       if(!objectp(room)) room=load_object("/d/qianjin/troom");
            obj->move(room);
            obj->set("startroom",base_name(room));
     message_vision(HIW"\nǧ��¥�Ĺ�ū�ֵߵߵشӰ������˳���������������$N�ļ�����������!\n\n��ū͵͵����$Nһ����Ʊ!�������ְ˽ŵذ�$n����һֻ�󲼴���Ҵ�ææ��̧����.....\n\n"NOR, me, obj);           
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
ָ���ʽ : dian <����>
 
���ָ���������һ�������Ѩ����������Է���Ů�ԣ���������ǧ��¥��
HELP
    );
    return 1;
}
