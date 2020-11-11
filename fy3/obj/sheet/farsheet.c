// far-vision sheet.c

#include <ansi.h>
#define MAX_GUARD 4

inherit SHEET;

void create()
{
    set_name(YEL "��ͨ�۷�" NOR, ({ "far-vision sheet", "sheet"}) );
    set_weight(5);
    set("unit", "��");
    set("value", 0);
    setup();
}

int burn_function()
{ 
    object me=this_player();
    object obj;

    if( !objectp(query("targetname")) )
        return notify_fail("����������������\n");
    message_vision(
        "$N���о��񣬼�����ζ�������һ��" + name() +"����������\n", me);
    me->receive_damage("sen", 5);
    obj = query("targetname");

    if(!environment(obj)) {
        message("vision", "��е��۾�����ģ�ȴʲôҲû������\n", me);
    } else
    {
        message("vision", "����˸�Ļ���У��㿴����\n", me);
        "/cmds/std/look"->look_room(me, environment(obj));
        message("vision", "��е����ӷ������ڰ���������˫�۾������㣡\n", obj);
        message("vision", "����ϸ�ؿ���һ�����ܣ�ȴʲôҲû�У�\n", obj);
    }
    destruct(this_object());
    return 1;
}
