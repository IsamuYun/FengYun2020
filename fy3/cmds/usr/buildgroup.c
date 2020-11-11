#include <ansi.h>
inherit F_CLEAN_UP;
int check_legal_name(string name);
int main(object me, string arg)
{
        object cash;
        string c_name;     
        string *dir,file,temp;
        int i;
        seteuid(getuid());
        if(!arg || sscanf(arg,"%s",c_name) != 1)
      	  return notify_fail("ָ���ʽ����buildgroup �׻��š�\n");
        if((int)me->query("score") < 10000)
       	 return notify_fail("������۵㲻��"+chinese_number(10000)+"�㡣\n");
        cash = present("ttcash",me);
        if(!cash) return notify_fail("������û��һ������Ʊ(tenthousand-cash)��\n");
        if((int) cash->query_amount() < 10)
        return notify_fail("������û��"+chinese_number(10)+"��һ������Ʊ(tenthousand-cash)��\n");
        if(!check_legal_name(c_name) )
        return 1;
        dir = get_dir(DATA_DIR+"group/");
        for(i=0; i<sizeof(dir); i++) 
        if(dir[i] == c_name)
      	  return notify_fail("���봴�������������Ѿ�������ռ���ˣ�\n"); 
	file = "/data/group/"+c_name;
	temp = me->query("name");
          write_file(file,"level 1\nmember 1\n"+ temp);

        me->set("group",c_name);
        me->add("score",-10000);
	me->set("grouptitle",1);
	me->set("groups",1);
	me->set("grouplv",1);
	me->set("groupscore",100);
        cash->add_amount(-10);
        message("system",HIC"\n�����ַ��ơ�������Ϣ��"HIY+ me->query("name")+"���������ţ�������Ϊ��"HIC+c_name+HIY"��������һ��ף�ظ�����Խ��Խǿ��\n\n"NOR, users() );
    return 1;
}
 
int help(object me)
{
    write(@HELP
�����ڿ��ַ����н����Լ�������
ָ���ʽ: 
buildgroup ����������

��ָ�����㴴��һ���µ����š�
�����ǽ��г�ս��ǰ�ᣬֻ�����ŵ��ų��ſ��Է����ս��

HELP
    );
        return 1;
}
 
int check_legal_name(string name)
{
        int i;
        i = strlen(name);
        if( (strlen(name) < 4) || (strlen(name) > 20 ) ) {
                write("�Բ����������ֱ���������ʮ�������֡�\n");
                return 0;
        }
        while(i--) {
                if( name[i]<=' ' ) {
                        write("�Բ����������ֲ����ÿ�����Ԫ��\n");
                        return 0;
                }
                if( i%2==0 && !is_chinese(name[i..<0]) ) {
                        write("�Բ������ֱ��������ġ�\n");
                        return 0;
                }
        }
        return 1;
}

