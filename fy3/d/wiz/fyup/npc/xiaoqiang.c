 // fy@wuji   testdamagenpc
#include <ansi.h>
inherit NPC; 
void create()
{
    set_name("Сǿ", ({ "xiao qiang" }) );
        set("race", "Ұ��");
        set("title",WHT"Сǿ������"NOR);
        set("nickname", HIY"��Ҷ�������"NOR);
        set("age", 32);
        set("long", "һֻ�޴��Сǿ.\n�����(fight xiao qiang)�����Թ�����˺���(stop test)ֹͣ���ԡ�\n"); 
        set("max_kee", 999999);
        set("max_gin", 999999);
        set("max_sen", 999999); 
        set("eff_kee", 999999);
        set("eff_gin", 999999);
        set("eff_sen", 999999); 
        set("kee", 999999);
        set("gin", 999999);
        set("sen", 999999); 
        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("attitude", "heroism");
          set("combat_exp", 1000000);
      set("chat_chance", 10);
        set("chat_msg", ({
        "Сǿ����������һֻССǿ��СѽССǿ��\n",
        "Сǿ�Ǻǵ�������һֻ������СǿŶ��\n",
        }) ); 
       
        setup();
        
        
} 
/*
varargs int receive_damage(string type, int damage)
{
       
        
    object me;
    int r_damage,gindam,keedam,sendam;
    me = this_player();
      
       
        if (damage <0) damage =0;
        if( type!="gin" && type!="kee" && type!="sen" )
                error("F_DAMAGE: �˺��������( ֻ���� gin, kee, sen ����֮һ )��\n"); 
	//add by tiandi ��������
	if( objectp(who))
		if(who->query("damagelv") )
			damage += damage /25*(int)who->query("damagelv");
	if (query("defenselv") > 0)
		damage = damage /25 * (25 - query("defenselv"));

         if (type != "gin"){
                gindam = 0;
            } else {
                gindam = damage;
                message_vision(HIW"\nСǿ���棺$N�ղ������ͨ�˺���"HIY"����"HIW"����ʧΪ"+(string)(gindam)+"����ϣ�\n"NOR, me);
            }


             if (type != "kee"){
                keedam = 0;
            } else {
              keedam = damage;
                  message_vision(HIW"\nСǿ���棺$N�ղ������ͨ�˺���"HIR"��Ѫ"HIW"����ʧΪ"+(string)(keedam)+"����ϣ�\n"NOR, me);
            }

 


             if (type != "sen"){
                sendam = 0;
             } else { 
             sendam = damage;
            message_vision(HIW"\nСǿ���棺$N�ղ������ͨ�˺���"HIM"����"HIW"����ʧΪ"+(string)(sendam)+"����ϣ�\n"NOR, me);
             } 
              return 1;
} 
varargs int receive_wound(string type, int damage)
{
       
        
    object me;
    int r_damage,gindam,keedam,sendam;
    me = this_player();
      
       
        if (damage <0) damage =0;
        if( type!="gin" && type!="kee" && type!="sen" )
                error("F_DAMAGE: �˺��������( ֻ���� gin, kee, sen ����֮һ )��\n"); 
	//add by tiandi ��������
	if( objectp(who))
		if(who->query("damagelv") )
			damage += damage /25*(int)who->query("damagelv");
	if (query("defenselv") > 0)
		damage = damage /25 * (25 - query("defenselv"));

         if (type != "gin"){
                gindam = 0;
            } else {
                gindam = damage;
   message_vision(WHT"\nСǿ���棺$N�ղ����ʵ���˺���"NOR+YEL"����"NOR+WHT"����ʧΪ"+(string)(gindam)+"����ϣ�\n"NOR, me);
            }


             if (type != "kee"){
                keedam = 0;
            } else {
              keedam = damage;
            message_vision(WHT"\nСǿ���棺$N�ղ����ʵ���˺���"NOR+RED"��Ѫ"NOR+WHT"����ʧΪ"+(string)(keedam)+"����ϣ�\n"NOR, me);
            }

 


             if (type != "sen"){
                sendam = 0;
             } else { 
             sendam = damage;
               message_vision(WHT"\nСǿ���棺$N�ղ����ʵ���˺���"NOR+MAG"����"NOR+WHT"����ʧΪ"+(string)(sendam)+"����ϣ�\n"NOR, me);
             } 
              return 1;
} 
*/
void init()
{
        ::init();
         add_action("do_stop", "stop");
} 
int do_stop(string arg)
{
           
       object me;
        me = this_player();

         if ( arg == "test")
  {
          message_vision(HIC"Сǿ����$Nͷ����Ĺ��򻹲��������������ģ��л���һ���������氡��\n"NOR,this_player());
           me->remove_all_killer();
          return 1;
  }
   return 0;
}
void die(){
         message_vision("$N΢΢һ��������ɫ�ָֻ��˺���\n", this_object());
        set("gin",query("max_gin"));
        set("kee",query("max_kee"));
        set("sen",query("max_sen"));

} 