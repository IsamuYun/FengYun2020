// dolian.c written by Tiandi
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me)
{
        object obj,ob1,ob2,ob3,ob4,ob5;
        string name;
        int i,tili,lv,tili_cost,exp;

        exp = (int)me->query("lifedoctor_exp") ;
        if (!exp) exp =0;
        lv = (int)me->query("lifedoctor");
        if(lv < 1)
           return notify_fail("ʲ�᣿\n");
        name = me->query("name");
        tili = (int)me->query("lifetili");
        tili_cost = 120 - lv;
		tili_cost = tili_cost /10*(10-me->query("save_for_doctor"));
        if( me->is_busy() )
           return notify_fail("����һ��������û����ɣ�\n");
        if( environment(me)->query("no_cook") )
           return notify_fail("�����޷�����������\n");
       
        if( me->is_fighting() )
           return notify_fail("ս������������������\n");

        if( me->query("lifetili") < tili_cost )
           return notify_fail("����������\n");
        ob1 = present("pilosulae",me);
        if (!ob1) return notify_fail("ȱ����ӡ�\n");
        ob2 = present("dioscoreae",me);
        if (!ob2) return notify_fail("ȱ�ٻ�ɽ��\n");
        ob3 = present("codonopsis",me);
        if (!ob3) return notify_fail("ȱ�ٵ��Ρ�\n");
        ob4 = present("astragalt",me);
        if (!ob4) return notify_fail("ȱ�ٱ��Ρ�\n");
        ob5 = present("lycii",me);
        if (!ob5) return notify_fail("ȱ�ٵ��顣\n");
        me->set("lifetili",tili - tili_cost );

        if( ob1 && ob2 && ob3 && ob4 && ob5  ) {
           message_vision("$N��һЩ��ҩ���뵤���У���������һ���Ʒ磬�����紦��ȥ������ʱǡ���ô�������ֻ��$N���ȶ�\n����˫�ֺϳ�ʮ�֣����в�ͣ��ĬĬ����һ�����һ��������뵤�����ͳ��ĺ�������������\n\n",me);
           destruct(ob1);
           destruct(ob2);
           destruct(ob3);
           destruct(ob4);
           destruct(ob5);
           call_out("give_yao",5,me,lv,exp,name);
           me->start_busy(5);
           return 1;
        }
}

private void give_yao(object me,int lv,int exp,string name)
{
        object obj;
        switch( random((lv+1))%10 ) {
        case 0:
        message_vision("$NС�������ش򿪵��������������һ�Ѻں����Ķ�����\n", me);
        obj=new("/obj/food/dan0");
        obj->set("long","һ����"+ name +"�������������ĺں����Ķ������ⶫ���ܳ��𣬻��ǸϽ����˰ɡ�\n");
        obj->move(me);
        break;
        case 1:
        message_vision("ɲ�Ǽ䣬��������ҫ�۵Ľ�⣬�������յ�һƬͨ���������콣�ⱦ����ӳ���£����е��˺���·𶼱����Ѥ�ö�Ŀ�ĵƻ���\n",me);
        obj=new("/obj/food/dan1");
        obj->set("long","һ����"+ name +"����������������ʵ�����˵ʳ��֮����Իָ�����������\n");
        obj->move(me);
        me->set("lifedoctor_exp",exp+1);
        break;
        case 2:
        message_vision("ɲ�Ǽ䣬��������ҫ�۵Ľ�⣬�������յ�һƬͨ���������콣�ⱦ����ӳ���£����е��˺���·𶼱����Ѥ�ö�Ŀ�ĵƻ���\n",me);
        obj=new("/obj/food/dan2");
        obj->set("long","һ����"+ name +"��������������ī�ɵ�����˵ʳ��֮����Իָ�����������\n");
        obj->move(me);
        me->set("lifedoctor_exp",exp+1);
        break;
        case 3:
        message_vision("ɲ�Ǽ䣬��������ҫ�۵Ľ�⣬�������յ�һƬͨ���������콣�ⱦ����ӳ���£����е��˺���·𶼱����Ѥ�ö�Ŀ�ĵƻ���\n",me);
        message_vision("$NС�������ش򿪵��������������һ��"HIM + "������" + NOR"��$N��ϲ����æ�ѵ�ҩ���뻳�С�\n", me);
        obj=new("/obj/food/dan3");
        obj->set("long","һ����"+ name +"�������������ĳ����񵤡���˵ʳ��֮����Իָ�����������\n");
        obj->move(me);
        me->set("lifedoctor_exp",exp+2);
        break;
        case 4:
        message_vision("ɲ�Ǽ䣬��������ҫ�۵Ľ�⣬�������յ�һƬͨ���������콣�ⱦ����ӳ���£����е��˺���·𶼱����Ѥ�ö�Ŀ�ĵƻ���\n",me);
        message_vision("$NС�������ش򿪵��������������һ��"HIM + "������" + NOR"��$N��ϲ����æ�ѵ�ҩ���뻳�С�\n", me);
        obj=new("/obj/food/dan4");
        obj->set("long","һ����"+ name +"�������������Ľ����񵤡���˵ʳ��֮����Իָ�����������\n");
        obj->move(me);
        me->set("lifedoctor_exp",exp+2);
        break;
        case 5:
        message_vision("������¡¡����Խ��Խ�󣬺ܿ죬һ�����׶�ߵĴ�¯�����ڵ�̨�ϡ���⽥����ȥ�����\n�����䣬��������ӿ������̨��һ�ɾ޴����������������\n",me);
        message_vision("$NС�������ش򿪵��������������һ��"HIM + "ȸ���ɵ�" + NOR"��$N��ϲ����æ�ѵ�ҩ���뻳�С�\n", me);
        obj=new("/obj/food/dan5");
        obj->set("long","һ����"+ name +"��������������ȸ���ɵ�����˵ʳ��֮����Իָ��󲿷����ĵ�������\n");
        obj->move(me);
        me->set("lifedoctor_exp",exp+3);
        break;
        case 6:
        message_vision("������¡¡����Խ��Խ�󣬺ܿ죬һ�����׶�ߵĴ�¯�����ڵ�̨�ϡ���⽥����ȥ�����\n�����䣬��������ӿ������̨��һ�ɾ޴����������������\n",me);
        message_vision("$NС�������ش򿪵��������������һ��"HIM + "�ݾ��ɵ�" + NOR"��$N��ϲ����æ�ѵ�ҩ���뻳�С�\n", me);
        obj=new("/obj/food/dan6");
        obj->set("long","һ����"+ name +"���������������ݾ��ɵ�����˵ʳ��֮����Իָ��󲿷����ĵķ�����\n");
        obj->move(me);
        me->set("lifedoctor_exp",exp+3);
        break;
        case 7:
        message_vision("������¡¡����Խ��Խ�󣬺ܿ죬һ�����׶�ߵĴ�¯�����ڵ�̨�ϡ���⽥����ȥ�����\n�����䣬��������ӿ������̨��һ�ɾ޴����������������\n",me);
        message_vision("$NС�������ش򿪵��������������һ��"HIM + "�����ɵ�" + NOR"��$N��ϲ����æ�ѵ�ҩ���뻳�С�\n", me);
        obj=new("/obj/food/dan7");
        obj->set("long","һ����"+ name +"�������������������ɵ�����˵ʳ��֮����Իָ��������ĵ�������\n");
        obj->move(me);
        me->set("lifedoctor_exp",exp+4);
        break;
        case 8:
        message_vision("������ʼ��С����Լ��С��һ��ʱ���ĵ�֮���ȶ�������$N������һ���������Ѿ���ȫ�����˵����ı�Դ֮��\n�������ȵ���ֱ�شӶ��������������������������������Χ������������ڵĸ�ˮһ�㡣\n",me);
        message_vision("$NС�������ش򿪵��������������һ��"HIM + "��Ȫʥ��" + NOR"��$N��ϲ����æ�ѵ�ҩ���뻳�С�\n", me);
        obj=new("/obj/food/dan8");
        obj->set("long","һ����"+ name +"����������������Ȫʥ������˵ʳ��֮����Իָ��������ĵķ�����\n");
        obj->move(me);
        me->set("lifedoctor_exp",exp+4);
        break;
		case 9:
        message_vision("������¡¡����Խ��Խ�󣬺ܿ죬һ�����׶�ߵĴ�¯�����ڵ�̨�ϡ���⽥����ȥ�����\n�����䣬��������ӿ������̨��һ�ɾ޴����������������\n",me);
        message_vision("$NС�������ش򿪵��������������һ��"HIM + "������" + NOR"��$N��ϲ����æ�ѵ�ҩ���뻳�С�\n", me);
        obj=new("/obj/food/dan9");
        obj->set("long","һ����"+ name +"�������������ķ���������˵ʳ��֮�����ʹ�˻ָ����ֻ�����\n");
        obj->move(me);
        me->set("lifedoctor_exp",exp+5);
        break;
        default:
        message_vision("$NС�������ش򿪵��������������һ�Ѻں����Ķ�����\n", me);
        break;
        }
        exp = (int)me->query("lifedoctor_exp") ;
		if (lv == 20)
		{
	        me->set("lifedoctor_exp",0);
		}
        if (exp > lv*lv*16) {
        me->set("lifedoctor_exp",0);
        me->set("lifedoctor",lv+1);
        write(HIW"����������ɽ����ˣ�\n"NOR);
		if (me->query("lifedoctor")==20)
			message("system",HIC "\n�����ַ��ơ���������"+me->query("name")+"���������������ϵĳɾͣ������"HIY"��ҽ���˲�������"HIC"�ĳƺš�\n" NOR,users());
			me->add("score",10000);
			write(HIW"�������������һ��㣡\n"NOR);
        }
        me->start_busy(5);
}

int help(object me)
{
        write(@HELP
ָ���ʽ : dolian 

���ָ��������������Լ�������������һЩ��ҩ.

HELP
    );
        return 1;
}