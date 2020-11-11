#include <login.h>
#include <obj.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
        string wiz_status;
        object npc;
        if( me != this_player(1) ) return 0;
        wiz_status = SECURITY_D->get_status(me);
        if( wiz_status != "(admin)" && wiz_status != "(arch)" )
                    return notify_fail("只有 (admin) 的巫师才能重新启动" + MUD_NAME + "\n");
        seteuid(getuid());
        npc = new(NPC_DEMOGORGON);
        npc->move(START_ROOM);
        npc->start_shutdown();
        write("Ok。\n");
        return 1;
}
