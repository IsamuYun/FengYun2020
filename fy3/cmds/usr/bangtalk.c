// user list
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me,string arg)
{
        object *ob,*target;
        int i;
	string mebang,obbang;
	string fa_name,outarg;
        if(me->query("chblk_on"))
                return notify_fail("���Ƶ�������ˣ�\n");
	mebang = (string)me->query("class");
	if(!mebang) return notify_fail("�㲻�����κΰ��ɣ�\n");
        ob=users();
        i = sizeof(ob);
        while (i--) {
		obbang = (string)ob[i]->query("class");
		if ( (mebang == obbang || wizardp(ob[i])) && !ob[i]->query("env/bangtalk"))
		{
			if (sizeof(target)==0)
				target=({ob[i]});
			 else 
				target+=({ob[i]});
		}
	}
	if(!stringp(fa_name=me->query("family/family_name")))
		 fa_name = "ƽ�����";
	if(!stringp(outarg = arg))
		outarg = "����������";	
	message("vision", HIW "��"+fa_name+"��" + 
	me->query("name") + "(" + capitalize(me->query("id")) + ")" + 
	"��" + outarg + "\n" NOR, target);	
        return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : bangtalk ����
��ͬ�ŵ������ͨ������᡿Ƶ������
bangtalkҲ������bt������
HELP
    );
    return 1;
}
