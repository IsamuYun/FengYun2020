// earth-warp sheet.c

inherit SHEET;

#include <ansi.h>
#include <login.h>

void create()
{
    set_name(YEL "���紫�ͷ�" NOR, ({ "earth-warp sheet", "sheet"}) );
    set_weight(5);
    set("unit", "��");
    set("value", 0);
    setup();
}

int burn_function()
{
    object me = this_player();
    object env;

    env = environment(me);

    if(me->is_fighting())
        return notify_fail("ս���в���ʹ�����紫�ͷ���\n");

    me->start_busy(random(3)+1);
    message_vision(
        HIB "$N����һ�����紫�ͷ���\n"
        "��Ȼ���ܴ�����һ�����쬵����磬����֮���ݷ��������Ӱ�ڻζ�...\n"
        "Ȼ��һ����ͻȻ����\n" NOR, me);

    message("vision", 
        "����...." + me->name() + "�Ѿ������ˡ�\n"
        , env, ({ me }));

    tell_object(me,
        CYN "��ֻ�������Ӳ�����׹��һֱ��׹��һֱ��׹��һֱ��׹��һֱ��׹ .....\n"
        NOR "��֪��ʲ��ʱ���㷢������ʵһֱ��վ�ڼ�Ӳ�ĵ����ϣ��������ܵľ���\n"
        "ȴ��һ����....\n");

    me->move(DEATH_ROOM);

    destruct(this_object());

    return 1;
}
