// Daemon:/adm/daemons/ynvoted.c
/* ����Ǿ�ӭ��ͶƱ�ϵͳ�ļ�
    ����ͶƱϵͳ����һ��ͼ�νӿڵ�����MUD���ֶ�ʿ��Ѫ��Ʈ���
    ������������������ģ����Լ���ߵ���ͶƱ�������Ǹ��Լ�ͶƱ��
    ��ѡ��һ��ʲô�����˧�������ɰ���������Ҳ����뽱������
    ��ʧΪһ���ܹ�������ҵ���Ȥ������롣
    ��Ҫ�ĳ���˼·�Ƚϼ򵥣���ΪͶƱʱ��Ƚ϶̣�����Ʊ���Ǽ���
    ������ϵģ������õ���tempֵ����ע�⣬����ĳ�����ͶƱ��
    �����˳��������ǲ��ң�ԭ��Ͷ������Ʊȫû�ˣ���ʵ��add ����
    ��add_tempҲ���ԣ�ע��Ͷ��Ʊ��Ʊ��ɾ�������ˡ���Ϊһ���
    Ͷһ�Σ������������ɾ�Ǹ�tempֵ�ˡ���������������һ�궼��
    ���ϰɣ��ֲ�ѽ����
    ����������Ǹ���ҵ���������ɣ�hehe��*/

#include <ansi.h>
inherit F_DBASE;
void vote(object ob,object me);
int vote_list(object ob1,object ob2);
void send_gift(object ob,int rank);
void start_vote();
void gift_who(object who,int rank);
private void count_time(int min);
void count_vote();

void create()
{
	seteuid(ROOT_UID);
	message("system", RED"�����꾫�顿"WHT"��λͬѧ�������ֵ��ˣ��ڱ�����ӿ�ֳ��������ĺ��˺��£���ˣ�����
	    �����ؿ����λͬѧΪ�Լ���֪�������ڰ���ͬѧ�ĺ�ѧ��Ͷ��һƱ�����꾫
	    �齫������Ϳ��͹����ҡ�ȫ���Ա����һλ���ܴ�Ҹм�������ѧ������
	    ������������һЩ���������ˣ��Ǿ�ӭ��ͶƱ���ʽ��ʼ������ʹ��
	    ynvote <id>ָ��Ϊ�����л��һ�����Ͷ�±����һƱ��\n"NOR, users());
	start_vote(); // ��ʼͶƱ��
}

void start_vote()
{
	message("system",RED"�����꾫�顿"WHT"��λͬѧ���𼱣�������ʵ10����ʱ�乩������Ͷ˭��Ʊ��\n" NOR,users());
	set_temp("voting",1); // ��������ͶƱ
	call_out("count_time",60,1); // "10"��ָ����ͶƱʱ��10���ӣ������Լ��޸�
}

private void count_time(int min)
{
	min--;
	if( min ) {
		message("system",RED"�����꾫�顿"WHT"��λͬѧ���𼱣���������ʵ" + chinese_number(min) +"���ӵ�ʱ�䣬�������Ͷ��\n"NOR,users() );
		call_out("count_time", 60, min); // ���ߴ�һ��м�����ʱ��
	} else {
		message("system",RED"�����꾫�顿"WHT"��λͬѧ�����δǾ�ӭ������ͶƱ��Ѿ�Բ�����������ڹ�����Ա���ڽ��ż�Ʊ�У�\n"NOR,users() );
		call_out("count_vote", 3); // ������
	}
}

int vote_list(object ob1, object ob2)  // ����˭�ĵ�Ʊ��
{
	int score1,score2;
	score1 = ob1->query_temp("voted");
	score2 = ob2->query_temp("voted");
	return score2 - score1;
}

void count_vote()
{
	object *ob =filter_array(objects(), (: userp($1) && !wizardp($1) :)); // imm���ϵ���ʦ���㣡
	object *list = sort_array(ob,(: vote_list :)); // ��efun sort_array()��������ĺ�������ҵĵ�Ʊ����������
	string msg;
	int i;
	if (!list){
	message("system",RED"�����꾫�顿"WHT"��Ϊ�����ͶƱ��̫�٣��Ǿ�ӭ��ͶƱ����ȡ�������ź���\n"NOR,users());
	for(i=0; i<sizeof(ob); i++){
	ob[i]->delete("have_voted");
	}
	if (i>=sizeof(ob)) {
		return;
		}
	}
	else {
	msg =  WHT"\n            �� "+WHT+MUD_NAME+"����ͶƱǰ����"WHT" ����\n";
	msg += WHT"���������ө��ߩ����������������ө��������䩥��������\n";
	msg += WHT"�� "RED"����"WHT" ��   "WHT"��  ��  ��  ��"WHT"   �� "RED"��  ��"WHT" �� "WHT"Ʊ  ��"WHT" ��\n";
	msg += WHT"�ĩ������ة��������������������ة��������ة���������\n";
	for (i = 0 ;i < 3 ; i++) { // 3��ֻ�г�ǰ������������MUD�˶�Ļ����͸�ʲô5��10���ɣ�����³Ѹ����˵�����й����������С�ʮ��֢���ġ���
	if( i >= sizeof(list)) msg += WHT"��"RED"�������ң�������                                "WHT"��\n";
		else {
		msg += sprintf(WHT"��  "WHT"%-5s "RED"%-22s"WHT"%-10s "RED"%5d  "WHT"��\n",chinese_number(i+1),list[i]->query("name")+"("+
	capitalize(list[i]->query("id"))+")", list[i]->query("family")?  list[i]->query("family/family_name"):"��ͨѧ��",
	list[i]->query_temp("voted"));
		}
			 }
	msg += WHT"����������������������������������������������������\n";
	msg += RED+RTIME_D->chinese_time(2,ctime(time()))+"ͶƱԲ����ɡ�\n"NOR;
	delete_temp("voting"); // ͶƱ������
	message("system",msg,users() );
	gift_who(list[0],1); // ��ǰ����������ѽ
	gift_who(list[1],2);
	gift_who(list[2],3);
	return;
	}
}

void gift_who(object who,int rank)
{
	object *ob=users();
	int i;
	message("system",RED"�����꾫�顿"WHT"����ȵ�����ѧ���������ƺŽ�����"RED+who->name()+"("+who->query("id")+")"WHT"ͬѧ��\n"NOR,users());
	send_gift(who,rank);
	for(i=0; i<sizeof(ob); i++){
	ob[i]->delete("have_voted"); // ɾ��Ͷ��Ʊ�ļǺ�
	}
	if (i>=sizeof(ob)) {
	return;
	}
}

void send_gift(object ob,int rank) // ���β�ͬ�����Ľ����Ķ���Ҳ��ͬ
{
	string gift;
	int i=(1000+random(ob->query("combat_exp")/3))/rank; // ����̫��ɣ�һ���һ�Ρ�
	int j=(100+random(500))/rank;
	int k=(10+random(80))/rank;
	object obj;
// ���������3�ֽ��������Լ���������һЩ
	switch (random(3))
	{
		case 0:
			gift=chinese_number(i)+"��ѧ��ֵ";
			ob->add("combat_exp",i);
			break;
		case 1:
			gift=chinese_number(j)+"��Ǳ��ֵ";
			ob->add("potential",j);
			break;
		case 2:
			obj=new(GOLD_OB);
			obj->set_amount(k);
			gift=chinese_number(obj->query_amount())+"�Ű�Ԫ��";
			obj->move(ob);
			break;
	}
	tell_object(ob,RED"ף���㣬"WHT+ob->name()+RED"ͬѧ��������һ���ɫ�ı���ʹ�㵱ѡ��"WHT+MUD_NAME+RED"
���ѧ�������õĽ�����"WHT+gift+RED"��Enjoy it��\n"NOR);
	return;
}