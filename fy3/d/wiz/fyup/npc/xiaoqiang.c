 // fy@wuji   testdamagenpc
#include <ansi.h>
inherit NPC; 
void create()
{
    set_name("小强", ({ "xiao qiang" }) );
        set("race", "野兽");
        set("title",WHT"小强永不败"NOR);
        set("nickname", HIY"大家都来打我"NOR);
        set("age", 32);
        set("long", "一只巨大的小强.\n你可以(fight xiao qiang)来测试功夫的伤害，(stop test)停止测试。\n"); 
        set("max_kee", 999999);
        set("max_gin", 999999);
        set("max_sen", 999999); 
        set("eff_kee", 999999);
        set("eff_gin", 999999);
        set("eff_sen", 999999); 
        set("kee", 999999);
        set("gin", 999999);
        set("sen", 999999); 
        set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("attitude", "heroism");
          set("combat_exp", 1000000);
      set("chat_chance", 10);
        set("chat_msg", ({
        "小强唱道：我是一只小小强，小呀小小强。\n",
        "小强呵呵道：我是一只打不死的小强哦。\n",
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
                error("F_DAMAGE: 伤害种类错误( 只能是 gin, kee, sen 其中之一 )。\n"); 
	//add by tiandi 攻防修正
	if( objectp(who))
		if(who->query("damagelv") )
			damage += damage /25*(int)who->query("damagelv");
	if (query("defenselv") > 0)
		damage = damage /25 * (25 - query("defenselv"));

         if (type != "gin"){
                gindam = 0;
            } else {
                gindam = damage;
                message_vision(HIW"\n小强报告：$N刚才造成普通伤害，"HIY"精力"HIW"的损失为"+(string)(gindam)+"，完毕！\n"NOR, me);
            }


             if (type != "kee"){
                keedam = 0;
            } else {
              keedam = damage;
                  message_vision(HIW"\n小强报告：$N刚才造成普通伤害，"HIR"气血"HIW"的损失为"+(string)(keedam)+"，完毕！\n"NOR, me);
            }

 


             if (type != "sen"){
                sendam = 0;
             } else { 
             sendam = damage;
            message_vision(HIW"\n小强报告：$N刚才造成普通伤害，"HIM"心神"HIW"的损失为"+(string)(sendam)+"，完毕！\n"NOR, me);
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
                error("F_DAMAGE: 伤害种类错误( 只能是 gin, kee, sen 其中之一 )。\n"); 
	//add by tiandi 攻防修正
	if( objectp(who))
		if(who->query("damagelv") )
			damage += damage /25*(int)who->query("damagelv");
	if (query("defenselv") > 0)
		damage = damage /25 * (25 - query("defenselv"));

         if (type != "gin"){
                gindam = 0;
            } else {
                gindam = damage;
   message_vision(WHT"\n小强报告：$N刚才造成实体伤害，"NOR+YEL"精力"NOR+WHT"的损失为"+(string)(gindam)+"，完毕！\n"NOR, me);
            }


             if (type != "kee"){
                keedam = 0;
            } else {
              keedam = damage;
            message_vision(WHT"\n小强报告：$N刚才造成实体伤害，"NOR+RED"气血"NOR+WHT"的损失为"+(string)(keedam)+"，完毕！\n"NOR, me);
            }

 


             if (type != "sen"){
                sendam = 0;
             } else { 
             sendam = damage;
               message_vision(WHT"\n小强报告：$N刚才造成实体伤害，"NOR+MAG"心神"NOR+WHT"的损失为"+(string)(sendam)+"，完毕！\n"NOR, me);
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
          message_vision(HIC"小强排排$N头，你的功夫还不错嘛。打的我痒痒的，有机会一定在找我玩啊。\n"NOR,this_player());
           me->remove_all_killer();
          return 1;
  }
   return 0;
}
void die(){
         message_vision("$N微微一凝气，脸色又恢复了红润。\n", this_object());
        set("gin",query("max_gin"));
        set("kee",query("max_kee"));
        set("sen",query("max_sen"));

} 