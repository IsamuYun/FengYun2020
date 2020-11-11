#include <ansi.h>

inherit F_CLEAN_UP;
int main(object me, string arg)
{
	object ob;
            string target,obj,familys;
	if( !arg )	return notify_fail("bangtitle <ĳ��> <����>��\n");
        if( !arg || sscanf(arg, "%s %s", obj,target)!=2 )
                return notify_fail("bangtitle <ĳ��> <����>��\n");
	ob = find_player(obj);
	familys=me->query("family/family_name");
if( !ob )	ob = find_living(obj);
	if( !ob )	ob = present(obj, environment(me));
       if( !ob ) return notify_fail("��ĵ��Ӳ������ϲ��ܸ��������š�\n");
       if( me->query("family/privs") == 0) return notify_fail("�㲻�����Ų��������ָ�\n");
       if( ob->query("family/master_id") != me->query("id")) return notify_fail("��ֻ�ܸ��Լ��ĵ��Ӹ����š�\n");
	if( strlen(target) > 20 )
return notify_fail("����̫���ˣ���һ����һ��ġ�����һ��ġ�\n");
	target = replace_string(target, "$BLK$", BLK);
	target= replace_string(target, "$RED$", RED);
	target= replace_string(target, "$GRN$", GRN);
	target= replace_string(target, "$YEL$", YEL);
	target= replace_string(target, "$BLU$", BLU);
	target= replace_string(target, "$MAG$", MAG);
	target= replace_string(target, "$CYN$", CYN);
	target= replace_string(target, "$WHT$", WHT);
	target= replace_string(target, "$HIR$", HIR);
	target= replace_string(target, "$HIG$", HIG);
	target= replace_string(target, "$HIY$", HIY);
	target= replace_string(target, "$HIB$", HIB);
	target= replace_string(target, "$HIM$", HIM);
	target= replace_string(target, "$HIC$", HIC);
	target= replace_string(target, "$HIW$", HIW);
	target= replace_string(target, "$NOR$", NOR);
	ob->set("title",familys+target+ NOR);
	write("Ok.\n");
	return 1;
}
int help(object me)
{
        write(@HELP
ָ���ʽ : bangtitle <����> <���ţ�ͷ��>
 
���ָ���������İ��ɵĵ����д�������Ż�ͷ�Ρ�
ʹ�� ANSI �Ŀ�����Ԫ�ı���ɫ�����������µĿ����ִ���

$BLK$ - ��ɫ		$NOR$ - �ָ�������ɫ
$RED$ - ��ɫ		$HIR$ - ����ɫ
$GRN$ - ��ɫ		$HIG$ - ����ɫ
$YEL$ - ����ɫ		$HIY$ - ��ɫ
$BLU$ - ����ɫ		$HIB$ - ��ɫ
$MAG$ - ǳ��ɫ		$HIM$ - �ۺ�ɫ
$CYN$ - ����ɫ		$HIC$ - ����ɫ
$WHT$ - ǳ��ɫ		$HIW$ - ��ɫ
 
����ϵͳ�Զ������ִ�β�˼�һ�� $NOR$��

HELP
        );
        return 1;
}
