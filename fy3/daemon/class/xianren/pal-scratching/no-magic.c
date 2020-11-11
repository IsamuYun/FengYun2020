// no-magic.c
// yiru@hero
// bug-free version of sheet, ^_^

inherit F_CLEAN_UP;

int scribe(object me, object sheet, string arg)
{
    object newsheet;
    string err;
    int lvl;

    lvl = me->query_skill("scratching");
    if( lvl < 300 )
        return notify_fail("你的符之术不够高！\n");

    if( sheet->name() != "桃符纸" )
        return notify_fail("醉仙封魔符要画在桃符纸上！\n");

    if( (int)me->query("atman") < 300 ) 
        return notify_fail("你的灵力不够了！\n");

    sheet->add_amount(-1);
    seteuid( geteuid(me));

    newsheet = new("/obj/sheet/nomagicfu");

    if(newsheet)
        newsheet->move(me);
    else
        return notify_fail("程序 /obj/sheet/nomagicfu 出错，请通知管理员！\n");

    newsheet->set("level", lvl);
    me->add("atman", -300);
    me->receive_damage("gin", 300);
    message_vision("$N写了一道$n。\n", me, newsheet);
    return 1;
}
