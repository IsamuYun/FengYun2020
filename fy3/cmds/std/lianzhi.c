// lianzhi.c by Tiandi 20071211
#include <ansi.h>

int main(object me, string arg)
{
        int lv,tili,tili_cost,stamp,clv,exp,bdamage;
        string name,ctype,newfile,filename,id,timestamp,cname;
        object ob1,ob2,ob;
        id = me->query("id");
        lv = (int)me->query("lifearmor");
        exp = me->query("lifearmor_exp");
        if (lv < 1)
        return notify_fail("�㻹������������ܡ�\n");

        name = me->query("name");
        tili = (int)me->query("lifetili");

        if( me->is_busy() )
                    return notify_fail("����һ��������û����ɣ�\n");
        if(! environment(me)->query("makearmor") )
                    return notify_fail("������Ʒ�����ڲ��̲��вſ��Խ��С�\n");
        if( me->is_fighting() )
                    return notify_fail("ս�������ƣ���������\n");
        if(!arg || sscanf(arg,"%s %d",ctype,clv) != 2)
                     return notify_fail("��������ȷ�ĸ�ʽ����ϸ�뿴help lianzhi��\n");
        if ( clv > lv)
                    return notify_fail("����Ҫ�����������ķ��ߣ�������ĥ��ĥ����\n");
        if ( clv > 10 || clv<1)
                    return notify_fail("���Ʒ��ߵĵȼ�ֻ��1-10��\n");
        tili_cost = 50*clv;
		tili_cost = tili_cost /10*(10-me->query("save_for_armor"));
        if( me->query("lifetili") < tili_cost )
                    return notify_fail("����������\n");
        ob1 = present("duan book",me);
        if (!ob1) return notify_fail("ȱ�ٷ��������õ�����ָ���顣\n");
        if(!ob1->query("for_create_armor")) return notify_fail("������Ŀ���飿\n");
        if(ob1->query("for_create_armor") < (int)clv)
                    return notify_fail("�Ȿ����ָ���黹���������Ƴ���˸߼��ķ��ߡ�\n");
        ob2 = present("old iron",me);
        if (!ob2) return notify_fail("ȱ�ٷ��������õ�������\n");
         if(!ob2->query("for_create_armor")&&!ob2->query("for_create_weapon")) return notify_fail("������Ŀ���飿\n");
        if(ob2->query("for_create_armor") < (int)clv)
                    return notify_fail("�����ϻ����������Ƴ���˸߼��ķ��ߡ�\n");
         if(ob1->query("mtype")!= ctype)
                   return notify_fail("�Ȿ�����鲻�����Ƴ�������ߡ�\n");
        seteuid(ROOT_UID);
        me->set("lifetili",tili-tili_cost);
        switch( ctype ) {
                    case "cloth":
                               newfile = read_file("/obj/armors/duancloth.c");
                              switch (clv) {
                                       case 1:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵİ�������\n");
                                        exp = exp + 1;
                                        cname = "������";
                                        break;
                                        case 2:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ����ƺͷ����޲�֯�͵ĳ��ۡ�\n");
                                        cname = HIW"���ƺͷ�"NOR;
                                        exp = exp + 2;
                                        break;
                                        case 3:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵĿ�ɳ�����������Ų���ɳ�����ɡ�\n");
                                        cname = MAG"��ɳ����"NOR;
                                        exp = exp + 3;
                                        break;
                                        case 4:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ�Ҷ�ư���ͼ���������ʵؾ��µĳ��ۣ��к�ǿ�ķ����� ��\n");
                                        cname =HIG"Ҷ�ư�"NOR;
                                        exp = exp + 4;
                                        break;
                                        case 5:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ�ҹ���ס��Ͻ�����ս�ף����������ż�ǿ�ķ�������\n");
                                        cname = RED"ҹ����"NOR;
                                        exp = exp + 5;
                                        break;
                                        case 6:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ�������¡��׽�������ս�״��������Ե�Ӣ���ˬ��\n");
                                        cname = YEL"�������"NOR;
                                        exp = exp + 6;
                                        break;
                                        case 7:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ����ս������˵�е���������ɵĿ��ף�����沼���Ѻ�ʵ�ʼ�Ӳ�ޱȡ�\n");
                                        cname = CYN"���ս��"NOR;
                                        exp = exp + 7;
                                        break;
                                        case 8:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ�����ս�ס�������֮���������ɡ�\n");
                                        cname = HIY"����ս��"NOR;
                                        exp = exp + 8;
                                        break;
                                        case 9:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ�����ħ�ۡ��ǻ�ë��ħ�����ķ��ߡ�\n");
                                        cname = HIR"����ħ��"NOR;
                                        exp = exp + 9;
                                        break;
                                        case 10:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ��������硣������������սʱ��ר��װ��������Ч�������֪��\n");
                                        cname =HIC "��������"NOR;
                                        exp = exp + 10;
                                        break;
                                        default:
                                        break;
                                        }
                               break;
                    case "head":
                               newfile = read_file("/obj/armors/duanhead.c");
                               switch (clv) {
                                        case 1:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ��鲼ͷ��������ͨͨ��\n");
                                        exp = exp + 1;
                                        cname = "�鲼ͷ��";
                                        break;
                                        case 2:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵĺ���ͷ����Ч�����鲼��Ҫ�õ㡣\n");
                                        cname = HIW"����ͷ��"NOR;
                                        exp = exp + 2;
                                        break;
                                        case 3:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ��ޱ�ñ��û��ñ�ص�ñ�ӡ�\n");
                                        cname = MAG"�ޱ�ñ"NOR;
                                        exp = exp + 3;
                                        break;
                                        case 4:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵĽ���ñ������������ʮ������\n");
                                        cname =HIG"����ñ"NOR;
                                        exp = exp + 4;
                                        break;
                                        case 5:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ�����ñ������һ���ܳ���̫����\n");
                                        cname = RED"����ñ"NOR;
                                        exp = exp + 5;
                                        break;
                                        case 6:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ�ǭ��Ƥñ���������ߵ�ζ����\n");
                                        cname = YEL"ǭ��Ƥñ"NOR;
                                        exp = exp + 6;
                                        break;
                                        case 7:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ��㻨����ƮҶ�㻨���һ�����ӡ�\n");
                                        cname = CYN"�㻨��"NOR;
                                        exp = exp + 7;
                                        break;
                                        case 8:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ���Ƥñ����֪����ʲôƤ�����ġ�\n");
                                        cname = HIY"��Ƥñ"NOR;
                                        exp = exp + 8;
                                        break;
                                        case 9:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵķ���ڣ����������з�˵���ë��\n");
                                        cname = HIR"�����"NOR;
                                        exp = exp + 9;
                                        break;
                                        case 10:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ�����ڣ���������Ƭ����������\n");
                                        cname =HIC "�����"NOR;
                                        exp = exp + 10;
                                        break;
                                        default:
                                        break;
                                        }
                               break;
                    case "neck":
                               newfile = read_file("/obj/armors/duanneck.c");
                              switch (clv) {
                                       case 1:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵĻ���������\n");
                                        exp = exp + 1;
                                        cname = "��������";
                                        break;
                                        case 2:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ�˫ɫ�����������ӳ��\n");
                                        cname = HIW"˫ɫ����"NOR;
                                        exp = exp + 2;
                                        break;
                                        case 3:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ�õ����������ȥ��һ��õ�塣\n");
                                        cname = MAG"õ����"NOR;
                                        exp = exp + 3;
                                        break;
                                        case 4:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ���ľ�飬ɢ����ľͷ������ ��\n");
                                        cname =HIG"��ľ��"NOR;
                                        exp = exp + 4;
                                        break;
                                        case 5:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ�Ц���������׺�һ��Ц��������������\n");
                                        cname = RED"Ц������"NOR;
                                        exp = exp + 5;
                                        break;
                                        case 6:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ�Ư�취�顣ϸϸ����������һ�Ž�׵����ӡ�\n");
                                        cname = YEL"Ư�취��"NOR;
                                        exp = exp + 6;
                                        break;
                                        case 7:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ��������衣���˴���������\n");
                                        cname = CYN"��������"NOR;
                                        exp = exp + 7;
                                        break;
                                        case 8:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵı�ˮ�塣���̵����ӣ�ȴ����������\n");
                                        cname = HIY"��ˮ��"NOR;
                                        exp = exp + 8;
                                        break;
                                        case 9:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ�Ǭ��������˵���Կ�������һ�С�\n");
                                        cname = HIR"Ǭ����"NOR;
                                        exp = exp + 9;
                                        break;
                                        case 10:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ�����֮�硣��������������������������м�ǿ�����á�\n");
                                        cname =HIC "����֮��"NOR;
                                        exp = exp + 10;
                                        break;
                                        default:
                                        break;
                                        }
                               break; 
                    case "boots":
                              newfile = read_file("/obj/armors/duanboots.c");
                              switch (clv) {
                                       case 1:
                                        newfile = replace_string( newfile, "����","һ˫��" + name + "���ƶ��ɵ���Ƥѥ��\n");
                                        exp = exp + 1;
                                        cname = "��Ƥѥ";
                                        break;
                                        case 2:
                                        newfile = replace_string( newfile, "����","һ˫��" + name + "���ƶ��ɵ�ţƤѥ��ţƤ�Ƴɡ�\n");
                                        cname = HIW"ţƤѥ"NOR;
                                        exp = exp + 2;
                                        break;
                                        case 3:
                                        newfile = replace_string( newfile, "����","һ˫��" + name + "���ƶ��ɵ���Ь���ܼӿ�ʹ���ߵ��ƶ��ٶȡ�\n");
                                        cname = MAG"��Ь"NOR;
                                        exp = exp + 3;
                                        break;
                                        case 4:
                                        newfile = replace_string( newfile, "����","һ˫��" + name + "���ƶ��ɵ����п������ǳ�����ѥ�ӣ�����·���ɿ� ��\n");
                                        cname =HIG"���п���"NOR;
                                        exp = exp + 4;
                                        break;
                                        case 5:
                                        newfile = replace_string( newfile, "����","һ˫��" + name + "���ƶ��ɵ�����ѥ�������г������˶���������\n");
                                        cname = RED"����ѥ"NOR;
                                        exp = exp + 5;
                                        break;
                                        case 6:
                                        newfile = replace_string( newfile, "����","һ˫��" + name + "���ƶ��ɵ�׷��ѥ����һ��ǧ��֮Ч����\n");
                                        cname = YEL"׷��ѥ"NOR;
                                        exp = exp + 6;
                                        break;
                                        case 7:
                                        newfile = replace_string( newfile, "����","һ˫��" + name + "���ƶ��ɵ�ս�����ġ��ܸ��õķ���ʹ���ߵ�������\n");
                                        cname = CYN"ս������"NOR;
                                        exp = exp + 7;
                                        break;
                                        case 8:
                                        newfile = replace_string( newfile, "����","һ˫��" + name + "���ƶ��ɵ�����ս�ġ�һֻ����Ƥ��һֻ�ɻ�Ƥ�Ƴɡ�\n");
                                        cname = HIY"����ս��"NOR;
                                        exp = exp + 8;
                                        break;
                                        case 9:
                                        newfile = replace_string( newfile, "����","һ˫��" + name + "���ƶ��ɵ�̤ѩ�޺ۡ���֮��Ӱ��磬̤ѩ�޺ۡ�\n");
                                        cname = HIR"̤ѩ�޺�"NOR;
                                        exp = exp + 9;
                                        break;
                                        case 10:
                                        newfile = replace_string( newfile, "����","һ˫��" + name + "���ƶ��ɵ������ɡ���֮���֮�У�������С�\n");
                                        cname =HIC "������"NOR;
                                        exp = exp + 10;
                                        break;
                                        default:
                                        break;
                                        }
                               break;   
                    case "finger":
                              newfile = read_file("/obj/armors/duanfinger.c");
                              switch (clv) {
                                       case 1:
                                        newfile = replace_string( newfile, "����","һö��" + name + "���ƶ��ɵ����䡣\n");
                                        exp = exp + 1;
                                        cname = "����";
                                        break;
                                        case 2:
                                        newfile = replace_string( newfile, "����","һö��" + name + "���ƶ��ɵ�÷���䣬����÷��״��\n");
                                        cname = HIW"÷����"NOR;
                                        exp = exp + 2;
                                        break;
                                        case 3:
                                        newfile = replace_string( newfile, "����","һö��" + name + "���ƶ��ɵ���ս�ָ���������������������\n");
                                        cname = MAG"��ս�ָ"NOR;
                                        exp = exp + 3;
                                        break;
                                        case 4:
                                        newfile = replace_string( newfile, "����","һö��" + name + "���ƶ��ɵĻ��䣬�������л��������� ��\n");
                                        cname =HIG"����"NOR;
                                        exp = exp + 4;
                                        break;
                                        case 5:
                                        newfile = replace_string( newfile, "����","һö��" + name + "���ƶ��ɵ������ָ��������������������\n");
                                        cname = RED"�����ָ"NOR;
                                        exp = exp + 5;
                                        break;
                                        case 6:
                                        newfile = replace_string( newfile, "����","һö��" + name + "���ƶ��ɵľ���䣬����֮�˲���ӵ�С�\n");
                                        cname = YEL"�����"NOR;
                                        exp = exp + 6;
                                        break;
                                        case 7:
                                        newfile = replace_string( newfile, "����","һö��" + name + "���ƶ��ɵ������������������ܴ�����������\n");
                                        cname = CYN"��������"NOR;
                                        exp = exp + 7;
                                        break;
                                        case 8:
                                        newfile = replace_string( newfile, "����","һö��" + name + "���ƶ��ɵĵ�����û����֪��������Դ��\n");
                                        cname = HIY"����"NOR;
                                        exp = exp + 8;
                                        break;
                                        case 9:
                                        newfile = replace_string( newfile, "����","һö��" + name + "���ƶ��ɵ��߲ʷ�ʯ���ʺ����������ֳ�����������\n");
                                        cname = HIR"�߲ʷ�ʯ"NOR;
                                        exp = exp + 9;
                                        break;
                                        case 10:
                                        newfile = replace_string( newfile, "����","һö��" + name + "���ƶ��ɵ������ָ�����ߵ�������\n");
                                        cname =HIC "�����ָ"NOR;
                                        exp = exp + 10;
                                        break;
                                        default:
                                        break;
                                        }
                               break;  
                    case "waist":
                              newfile = read_file("/obj/armors/duanwaist.c");
                              switch (clv) {
                                       case 1:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ�ϸ������\n");
                                        exp = exp + 1;
                                        cname = "ϸ����";
                                        break;
                                        case 2:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵĴ�����������ͨ��\n");
                                        cname = HIW"������"NOR;
                                        exp = exp + 2;
                                        break;
                                        case 3:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ��鲼������Ч����������\n");
                                        cname = MAG"�鲼����"NOR;
                                        exp = exp + 3;
                                        break;
                                        case 4:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ���Ƥ����������Ƥ�Ƴɵġ�\n");
                                        cname =HIG"��Ƥ����"NOR;
                                        exp = exp + 4;
                                        break;
                                        case 5:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵİ�¹���������з�����Ч����\n");
                                        cname = RED"��¹����"NOR;
                                        exp = exp + 5;
                                        break;
                                        case 6:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵĻ�Ƥ�������������Ƶ�װ����\n");
                                        cname = YEL"��Ƥ����"NOR;
                                        exp = exp + 6;
                                        break;
                                        case 7:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ���겼���򵥵�һ�鲼ȴ���кܴ�Ĺ�Ч��\n");
                                        cname = CYN"��겼"NOR;
                                        exp = exp + 7;
                                        break;
                                        case 8:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵĵ����������и�֮�˲��ܵõ�����\n");
                                        cname = HIY"��������"NOR;
                                        exp = exp + 8;
                                        break;
                                        case 9:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ���ɽ�������˳������������̡�\n");
                                        cname = HIR"��ɽ��"NOR;
                                        exp = exp + 9;
                                        break;
                                        case 10:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵĻ����ɴ��������Ч�ķ�������������\n");
                                        cname =HIC "�����ɴ�"NOR;
                                        exp = exp + 10;
                                        break;
                                        default:
                                        break;
                                        }
                               break; 
                    case "shield":
                              newfile = read_file("/obj/armors/duanshield.c");
                              switch (clv) {
                                       case 1:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ����ܡ�\n");
                                        exp = exp + 1;
                                        cname = "����";
                                        break;
                                        case 2:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵĸֶܣ�����Ч���ܲ\n");
                                        cname = HIW"�ֶ�"NOR;
                                        exp = exp + 2;
                                        break;
                                        case 3:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ������ܡ�����Ч����С��\n");
                                        cname = MAG"������"NOR;
                                        exp = exp + 3;
                                        break;
                                        case 4:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵĴ����ܣ��ô���з�Ŀ��Ƴɡ�\n");
                                        cname =HIG"������"NOR;
                                        exp = exp + 4;
                                        break;
                                        case 5:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ�����ܡ����кܺõķ�������\n");
                                        cname = RED"�����"NOR;
                                        exp = exp + 5;
                                        break;
                                        case 6:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ�ɺ���ܣ��кܸߵ����ԡ�\n");
                                        cname = YEL"ɺ����"NOR;
                                        exp = exp + 6;
                                        break;
                                        case 7:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ�����ս�ܡ���������ǿ�Ķ��ơ�\n");
                                        cname = CYN"����ս��"NOR;
                                        exp = exp + 7;
                                        break;
                                        case 8:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ�����ܡ���Ե�˲��ܵ�֮��\n");
                                        cname = HIY"�����"NOR;
                                        exp = exp + 8;
                                        break;
                                        case 9:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ���ᰶܡ�ɢ�������������⡣\n");
                                        cname = HIR"��ᰶ�"NOR;
                                        exp = exp + 9;
                                        break;
                                        case 10:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ�Ԫ�ɰԶܣ����е����ߡ�\n");
                                        cname =HIC "Ԫ�ɰԶ�"NOR;
                                        exp = exp + 10;
                                        break;
                                        default:
                                        break;
                                        }
                               break; 
                    case "wrists":
                              newfile = read_file("/obj/armors/duanwrists.c");
                              switch (clv) {
                                       case 1:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵĸ�������\n");
                                        exp = exp + 1;
                                        cname = "��������";
                                        break;
                                        case 2:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ����߻������ߵ�������\n");
                                        cname = HIW"���߻���"NOR;
                                        exp = exp + 2;
                                        break;
                                        case 3:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ�����̡��������޳������ʺϹ��������\n");
                                        cname = MAG"�����"NOR;
                                        exp = exp + 3;
                                        break;
                                        case 4:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ���廤�󣬼����塣\n");
                                        cname =HIG"��廤��"NOR;
                                        exp = exp + 4;
                                        break;
                                        case 5:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵİ�ս��硣ս���в���ȱ�ٵ�װ����\n");
                                        cname = RED"��ս���"NOR;
                                        exp = exp + 5;
                                        break;
                                        case 6:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ����˻���ÿһֻ�϶������һλ�������ˡ�\n");
                                        cname = YEL"���˻���"NOR;
                                        exp = exp + 6;
                                        break;
                                        case 7:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ�����������˸е�����ʮ�ֳ��ء�\n");
                                        cname = CYN"�����"NOR;
                                        exp = exp + 7;
                                        break;
                                        case 8:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ��˵����ƺ��й��������з������졣\n");
                                        cname = HIY"�˵�"NOR;
                                        exp = exp + 8;
                                        break;
                                        case 9:
                                        newfile = replace_string( newfile, "����","һ����" + name + "���ƶ��ɵ����ǵ��绤��������������֮�ġ�\n");
                                        cname = HIR"���ǵ��绤��"NOR;
                                        exp = exp + 9;
                                        break;
                                        case 10:
                                        newfile = replace_string( newfile, "����","һֻ��" + name + "���ƶ��ɵ�������绤��ֻ��һ������������д��\n");
                                        cname =HIC "������绤��"NOR;
                                        exp = exp + 10;
                                        break;
                                        default:
                                        break;
                                        }
                               break; 

							   default:
                               return notify_fail("���ַ����㻹�������ơ�\n");
                    }
        timestamp = sprintf("%c%c%c%c%c%c%d",
        'a'+random(20),'a'+random(20),'a'+random(20),'a'+random(20),'a'+random(20),
        'z',time());
       stamp=time();
       newfile = replace_string( newfile, "���Ƶ�", cname);
        newfile = replace_string( newfile, "order", ctype);
         newfile = replace_string( newfile, "fengyun", id);
         newfile = replace_string( newfile, "STAMP",timestamp);

      //  filename =  DATA_DIR+ "self/" +timestamp + ".c";
	  //  filename�ĳ����Ŀ¼�µģ������Ժ�readʱ����
		filename = DATA_DIR+"user/" + id[0..0] + "/" + id + "/" +timestamp + ".c";
        if( !write_file(filename, newfile,1))
                    return 0;
        ob = new(filename);
        if(ob2->query("equipped")) {ob2->unequip(); me->reset_action();}
        ob2->move(environment(me));
        bdamage = 100*(clv-1)+20+ random(80);
        ob->set("weight",ob2->query_weight());
        ob->set("rigidity",ob2->query("rigidity"));
		if (ctype == "cloth")
		{
			ob->set("armor_prop/armor",bdamage);
			ob->set("base_armor",bdamage);
		}
		else if (ctype == "head")
		{
			ob->set("armor_prop/marmor",bdamage/10*7);
			ob->set("armor_prop/mdamage",bdamage/10*9);
		}
		else if (ctype == "neck")
		{
			ob->set("armor_prop/addforce",random(bdamage/10)+clv);
			ob->set("armor_prop/dodge",bdamage);
		}
		else if (ctype == "boots")
		{
			ob->set("armor_prop/move",bdamage);
			ob->set("armor_prop/heavyhit",random(bdamage/100)+clv/2);
		}
		else if (ctype == "finger")
		{
			ob->set("armor_prop/addkee",random(bdamage/10)+clv*10);
			ob->set("armor_prop/addmana",random(bdamage/10)+clv*10);
		}
		else if (ctype == "waist")
		{
			ob->set("armor_prop/addeffkee",bdamage*2);
			ob->set("armor_prop/against",random(bdamage/100)+clv);
		}
		else if (ctype == "wrists")
		{
			ob->set("armor_prop/attack",bdamage*3/2);
			ob->set("armor_prop/mattack",bdamage/4);
		}
		else if (ctype == "shield")
		{
			ob->set("armor_prop/armor",bdamage/2);
			ob->set("base_armor",bdamage/2);
		}
        ob->set("limited_lv",clv*10);
        ob->set("value",clv*10000);
		ob->set("abradability",500);
		if (ctype != "cloth")
	{
			ob->set("level",20);
			ob->set("leveled",20);
	}
		if(!random(10))
			ob->add("abradability",clv*50);
		if(!random(10))
			ob->set("armor_prop/strength",random(clv*5)+1);
		if(!random(10))
			ob->set("armor_prop/courage",random(clv*5)+1);
		if(!random(10))
			ob->set("armor_prop/intelligence",random(clv*5)+1);
		if(!random(10))
			ob->set("armor_prop/spirituality",random(clv*5)+1);
		if(!random(10))
			ob->set("armor_prop/composure",random(clv*5)+1);
		if(!random(10))
			ob->set("armor_prop/personality",random(clv*5)+1);
		if(!random(10))
			ob->set("armor_prop/constitution",random(clv*5)+1);
		if(!random(10))
			ob->set("armor_prop/karma",random(clv*5)+1);
		if(!random(10))
			ob->set("armor_prop/agility",random(clv*5)+1);
		if(!random(10))
			ob->set("armor_prop/durability",random(clv*5)+1);
		if(!random(10))
			ob->set("armor_prop/flexibility",random(clv*5)+1);
		if(!random(10))
			ob->set("armor_prop/tolerance",random(clv*5)+1);
        ob->save();
        ob->restore();
        if(ob->move(me)){
        me->add("created_armor",1);
        me->start_busy(1);
        write("�㽫���ϵ�"+ob2->name()+"�ӽ��˴���¯�У�����"+ob1->name()+"���������ķ����������ƣ�һ������֮��һ"+ob->query("unit")+
        ob->name()+"����������ǰ��\n");
        me->set("lifearmor_exp",exp);
        destruct(ob2);
        destruct(ob1);
		seteuid(getuid());
        return 1;
        }
}

int help(object me)
{
write(@HELP
ָ���ʽ : lianzhi ��� ���ߵȼ�

���ָ���������������������Ƴ��������
ǰ������������������Ҫ�Ĳ��ϣ��������Ƶ�
�ȼ�Ҫ���ڷ��ߵȼ���
���������
	ͷ    head
	��    cloth
	��    boots
	��ָ  finger
	��    waist
	��    shield
	����  wrists
	����  neck

HELP
    );
return 1;
}