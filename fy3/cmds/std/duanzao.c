// duanzao.c by Tiandi 20071211
#include <ansi.h>

int main(object me, string arg)
{
        int lv,tili,tili_cost,stamp,clv,exp,bdamage;
        string name,ctype,newfile,filename,id,timestamp,cname;
        object ob1,ob2,ob;
        id = me->query("id");
        lv = (int)me->query("lifeweapon");
        exp = me->query("lifeweapon_exp");
        if (lv < 1)
        return notify_fail("�㻹������������ܡ�\n");

        name = me->query("name");
        tili = (int)me->query("lifetili");

        if( me->is_busy() )
                    return notify_fail("����һ��������û����ɣ�\n");
        if(! environment(me)->query("making") )
                    return notify_fail("������Ʒ�����������̲ſ��Խ��С�\n");
        if( me->is_fighting() )
                    return notify_fail("ս���ж��죿��������\n");
        if(!arg || sscanf(arg,"%s %d",ctype,clv) != 2)
                     return notify_fail("��������ȷ�ĸ�ʽ����ϸ�뿴help duanzao��\n");
        if ( clv > lv)
                    return notify_fail("����Ҫ������������������������ĥ��ĥ����\n");
        if ( clv > 10 || clv<1)
                    return notify_fail("���������ĵȼ�ֻ��1-10��\n");
        tili_cost = 50*clv;
		tili_cost = tili_cost /10*(10-me->query("save_for_weapon"));
        if( me->query("lifetili") < tili_cost )
                    return notify_fail("����������\n");
        ob1 = present("duan book",me);
        if (!ob1) return notify_fail("ȱ�����������õ�����ָ���顣\n");
        if(!ob1->query("for_create_weapon")) return notify_fail("������Ŀ���飿\n");
        if(ob1->query("for_create_weapon") < (int)clv)
                    return notify_fail("�Ȿ����ָ���黹�����Զ������˸߼���������\n");
        ob2 = present("old iron",me);
        if (!ob2) return notify_fail("ȱ�����������õ�������\n");
         if(!ob2->query("for_create_weapon")) return notify_fail("������Ŀ���飿\n");
        if(ob2->query("for_create_weapon") < (int)clv)
                    return notify_fail("�����ϻ������Զ������˸߼���������\n");
         if(ob1->query("mtype")!= ctype)
                   return notify_fail("�Ȿ�����鲻�ܶ��������������\n");
        seteuid(ROOT_UID);
        me->set("lifetili",tili-tili_cost);
        switch( ctype ) {
                    case "blade":
                               newfile = read_file("/obj/weapons/duanblade.c");
                              switch (clv) {
                                       case 1:
                                      newfile = replace_string( newfile, "����","һ����" + name + "������ɵ���������\n");
                                        exp = exp + 1;
                                        cname = "������";
                                        break;
                                        case 2:
                                        newfile = replace_string( newfile, "����","һ����" + name + "������ɵİ��絶���置���õı�������ϸ������\n");
                                        cname = HIW"���絶"NOR;
                                        exp = exp + 2;
                                        break;
                                        case 3:
                                        newfile = replace_string( newfile, "����","һ����" + name + "������ɵ�ҹ��ħ���������Ƴɵĵ�������������ҹħ֮ɫ��\n");
                                        cname = MAG"ҹ��ħ��"NOR;
                                        exp = exp + 3;
                                        break;
                                        case 4:
                                        newfile = replace_string( newfile, "����","һ����" + name + "�������������Ҷ��ϸ�䵶��\n");
                                        cname =HIG"��Ҷ��"NOR;
                                        exp = exp + 4;
                                        break;
                                        case 5:
                                        newfile = replace_string( newfile, "����","һ����" + name + "������ɵ���Ѫ������������ԼԼ�����Ǻ���һƬѪ����\n");
                                        cname = RED"��Ѫ��"NOR;
                                        exp = exp + 5;
                                        break;
                                        case 6:
                                        newfile = replace_string( newfile, "����","һ����" + name + "������ɵ��������������棬ȴ����ȥ���Ƹ�˯�ѵ�Ӥ����������\n");
                                        cname = YEL"�����"NOR;
                                        exp = exp + 6;
                                        break;
                                        case 7:
                                        newfile = replace_string( newfile, "����","һ����" + name + "������ɵ��������µ�����������ʱ�ع������İ��䵶����˵����������������\n��������£������ޱȣ��ڰ������ȡ�Ͻ��׼���̽��ȡ��ع�����������֪ȥ��Ψ��˵���\n");
                                        cname = CYN"�������µ�"NOR;
                                        exp = exp + 7;
                                        break;
                                        case 8:
                                        newfile = replace_string( newfile, "����","һ����" + name + "������ɵ�����ն�硣Ѹ�����磬һ��ն�¡�\n");
                                        cname = HIY"����ն��"NOR;
                                        exp = exp + 8;
                                        break;
                                        case 9:
                                        newfile = replace_string( newfile, "����","һ����" + name + "������ɵĻ���ŭ�С���˵�����ǻ����ù��ı�������˶�����ǧ�\n");
                                        cname = HIR"����ŭ��"NOR;
                                        exp = exp + 9;
                                        break;
                                        case 10:
                                        newfile = replace_string( newfile, "����","һ����" + name + "������ɵ�а��Ե�������֮�ԣ��ֵ�������а��һ��������һ�־������µĸо���\n");
                                        cname =HIC "а��Ե�"NOR;
                                        exp = exp + 10;
                                        break;
                                        default:
                                        break;
                                        }
                               break;
                    case "sword":
                               newfile = read_file("/obj/weapons/duansword.c");
                               switch (clv) {
                                        case 1:
                                        newfile = replace_string( newfile, "����","һ����" + name + "������ɵ�������\n");
                                        exp = exp + 1;
                                        cname = "����";
                                        break;
                                        case 2:
                                        newfile = replace_string( newfile, "����","һ����" + name + "������ɵ����񽣡����ƵĶ̽���ɫ������\n");
                                        cname = HIW"����"NOR;
                                        exp = exp + 2;
                                        break;
                                        case 3:
                                        newfile = replace_string( newfile, "����","һ����" + name + "������ɵ����潣��ƽ�����棬������˪��\n");
                                        cname = MAG"���潣"NOR;
                                        exp = exp + 3;
                                        break;
                                        case 4:
                                        newfile = replace_string( newfile, "����","һ����" + name + "������ɵ��޻��齣����������绨��ƬƬ���飬�����޻�ȴ�л���\n");
                                        cname =HIG"�޻��齣"NOR;
                                        exp = exp + 4;
                                        break;
                                        case 5:
                                        newfile = replace_string( newfile, "����","һ����" + name + "������ɵĺ��ƽ����Ժ���ʯ�Ƴ�,�������,��Ӳ�ޱ�,�ѵõ�����֮�\n");
                                        cname = RED"���ƽ�"NOR;
                                        exp = exp + 5;
                                        break;
                                        case 6:
                                        newfile = replace_string( newfile, "����","һ����" + name + "������ɵ����¡�ҹ���䣬��¶ü�⣬Ц����ڤ·��\n");
                                        cname = YEL"����"NOR;
                                        exp = exp + 6;
                                        break;
                                        case 7:
                                        newfile = replace_string( newfile, "����","һ����" + name + "������ɵĲط硣��������Ҷ��������ֱָ�����С�\n");
                                        cname = CYN"�ط�"NOR;
                                        exp = exp + 7;
                                        break;
                                        case 8:
                                        newfile = replace_string( newfile, "����","һ����" + name + "������ɵ����¿��졣����ʱ�����ذ������߿��裬��ɳ��ʯ�����ں�Х��\n");
                                        cname = HIY"���¿���"NOR;
                                        exp = exp + 8;
                                        break;
                                        case 9:
                                        newfile = replace_string( newfile, "����","һ����" + name + "������ɵ���ѩ�кۡ�̤ѩ�޺ۣ�ȴ��ѩ�кۣ�����ǧ��֮��ȡ���׼�������\n");
                                        cname = HIR"��ѩ�к�"NOR;
                                        exp = exp + 9;
                                        break;
                                        case 10:
                                        newfile = replace_string( newfile, "����","һ����" + name + "������ɵ���ˮ�̲����˽�������Ƭ������һƬ���۵�ӳ��ˮ�У�\n�̲�����֮�У������޷�ʶ�ƴ˽�������ʵ��Ρ�\n");
                                        cname =HIC "��ˮ�̲�"NOR;
                                        exp = exp + 10;
                                        break;
                                        default:
                                        break;
                                        }
                               break;
					  case "staff":
                               newfile = read_file("/obj/weapons/duanstaff.c");
                               switch (clv) {
                                        case 1:
                                        newfile = replace_string( newfile, "����","һ����" + name + "������ɵİ˽����ȡ�\n");
                                        exp = exp + 1;
                                        cname = "�˽�����";
                                        break;
                                        case 2:
                                        newfile = replace_string( newfile, "����","һ����" + name + "������ɵ�������ȡ������ޱȡ�\n");
                                        cname = HIW"�������"NOR;
                                        exp = exp + 2;
                                        break;
                                        case 3:
                                        newfile = replace_string( newfile, "����","һ����" + name + "������ɵ�ة���ȡ���˵Я��֮���г�һ�ջ��Ϊة�ࡣ\n");
                                        cname = MAG"ة����"NOR;
                                        exp = exp + 3;
                                        break;
                                        case 4:
                                        newfile = replace_string( newfile, "����","һ����" + name + "������ɵ��������ȡ�ӡ����ɮ���´�ʦʹ�õ����ȡ�\n");
                                        cname =HIG"��������"NOR;
                                        exp = exp + 4;
                                        break;
                                        case 5:
                                        newfile = replace_string( newfile, "����","һ����" + name + "������ɵ��޷��ȡ��Ժ�����ʯ������ɣ����ϳɵı���֮һ��\n");
                                        cname = RED"�޷���"NOR;
                                        exp = exp + 5;
                                        break;
                                        case 6:
                                        newfile = replace_string( newfile, "����","һ����" + name + "������ɵ����������಼�£�����������\n");
                                        cname = YEL"����"NOR;
                                        exp = exp + 6;
                                        break;
                                        case 7:
                                        newfile = replace_string( newfile, "����","һ����" + name + "������ɵĻ��⡣һ��ƫܰ�������������а�â���ֶ�����\n");
                                        cname = CYN"����"NOR;
                                        exp = exp + 7;
                                        break;
                                        case 8:
                                        newfile = replace_string( newfile, "����","һ����" + name + "������ɵ������ѩ������ʱ���ʱ�����ѩ������仯�޳���\n");
                                        cname = HIY"�����ѩ"NOR;
                                        exp = exp + 8;
                                        break;
                                        case 9:
                                        newfile = replace_string( newfile, "����","һ����" + name + "������ɵ��޻����ġ��ɴ�˵�е�������������ұ�����ɡ����Ժ�ʹ���ߵ�������ͬ��\n");
                                        cname = HIR"�޻�����"NOR;
                                        exp = exp + 9;
                                        break;
                                        case 10:
                                        newfile = replace_string( newfile, "����","һ����" + name + "������ɵ�Ǭ��������Ǭ��������������һ�ȶ�����������Ǭ����\n");
                                        cname =HIC "Ǭ������"NOR;
                                        exp = exp + 10;
                                        break;
                                        default:
                                        break;
                                        }
                               break;
					  case "hammer":
                               newfile = read_file("/obj/weapons/duanhammer.c");
                               switch (clv) {
                                        case 1:
                                        newfile = replace_string( newfile, "����","һ����" + name + "������ɵ�ͭо����\n");
                                        exp = exp + 1;
                                        cname = "ͭо��";
                                        break;
                                        case 2:
                                        newfile = replace_string( newfile, "����","һ����" + name + "������ɵľ��˴������˶���ޱ�,ʮ�ֳ��ء�\n");
                                        cname = HIW"���˴�"NOR;
                                        exp = exp + 2;
                                        break;
                                        case 3:
                                        newfile = replace_string( newfile, "����","һ����" + name + "������ɵĽ�����������ϵȸֲ��������ɡ�\n");
                                        cname = MAG"�������"NOR;
                                        exp = exp + 3;
                                        break;
                                        case 4:
                                        newfile = replace_string( newfile, "����","һ����" + name + "������ɵĿ�ɽ���������ô�����Ϊ��ɽ��·֮�á�\n");
                                        cname =HIG"��ɽ��"NOR;
                                        exp = exp + 4;
                                        break;
                                        case 5:
                                        newfile = replace_string( newfile, "����","һ����" + name + "������ɵĻ�Բ�����ι�״,˵���Ǵ��Ӳ���˵���Ǹ���\n");
                                        cname = RED"��Բ��"NOR;
                                        exp = exp + 5;
                                        break;
                                        case 6:
                                        newfile = replace_string( newfile, "����","һ����" + name + "������ɵĻ��紸��ʹ�������������,��Хһ�㡣\n");
                                        cname = YEL"���紸"NOR;
                                        exp = exp + 6;
                                        break;
                                        case 7:
                                        newfile = replace_string( newfile, "����","һ����" + name + "������ɵĺ�¡¡����¡¡.....��\n");
                                        cname = CYN"��¡¡"NOR;
                                        exp = exp + 7;
                                        break;
                                        case 8:
                                        newfile = replace_string( newfile, "����","һ����" + name + "������ɵĿ���ٵء�ʹ��ʱ�ᷢ������ٵذ��������ʹ�����������\n");
                                        cname = HIY"����ٵ�"NOR;
                                        exp = exp + 8;
                                        break;
                                        case 9:
                                        newfile = replace_string( newfile, "����","һ����" + name + "������ɵĻ�����ʯ����˵�е���ʯ����,���������Ǽ��������˿ɱ档\n");
                                        cname = HIR"������ʯ"NOR;
                                        exp = exp + 9;
                                        break;
                                        case 10:
                                        newfile = replace_string( newfile, "����","һ����" + name + "������ɵ�ǧ�ﴸ����һ������,ǧ��֮�������������Զ֮��\n");
                                        cname =HIC "ǧ�ﴸ��"NOR;
                                        exp = exp + 10;
                                        break;
                                        default:
                                        break;
                                        }
                               break;
					case "ring":
                               newfile = read_file("/obj/weapons/duanring.c");
                               switch (clv) {
                                        case 1:
                                        newfile = replace_string( newfile, "����","һ˫��" + name + "������ɵ���צȭ�ס�\n");
                                        exp = exp + 1;
                                        cname = "��צȭ��";
                                        break;
                                        case 2:
                                        newfile = replace_string( newfile, "����","һ˫��" + name + "������ɵĻ�צȭ�ס�ģ�»�צ�������ɡ�\n");
                                        cname = HIW"��צȭ��"NOR;
                                        exp = exp + 2;
                                        break;
                                        case 3:
                                        newfile = replace_string( newfile, "����","һ˫��" + name + "������ɵĸ���ȭ�ס���������ָ�����ܺܺõı�����\n");
                                        cname = MAG"����ȭ��"NOR;
                                        exp = exp + 3;
                                        break;
                                        case 4:
                                        newfile = replace_string( newfile, "����","һ˫��" + name + "������ɵ������С�ʹ���л��������\n");
                                        cname =HIG"������"NOR;
                                        exp = exp + 4;
                                        break;
                                        case 5:
                                        newfile = replace_string( newfile, "����","һ˫��" + name + "������ɵĹ��֡�������ڤ֮�����Ʒ������ɭɭ�Ĺ�����\n");
                                        cname = RED"����"NOR;
                                        exp = exp + 5;
                                        break;
                                        case 6:
                                        newfile = replace_string( newfile, "����","һ˫��" + name + "������ɵ�����ȭ�ס��ײ���������˵ʹ��ʱ�ܴ��������\n");
                                        cname = YEL"����ȭ��"NOR;
                                        exp = exp + 6;
                                        break;
                                        case 7:
                                        newfile = replace_string( newfile, "����","һ˫��" + name + "������ɵķ���С���ͷ��ˣ�һȭ�����¡�\n");
                                        cname = CYN"�����"NOR;
                                        exp = exp + 7;
                                        break;
                                        case 8:
                                        newfile = replace_string( newfile, "����","һ˫��" + name + "������ɵ�����������ʹ��ʱ�ᷢ��������ĺ�����ʹ���ֵ�ս�ľ���\n");
                                        cname = HIY"��������"NOR;
                                        exp = exp + 8;
                                        break;
                                        case 9:
                                        newfile = replace_string( newfile, "����","һ˫��" + name + "������ɵ���ʯ��ɽ������ޱȣ�����ʯ��ɽ��\n");
                                        cname = HIR"��ʯ��ɽ"NOR;
                                        exp = exp + 9;
                                        break;
                                        case 10:
                                        newfile = replace_string( newfile, "����","һ˫��" + name + "������ɵ�Ե����ɽ����Ե�˵�֮���ܶ����½�ɽ��\n");
                                        cname =HIC "Ե����ɽ"NOR;
                                        exp = exp + 10;
                                        break;
                                        default:
                                        break;
                                        }
                               break;
                    default:
                               return notify_fail("���������㻹������졣\n");
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
        bdamage = 100*(clv-1)+30+ random(100);
        ob->set("weight",ob2->query_weight());
        ob->set("rigidity",ob2->query("rigidity"));
        ob->set("weapon_prop/damage",bdamage);
        ob->set("base_damage",bdamage);
        ob->set("limited_lv",clv*10);
        ob->set("value",clv*10000);
		ob->set("abradability",500);
		if(!random(10))
			ob->add("abradability",clv*50);
		if(!random(10))
			ob->set("weapon_prop/strength",random(clv*5)+1);
		if(!random(10))
			ob->set("weapon_prop/courage",random(clv*5)+1);
		if(!random(10))
			ob->set("weapon_prop/intelligence",random(clv*5)+1);
		if(!random(10))
			ob->set("weapon_prop/spirituality",random(clv*5)+1);
		if(!random(10))
			ob->set("weapon_prop/composure",random(clv*5)+1);
		if(!random(10))
			ob->set("weapon_prop/personality",random(clv*5)+1);
		if(!random(10))
			ob->set("weapon_prop/constitution",random(clv*5)+1);
		if(!random(10))
			ob->set("weapon_prop/karma",random(clv*5)+1);
		if(!random(10))
			ob->set("weapon_prop/agility",random(clv*5)+1);
		if(!random(10))
			ob->set("weapon_prop/durability",random(clv*5)+1);
		if(!random(10))
			ob->set("weapon_prop/flexibility",random(clv*5)+1);
		if(!random(10))
			ob->set("weapon_prop/tolerance",random(clv*5)+1);
        ob->save();
        ob->restore();
        if(ob->move(me)){
        me->add("created_weapon",1);
        me->start_busy(1);
        write("�㽫���ϵ�"+ob2->name()+"�ӽ��˴���¯�У�����"+ob1->name()+"���������ķ������ж��죬һ������֮��һ"+ob->query("unit")+
        ob->name()+"��ճ����ˡ�\n");
        me->set("lifeweapon_exp",exp);
        destruct(ob2);
        destruct(ob1);
		seteuid(getuid());
        return 1;
        }
}

int help(object me)
{
write(@HELP
ָ���ʽ : duanzao ��� �����ȼ�

���ָ�����������������ܶ������������
ǰ�����������ж�����Ҫ�Ĳ��ϣ����Ҷ����
�ȼ�Ҫ���������ȼ���
Ŀǰ���ŵĿ��Զ��������
	��    sword
	��    blade
	��    staff
	ȭ��  ring
	��    hammer

HELP
    );
return 1;
}