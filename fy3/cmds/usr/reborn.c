// reborn.c
// yiru@hero
// ������������ʹ�ô����
#include <ansi.h>

inherit F_CLEAN_UP;

int reborn_skill(object ob);
int reborn_attrib(object ob);

string *revive_loc= ({
  "/d/fy/church",
  "/u/guanwai/tower",
});

int main(object me, string arg)
{
	if ( me->query("level") < 101 )
	{
		write(HIY"��Ҳ������!!!!!\n\n��ĵȼ�̫�ͣ����޷�������\n\n\n"NOR);
		return 1;
	}

	if( me->query("reborned") > 5 )
	{
		write(HIY"��Ҳ������!!!!!\n\n���Ѿ������ٴ������ˣ�\n\n\n"NOR);
		return 1;		
	}
	
	write(HIC"��������\n"NOR);
	input_to("check_password", 1, me, 1);
	return 1;
}

void check_password(string passwd, object me, int flag)
{
    object link_ob;
    string old_pass;

    link_ob = me->query_temp("link_ob");
    old_pass = link_ob->query("password");

    if ( crypt(passwd, old_pass) != old_pass )
    {
        write(HIM"����ԡ�\n"NOR);
        return;
    }

    reborn_skill(me);
    reborn_attrib(me);

    log_file("static/reborn",
      sprintf("%s rebornd once on %s\n",
        me->name_id(), ctime(time()) ) );

    return ;
}

int reborn_skill(object ob)
{
    mapping skills;
    string *sk;
   
	skills = ob->query_skills();
	if (!sizeof(skills))
	{
	    return 1;
	}
	
	sk = keys(skills);
	foreach ( string sname in sk )
	{
		//����literate�ļ���
	    if ( sname == "literate" ) continue;
            if ( sname == "incarnation" ) continue;          
	    //�������300
	    if ( skills[sname] >= 300 )
	    {
	    	ob->set_skill(sname, 300 );
	    }
        else
	    {
	    	ob->delete_skill(sname);
	    }
	}

    return 1;
}

int reborn_attrib(object ob)
{
object silk;

string *attribs = ({ "tol", "cps", "cor", "con", "per",
      "kar", "str", "fle", "dur", "agi" }); // "int" "spi" ����

    //�����ʦ
	ob->delete("betrayer");
   //�ع����
    ob->delete("class");
    ob->delete("family");
    ob->set("title", "��ͨ����-ת��");

    foreach (string attrib in attribs)
    {
        if ( ob->query(attrib) >= 60 )
        {
        	ob->set(attrib, 60);
        }
        else
        {
        	ob->set(attrib, 6);
        }
    }

    ob->set("combat_exp", 1000000);
    ob->set("potential",0);
    ob->set("learned_points",0);
    ob->set("pot_deposit",0);
    ob->set("score", 3000);
    ob->set("used_gift_points",0);
    ob->set("bellicosity", 0);
    ob->set("mud_age", 0);
  ob->set("eatdans", 0);
  ob->set("eatxpd", 0);
  ob->set("eatwqd", 0);
ob->set("alibaoo_over", 0);
ob->set("tiejob",0);



 ob->set("killhyr", 0);
 ob->set("jiebiao", 0);
 ob->set("ftongji", 0);
 ob->set("get_lin_end", 0);
 ob->set("succ_letter_num", 0);
 ob->set("TASK", 0);
 ob->set("bigtasks", 0);
 ob->set("kf_worked", 0);
ob->set("age_modify",0);
ob->set("kf_jiangli",0);
 
	ob->set("max_mana", 0);
	ob->set("max_force", 0);
	ob->set("max_atman", 0);
	ob->set("mana", 0);
	ob->set("force", 0);
	ob->set("atman", 0);

    UPDATE_D->check_user(ob);
    ob->delete("vendetta");
    ob->delete("vendetta_mark");

	ob->set("deposit", 1000000);
	message("system",HIY "\n��ϵͳ��Ϣ��:"+HIR "��Ȼ�䣬��������һ��ҫ�۵ĺ�ɫ��������������Ϸ·����»��꣬˲���ȼ�˵���Ĳ�ľɭ��,��˼����翣���ʶ���������������"+ob->name()
    	+"��"+environment(ob)->query("short")+"�����ˡ�\n" NOR,users());
	message("system",HIY "\n��ϵͳ��Ϣ��:"+HIG "��ϲ"+ob->name()+"����ת����\n" NOR,users());
	ob->unconcious();
    ob->move(revive_loc[random(sizeof(revive_loc))]);
	ob->set("startroom", base_name(environment(ob)));

	message("vision",
          "���Ȼ����ǰ�����һ����Ӱ����������Ӱ�ֺ����Ѿ�������\n"
          "�ܾ��ˣ�ֻ����һֱû������\n", environment(ob), ob);

    ob->add("reborned", 1);
silk = new("/obj/prize/f_p");
silk->move(ob);
       
    ob->save();
    return 1;
}

int help(object me)
{
    write(@HELP
ָ���ʽ :
    reborn

������
    ���Ա����������300������������ɳ��⣩,����300�������������������60�㣬���Ǻ����Գ��⡣
    ����¼����,��Ҫ�������5�κ�ſ��Ժ���һ���໥ѧϰ��
    ���屣������������������ױ�����
�����
    ����Ѱ�ʦ��־����Ϊ��ͨ���ա�
    ���Ǳ�ܣ�����Ѵ�Ǳ�ܣ�
    ���������1M��

�ɻ�ã�
    �󻹵�һ��������ɽɱ��̽���Ļ��ᣨ����������ӣ�
    
    
����������
 �Ե��˺��Ͷ��˺������ն�����Ϊԭ������1+reborned),
 ����TASK����quest�ȣ���sc������ĳ������������Ľ��������ϳ�������ֵ��
 ԭ���Ľ�������1+reborned/5)
 ����2����������ܰݵ�������,�����ͨ���ղ��ܰݰ�������.

���ƣ�
����5�Ρ�

HELP);
    return 1;
}
