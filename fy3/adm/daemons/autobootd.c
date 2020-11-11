#include <ansi.h>
#include <net/daemons.h>
#include <mudlib.h>
//autoboot at 8:00
#define REBOOT_TIME 2.1

inherit F_DBASE;

static int last_time=1440;//24 hours,60*24 minute

int query_time()
{
	return last_time;
}
void set_time(int time)
{
	last_time=time;
}
void pass_time()
{
	if(last_time>0) last_time-=1;
}
void auto_boot();

void create()
{
	mixed *local;
	int t,r;
        seteuid(ROOT_UID);
        set("channel_id", "ϵͳ����");
        CHANNEL_D->do_channel( this_object(), "sys", MUD_NAME+"�Զ�����ϵͳ�Ѿ�������\n");
#ifdef REBOOT_TIME
	local=localtime(time());
	t=local[2]*60+local[1];
	r=1440+REBOOT_TIME*60-t;
	r%=1440;
	set_time(r);
#endif
        call_out("auto_boot", 60);
}

void auto_boot()
{
        int i,mem,last;
        object *ob, link_ob;
        string id;

	pass_time();
	last=query_time();
	if(last>0 && last<10)
		message("channel:chat", HIR"��ϵͳ��Ϣ��: Ϊ����߱����Ƶ��ٶȽ���"+chinese_number(last)+"���Ӻ�����������\n"NOR,users());
	
	if(last>0)
	{
        remove_call_out("auto_boot");
        call_out("auto_boot", 60);
	return;
	}

//do autoboot

        seteuid(getuid());
        ob=users();
        i=sizeof(ob);
        reclaim_objects();
        for( i=0;i<sizeof(ob);i++) {
                id = (string) ob[i]->query("id");
                if (!id) continue;
                if(!environment(ob[i]) )        continue;
                if( !objectp(link_ob = ob[i]->query_temp("link_ob")) ) continue;
                if( (int)link_ob->save() && (int)ob[i]->save() )
message("channel:chat", HIR"��ϵͳ��Ϣ��"+MUD_NAME+"Ҫ���������ˡ���Ҫ�������ĵ����Ѿ��Զ����̡�\n"NOR,ob[i]);
                else
message("channel:chat", HIR"��ϵͳ��Ϣ��"+MUD_NAME+"Ҫ���������ˡ����ĵ����Ѿ��Զ�����ʧ�ܣ�������ʦ��ϵ��\n"NOR,ob[i]);
        }

	if( find_object(DNS_MASTER) ) DNS_MASTER->send_shutdown();
	shutdown(0);
}

