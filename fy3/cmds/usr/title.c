// title by tiandi ����ҿ����Լ����ƺ�

inherit F_CLEAN_UP;
    string *name= ({
   "����ʹ�õĳƺ�",
   "����ʹ�õĳƺ�",
   "����ʹ�õĳƺ�",
   "����ʹ�õĳƺ�",
   "����ʹ�õĳƺ�",
   "����ʹ�õĳƺ�",
   "����ʹ�õĳƺ�",
   "����ʹ�õĳƺ�",
   "����ʹ�õĳƺ�",
   "����ʹ�õĳƺ�",
   "����ʹ�õĳƺ�",
   "����ʹ�õĳƺ�",
   "����ʹ�õĳƺ�",
   "����ʹ�õĳƺ�",
   "����ʹ�õĳƺ�",
   "����ʹ�õĳƺ�",
   "����ʹ�õĳƺ�",
   "����ʹ�õĳƺ�",
   "����ʹ�õĳƺ�",
   "����ʹ�õĳƺ�",
   "����ʹ�õĳƺ�",
   "����ʹ�õĳƺ�",
   "����ʹ�õĳƺ�",
   "����ʹ�õĳƺ�",
   "����ʹ�õĳƺ�",
   "����ʹ�õĳƺ�",
   "����ʹ�õĳƺ�",
   "����ʹ�õĳƺ�",
   "����ʹ�õĳƺ�",
   "����ʹ�õĳƺ�",
   "����ʹ�õĳƺ�",
   "����ʹ�õĳƺ�",   });   

int main(object me, string arg)
{
	int i;
	i = 1;
	if( !arg ) 
		{
		write("�����ڳƺ��ǡ�" + me->query("title") + "����\n");
		write("��Ŀǰ�Ŀ���ʹ�õĳƺ��У�\n");
		if (me->query("m_success/С��"))
			{
			write("Ӣ�۾���\n");
			name[i]="Ӣ�۾���";
			i++;
			}			
		if (me->query("m_success/ç��"))
			{
			write("��Խç�ֵĺ���\n");
			name[i]="��Խç�ֵĺ���";
			i++;
			}			
		if (me->query("m_success/����"))
			{
			write("����ר��\n");
			name[i]="����ר��";
			i++;
			}	
		if (me->query("m_success/����Ȫ"))
			{
			write("̽���ȷ�\n");
			name[i]="̽���ȷ�";
			i++;
			}			
		if (me->query("m_success/����԰Ͱ"))
			{
			write("�ƻ���\n");
			name[i]="�ƻ���";
			i++;
			}			
		if (me->query("m_success/����կ"))
			{
			write("��������կ\n");
			name[i]="��������կ";
			i++;
			}			
		if (me->query("m_success/�ײ�"))
			{
			write("���õײ�\n");
			name[i]="���õײ�";
			i++;
			}	
		if (me->query("m_success/��ƽ"))
			{
			write("ײ�����Դ�\n");
			name[i]="ײ�����Դ�";
			i++;
			}			
		if (me->query("m_success/�䵱���ŵ�����"))
			{
			write("͵������\n");
			name[i]="͵������";
			i++;
			}			
		if (me->query("m_success/������"))
			{
			write("�ƽ������ƹ���\n");
			name[i]="�ƽ������ƹ���";
			i++;
			}	
		if (me->query("m_success/����"))
			{
			write("���绽��\n");
			name[i]="���绽��";
			i++;
			}			
		if (me->query("m_success/ʶ������"))
			{
			write("�Թ���а������\n");
			name[i]="�Թ���а������";
			i++;
			}			
		if (me->query("m_success/�ɿ�����ͭ��"))
			{
			write("����嵽����\n");
			name[i]="����嵽����";
			i++;
			}			
		if (me->query("m_success/�±�����"))
			{
			write("�±�����\n");
			name[i]="�±�����";
			i++;
			}	
		if (me->query("m_success/����Ů��"))
			{
			write("�߸�Ů�˺�һ�����˵Ĺ���\n");
			name[i]="�߸�Ů�˺�һ�����˵Ĺ���";
			i++;
			}			
		if (me->query("m_success/ľ��"))
			{
			write("��������\n");
			name[i]="��������";
			i++;
			}	
		if (me->query("m_success/��ɲ��"))
			{
			write("������ȥ\n");
			name[i]="������ȥ";
			i++;
			}			
		if (me->query("m_success/����"))
			{
			write("����ʹ��\n");
			name[i]="����ʹ��";
			i++;
			}			
		if (me->query("m_success/������"))
			{
			write("�˱ں�һ\n");
			name[i]="�˱ں�һ";
			i++;
			}			
		if (me->query("m_success/��ʯ"))
			{
			write("�������²�����\n");
			name[i]="�������²�����";
			i++;
			}	
		if (me->query("m_success/��ѩ"))
			{
			write("�����ݴ���ţ��\n");
			name[i]="�����ݴ���ţ��";
			i++;
			}			
		if (me->query("m_success/���ǽ�"))
			{
			write("�����ĺ�����\n");
			name[i]="�����ĺ�����";
			i++;
			}			
		if (me->query("m_success/����ʹ��"))
			{
			write("�������\n");
			name[i]="�������";
			i++;
			}			
		if (me->query("m_success/ͨ��"))
			{
			write("����Ӣ��\n");
			name[i]="����Ӣ��";
			i++;
			}	
		if (me->query("lifecook")>19)
			{
			write("һ������\n");
			name[i]="һ������";
			i++;
			}			
		if (me->query("lifedoctor")>19)
			{
			write("ҽ���˲�����\n");
			name[i]="ҽ���˲�����";
			i++;
			}			
		if (me->query("lifecombine")>10)
			{
			write("�Զ໻��\n");
			name[i]="�Զ໻��";
			i++;
			}			
		if (me->query("lifeweapon")==100)
			{
			write("������ʦ\n");
			name[i]="������ʦ";
			i++;
			}			
		if (me->query("lifearmor")==100)
			{
			write("�Ƽ���ͯ\n");
			name[i]="�Ƽ���ͯ";
			i++;
			}			
		if (me->query("lifexiang")==10)
			{
			write("����������\n");
			name[i]="����������";
			i++;
			}			
		return 1;

	}
	i=0;
	while (i<sizeof(name))
		{
		if (arg != name[i])
			i++;
		else 	
			{
			me->set("title",name[i]);
			write("��ĳƺ��Ѿ���Ϊ��"+name[i]+"����\n");
			return 1;
			}
		}
	write("�㲻����ʹ������ƺš�\n");
	return 1;
}

int help(object me)
{
     write(@HELP
ָ���ʽ: title <����ʹ�õĳƺ�>

���ָ������(���)֪������������Щ�ƺſ���ʹ�á�

HELP
    );
    return 1;
}

