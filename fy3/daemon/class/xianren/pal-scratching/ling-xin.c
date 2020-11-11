// ling-xin.c
// yiru@hero
// bug-free version of sheet, ^_^

inherit F_CLEAN_UP;

int scribe(object me, object sheet, string arg)
{
    object newsheet;
    string err;
    int lvl;

    lvl = me->query_skill("scratching");
    if( lvl < 90 )
        return notify_fail("��ķ�֮�������ߣ�\n");

    if( sheet->name() != "�ҷ�ֽ" )
        return notify_fail("���ķ�Ҫ�����ҷ�ֽ�ϣ�\n");

    if( (int)me->query("atman") < 180 ) 
        return notify_fail("������������ˣ�\n");

    sheet->add_amount(-1);
    seteuid( geteuid(me));

    newsheet = new("/obj/sheet/lingxinfu");

    if(newsheet)
        newsheet->move(me);
    else
        return notify_fail("���� /obj/sheet/lingxinfu ������֪ͨ����Ա��\n");

    newsheet->set("level", lvl);
    me->add("atman", -120);
    me->receive_damage("gin", 60);
    message_vision("$Nд��һ��$n��\n", me, newsheet);
    return 1;
}
