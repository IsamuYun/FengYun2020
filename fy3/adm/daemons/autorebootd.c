#include <ansi.h>
#include <net/daemons.h>

inherit F_DBASE;
private void count_time(int min);
void auto_reboot_start();
void auto_reboot_done();
void create()
{
	seteuid(ROOT_UID);
	set("channel_id", "�Զ���ʱ��������");
		CHANNEL_D->do_channel( this_object(), "sys", "�Զ���ʱ���������Ѿ�������");
                call_out("auto_reboot_start", 86400*5+random(7200));
		log_file("AUTOREBOOT", sprintf("autoreboot�����ɹ���\n"));
		return;
}

void auto_reboot_start()
{
	remove_call_out("auto_reboot_start");
        message("system",HIR"������Ƶ����"HIY"Ϊ�����ϵͳ�������ٶȣ�����Ϸ��20�����ڻ��Զ�����\n" NOR,users());
        call_out("count_time",60,20); 
}

private void count_time(int min)
{
	min--;
	if( min ) {
                message("system",HIR"������Ƶ����"HIY"����ע��,���ڻ���" + chinese_number(min) +"���ӵ�ʱ������������\n"NOR,users() );
		call_out("count_time", 60, min); 
	} else {
		message("system",HIR"������Ƶ����"HIY"ϵͳ�����Զ�����������\n"NOR,users() );
		call_out("auto_reboot_done", 3); 
	}
}

void auto_reboot_done()
{
	int i,j;
	object *ob, link_ob;
	string id;
	j=0;
	seteuid(getuid());
	set("channel_id", "���̾���"); 
	ob=users();
	i=sizeof(ob);
	for( i=0;i<sizeof(ob);i++) {
	id = (string) ob[i]->query("id");
	if (!id) continue;
	if(!environment(ob[i]) )        continue;
	if( !objectp(link_ob = ob[i]->query_temp("link_ob")) ) continue;
	if( (int)link_ob->save() && (int)ob[i]->save() ) j = 1;
	else CHANNEL_D->do_channel( this_object(), "sys", ob[i]->query("name")+"�����Զ�����ʧ�ܡ�");
	}
	write_file("/log/static/LASTCRASH", HIY"ϵͳ�Զ������� "+ctime(time())+"\n"NOR, 1);
	CHANNEL_D->do_channel( this_object(), "sys", "�����Զ����̳ɹ���");
	if( find_object(DNS_MASTER) ) DNS_MASTER->send_shutdown();
	shutdown(0);
	return;
}
