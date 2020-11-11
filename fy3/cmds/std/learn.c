// learn.c

#include <skill.h>

inherit F_CLEAN_UP;

string *reject_msg = ({
        "˵������̫�����ˣ�������ҵ���\n",
        "�����ܳ�����һ����˵������̣�������ҵ���\n",
        "Ц��˵��������Ц�ˣ��������С�������ʸ�ָ�㡹��ʲ�᣿\n",
});

void create() { seteuid(getuid()); }

int main(object me, string arg)

{
        string skill, teacher, master;
        object ob, *list, marry_card,gold;
        int master_skill, my_skill, gin_cost;
        string target, cardname;
        int i,marry_flag,balance,learn_flag;
		int amount=0, pot;

        if(!arg || sscanf(arg, "%s from %s", skill, teacher)!=2 )
                return notify_fail("ָ���ʽ��learn <����> from <ĳ��>\n");

        if( me->is_fighting() )
                return notify_fail("����ĥǹ������������\n");

        if( !(ob = present(teacher, environment(me))) || !ob->is_character())
                return notify_fail("��Ҫ��˭��̣�\n");

        if( !living(ob) )
                return notify_fail("��....����Ȱ�" + ob->name() +
"Ū����˵��\n");
	
       if( !me->is_apprentice_of(ob) )
		if( !(ob->recognize_apprentice(me)) )
    		 	return notify_fail( ob ->name() + reject_msg[random(sizeof(reject_msg))] );
// until here we deicde that me can learn from ob!



       if (ob->query("env/no_teachskill") && strsrch(ob->query("env/no_teachskill"), skill+">") >= 0)
                return notify_fail(ob->name() + "��Ը���������ܡ�\n");
//        if( master_skill+">" = strsrch(ob->query("env/no_teachskill" )))
//       return notify_fail("����" + ob->name() + "����������������ѧ��\n")
        if( !master_skill = ob->query_skill(skill,1) )
				return notify_fail("���������±����ұ���ѧ�ˡ�\n");
        if( !master_skill = ob->query_skill_eff_lvl(skill) )
                return notify_fail("���������±����ұ���ѧ�ˡ�\n");

        if( ob->prevent_learn(me, skill) )
                return notify_fail(ob->name() + "��Ը���������ܡ�\n");
        my_skill = me->query_skill_eff_lvl(skill);
        if( my_skill >= master_skill )
                return notify_fail("�������ĳ̶��Ѿ�������ʦ���ˡ�\n");
		if( me->query_skill(skill,1) >= 1000 )
                return notify_fail("��������Ѿ�������ѧ�ˡ�\n");

   //     notify_fail("����Ŀǰ��������û�а취ѧϰ���ּ��ܡ�\n");

//by tiandiȥ����������

        if( !SKILL_D(skill)->valid_learn(me) )  return 0;
//	casue problem under query-skill-eff-lvl
        if( (int)me->query_skill(skill,1) == 0 ) {
                gin_cost *= 2;
                me->set_skill(skill,0);
        }
     	tell_object(me,"����"+ob->name()+"����йء�"+to_chinese(skill)+"�������ʡ�\n");
        if( ob->query("env/no_teach") )
                return notify_fail("����" + ob->name() +"���ڲ���׼���ش�������⡣\n");
        tell_object(ob, sprintf("%s��������йء�%s�������⡣\n", me->name(), to_chinese(skill)));


//by tiandi����learnΪֱ������
	my_skill = me->query_skill(skill,1);

	amount = my_skill   * 10;
	if( amount < 2) 
		amount = 2;
//	printf("%d\n",amount);
	pot = amount;
//	printf("%d\n",pot);
	if(pot < 0) pot =0;
	pot +=1;
            if( (int)me->query("potential") - (int)me->query("learned_points") < pot )
	{
              	  printf("���Ǳ�ܲ���%d�㣬�˼����޷�������\n",pot);
				  return 1;
	}
	//by tiandi ����ѧϰ�ļ������޲����������ȼ�*10
	if(my_skill  >=	(int)me->query("level")*10 ) 
			{
			printf("������ĵȼ�̫�ͣ����%s�Ļش������޷���ᡣ\n", ob->name() );
			return 1;
			}
		balance = me->query("deposit");
		if (balance > (my_skill + 1) * 100)
		{
			me->add("deposit", -(my_skill + 1) * 100);
			printf("ϵͳֱ�Ӵ������п۳������Ǯ�\n"); 
			learn_flag = 1;
		}
			else
	{
            gold = present("silver_money", me);
            if(!gold) {
				printf("�����еĴ����ˣ�����Ҳû�����ӡ�\n"); 
				return 1;
			}
            if((int) gold->query_amount() < (my_skill + 1))
			{
				printf("�����еĴ����ˣ�����Ҳû��%s�����ӡ�\n", chinese_number(my_skill + 1));
				return 1;
			}
	}

	 		 printf("�㽻��%s��������Ϊѧ�ѣ�����%s��ָ����%s��������%d����\n",chinese_number(my_skill + 1),ob->name(),to_chinese(skill), my_skill + 1);
                me->add("learned_points", pot);
			  me->set_skill(skill, my_skill + 1);
			  if (!learn_flag)
					gold->add_amount(-(my_skill + 1));
		  return 1;
}


int help(object me)
{
        write(@HELP
ָ���ʽ : learn <����> from <ĳ��>

���ָ������������������й�ĳһ�ּ��ܵ��������⣬��Ȼ������̵Ķ�������
����ϵ�����������ߣ����㾭�����ַ�ʽѧϰ�����ļ���Ҳ�����ܸ��������
�̵��ˣ�Ȼ����Ϊ����ѧϰ��ʽ�൱�һ�֡�����Ĵ��С������ѧϰ����˵����Ϥ
һ���¼������ķ�����

ͨ����һ���˸�ѧ��һ���¼����ǲ�����ʲ����������ģ����Ǿ���ʵ���ϵ�Ӧ����
�������⣬��Щ������ѧϰһ���¼��ܵĹ����Ǻ���Ҫ�ģ������Ǹ�����Ϊ������
�ܻ����Ļ������ܣ�����Ҫ���ɡ��������⡪������⡹�Ĺ��̲��ܵõ��Ϻõ�Ч��
������ǽ����ַ�������Ĺ����á�Ǳ�ܡ��Ĺ����ʾ��һ�����ܹ��Լ�����ĳЩ��
�⣬��ʾ��(��)�н�����������Ǳ�ܣ��������������Ǳ��ʱ�Ϳ����������ָ��
������������̣�����ý�����
(PS. Ǳ�ܻ�������������Ķ��壬����ֻ������֮һ )

����ѧϰҲ��Ҫ����һЩ��Ǯ����Ǯ�����ĺ���ѧϰ�ļ��ܵȼ��йء�

������֪�����ܴӶԷ�ѧ��ʲ�Ἴ�ܣ�����Է������ʦ���������� skills ָ��
ֱ�Ӳ鿴������������ʦ��������ͨ��������������ʾ����ֻ���Լ���취��

�������ָ�� : practice��study
HELP
        );
        return 1;
}
