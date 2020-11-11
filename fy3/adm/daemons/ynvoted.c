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
	message("system", HIY"������Ƶ����"HIW"\n\n��λ��ң������ֵ��ˣ��ڱ�����ӿ�ֳ��������ĺ��˺��£�
��ˣ����������ؿ����λ����Ϊ�Լ���֪�������ڰ�����ҵ���
Ͷ��һƱ��������ʦ�齫����֣�ݷ��ơ�ȫ���Ա����һλ����
��Ҹм������ܻ�ӭ����ң�������������һЩ���������ˣ�ͶƱ
���ʽ��ʼ������ʹ��

    ynvote <id>ָ��

Ϊ�����л��һ�����Ͷ�±����һƱ��\n\n"NOR, users());
	start_vote(); // ��ʼͶƱ��
}

void start_vote()
{
	message("system",HIY"������Ƶ����"HIW"��λ��ң��𼱣�������ʵ10����ʱ�乩������Ͷ˭��Ʊ��\n" NOR,users());
	set_temp("voting",1); // ��������ͶƱ
        call_out("count_time",500,1); // "10"��ָ����ͶƱʱ��10���ӣ������Լ��޸�
}

private void count_time(int min)
{
	min--;
	if( min ) {
                message("system",HIY"������Ƶ����"HIW"��λ��ң��𼱣���������ʵ" + chinese_number(min) +"���ӵ�ʱ�䣬�������Ͷ��\n"NOR,users() );
		call_out("count_time", 10, min); // ���ߴ�һ��м�����ʱ��
	} else {
                message("system",HIY"������Ƶ����"HIW"��λ��ң����δǾ�ӭ������ͶƱ��Ѿ�Բ��������\n\t���ڹ�����Ա���ڽ��ż�Ʊ�У�\n"NOR,users() );
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
	message("system",HIY"������Ƶ����"HIW"��Ϊ�����ͶƱ��̫�٣��Ǿ�ӭ��ͶƱ����ȡ�������ź���\n"NOR,users());
	for(i=0; i<sizeof(ob); i++){
	ob[i]->delete("have_voted");
	}
	if (i>=sizeof(ob)) {
		return;
		}
	}
	else {
	msg =  HIW"\n           "+WHT+MUD_NAME+"����ͶƱǰ����"WHT"\n";
	msg += HIW"���������ө��������������������ө��������ө���������\n";
	msg += HIW"�� "RED"����"WHT" ��   "WHT"��  ��  ��  ��"WHT"   �� "RED"��  ��"WHT" �� "WHT"Ʊ  ��"WHT" ��\n";
	msg += HIW"�ĩ������ة��������������������ة��������ة���������\n";
	for (i = 0 ;i < 3 ; i++) { // 3��ֻ�г�ǰ������������MUD�˶�Ļ����͸�ʲô5��10���ɣ�����³Ѹ����˵�����й����������С�ʮ��֢���ġ���
	if( i >= sizeof(list)) msg += WHT"��"RED"�������ң�������                                "WHT"��\n";
		else {
		msg += sprintf(WHT"��  "WHT"%-5s "RED"%-22s"WHT"%-10s "RED"%5d  "WHT"��\n",chinese_number(i+1),list[i]->query("name")+"("+
        capitalize(list[i]->query("id"))+")", list[i]->query("family")?  list[i]->query("family/family_name"):"��ͨ����",
	list[i]->query_temp("voted"));
		}
			 }
	msg += WHT"����������������������������������������������������\n";
	msg += HIY+"\n����ͶƱԲ����ɡ�\n"NOR;
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
	message("system",HIY"������Ƶ����"HIW"����ȵ����ܻ�ӭ��ҵ������ƺŽ�����"HIR+who->name()+"("+who->query("id")+")"HIW"��\n"NOR,users());
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
        int i=(10000+random(ob->query("combat_exp")/50))/rank; // ����̫��ɣ�һ���һ�Ρ�
        int j=(1000+random(ob->query("combat_exp")/100))/rank; 
        int k=(500+random(500))/rank;
	object obj;
// ���������3�ֽ��������Լ���������һЩ
	switch (random(3))
	{
		case 0:
			gift=chinese_number(i)+"�㾭��";
			ob->add("combat_exp",i);
			break;
		case 1:
			gift=chinese_number(j)+"��Ǳ��";
			ob->add("potential",j);
			break;
		case 2:
			obj=new(GOLD_OB);
			obj->set_amount(k);
                        gift=chinese_number(obj->query_amount())+"���ƽ�";
			obj->move(ob);
			break;
	}
	tell_object(ob,HIM"ף���㣬"WHT+ob->name()+HIM"��������һ���ɫ�ı���ʹ�㵱ѡ��"WHT+MUD_NAME+RED"
���ܻ�ӭ����ң����õĽ�����"HIW+gift+HIM"��������\n"NOR);
	return;
}
