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

        if( !arg ) return notify_fail("你要捡起什麽东西？\n");
        if( me->is_busy() )
                return notify_fail("你上一个动作还没有完成！\n");

        // Check if a container is specified.
        if( sscanf(arg, "%s from %s", arg, from)==2 ) {
                env = present(from, me);
                if(!env) env = present(from, environment(me));
                if(!env) return notify_fail("你找不到 " + from + " 这样东西。\n");
                if( (env->query("no_get_from") || living(env) ) 
                        && (wiz_level(me) <= wiz_level(env)))
                        return notify_fail("你的巫师等级必须比对方高，才能搜身。\n");
        } else env = environment(me);

        // Check if a certain amount is specified.

        // add by Tiandi for limit get from corpse if the corpse is not belong to u.
        if (env->query_temp("killer")&&env->is_corpse()&&env->query_temp("killer")!= me->query("id")) {
                   if(!env->query_temp("corpseowner")){

                               return notify_fail("这具尸体不是你杀的。\n");
                               }else
                             {
message("system",HIC "\n【快乐风云】天神监督：自["+query_ip_name(me)+"]登录的"+me->query("name")+"("+ me->query("id") + ")拾取了"+env->name()+"中的东西！\n" NOR,users());
//write(HIC "\n【快乐风云】偷尸消息："+me->query("name")+"("+ me->query("id") + ")于["+query_ip_name(me)+"]处偷取了"+env->name()+"中的东西。\n" NOR,me);
                              }
                   }

        if(sscanf(arg, "%d %s", amount, item)==2) {
                if( !objectp(obj = present(item, env)) )
                        return notify_fail("这里没有这样东西。\n");
                if( !obj->query_amount() )
                        return notify_fail( obj->name() + "不能被分开拿走。\n");
                if( amount < 1 )
                        return notify_fail("东西的个数至少是一个。\n");
                if( amount > obj->query_amount() )
                        return notify_fail("这里没有那麽多的" + obj->name() + "。\n");
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
                if( me->is_fighting() ) return notify_fail("你还在战斗中！只能一次拿一样。\n");
                if( !env->query_max_encumbrance() )     return notify_fail("那不是容器。\n");
        if( env->is_tree() )
             return notify_fail("这是给新手活命用的，还是不要太贪心了吧n");
                inv = all_inventory(env);
                if( !sizeof(inv) )
        {
            if( env->is_tree() )
               return notify_fail("树上什么也没有了。\n");
                        return notify_fail("那里面没有任何东西。\n");
        }

                for(i=0; i<sizeof(inv); i++) {
                        if( inv[i]->is_character() || inv[i]->query("no_get") ) continue;
                        do_get(me, inv[i]);
                }
                write("捡好了。\n");
                return 1;
        }

        if( !objectp(obj = present(arg, env)) || living(obj) )
                return notify_fail("你附近没有这样东西。\n");

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
              return notify_fail("你只能背负其他玩家的身体。\n");
                // If we try to save someone from combat, take the risk :P
        } else {
               if( no_get = obj->query("no_get") )
              return notify_fail( stringp(no_get) ? no_get : "这样东西不能拣。\n");
        }

        if( guard = obj->query_temp("guarded") ) {
                guard = filter_array(guard, (:
                        objectp($1) && present($1, environment($2)) && living($1) && ($1!=$2)
                        :), me);
                if( sizeof(guard) )
                        return notify_fail( guard[0]->name() 
                                + "正守在" + obj->name() + "一旁，防止任何人拿走。\n");
        }

         if (obj->query_temp("killer")) {
                    if((obj->is_corpse()&&obj->query_temp("killer") != me->query("id")))
//                    (obj->is_corpse()&&obj->query_temp("corpseowner")!=" "&&obj->query_temp("corpseowner") != me->query("id")))
                    return notify_fail("这具尸体不是你杀的。\n");
}
        if( obj->query("equipped") ) equipped = 1;
        if( obj->move(me) ) {
                if( me->is_fighting() ) me->start_busy(1);
                if( obj->is_character() )
                        message_vision( "$N将$n扶了起来背在背上。\n", me, obj );
                else
                        message_vision( sprintf("$N%s一%s$n。\n", 
                
                                old_env==environment(me)? "捡起":
                                        (old_env->is_character() ?
                                                "从" + old_env->name() + "身上" + (equipped? "除下" : "搜出"):
                    (old_env->is_tree() ? "从" + old_env->name() +"上摘下" :
                                                "从" + old_env->name() + "中拿出") ),
                                obj->query("unit")), me, obj );
                return 1;
        }
        else return 0;
}

int help(object me)
{
        write(@HELP
指令格式 : get <物品名称> [from <容器名>]
 
这个指令可以让你捡起地上或容器内的某样物品.
 
HELP
    );
    return 1;
}
