// pawn_ticket.c
// �޸ģ���ɽ��ѧ  �����ᣨMicro��----Micro_Liang@Hotmail.Com		1997.6

inherit ITEM;

string query_autoload() { return "1"; }
void autoload()	{}

void create()
{
	set_name("��Ʊ", ({ "pawn ticket", "ticket" }) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ŵ��̿����ĵ�Ʊ�������ͨ��������(read)���ڵ��̵Ĵ����\n");
		set("no_drop", 1);
		set("no_get", 1);
	}
}

int init()
{
	add_action("do_read", "read");
}

int do_read(string arg)
{
	object me, ob;
	mapping pawn;
	string *base_name, msg, str_path, str_name, str_id, str_unit;
	int i, num;

	me = this_player();
	seteuid(geteuid(me));

	if(!arg || !id(arg))	return 0;
	if(environment(this_object()) != me )	return 0;

	if(mapp(pawn = this_player()->query("pawn")) )
		base_name = keys(pawn);

	if(!sizeof(base_name))	return 0;

	msg = "����һ�ŵ��̿����ĵ�Ʊ������д�ţ�\n";

	for(i = 0; i < sizeof(base_name); i++) {
		sscanf(pawn[base_name[i]], "%s~%s~%s~%d~%s", str_path, str_name, str_id, num, str_unit);
		msg += sprintf("%-2d ", i + 1) + chinese_number(num) + str_unit 
			+ str_name + "(" + str_id + ")\n";
	}

	tell_object(me, msg);

	return 1;
}
