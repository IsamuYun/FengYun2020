
//xgchen@zzfy

#include <ansi.h>

int main(object me, string arg)
{
        object obj,dest;
        string sb1, sb2;

        if( !arg || arg=="" )
                return notify_fail("ָ���ʽ��nk sb1 sb2\n");

        if( !(sscanf(arg, "%s %s", sb1, sb2)==2) ) 
                return notify_fail("ָ���ʽ��nk sb1 sb2\n");

        if( sscanf(arg, "%s %s", sb1, sb2)==2 ) 
        dest=(present(sb1, environment(me)));
        obj=(present(sb2, environment(me)));

        if(sb1 == sb2)
                return notify_fail("����������ͬ��������\n");

        if(!objectp(obj = present(sb1, environment(me))) || 
                !objectp(dest = present(sb2, environment(me))))
        return notify_fail("����û�������ˡ�\n");

        if( !obj->is_character() || obj->is_corpse() || !dest->is_character() || dest->is_corpse() )
                return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

        if( !living(obj) || !living(dest) )
                return notify_fail("�Ѿ����˲���ս���ˡ�\n");

        message_vision(CYN "$N��$n˵����"+ RANK_D->query_self(obj) + obj->query("name") + "�����"
                + RANK_D->query_respect(dest) + "�ĸ��У�\n"NOR, obj,dest);
        message_vision(CYN"$Nһ���֣�˵����"+ RANK_D->query_self(dest) +"����ˡ�\n"NOR, dest);

        obj->delete_temp("halted");
        dest->delete_temp("halted");

        remove_call_out("check");
        call_out("check",2, obj, dest);

        dest->set("kee",(int)dest->query("max_kee"));
        obj->set("kee",(int)obj->query("max_kee"));

        dest->set("eff_kee",(int)dest->query("max_kee"));
        obj->set("eff_kee",(int)obj->query("max_kee"));

        remove_call_out("fighting");
        call_out("fighting",2, obj, dest);

        return 1;

}

void fighting(object dest, object obj)
{
            dest->set("biwu_fighter",1);
            obj->set("biwu_fighter",1);
        dest->fight_ob(obj);
        dest->fight_ob(obj);
}

void check(object obj, object dest)
{
        string name1, name2;
        if (!obj->query("family/family_name") && dest->query("family/family_name")){
        name1 ="�����ɵ�" + obj->query("name");
        name2 = dest->query("family/family_name")+"��"+dest->query("name");
        }
        else if (!dest->query("family/family_name") && obj->query("family/family_name")){
        name1 = obj->query("family/family_name")+"��"+obj->query("name");
        name2 ="�����ɵ�" + dest->query("name");
        }
        else if (!dest->query("family/family_name") && !obj->query("family/family_name")){
        name1 ="�����ɵ�" + obj->query("name");
        name2 ="�����ɵ�" + dest->query("name");
        }
        else {
        name1 = obj->query("family/family_name")+"��"+obj->query("name");
        name2 = dest->query("family/family_name")+"��"+dest->query("name");
        }
        message("channel:gab",HIR"�����䳡��"+
                name1+"��"+name2+"�ڱ���̨�Ͻ����ߵͣ�\n\n"NOR,users());
//      shout( HIR"�������᡽������ʽ��ʼ����" + name1 + "��" + name2 + "��\n"NOR);
//      write( HIR"�������᡽������ʽ��ʼ����" + name1 + "��" + name2 + "��\n"NOR);
}

int help(object me)
{
        write(@HELP
ָ���ʽ : nk <����1> <����2>
 
���ָ�����������NPC����һ�NPC����һ��๥����
HELP
        );
        return 1;
}

