// lifeskills.c written by Tiandi
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob;
        seteuid(getuid());
        if(!arg)
                    ob = me;
        else{
                    ob = present(arg, environment(me));
                    if (!ob) ob = find_player(arg);
                    if (!ob) ob = find_living(arg);
                    if (!ob) return notify_fail("��Ҫ�쿴˭������ܣ�\n");
         }
        if( ob!=me && !wizardp(me) )
                    return notify_fail("ֻ�й���Ա�ܲ쿴���˵�����ܡ�\n");
    if (me->query("lifecook"))
		{
		if (!me->query("lifecombine"))
			{
			me->set("lifecombine",1);
			me->set("lifexiang",1);
			}
		}
        write( (ob==me ? "��" : ob->name()) +"Ŀǰ���յ�����̶ܳ����£�\n\n");
        write( "����⿼��ɡ���    "  + ob->query("lifecook") + "/" + ob->query("lifecook_exp") );
        write( "\n���������ɡ���    "  + ob->query("lifedoctor") + "/" + ob->query("lifedoctor_exp") );
        write( "\n�����켼�ɡ���    "  + ob->query("lifeweapon") + "/" + ob->query("lifeweapon_exp") );
        write( "\n�����Ƽ��ɡ���    "  + ob->query("lifearmor") + "/" + ob->query("lifearmor_exp") );
	if (ob->query("stoneok")||ob->query("stonefail"))
        		write( "\n���ϳɼ��ɡ���    "  + ob->query("lifecombine") + "/" + ob->query("lifecombine_exp") +"     �ɹ���:     "+ ob->query("stoneok")*100/(ob->query("stoneok")+ob->query("stonefail"))+"%");
      	else
		write( "\n���ϳɼ��ɡ���    "  + ob->query("lifecombine") + "/" + ob->query("lifecombine_exp") );
	if (ob->query("xiangok")||ob->query("xiangfail"))
	 	write( "\n����Ƕ���ɡ���    "  + ob->query("lifexiang") + "/" + ob->query("lifexiang_exp") +"     �ɹ���:     "+ ob->query("xiangok")*100/(ob->query("xiangok")+ob->query("xiangfail"))+"%");
       	else
		write( "\n����Ƕ���ɡ���    "  + ob->query("lifexiang") + "/" + ob->query("lifexiang_exp") );
	 write( "\n\n ����:" + ob->query("lifetili") + "/" + ob->query("max_lifetili") + "\n\n");
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : lifeskills 

���ָ����������ѯ�Լ�������̶ܳȡ�

HELP
    );
return 1;
}
