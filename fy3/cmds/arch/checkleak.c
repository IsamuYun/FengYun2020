#include <combat.h>
#include <ansi.h>
#define SYNTAX	"指令格式：gq <dir>\n"
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	int i;
	string direc,*dir, roomname;
	string status;
	object room;
        if(!me->query("env/yesiknow")) return notify_fail("这个指令已经被废除了！\n");
	status = wizhood(me);
	if( me!=this_player(1)
	|| wiz_level(me) < wiz_level(status) )
		return notify_fail("你没有权力使用这个指令。\n");
	if( !arg ) return notify_fail(SYNTAX);
	if( sscanf(arg, "%s", direc)!=1 )
		return notify_fail(SYNTAX);
	seteuid(getuid());
	dir = get_dir(arg+"/");
        for(i=0; i<sizeof(dir); i++) {
	if( sscanf(dir[i],"%s.c", roomname) != 1) continue;
	if( room = find_object(arg+"/"+roomname+".c"))
			destruct(room);	
	room = load_object(arg+"/"+roomname+".c");
	if(!room->query("coor"))
	log_file("LEAK",sprintf("%s/%s\n",arg,roomname));
	}
	return 1;
}
