// yiru@hero
// ˮ�·���
// position.c

// NAME  ������
// FILE  ���ļ���
// LEVEL ����Ҫ�ĵȼ�
// COST1 �Ǻ�����������������������
// COST2 �Ǻľ�������Ѫ�����������

#define NAME  "������"
#define FILE  "/obj/sheet/curesheet"
#define LEVEL 60
#define COST1 15
#define COST2 30

// ���´���ȫ���ظ����롣hehe

inherit F_CLEAN_UP;

int scribe(object me, object sheet, string arg)
{
    object newsheet;

    if((int)me->query_skill("scratching") < LEVEL )
        return notify_fail("��ķ�֮�������ߣ�\n");

    if( sheet->name() != "�ҷ�ֽ" )
        return notify_fail( NAME "Ҫ�����ҷ�ֽ�ϣ�\n");

    if( (int)me->query("atman") < COST1 ) 
        return notify_fail("������������ˣ�\n");
    if( (int)me->query("force") < COST1 ) 
        return notify_fail("������������ˣ�\n");
    if( (int)me->query("mana") < COST1 ) 
        return notify_fail("��ķ��������ˣ�\n");

    sheet->add_amount(-1);
    seteuid( geteuid(me));
    newsheet = new(FILE);
    if(newsheet){
        newsheet->move(me);
        message_vision("$Nд��һ��$n��\n", me, newsheet);
    }else{
        tell_object(me, "д�������ˣ���֪ͨ����Ա���ļ�����"FILE"��\n");
    }
    me->add("atman", -COST1);
    me->add("force", -COST1);
    me->add("mana", -COST1);
    me->receive_damage("gin", COST2);
    me->receive_damage("kee", COST2);
    me->receive_damage("sen", COST2);
    return 1;
}
