//by tiandi ����
#include "ansi.h"
inherit F_CLEAN_UP;
int add_attribute(object user,int tol, int fle, int agi, int dur, int intt, int str, int con, int spi, int per, int cor, int cps, int kar);

int main(object me)
{
	int lv,i,j;
	object gold;
	string national;
	lv = me->query("level");
	j=0;
	if(lv>99)
		return notify_fail("���ĵȼ��Ѿ���Ŀǰ����߼����ˡ�\n");	
	j=2000;
	for(i=0;i<lv;i++)
		j=j+j/9;
	if(me->query("combat_exp") < j)
		return notify_fail("��ľ��黹����"+j+"�㣬����������\n");
	me->add("combat_exp",-j);
	me->add("level",1);
	me->add("gift_points",5);
	national = me->query("national");
	switch(national){
		case "����":  //ƽ��
			add_attribute(me,6,6,6,6,6,6,6,6,6,6,6,6);     
			break;
	            case "����": //(�����ͣ�
 	            	add_attribute(me,9,3,6,3,9,3,6,9,3,6,6,9);
                        	break;
        	 	case "����": //�������ͣ�
         	      		add_attribute(me,6,6,3,6,3,6,9,6,3,9,9,3);
                        	break;
        	 	case "�ɹ���"://����
			add_attribute(me,9,9,6,6,3,9,6,6,9,3,3,3);
                        	break;
         		case "����": //����
            		add_attribute(me,9,6,9,3,3,3,6,6,6,3,9,9);
                      		break;
         		case "����"://����
			add_attribute(me,6,9,3,9,6,6,6,3,3,9,9,3);
                       		break;
		}	
		me->add("max_lifetili",10);
		write("���ĵȼ�����"+to_chinese(me->query("level"))+"��\n");
		if (me->query("level") == 2)
			write("���Ƴǵ��������������������㡣\n");
		if (me->query("level") == 3)
			write("���ƺ�Ӧ��ȥ��Զ�ĵط������ˣ�ȥ�������ͤ���㿴������˵��������㷷���չ��������㡣\n");
		if (me->query("level") == 4)
			write("��˵������͵���̫�����˰�æ����ȥ�����ɣ�˵�����ܰ���æ�ء�\n");
		if (me->query("level") == 5)
			write("��ϲ�����˿���ѧϰ����ܵĵȼ������ҽ���������˽������Ϣ��\n");
		if (me->query("level") == 6)
			write("������˺��������˵��鷳���п�ȥ�����ɡ�\n");
		if (me->query("level") == 10)
	{
			write("��ϲ�㵽����ʮ�������������Ѿ��������ˣ���ȥ�ҷ��ƳǵĲ��ͳ���һ�°ɡ�\n");
			gold=new("/obj/money/gold");
			gold->set_amount(lv*10);
			gold->move(me);
			write("������һ�����ƽ�Ķ��⽱����\n");
	}
		if (me->query("level") == 20)
	{
			write("��ϲ�㵽���˶�ʮ�������������������㡣\n");
			gold=new("/obj/money/gold");
			gold->set_amount(lv*10);
			gold->move(me);
			write("�������������ƽ�Ķ��⽱����\n");
	}
		if (me->query("level") == 30)
	{
			write("��ϲ�㵽������ʮ����\n");
			gold=new("/obj/money/gold");
			gold->set_amount(lv*10);
			gold->move(me);
			write("�������������ƽ�Ķ��⽱����\n");
	}
		if (me->query("level") == 35)
			write("��ϲ�㵽������ʮ�弶���������ڵ�����Ӧ�ÿ���ȥ����׽��ʮ������ˡ�\n");
		if (me->query("level") == 45)
			write("��ϲ�㵽������ʮ�弶���������ڵ�����Ӧ�ÿ���ץ��ϸ�ˡ�\n");	
		if (me->query("level") == 50)
			write("��ϲ�㵽������ʮ�������������������㡣\n");
		return 1;	
}

int add_attribute(object user,int tol, int fle, int agi, int dur, int intt, int str, int con, int spi, int per, int cor, int cps, int kar)
{
user->add("tol",tol);
user->add("fle",fle);
user->add("agi",agi);
user->add("dur",dur);
user->add("int",intt);
user->add("str",str);
user->add("con",con);
user->add("spi",spi);
user->add("per",per);
user->add("cor",cor);
user->add("cps",cps);
user->add("kar",kar);
return 1;
}

int help()
{
        write(@TEXT
ָ���ʽ��upgrade

������ĵ�ǰ���鳬����������ʱ������ʹ��upgrade���������
���𣬼���Խ�ߣ���������ҲԽ�ߡ�ÿ������������5�����Ե�
�������ɷ��䡣
TEXT
        );
        return 1;
}

