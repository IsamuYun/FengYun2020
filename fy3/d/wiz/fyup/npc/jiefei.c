// qiangdao  by tiandi

#include <ansi.h>

inherit NPC;
void create()
{

    set_name("��·�ٷ�", ({ "jie fei" }) );
    set("long", "һ��ר����·��������Ľٷˡ�˵�����������ϻ���д�ٶ����ı��\n");
 set("no_arrest",1);

    set("combat_exp", 5000000+random(20000000));
    set_skill("sword", 60);
    set_skill("parry", 60);
    set_skill("dodge", 60);
    set_skill("move", 500);
    set_skill("magic", 60);
    set_skill("sharen-sword", 200);
    set_skill("long-steps",300);

    set_skill("force", 60);

    map_skill("sword","sharen-sword");
    map_skill("dodge","long-steps");
    map_skill("move","long-steps");

    set("chat_chance_combat", 90);
    set("chat_msg_combat", ({
        (: perform_action, "sword.sharenruma" :),
      }) );
    set("chat_chance", 5);
    set("chat_msg", ({
                "��˵�ھ��ֿ�ʼ���������ˣ��ٺ٣����Ҹ��������֡�����\n",
	                (: random_move :),
        }) );
    setup();

    carry_object("/obj/weapon/sword")->wield();
	if (random(2)) 
	          carry_object("/d/wiz/fyup/obj/baotu");
}
void init()
{
        call_out("leave",900);
}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(HIC "��·�ٷ��Ҳ�����ʳ�ķ���һ���̵����ˡ�\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",10);
}

void die()
{
       
	int exp,pot,score,reb,ti;
	object me ,ob,gift;
	mapping quest;
	me = this_object()->query_temp("last_damage_from");
	ob = this_object();

            tell_object(me,"\n��ϲ�㣡նɱ��һ���ٷˣ�\n");
            reb = me->query("reborned");
	me->add("killjiefei",1);
	score = 1 ;  
	exp = random(2000)+1000;
	me->add("combat_exp",exp);
	me->add("score",score);
  	tell_object(me,HIW"�㱻�����ˣ�\n" +
	chinese_number(exp) + "��ʵս����\n"+
	chinese_number(score)+"������\n" NOR);
//	if (random(2)) {
//	gift = new("/d/wiz/fyup/obj/baotu");
//	gift->move(me);
//          tell_object(me,"��ӽٷ˵������ѵ�һ�Ųر�ͼ��\n");
//	}
    ::die();
}