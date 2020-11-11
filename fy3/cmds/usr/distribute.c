// nick.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int gift_points;
	int used_gift_points;
	if( !arg ) return notify_fail("��Ҫ���䵽�ĸ������ϣ�\n");
	gift_points = me->query("gift_points");
	used_gift_points = me->query("used_gift_points");
	if( used_gift_points >= gift_points )
	return notify_fail("��û�в����㡣\n");
	if(me->is_busy())
	return notify_fail("���ϸ�������û��ɡ�\n");
	switch (arg) {
	case "����" :
	case "caizhi" :
                      	return notify_fail("���ܷ���������ԡ�\n");
		break;
        case "����" :
        case "tizhi" :
                        me->add("used_gift_points",1);
                        me->add("con",1);
                        break;
        case "����" :
        case "lingxing" :
                        me->add("used_gift_points",1);
                        me->add("spi",1);
                        break;
        case "����" :
        case "meili" :
                        me->add("used_gift_points",1);
                        me->add("per",1);
                        break;
        case "����" :
        case "yongqi" :
                        me->add("used_gift_points",1);
                        me->add("cor",1);
                        break;
        case "����" :
        case "liliang" :
                        me->add("used_gift_points",1);
                        me->add("str",1);
                        break;
        case "����" :
        case "naili" :
                        me->add("used_gift_points",1);
                        me->add("dur",1);
                        break;
        case "����" :
        case "renxing" :
                        me->add("used_gift_points",1);
                        me->add("fle",1);
                        break;
        case "�ٶ�" :
        case "sudu" :
                        me->add("used_gift_points",1);
                        me->add("agi",1);
                        break;
        case "����" :
        case "qiliang" :
                        me->add("used_gift_points",1);
                        me->add("tol",1);
                        break;
        case "����" :
        case "yunqi" :
                        me->add("used_gift_points",1);
                        me->add("kar",1);
                        break;
        case "����" :
        case "dingli" :
                        me->add("used_gift_points",1);
                        me->add("cps",1);
                        break;
        default :
			return notify_fail("û�����������\n");

	}
	write("Ok.\n");
//	me->start_busy(1);
	return 1;
}
int help(object me)
{
        write(@HELP
ָ���ʽ : distribute <�������>
���ָ��������㽫��������䵽��ָ���Ĳ����ϡ�������
һ�������������Զ���ɸ��ġ�

distribute tizhi ���㽫һ���������䵽�����ϡ�

�粻���������ģ�����ƴ�����档
���� caizhi	���� tizhi
���� lingxing	���� meili
���� yongqi	���� liliang
���� naili	���� renxing
�ٶ� sudu	���� qiliang
���� yunqi	���� dingli
HELP
        );
        return 1;
}
