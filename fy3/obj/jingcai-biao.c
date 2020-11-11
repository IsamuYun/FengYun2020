//˭�����桤/clone/misc/jincai-biao.c
//�����޸ľͿ���Ӧ���ܶ����������Ϸ��Ѻע�Ķ�����

#include <ansi.h>
inherit ITEM;//�̳���Ʒ
inherit F_SAVE;//�̳п�save������

mapping *all_biao;//ȫ�ֱ��������������Ѻע����������
int num;//ȫ�ֱ������˴�Ϊ�й���Ŀǰ������
int jieguo;//ȫ�ֱ������˴�Ϊ���ս��

//��������Ϊ��������
int do_read(string);
int do_post(string);
int do_ya(string);
void enough_rest();

void create()
{
	set_name(HIY"2000��"HIR"Ϥ��"HIC"����"HIG"���±�"NOR, ({ "biao"}) );
	set("long",
		"����һ����¼��˭�����桱��ҶԱ�����˻��й������Ž����\n"
		"�Ľ������ľ���Ѻע��������Ѻע��read rules���鿴Ŀǰ��\n"
		"Ͷע�����read biao��\n");//���������԰�ʵ������޸ĳɣ����ޱ����±�ȵ�
	set("unit", "��");
	set("no_put", 1);
	set("no_get", 1);
	set_weight(900000000);//���㲻�����Get
	seteuid(getuid());
	restore();
}

void init()
{
	add_action("do_read", "read");
	add_action("do_post", "post");
	add_action("do_ya","ya");
	add_action("do_duijiang","duijiang");
}

string query_save_file()
{
	return DATA_DIR + "board/jingcai-biao";//����Զ���һ�������ļ���·��
}

int do_ya(string arg)//�����ע
{
	int i,j;
	object me,ob;
	mapping biao;
	
	me = this_player();
	if(query("end_ya"))             //��ʾֹͣ��ע������ʦ��do_post()���������
    	return notify_fail("��ֹʱ���ѹ�����2004����˻�����Ѻ��......\n");
	if (query_temp("busy"))        //��ֹ����ͬ��Ѻע��������
		return notify_fail("�Ժ�........\n");
	if(me->query("du"))            //��������ϵĲ���
   	    return notify_fail("ÿ��ֻ��Ѻһ�Σ�\n");
	if(!arg || sscanf(arg, "%d %d", i,j) != 2)//�������ָ��
		return notify_fail("�����ʽ��ya <ö��> <�������ƽ�>\n");
    if(i<1||i>50)                  //�ų�һЩ�����ܵ�Ѻע����
		return notify_fail("�����ܰɣ����ǲ��������Ǯ��\n");
	if(j < 1)                     //����1gold
		return notify_fail("�����׬����\n");
    if(j>1000)                    //���ޣ��������ɵ���
	    return notify_fail("Ѻ��̫�࣬������1000��\n");
    if((int)j>me->query("balance")/10000) //Ǯׯ�Ĵ���Ѻ��Ǯ
        return notify_fail("���ﲻ���ֽ𣡵�Ǯׯ�湻��Ǯ��������\n");
	
	message_vision("$N���˰������������������Ϊ�й������õ� "+i+" ö���ƣ�Ѻ "+j+" ���ƽ𣡡�\n",me);
	me->add("balance",-j*10000);
	tell_object(me,"Ǯׯ�Ѿ��۳�����Ѻ�µ�"+j+"���ƽ���Ⱥ��Ļ����ɣ�\n");
    
    me->set("du/win",i);//������������²�������ǶĵĽ��
    me->set("du/gold",j);//�����Ѻ��Ǯ��

    biao = ([
    	"id":me->query("id"),
    	"name":me->query("name"),
    	"win":i,
    	"gold":j,
    	]);//����һ����¼�����Ѻע���ݵ�ӳ��
    if( !pointerp(all_biao) ) all_biao = ({ biao });
	else all_biao += ({ biao });
	save();//���������ļ���Ӧ��.o�ļ���
    
	remove_call_out("enough_rest");
	call_out("enough_rest", 1);//1���ȡ��busy
	return 1;
}

int do_post(string arg)//��ʦר�ã��������
{
	int i;
	object me= this_player();

	if(!wizardp(me)) return 0;
	if( !arg)
		return notify_fail("��Ҫ����ʲô��\n");
	if(sscanf(arg, "%d", i)==1 )//ֻ�����ֱ�ʾ���¼�ʱ���
	{
		if( i > num )//��ס�����num�����ļ�ͷ����ģ��Ƕ�������ļ����κκ������ɹ��õ�
		{
			shout( HIW"���ĳ���Ϣ����ĳλ��ʦ�����˾��±��ϵ��й��������� "+num+" ö����Ϊ "+i+" ö��\n"NOR);
			num = i;//����
			save();
			return 1;
		}
		else return notify_fail("��������Խ��Խ����\n");
	}
	if(sscanf(arg, "-last %d", i)==1 )//��-last��������ʾ�������ս��
	{
		if( i > num )
		{
			shout( HIW"���ĳ���Ϣ�������˾������ս���������� "+jieguo+" ö��Ѻ�ԵĿ�ȥ�ҽ�����\n"NOR);
			jieguo = i;//����
			save();
			return 1;
		}
		else return notify_fail("��������Խ��Խ����\n");
	}
	if(arg=="end")
	{
		set("end_ya",1);//ֹͣѺע
		shout( HIW"���ĳ���Ϣ�������˾��¿�ʼֹͣ��ע�����ע���������\n"NOR);
		save();
		return 1;
	}
	return notify_fail("��Ҫ���µĽ������Ƕ��٣�\n");
}

int do_read(string arg)//��Ҳ鿴
{
	int i,j,k;
	object me;
	string name,str,str1,str2;
	mapping biao;
	
	me = this_player();
	
	if(arg == "rules")
	{
		write("Ϥ����˻ᣬ�й������ž����ܻ����ö���ƣ���ӭ�ڴ�Ѻע��\n"
			"Ѻע���Իƽ�Ϊ��λ�����Ѻ1000 gold������ 1 gold���ֽ�\n"
			"�գ������ȴ��Ǯׯ��Ѻ�ĺ�Ǯׯֱ�ӿ�Ǯ��Ѻ��ʱ�䵽20�Ž�\n"
			"ֹ��ѺС��15�������һ��ʮ����Ѻ15��22֮���������һ������\n"
			"22���ϵ�������һ��ʮ�壬����������Ѻ���߰����������ƽ�\n"
			"��������ա�����˺�� "HIY"ya <ö��> <�������ƽ�>"NOR"\n"
			"��Ȼÿ��IDֻ��Ѻһ�Σ�Ѻ�������ڣ�\n");//����������ÿ����ʦ��ƵĶ�
		write("��ʹ��duixianָ���Ľ����Զ��������ʻ���\n");
		return 1;
	}
	if(arg == "biao")
	{
		if(num)//���˽��ƵĲ���
			write("�������������������������\n"
			HIG"������˻ᣬ�й��� "HIY+num+HIG" ö���ƣ�(��ʼ�ҽ�duijiang)");
		if( !pointerp(all_biao) || !sizeof(all_biao) ) //��ʾ��û������
		{
			write("\n��û���˿�ʼͶע��\n");
			return 1;
		}
		write("���� "+sizeof(all_biao)+" �����Ͷע��\n"
		HIC"�������������Ԥ���������Ѻ�ƽ������������������Ԥ���������Ѻ�ƽ���\n"
		"����������������������������������������������������������������������\n");
		str1 = HIM"�Ѿ��ҹ�������ң�\n"NOR;
		str2 = HIM"��δ�ҹ�������ң�\n"NOR;
		j = 0;
		k = 0;
		for(i=0; i<sizeof(all_biao); i++)//all_biaoҲ��ȫ�ֱ��������ļ�ͷ
		{
			name = all_biao[i]["name"]+"("+all_biao[i]["id"]+")";//ȡ��ÿ��Ѻע��ҵ�����
			if(!(int)all_biao[i]["dui"])//dui����������ڶҽ�������,���ʾû�ҽ��ģ�����str2
			{
				str2 += sprintf("%-18s    %-5d  %-5d%s",name,(int)all_biao[i]["win"],
					(int)all_biao[i]["gold"],j%2?"\n":"��",);
				j++;//j�������k����Ϊ������һ�У������õ�j%2���ǳ�2ʣ�µ�������Ϊ0�ͻ���
			}
			else//��dui�����ģ�����str1
			{
				str1 += sprintf("%-18s    %-5d  %-5d%s",name,(int)all_biao[i]["win"],
					(int)all_biao[i]["gold"],k%2?"\n":"��",);
				k++;
			}
		}
/*�����str1��str2���Ը��ݲ�ͬ��������ֲ�ͬ����Ϣ,�����ڱ����У�����
����all_biao[i]["win"]�Ƿ����num����Ŀǰ�Ľ��������ж���Щ��һ���ϣ
������Щ����Ѿ�����̭��str1="�޻�ϣ�������"��......
*/
		write(str1+"\n"+str2+"\n");//��ʾ��Ϣ
		return 1;
	}
	else
		write("��Ҫ��ʲô��Ѻע������read rules��Ѻע�����read biao��\n");
	return 1;
}

void enough_rest()
{
	delete_temp("busy");
}

int do_duijiang()//�ҽ�ָ��
{
	int i,j;
	object me,ob;
	mapping biao,du;

	me = this_player();
	
	if(!jieguo)//û��jieguo�ͱ�ʾû�п�ʼ�ҽ�
		return notify_fail("��δ���ҽ�ʱ�䣡\n");
	if(!du = me->query("du"))//�������ϲ���
		return notify_fail("��û�н��ģ������Ѿ��ҹ����ˣ�\n");
	if (query_temp("busy"))
		return notify_fail("�Ժ�........\n");
	set_temp("busy",1);
	if(du["win"]==jieguo)//������������н�
	{
		if(du["win"]>22) i = du["gold"]*15;//1��15
		else if(du["win"]>14) i = du["gold"]*6;//1��6
		else		i = du["gold"]*12;//1��12
//��Щ�����԰����趨�Ĺ�������
		write("��Ѻ "+du["win"]+" ����� "+du["gold"]+" ���ƽ𣬰��涨�ý��� "+i+" ���ƽ��ѻ������Ǯׯ�ʻ���\n");
		shout( HIW"���ĳ���Ϣ����"+me->name()+"�ҽ��õ� "+i+" ���ƽ�\n"NOR);	
		me->add("balance",i*10000);
	}
	else//û�жԵ�Ҳ�������Ž���
	{
		ob = new("/clone/food/jitui");
		ob->move(me);
		write("��ûѺ�ԣ�����һ����ο��������һ�����Ȱɣ�\n");
		message_vision(HIY"���±���ͷͻȻ���һ�������ˡ��ص���һ���͹��ļ��ȣ����õ���$N�����С�\n"NOR,me);
	}
	for(j=0; j<sizeof(all_biao); j++)
	{
		if(all_biao[j]["id"]==me->query("id"))
			all_biao[j]["dui"] = 1;//��ʾ���˶ҹ�����
	}
	save();//����
	me->delete("du");//���ϲ���ȡ�����Է��ظ��ҽ�
	remove_call_out("enough_rest");
	call_out("enough_rest", 1);
	return 1;
}