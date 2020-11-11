//»¶ÀÖÓ¢ÐÛ
//±ê×¼Ò©º¯Êý receive.c
//created by lion@hero

#include <ansi.h>
#include <condition.h>

int update_condition(object me, mapping info)
{
        if( !mapp(info) ) return 0;
        if( info["duration"] < 1 ) return 0;
        if( (int)me->query("eff_kee") < (int)me->query("max_kee") 
          ||(int)me->query("eff_gin") < (int)me->query("max_gin")
          ||(int)me->query("eff_sen") < (int)me->query("max_sen")  
        ){
        me->receive_curing("gin", info["gin_curing"]);
        me->receive_curing("kee", info["kee_curing"]);
        me->receive_curing("sen", info["sen_curing"]); 
        }
        else{
        me->add("gin",info["gin_curing"]);
        me->add("kee",info["kee_curing"]);
        me->add("sen",info["sen_curing"]);
        }
        tell_object(me, info["message"]+NOR );
        info["duration"] --;
        return CND_CONTINUE;
}

string query_type() { return "receive"; }
