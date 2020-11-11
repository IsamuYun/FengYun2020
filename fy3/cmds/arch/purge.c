// purge.c

#include <ansi.h>
#define SYNTAX	"ָ���ʽ��purge [<δ��������>] | <ʹ��������> because <ԭ��>\n"

inherit F_CLEAN_UP;
int rmhirdir(string dir);
private int do_purge_players(int day);
int main(object me, string arg)
{
	string name, reason;
	string status;
	int day;

	status = wizhood(me);
	if( me!=this_player(1)
	|| wiz_level(me) < wiz_level(status) )
		return notify_fail("��û��Ȩ��ʹ�����ָ�\n");

	if( !arg ) return notify_fail(SYNTAX);

	if( sscanf(arg, "%d", day) && day >= 0) return do_purge_players(day);

	if( sscanf(arg, "%s because %s", name, reason)!=2 )
		return notify_fail(SYNTAX);

	seteuid(getuid());
	if( file_size(DATA_DIR + "login/" + name[0..0] + "/" + name + "/" + name + SAVE_EXTENSION)<0 )
		return notify_fail("û����λʹ���ߡ�\n");

      rmhirdir(DATA_DIR + "login/" + name[0..0] + "/" + name );
      rmhirdir(DATA_DIR + "user/" + name[0..0] + "/" + name );

	write( "ʹ���� " + capitalize(name) + " ɾ�����ˡ�\n");
	log_file("static/PURGE", sprintf("[%s] %s purged %s because %s.\n",
		ctime(time())[0..15], geteuid(this_player(1)), name, reason));

	return 1;
}

private int do_purge_players(int day)
{
	int i, j, ppl_cnt, count;
	string *dir, *ppls, name;
	mixed info;
	int info2;

	seteuid(getuid());
	message("system", HIY"\n*** ������Ҵ��浵�У����Ժ򼸷���.... ***\n"NOR, users());
	message("system", HIR"�����У�"HBBLU,users());
	count = 0;
	ppl_cnt = 0;
	dir = get_dir(DATA_DIR + "login/");
	for(i=0; i<sizeof(dir); i++) {
		reset_eval_cost();
		message("system", dir[i],users());
		ppls = get_dir(DATA_DIR + "login/" + dir[i] + "/");
		ppl_cnt += sizeof(ppls);
		for(j=0; j<sizeof(ppls); j++) {
			if( sscanf(ppls[j], "%s", name)==1 )
				if( (string)SECURITY_D->get_status(name)!="(player)" )
					continue;
			info = stat(DATA_DIR + "login/" + dir[i] + "/" + ppls[j] +"/" +  ppls[j] + SAVE_EXTENSION);
			info2 = file_size(DATA_DIR + "login/" + dir[i] + "/" + ppls[j]
			 +"/" +  ppls[j] + SAVE_EXTENSION);  
			if( info2 < 0 || time()-info[1] >= day*86400 ) {
				rmhirdir(DATA_DIR + "login/" + dir[i] + "/" + ppls[j] );
				rmhirdir(DATA_DIR + "user/" + dir[i] + "/" + ppls[j] );
				count ++;
			}
		}
	}
	write(NOR+WHT"\n\nԭ���ܹ��� " + ppl_cnt + " λʹ���ߡ�\n");
	write( count + " ������ " + day + " ��δ���ߵ�ʹ���߱�������ˡ�\n");
	message("system",NOR+WHT"\n�����ܹ��� " + (ppl_cnt - count) + " λʹ���ߡ�\n"NOR,users());
	log_file("static/PURGE", sprintf("[%s] %s cleaned up %d characters who didn't login for more than %d days\n"
		"\t\tResulting statistics: %d characters remaining.\n",
		ctime(time())[0..15], geteuid(this_player(1)), count, day, ppl_cnt - count));


	return 1;
}

int rmhirdir(string dirstr)
{
string *dir;
int i;
dir = get_dir(dirstr+"/");
        for(i=0; i<sizeof(dir); i++) {
		if(file_size(dirstr+"/"+dir[i]) == -2 ) {
				rmhirdir( dirstr +"/"+dir[i]);
				rmdir(dirstr+"/"+dir[i]);
						}
		rm(dirstr+"/"+dir[i]);
	}
rmdir(dirstr);

return 1;

}
int help(object me)
{
write(@HELP
ָ���ʽ��purge [<δ��������>] | <ʹ��������> because <ԭ��>

���һ��ʹ���߻��������һ�������������ߵ�ʹ���ߡ�
HELP
	);
    return 1;
}

