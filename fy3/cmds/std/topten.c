// toptenadd.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string str,*astr,type;
	int i;
	seteuid(geteuid(me));
	if (!arg||arg=="")
		  return notify_fail("ָ���ʽ : topten ��������
Ŀǰ�����������У�\n
        ��һ������ ��ʮ��������а�gaoshou��
        ��һ������ ��ʮ�������а�richman��
        ��һ������ ��ʮ��ħͷ���а�motou��
        ��һ������ ��ʮ���������а�laoshou��
        ��һ������ ��ʮ�����������а�beiqing��\n");
        if(arg=="gaoshou"||arg=="exp")
              type="exp";
        else if(arg=="richman"||arg=="rich")
              type="rich";
        else if(arg=="motou"||arg=="pker")
              type="pker";
        else if(arg=="laoshou"||arg=="age")
              type="age";
        else if(arg=="beiqing"||arg=="killed")
              type="killed";
        else if(arg=="task"||arg=="tasker")
              type="tasker";
        else 
              type=arg;   
        str=TOPTEN_D->topten_query(type);
	write(str+"\n");
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : topten ��������
Ŀǰ������������:
gaoshou  ʮ�����
richman  ʮ����
motou    ʮ��ħͷ
laoshou  ʮ������
beiqing  ʮ��������
tasker  ʮ��ʹ������
HELP
    );
    return 1;
}
