// kill.c

#include <ansi.h>
#define LOWER_LIMIT 500000
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj,ob;
	string *killer, callname;
	seteuid(getuid());
	if( environment(me)->query("no_fight") )
		return notify_fail("���ﲻ׼ս����\n");

	if( !arg )
		return notify_fail("����ɱ˭��\n");

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("����û������ˡ�\n");

	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

	if(obj==me)
		return notify_fail("�� suicide ָ���ȽϿ�:P��\n");

	callname = RANK_D->query_rude(obj);
       if (me->query("jiebai") &&userp(obj)&& strsrch(me->query("jiebai"), obj->query("id")+">") >= 0)
              return notify_fail("ι������ˣ��������ݹ�������ɱ��!\n");
 	if (me->query("marry") == obj->query("id"))
              return notify_fail("�������ô���ģ������ϰ鶼ɱ��\n");
    if (me->query("level")<10 && userp(obj))
              return notify_fail("�㻹�������ֱ�������\n");
      if( userp(obj) && (int) obj->query("level") < 10 &&
              !me->query("licensed_to_kill"))
              return notify_fail("���ֻ��������ֱ�������\n");
	if( userp(obj)&&userp(me))
   log_file( "KILL_LOG", sprintf("(%s)
 %s tried to kill %s\n", ctime(time()), me->query("id"), obj->query("id")));

        obj->add_temp("kill/"+me->query("id"),1);

	message_vision("\n$N����$n�ȵ�����" 
		+ callname + "�����ղ������������һ��\n\n", me, obj);
        me->kill_ob(obj);
        me->set("killren",1);
	if( !userp(obj) )
                obj->kill_ob(me);
	else {
		obj->fight_ob(me);
		tell_object(obj, HIR "�����Ҫ��" + me->name() 
			+ "�����ಫ������Ҳ���������һ�� kill ָ�\n" NOR);
	}
      if (!userp(me)) return 1;
    if (stringp(obj->query("marry"))){
    ob=present(obj->query("marry"),environment(me));
    if (ob && userp(ob) && living(ob) && ob!=me ){
        if (ob->query("gender")=="����")
            message_vision(CYN"\n$Nһ��ŭ��"+me->name()+"���㾹���۸������ţ��Ҹ���ƴ�ˣ�\n\n"NOR, ob);
        else
            message_vision(CYN"\n$N����һ����"+me->name()+"�������㲻���۷򸾷���������У�\n\n"NOR, ob);
        ob->kill_ob(me); me->fight_ob(ob);
    }
    }
    if( !stringp(callname=obj->query("family/family_name")))
        if( !stringp(callname=obj->query("friend")))
        return 1;
    ob=first_inventory(environment(me));
    while(ob){
        if( ob!=obj && ob->is_character() && !ob->is_corpse() && living(ob)){
//ͬ�Ż�������ҿɲ����룩
            if ( (string)ob->query("family/family_name")==callname && !ob->is_killing(me) && !userp(ob) ){
                message_vision(CYN"\n$N��ŭ��"+me->name()+"���㾹��ı���ҵ�ͬ�ţ����У�\n\n"NOR, ob);
                ob->kill_ob(me); me->kill_ob(ob);
            }
//�ݰѵ��ֵܻ��� ��ʱ������
//            if ((string)ob->query("friend")==callname  || (string)ob->query("friend")==obj->query("id") ){
//                message_vision(CYN"\n$N����һЦ��"+me->name()+"����Ҫɱ�Ұݰѵ��ֵܣ����������ң�\n\n"NOR, ob);
//                ob->kill_ob(me); me->fight_ob(ob);
//            }
        }
        ob=next_inventory(ob);
    }
    return 1;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : kill <����>
 
���ָ������������ʼ����һ��������ҡ���ɱ���Է���kill �� fight ����
��ͬ���˫�������浶ʵǹ�ش򶷣�Ҳ����˵����������ˡ���� kill ֻ�赥��
��һ����Ը�Ϳ��Գ������������κ���ʹ�� kill ָ��Ὺʼս����ͨ�����
�Է��� NPC �Ļ�������Ҳ��ͬ������ʹ�� kill��

�����˶���ʹ�� kill ָ��ʱ����ֺ�ɫ�����������㣬���һ����Ҷ��ԣ����
��û�ж�һ������ʹ�ù� kill ָ��Ͳ��Ὣ�Է���Ĵ��˻�ɱ��( ʹ�÷�����
��)��

�������ָ��: fight

�й� fight �� kill �������뿴 'help combat'.
HELP
    );
    return 1;
}
 
