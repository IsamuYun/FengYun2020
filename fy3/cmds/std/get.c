// Filename : /cmds/std/get.c
//modify by atu for LSFY 2000/01/15
#include <ansi.h>

inherit F_CLEAN_UP;

int do_get(object me, object ob);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        string from, item;
        object obj, *inv, env, obj2;
        int i, amount;

        if( !arg ) return notify_fail("��Ҫ����ʲ�ᶫ����\n");
        if( me->is_busy() )
                return notify_fail("����һ��������û����ɣ�\n");

        // Check if a container is specified.
        if( sscanf(arg, "%s from %s", arg, from)==2 ) {
                env = present(from, me);
                if(!env) env = present(from, environment(me));
                if(!env) return notify_fail("���Ҳ��� " + from + " ����������\n");
                if( (env->query("no_get_from") || living(env) ) 
                        && (wiz_level(me) <= wiz_level(env)))
                        return notify_fail("�����ʦ�ȼ�����ȶԷ��ߣ���������\n");
        } else env = environment(me);

        // Check if a certain amount is specified.

        // add by Tiandi for limit get from corpse if the corpse is not belong to u.
        if (env->query_temp("killer")&&env->is_corpse()&&env->query_temp("killer")!= me->query("id")) {
                   if(!env->query_temp("corpseowner")){

                               return notify_fail("���ʬ�岻����ɱ�ġ�\n");
                               }else
                             {
message("system",HIC "\n�����ַ��ơ�����ල����["+query_ip_name(me)+"]��¼��"+me->query("name")+"("+ me->query("id") + ")ʰȡ��"+env->name()+"�еĶ�����\n" NOR,users());
//write(HIC "\n�����ַ��ơ�͵ʬ��Ϣ��"+me->query("name")+"("+ me->query("id") + ")��["+query_ip_name(me)+"]��͵ȡ��"+env->name()+"�еĶ�����\n" NOR,me);
                              }
                   }

        if(sscanf(arg, "%d %s", amount, item)==2) {
                if( !objectp(obj = present(item, env)) )
                        return notify_fail("����û������������\n");
                if( !obj->query_amount() )
                        return notify_fail( obj->name() + "���ܱ��ֿ����ߡ�\n");
                if( amount < 1 )
                        return notify_fail("�����ĸ���������һ����\n");
                if( amount > obj->query_amount() )
                        return notify_fail("����û��������" + obj->name() + "��\n");
                else if( amount == (int)obj->query_amount() ) {
                        return do_get(me, obj);
                } else {
                        i=(int)obj->query_amount();
                        obj->set_amount(amount);
                        obj2 = new(base_name(obj));
                        obj2->set_amount( i- amount);
                        obj2->move(env);                        // For containers.
                        // Counting precise amount costs more time.
                        if( me->is_fighting() ) me->start_busy(3);
                        return do_get(me, obj);
                }
        }

        // Check if we are makeing a quick get.
        if(arg=="all") {
                if( me->is_fighting() ) return notify_fail("�㻹��ս���У�ֻ��һ����һ����\n");
                if( !env->query_max_encumbrance() )     return notify_fail("�ǲ���������\n");
        if( env->is_tree() )
             return notify_fail("���Ǹ����ֻ����õģ����ǲ�Ҫ̫̰���˰ɣ\n");
                inv = all_inventory(env);
                if( !sizeof(inv) )
        {
            if( env->is_tree() )
               return notify_fail("����ʲôҲû���ˡ�\n");
                        return notify_fail("������û���κζ�����\n");
        }

                for(i=0; i<sizeof(inv); i++) {
                        if( inv[i]->is_character() || inv[i]->query("no_get") ) continue;
                        do_get(me, inv[i]);
                }
                write("����ˡ�\n");
                return 1;
        }

        if( !objectp(obj = present(arg, env)) || living(obj) )
                return notify_fail("�㸽��û������������\n");

        return do_get(me, obj);  
}
        
int do_get(object me, object obj)
{
        object old_env, *guard;
        int equipped;
       mixed no_get;

        if( !obj ) return 0;
        old_env = environment(obj);

        if( obj->is_character() ) {
                if( living(obj) ) return 0;
        if( !userp(obj) && !obj->is_corpse() )
              return notify_fail("��ֻ�ܱ���������ҵ����塣\n");
                // If we try to save someone from combat, take the risk :P
        } else {
               if( no_get = obj->query("no_get") )
              return notify_fail( stringp(no_get) ? no_get : "�����������ܼ�\n");
        }

        if( guard = obj->query_temp("guarded") ) {
                guard = filter_array(guard, (:
                        objectp($1) && present($1, environment($2)) && living($1) && ($1!=$2)
                        :), me);
                if( sizeof(guard) )
                        return notify_fail( guard[0]->name() 
                                + "������" + obj->name() + "һ�ԣ���ֹ�κ������ߡ�\n");
        }

         if (obj->query_temp("killer")) {
                    if((obj->is_corpse()&&obj->query_temp("killer") != me->query("id")))
//                    (obj->is_corpse()&&obj->query_temp("corpseowner")!=" "&&obj->query_temp("corpseowner") != me->query("id")))
                    return notify_fail("���ʬ�岻����ɱ�ġ�\n");
}
        if( obj->query("equipped") ) equipped = 1;
        if( obj->move(me) ) {
                if( me->is_fighting() ) me->start_busy(1);
                if( obj->is_character() )
                        message_vision( "$N��$n�����������ڱ��ϡ�\n", me, obj );
                else
                        message_vision( sprintf("$N%sһ%s$n��\n", 
                
                                old_env==environment(me)? "����":
                                        (old_env->is_character() ?
                                                "��" + old_env->name() + "����" + (equipped? "����" : "�ѳ�"):
                    (old_env->is_tree() ? "��" + old_env->name() +"��ժ��" :
                                                "��" + old_env->name() + "���ó�") ),
                                obj->query("unit")), me, obj );
                return 1;
        }
        else return 0;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : get <��Ʒ����> [from <������>]
 
���ָ��������������ϻ������ڵ�ĳ����Ʒ.
 
HELP
    );
    return 1;
}
