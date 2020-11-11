// post_officer.c

inherit NPC;

string send_mail();
string receive_mail();

void create()
{
	set_name("����", ({ "officer", "post officer" }) );
	set("title", "�������䳤");
	set("gender", "����" );
		  set_temp("kf_tufei",41);
        set("pursuer", 1);
set("age", 43);
	set("long",
		"���絣�η�������䳤�Ѿ��м����ˣ��˺ܺã�\n"
		"���������ķ����൱����������������վ�������졣\n");
	set("combat_exp", 800);
	set("attitude", "friendly");
	set("inquiry", ([
		"��վ" : "�ǰ�... ������Ƿ������Ҫ������",
		"����" : (: send_mail :),
		"����" : (: receive_mail :),
		"mail" : (: receive_mail :),
	]) );
	set_skill("literate", 70);
	set_skill("unarmed", 400);
	setup();
	add_money("silver", 70);
}

string send_mail()
{
	object mbox;

	if( this_player()->query_temp("mbox_ob") )
		return "������仹�ڰɣ�������Ϳ��Լ����ˡ�\n";
	if( !environment()
	||	base_name(environment()) != query("startroom") )
		return "���Ǳ�Ǹ��������һ�µ���վ�����Ұɡ�\n";
	seteuid(getuid());
	mbox = new(MAILBOX_OB);
	mbox->move(this_player());
	return "Ŷ... Ҫ������������������䣬���ŵķ�����������˵����\n";
}

string receive_mail()
{
	object mbox;

	if( this_player()->query_temp("mbox_ob") )
		return "������仹�ڰɣ������е��Ŷ������档\n";
	if( !environment()
	||	base_name(environment()) != query("startroom") )
		return "���Ǳ�Ǹ��������һ�µ���վ�����Ұɡ�\n";
	seteuid(getuid());
	mbox = new(MAILBOX_OB);
	mbox->move(this_player());
	return "�ã���������....���ˣ�����������⣬�������ɣ���������ˡ�\n";
}
