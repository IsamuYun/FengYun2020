#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
       int  exp1;
	object ob;
	string obj,exp2;
        if( !arg )      return notify_fail("settop <ĳ��> <exp/pot/score/atman/force/mana/int/dur/spi/str/kar/per/con/cor/cps/fle/tol/agi/gongxian/mud_age> <����>��\n");
        if( !arg || sscanf(arg, "%s %s %d", obj, exp2, exp1)!=3 )
                        return notify_fail("settop <ĳ��> <exp/pot/score/atman/force/mana/int/dur/spi/str/kar/per/con/cor/cps/fle/tol/agi/gongxian/mud_age> <����>��\n");
	if( !ob )	ob = find_living(obj);
	if( !ob )	ob = present(obj, environment(me));
        if( !ob ) return notify_fail("�Ҳ����������.\n");

	switch (exp2){
		case "mana":
			ob->set("max_mana",exp1);
			tell_object(ob,HIR"���������Ϊʹ��ʦ���������࿴,��˵����㷨��Ϊ��\n" +
			chinese_number(exp1) + "�㷨��!\n"NOR);
			break;
		case "force":
			ob->set("max_force",exp1);
                        tell_object(ob,HIR"���������Ϊʹ��ʦ���������࿴,��˵���������Ϊ��\n" +                      
                        chinese_number(exp1) + "������!\n"NOR);
			break;
		case "atman":
			ob->set("max_atman",exp1);
			tell_object(ob,HIR"���������Ϊʹ��ʦ���������࿴,��˵���������Ϊ��\n" +
			chinese_number(exp1) + "������!\n"NOR);
			break;
                case "mud_age":
                        ob->set("mud_age",exp1);
                        tell_object(ob,HIR"���������Ϊʹ��ʦ���������࿴,��˵���������ʱ��Ϊ��\n" +
                        chinese_number(exp1) + "��!!\n"NOR);
                   	break;
		case "exp":
			ob->set("combat_exp",exp1);
			tell_object(ob,HIR"���������Ϊʹ��ʦ���������࿴,��˵�����ʵս����Ϊ��\n" +
			chinese_number(exp1) + "��ʵս����!\n"NOR);
			break;
		case "pot":
			ob->set("potential",exp1);
		       tell_object(ob,HIR"���������Ϊʹ��ʦ���������࿴,��˵�����Ǳ��Ϊ��\n" +
			chinese_number(exp1) + "��Ǳ��!\n"NOR);
			break;
		case "score":
			ob->set("score",exp1);
		       tell_object(ob,HIR"���������Ϊʹ��ʦ���������࿴,��˵���������Ϊ��\n" +
			chinese_number(exp1) + "������!\n"NOR);
			break;
                case "int":
			ob->set("int",exp1);
		       tell_object(ob,HIR"���������Ϊʹ��ʦ���������࿴,��˵��������Ϊ��\n" +
			chinese_number(exp1) + "�����!\n"NOR);
			break;
                case "dur":
			ob->set("dur",exp1);
		       tell_object(ob,HIR"���������Ϊʹ��ʦ���������࿴,��˵���������Ϊ��\n" +
			chinese_number(exp1) + "������!\n"NOR);
			break;
                case "spi":
			ob->set("spi",exp1);
		       tell_object(ob,HIR"���������Ϊʹ��ʦ���������࿴,��˵���������Ϊ��\n" +
			chinese_number(exp1) + "������!\n"NOR);
			break;
                case "str":
			ob->set("str",exp1);
		       tell_object(ob,HIR"���������Ϊʹ��ʦ���������࿴,��˵���������Ϊ��\n" +
			chinese_number(exp1) + "������!\n"NOR);
			break;
                case "kar":
			ob->set("kar",exp1);
		       tell_object(ob,HIR"���������Ϊʹ��ʦ���������࿴,��˵���������Ϊ��\n" +
			chinese_number(exp1) + "������!\n"NOR);
			break;
                case "per":
			ob->set("per",exp1);
		       tell_object(ob,HIR"���������Ϊʹ��ʦ���������࿴,��˵���������Ϊ��\n" +
			chinese_number(exp1) + "������!\n"NOR);
			break;
                case "con":
			ob->set("con",exp1);
		       tell_object(ob,HIR"���������Ϊʹ��ʦ���������࿴,��˵���������Ϊ��\n" +
			chinese_number(exp1) + "������!\n"NOR);
			break;
                case "cor":
			ob->set("cor",exp1);
		       tell_object(ob,HIR"���������Ϊʹ��ʦ���������࿴,��˵���������Ϊ��\n" +
			chinese_number(exp1) + "������!\n"NOR);
			break;
                case "cps":
			ob->set("cps",exp1);
		       tell_object(ob,HIR"���������Ϊʹ��ʦ���������࿴,��˵���������Ϊ��\n" +
			chinese_number(exp1) + "������!\n"NOR);
			break;
                case "fle":
			ob->set("fle",exp1);
		       tell_object(ob,HIR"���������Ϊʹ��ʦ���������࿴,��˵���������Ϊ��\n" +
			chinese_number(exp1) + "������!\n"NOR);
			break;
                case "tol":
			ob->set("tol",exp1);
		       tell_object(ob,HIR"���������Ϊʹ��ʦ���������࿴,��˵����㶨��Ϊ��\n" +
			chinese_number(exp1) + "�㶨��!\n"NOR);
			break;
                case "agi":
			ob->set("agi",exp1);
		       tell_object(ob,HIR"���������Ϊʹ��ʦ���������࿴,��˵������ٶ�Ϊ��\n" +
			chinese_number(exp1) + "���ٶ�!\n"NOR);
			break;
                case "gongxian":
			ob->set("gongxian",exp1);
		       tell_object(ob,HIR"���������Ϊʹ��ʦ���������࿴,��˵����㹱��Ϊ��\n" +
			chinese_number(exp1) + "�㹱��!\n"NOR);
			break;
			}
                     return 1;
       }
