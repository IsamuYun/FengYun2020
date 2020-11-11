// yiru@hero
// 水月符法
// position.c

// NAME  是名字
// FILE  是文件名
// LEVEL 是需要的等级
// COST1 是耗灵力、内力、法力的数量
// COST2 是耗精力、气血、心神的数量

#define NAME  "观音符"
#define FILE  "/obj/sheet/curesheet"
#define LEVEL 60
#define COST1 15
#define COST2 30

// 以下代码全是重复代码。hehe

inherit F_CLEAN_UP;

int scribe(object me, object sheet, string arg)
{
    object newsheet;

    if((int)me->query_skill("scratching") < LEVEL )
        return notify_fail("你的符之术不够高！\n");

    if( sheet->name() != "桃符纸" )
        return notify_fail( NAME "要画在桃符纸上！\n");

    if( (int)me->query("atman") < COST1 ) 
        return notify_fail("你的灵力不够了！\n");
    if( (int)me->query("force") < COST1 ) 
        return notify_fail("你的内力不够了！\n");
    if( (int)me->query("mana") < COST1 ) 
        return notify_fail("你的法力不够了！\n");

    sheet->add_amount(-1);
    seteuid( geteuid(me));
    newsheet = new(FILE);
    if(newsheet){
        newsheet->move(me);
        message_vision("$N写了一道$n。\n", me, newsheet);
    }else{
        tell_object(me, "写符出错了！请通知管理员，文件名："FILE"。\n");
    }
    me->add("atman", -COST1);
    me->add("force", -COST1);
    me->add("mana", -COST1);
    me->receive_damage("gin", COST2);
    me->receive_damage("kee", COST2);
    me->receive_damage("sen", COST2);
    return 1;
}
