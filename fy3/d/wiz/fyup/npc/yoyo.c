// by Tiandi for reborned user
inherit NPC;
#include <ansi.h>
void create()
{
	set_name("������", ({ "yoyo" }) );
	set("gender", "Ů��" );
	set("age", 23);
        set("title","���׵ܵ����������յĿ������");
	set("long", "һ�����պܺ�ȴ���������Ĵ��ʦ��\n");
   	set("per", 160);
	set("combat_exp",200000000 );
	set("attitude", "friendly");
	set("chat_chance", 1);
	set_skill("sword",500);
	set_skill("iron-cloth",500);
	set_skill("yiqiforce",500);

         map_skill("iron-cloth","yiqiforce");
	set_skill("fallingstar-sword",500);
         map_skill("sword","fallingstar-sword");
	set("max_force", 15000);
          set("max_kee", 555000);
        set("max_sen", 255000);
         set("max_gin", 255000);
         set("max_mana", 15000);
         set("max_atman", 15000);
         set("force", 15000);
         set("atman", 15000);
         set("mana", 15000);
          set("force_factor", 500);
	set("marry","fengsh");
	set("marryname","���ĺ�");

	set("marks/kuaihuo",1);
	set("TASK",3000);
	set("chat_chance_combat", 50 );
	set("chat_msg", ({   "�����������ܵ�~~������?�������ƵĲ�,����������\n",
			   "�������߿���˵��������С��,������ȥ��,�ò����������˲�,���������ˡ�\n",
				}) );
	set("chat_msg_combat", ({"������ŭ���������ҵĵ������£�������ˣ����㽶Ƥ��\n",
				  (: perform_action, "sword.onheart" :),
				 "������һ�ߴ�һ�߽�.....������С͵����͵���Ҹ��ܵ����Ĳ�..�Ҵ�~~~��\n", 
				    (: perform_action, "sword.tianyaliuxing" :),
				 
				}) );
				
	set("inquiry", (["�㽶" : "�ҵܵ���ϲ���԰�˿�㽶�ˣ���ÿ�춼Ҫ�ո����ԡ�",   
		          "����" : "�����������Ե�������������(upmax_hp)��Ӧ�ľ�����" ,
		        "�ղ�" : "������������һ���µĲ�,���㽶,��ˮ,����,�ɿ���Ϊԭ��,ζ��һ��������" ,
		     "�ܵ�" : "����С���ֲ�֪������ȥ��,�ѵ������Ĳ���ô����ô��" ,
               "����":"ֻҪ�����ǲ������ĵܴܵ��������������ཱܶ��Ŷ~",
			"˫Ч��":"ÿ���һ�ٸ�ʹ�����Ե���������ȡ(getreward)����һ��˫Ч��",
				]));

	setup();
       	 carry_object("/d/fy/npc/obj/leafsword")->wield();

}
void init()
{
	add_action("do_upgrade", "upmax_hp");
	add_action("do_change", "getreward");
}
int do_change()
{
	object me,dan;
	int a,b;
	me = this_player();
	a = me->query("TASK");
	b = me->query("TASKREWARD");
	if (a - b > 99) 
	{
		a = a -100;
		dan = new("/obj/food/double");
		dan ->move(me);
		me->add("TASKREWARD",100);
		write("�����������������һ��˫Ч����\n");
		message("system",HIY "\n�����ַ��ơ�ʹ��������"+me->query("name")+"�����ڷ�Ŭ������ɷ���ʹ�����������������ʶ������һ��˫Ч����ʾ������\n" NOR,users());
	}
	else
		write("��Ŀǰ��ɵ�ʹ������������\n");
	return 1;
}
int do_upgrade()
{
	object me;
	int reb,rebb;
	mapping my;

	me = this_player();
	reb = me->query("reborned"); 
	rebb = me->query("rebb");
	if (!reb)  
	{
		message_vision("$N����$n˵����"+RANK_D->query_respect(me)+"�㻹û���������ɣ�����ˣ����ˣ�\n",this_object(), me);    
         	  	return 1;  
	}
	if (rebb < reb)
	 {
	 	message_vision("$N˵������Ȼ���Ѿ��������ˣ��ǽ���ҾͰ�������һ�¸��������ɣ�\n",this_object(), me);    
		me->set("rebb",reb);
		me->save();
                message("system",HIC "\n�����ַ��ơ�����������"+me->query("name")+"�������������ʷ����˱仯����˾������������޵õ��������ˡ�\n" NOR,users());
		return 1;
	}
	else
		message_vision("$N˵����$n�ǲ����Ѿ������ˣ�����ô�о���ô�����أ�\n",this_object(), me);    
	return 1;
}
void die()
{
        int gin,kee,sen;
        gin =(int)query("max_gin");
        kee =(int)query("max_kee");
        sen =(int)query("max_sen");
        set("eff_kee",kee);set("kee",kee);
        set("eff_gin",gin);set("gin",gin);
        set("eff_sen",sen);set("sen",sen);
    message_vision("$N�ӻ����ó�һöʮȫ����������һ�ţ���ʱ�������ָֻ��������״̬��\n",this_object());
        return ;

}

