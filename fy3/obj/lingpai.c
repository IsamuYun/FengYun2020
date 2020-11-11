// add for LSFY by atu 2000/01/10

#include <ansi.h>
inherit ITEM;
//inherit F_CLEAN_UP;
void kf_same(object who,object me);

void setup()
{}

void init()
{
        add_action("do_watch","guancha");
        add_action("do_watch","watch");
        add_action("do_catch","daibu");
        add_action("do_catch","catch");
}
int is_container() { return 1; }


void create()
{
	set_name("����", ({"ling pai","ling" }));
       set_max_encumbrance(10);
       set("unit", "��");
       set("long", "����һ����������,���ִ��죬����֤���ٸ���ʿ����ݡ�\n�����������Ȩ��Ѱ�ﷸ(guancha)���������ɷ�(daibu)��\n");
       set("value", 0);
       set("no_drop", "�������������뿪�㡣\n");
       set("no_burn",1);
       set("no_get", "���ǿ��⸮�Ķ�����ƽ�������˻����鷳�ġ�\n");
       set_weight(200);
       set("place","on");

       setup();
}
int do_watch(string arg)
{
	object obj,new_obj;
	object me = this_player();
	object ob = this_object();
	string targ;
	if (!me->query("kaifengfu"))
		return notify_fail("�㲢�ǳ�͢��Ա���αز�������ģ�\n");
	if (!ob=present("ling pai",me))
		return notify_fail("ʲô��\n");
	if (me->query_temp("kf_finish"))
		return notify_fail("�����˵��Żػ��ģ��㻹��ĥ��ʲô��\n");
	if (!arg||!obj=present(arg,environment(me)))
		return notify_fail("��Ҫ�۲�˭��\n");
	if( !obj->is_character() || obj->is_corpse() )
	return notify_fail("��ֻ�ܹ۲�һ��������塣\n");
//	if( !present("picture",ob))
//		return notify_fail("�����Ѿ����������ɷ�����ĥ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("����æ�š�\n");
	targ=obj->query("name");
	tell_object(me,"����������������"+targ+"��\n\n");
//	me->start_busy(1);

	if (obj->query_temp("kf_tufei")==me->query_temp("kf_npc")
	&&  random(me->query("kar")+15)>10){
		switch(random(5)) {
		case 0:
			tell_object(me,WHT"�㷢��"+targ+"��Ȼ��ͷһ�ͣ��ƺ���ܿ����Ŀ�⡣\n\n"NOR);
                     break;
		case 1:
			tell_object(me,WHT"�㷢��"+targ+"��Ȼ���˸����£�������ɫ��\n\n"NOR);
			break;
		case 2:
			tell_object(me,WHT"�㷢��"+targ+"̫��Ѩ�߸߷����ƺ��Ǹ�������ˡ�\n\n"NOR);
			break;
		case 3:
			tell_object(me,WHT"�㷢��"+targ+"����Ĺ����ҵģ���������һ�����С�\n\n"NOR);
			break;
		case 4:
			tell_object(me,WHT"�㷢��"+targ+"�����о���һ���������ֱ��һ��ãȻ��\n\n"NOR);
			break;
		}
		me->set_temp("kf_faxian",1);
		obj->set_temp("kf_faxianed",me->query("id"));

		}  
	else{
		switch(random(11)) {
			case 0:
			tell_object(me,"ֻ��"+targ+"����üŪ�ۣ�ɫ���ԵĶ���������\n\n");
			break;
			
			case 1:
			tell_object(me,"ֻ��"+targ+"������Ƽ��ݣ��������\n\n");
			break;
			
			case 2:
			tell_object(me,"ֻ��"+targ+"���΢�죬һ�����ߵ�ģ����\n\n");
                     break;
                
			case 3:
			tell_object(me,"ֻ��"+targ+"�������⣬�������硣\n\n");
			break;
			
			case 4:
			tell_object(me,"ֻ��"+targ+"��ʹ�������޵���������Ƶġ�\n\n");
			break;

			case 5:
			tell_object(me,"ֻ��"+targ+"���㽩Ӳ������ɢ���Ž�������\n\n");
			break;

			case 6:
			tell_object(me,"ֻ��"+targ+"���ޱ��飬����ľ����\n\n");
			break;
			
			case 7:
			tell_object(me,"ֻ��"+targ+"���ü��������Ŀ���թ��\n\n");
			break;
         
			case 8:
			tell_object(me,"ֻ��"+targ+"��Ц���������ϼ���һ˿��Ц��\n\n");
			break;
                
			case 9:
         
			tell_object(me,"ֻ��"+targ+"ͦ�ص��ǣ�һ����������ɫ��\n\n");
                     break;
                
			case 10:
			tell_object(me,"ֻ��"+targ+"���������ݣ�һ���������ɫ��\n\n");
			break;
		}
	}
	return 1;
}

int do_catch(string arg)
{
	object obj,new_obj;
	object me = this_player();
	object ob = this_object();                        //100
	if (!ob=present("ling pai",me))
		return notify_fail("ʲô��\n");
	if (!me->query("kaifengfu"))
		return notify_fail("�㲢�ǳ�͢��Ա���αز�������ģ�\n");
	if (me->query_temp("kf_finish"))
		return notify_fail("�����˵��Żػ��ģ��㻹��ĥ��ʲô��\n");
	if (!arg||!obj=present(arg,environment(me)))
		return notify_fail("��Ҫ����˭��\n");
	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("��ֻ�ܴ���һ�����ˡ�\n");
	if( !me->query_temp("kf_faxian")
	|| obj->query_temp("kf_faxianed")!=me->query("id") )
		return notify_fail("���⸮����������û��֤���������ˣ�\n");
	message_vision ("$N����$n��Цһ���������µİ��ӷ��ˣ�����ʵʵ��������һ�ˡ�\n\n",me,obj);
        if ((int)me->query_temp("kf_whatnpc")==1)  new_obj = new("/d/kaifengfu/npc/tufei1.c");
    if ((int)me->query_temp("kf_whatnpc")==2)  new_obj = new("/d/kaifengfu/npc/tufei2.c");
    if ((int)me->query_temp("kf_whatnpc")==3)  new_obj = new("/d/kaifengfu/npc/tufei3.c");
    if ((int)me->query_temp("kf_whatnpc")==4)  new_obj = new("/d/kaifengfu/npc/tufei4.c");
    if ((int)me->query_temp("kf_whatnpc")==5)  new_obj = new("/d/kaifengfu/npc/tufei5.c");
    if ((int)me->query_temp("kf_whatnpc")==6)  new_obj = new("/d/kaifengfu/npc/tufei6.c");
	message_vision (RED"$n���һ���ҿ�αװ��¶��������Ŀ��\n"NOR,me,obj);
//	destruct(obj);
	obj->delete_temp("kf_faxianed");
//       new_obj = present("picture",ob);
	kf_same(new_obj,me);    
       new_obj->move(environment(me));    
	message_vision (RED"$n��ȵ������Ӻ���ƴ�ˣ�\n"NOR,me,new_obj);
       new_obj->kill_ob(me);
       me->kill_ob(new_obj);
       new_obj->set_leader(me);
       new_obj->set_temp("kf_npc",me->query_temp("kf_npc"));
       new_obj->set_temp("kf_ownname",me->query("id"));
       new_obj->delete("no_see");
       new_obj->start_busy(1);
       me->delete_temp("kf_faxian");
//	me->set_temp("kf_finish");
       return 1;
}

void kf_same(object who,object me)
{
	mapping myscore;
	int maxskill;
	myscore = me->query_entire_dbase();
	who->set("combat_exp", (int)me->query("combat_exp")*10/7);

	who->set("max_kee", (int)myscore["max_kee"]);
	who->set("eff_kee", (int)myscore["eff_kee"]);
	who->set("kee", (int)myscore["max_kee"]);

	who->set("max_gin", (int)myscore["max_gin"]);
	who->set("eff_gin", (int)myscore["eff_gin"]);
	who->set("gin", (int)myscore["max_gin"]);

	who->set("max_sen", (int)myscore["max_sen"]);
	who->set("eff_sen", (int)myscore["eff_sen"]);
	who->set("sen", (int)myscore["max_sen"]);

	who->set("max_force", (int)myscore["max_force"]);
	who->set("force", (int)myscore["max_force"]);
	who->set("force_factor", 0);
	maxskill = me->query_skill("force",1);
	if(maxskill < me->query_skill("parry",1)) maxskill=me->query_skill("parry",1); 
	if(maxskill < me->query_skill("dodge",1)) maxskill=me->query_skill("dodge",1); 
	if(maxskill < me->query_skill("sword",1)) maxskill=me->query_skill("sword",1); 
	if(maxskill < me->query_skill("blade",1)) maxskill=me->query_skill("blade",1); 
	if(maxskill < me->query_skill("unarmed",1)) maxskill=me->query_skill("unarmed",1); 
	who->set("maxskill",maxskill);

}

