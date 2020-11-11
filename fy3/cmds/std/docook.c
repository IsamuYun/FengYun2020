// docook.c written by Tiandi
#include <ansi.h>

inherit F_CLEAN_UP;
int main(object me)
{
        object obj, env;
        string name;
        int i,tili,lv,tili_cost,exp;

        exp = (int)me->query("lifecook_exp") ;
        if (!exp) exp =0;
        lv = (int)me->query("lifecook");
        if (lv < 1)
           return notify_fail("ʲ�᣿\n");
        name = me->query("name");
        tili = (int)me->query("lifetili");
        tili_cost = 120 - lv;
		tili_cost = tili_cost /10*(10-me->query("save_for_cook"));
        if( me->is_busy() )
           return notify_fail("����һ��������û����ɣ�\n");
        if( environment(me)->query("no_cook") )
           return notify_fail("�����޷�������⿡�\n");
        if( me->is_fighting() )
           return notify_fail("ս������⿣���������\n");
        if( me->query("lifetili") < tili_cost )
           return notify_fail("����������\n");
        me->set("lifetili",tili - tili_cost );
           message_vision("$N�����������ӣ��ó�һ����۰�����ǰ��׼����⿣�\n", me);

        call_out( "do_docook",5, me, lv,exp,name);
        me->start_busy(5);
        return 1;
}

private void do_docook(object me,int lv,int exp,string name)
{
        object obj;
		int jj;
		jj = random((lv+1))%10;
        switch( jj ) {
        case 0:
        message_vision("$N���ְ���۷���ˮ�������������������˰���Ҳû��ʲô���֡�\n", me);
        break;
        case 1:
        obj=new("/obj/food/cj");
        obj->set("long","һֻ��"+ name +"������⿵Ĵ����\n");
        obj->move(me);
        message_vision("$N����һץ�����Ա�ק��һ���ɾ��Ŀ��裬����������Ҩ�˴����һ����������С�\n����ͬʱ����һ����ˮ��Ҩ�����ˮ��������ע�����У���ֻ�����Ų�ͬ�Ķ�����\n", me);
        message_vision(HIG"$N����һ��Ŭ����������һ�������\n"NOR, me);
        me->set("lifecook_exp",exp+1);
        break;
        case 2:
        obj=new("/obj/food/cj2");
        obj->set("long","һֻ��"+ name +"������⿵��������������������֥�顣\n");
        obj->move(me);
        message_vision("$N����һץ�����Ա�ק��һ���ɾ��Ŀ��裬����������Ҩ�˴����һ����������С�\n����ͬʱ����һ����ˮ��Ҩ�����ˮ��������ע�����У���ֻ�����Ų�ͬ�Ķ�����\n", me);
        message_vision(HIG"$N����һ��Ŭ����������һ�������\n"NOR, me);
        me->set("lifecook_exp",exp+1);
        break;
        case 3:
        obj=new("/obj/food/cj3");
        obj->set("long","һֻ��"+ name +"������⿵������֣�Ӧ��ζ�������ɡ�\n");
        obj->move(me);
        message_vision("$N����һץ�����Ա�ק��һ���ɾ��Ŀ��裬����������Ҩ�˴����һ����������С�\n����ͬʱ����һ����ˮ��Ҩ�����ˮ��������ע�����У���ֻ�����Ų�ͬ�Ķ�����\n", me);
        message_vision(HIG"$N����һ��Ŭ����������һ�������֡�\n"NOR, me);
        me->set("lifecook_exp",exp+2);
        break;
        case 4:
        obj=new("/obj/food/cj4");
        obj->set("long","һֻ��"+ name +"������⿵Ľ��ǣ�����øϿ���ˣ���������ˡ�\n");
        obj->move(me);
        message_vision("$N����һץ�����Ա�ק��һ���ɾ��Ŀ��裬����������Ҩ�˴����һ����������С�\n����ͬʱ����һ����ˮ��Ҩ�����ˮ��������ע�����У���ֻ�����Ų�ͬ�Ķ�����\n", me);
        message_vision(HIG"$N����һ��Ŭ����������һ�����ǡ�\n"NOR, me);
        me->set("lifecook_exp",exp+2);
        break;
        case 5:
        obj=new("/obj/food/cj5");
        obj->set("long","һֻ��"+ name +"������⿵Ľ���Ȧ����Ũ��ζ�����˺�Զ��\n");
        obj->move(me);
        message_vision("$N����һ�ӣ���һ˫���Ӳ�֪����ʲô�ط�����������֮�У�\n�������͹��е�������һ�ţ�����漼��ı����һ��Բ�ε�Ȧ����������һ�㣬�ڿ��ӵ������£����Ϸ�ת�š�\n", me);
        message_vision(HIG"$N����һ��Ŭ����������һ������Ȧ��\n"NOR, me);
        me->set("lifecook_exp",exp+3);
        break;
        case 6:
        obj=new("/obj/food/cj6");
        obj->set("long","һֻ��"+ name +"������⿵���ѿ�ƣ���������ѿ�����С��ѿ��\n");
        obj->move(me);
        message_vision("$N����һ�ӣ���һ˫���Ӳ�֪����ʲô�ط�����������֮�У�\n�������͹��е�������һ�ţ�����漼��ı����һ��Բ�ε�Ȧ����������һ�㣬�ڿ��ӵ������£����Ϸ�ת�š�\n", me);
        message_vision(HIG"$N����һ��Ŭ����������һ����ѿ�ơ�\n"NOR, me);
        me->set("lifecook_exp",exp+3);
        break;
        case 7:
        obj=new("/obj/food/cj7");
        obj->set("long","һֻ��"+ name +"������⿵ĳ��ɾ���ҥ�����˿��Եõ����ɡ�\n");
        obj->move(me);
        message_vision("$N����һ�ӣ���һ˫���Ӳ�֪����ʲô�ط�����������֮�У�\n�������͹��е�������һ�ţ�����漼��ı����һ��Բ�ε�Ȧ����������һ�㣬�ڿ��ӵ������£����Ϸ�ת�š�\n", me);
        message_vision(HIG"$N����һ��Ŭ����������һ�����ɾ���\n"NOR, me);
        me->set("lifecook_exp",exp+4);
        break;
        case 8:
        obj=new("/obj/food/cj8");
        obj->set("long","һֻ��"+ name +"������⿵���˿���������ۣ�ǧ˿���ơ�\n");
        obj->move(me);
        message_vision("$N����һ�ӣ���һ˫���Ӳ�֪����ʲô�ط�����������֮�У�\n�������͹��е�������һ�ţ�����漼��ı����һ��Բ�ε�Ȧ����������һ�㣬�ڿ��ӵ������£����Ϸ�ת�š�\n", me);
        message_vision(HIG"$N����һ��Ŭ����������һ����˿����\n"NOR, me);
        me->set("lifecook_exp",exp+4);
        break;
        case 9:
        obj=new("/obj/food/cj9");
        obj->set("long","һֻ��"+ name +"������⿵�ɽ�μ��Σ���������θ�ڴ󿪣�����һ����ҩ�ü�ֵ��\n");
        obj->move(me);
        message_vision("$N������������Ѿ���ȫͣ�������е�����ϣ����絶��״��ѩ������·��ڿ��з���һ�㣬��\n�۱��г�Ƭ��������׹�䡣��ϸ������ÿһƬ�������ŵġ����ⲻͣ��˸�š�\n", me);
        message_vision(HIG"$N����һ��Ŭ����������һ��ɽ�μ��Ρ�\n"NOR, me);
        me->set("lifecook_exp",exp+5);
        break;
        default:
        message_vision("$N����һץ�����Ա�ק��һ���ɾ��Ŀ��裬����������Ҩ�˴����һ����������С�\n����ͬʱ����һ����ˮ��Ҩ�����ˮ��������ע�����У���ֻ�����Ų�ͬ�Ķ�����\n", me);
        break;
        }
        exp = (int)me->query("lifecook_exp") ;
		if (lv == 20)
		{
	        me->set("lifedoctor_exp",0);
		}
        if (exp > lv*lv*16) {
           me->set("lifecook_exp",0);
           me->set("lifecook",lv+1);
           write(HIW"�����⿼��ɽ����ˣ�\n"NOR);
	if (me->query("lifecook")==20)
			message("system",HIC "\n�����ַ��ơ���������"+me->query("name")+"��������⿼����ϵĳɾͣ������"HIY"��һ��������"HIC"�ĳƺš�\n" NOR,users());
			me->add("score",10000);
			write(HIW"�������������һ��㣡\n"NOR);
        }
        me->start_busy(5);
}

int help(object me)
{
        write(@HELP
ָ���ʽ : docook 

���ָ��������������Լ�����⿼�����һЩʳ��.

HELP
    );
return 1;
}