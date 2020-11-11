// Tie@fy
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("����", ({ "gaoren" }) );
        set("gender", "����" );
	set("title","������");
        set("age", 32);
        set("long","һ���ð�����ϵ�ʿ���Ը��ƶ�������ʱ������\n");
        set("combat_exp", 5000);
        set("attitude", "friendly");
        set("chat_chance", 15);
        set("chat_msg", ({
   //             (: random_move :)
        }) );
				set("inquiry", (["ѵ��" : "�ҿ��԰�����ѵ��(train)��ĳ���ȼ���ǰ���������㹻��Ǳ�ܡ�",   
				]));
        setup();
        carry_object("/obj/cloth")->wear();

}

void init()
{	
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_train", "train");

}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
                        say( "����˵������λ" + RANK_D->query_respect(ob)
                                + "����������һ�ģ�\n");
                        break;
                case 1:
                        say( "����Ц�����ⲻ���������ˣ�\n");
                        break;
        }
}

int do_train(string arg)
{
	object me,pet,gold;
	int cost,exp;
	int j,lv,i;
	string which;
        me = this_player();
        if(me->is_busy())
        return notify_fail("����һ��������û����ɡ�\n");
	if(!arg) return notify_fail("���˵�������ֻ��ѵ��(train <pet id>)��ת�������Ǳ�ܸ������\n");
	pet = present(arg,environment());
	if(!objectp(pet)) return notify_fail("���˵�������Ҫѵ��ʲô����ѽ����\n");
	if(pet->query("possessed") != me )
	return notify_fail("���˵������Ǻ�������İɣ���\n");
	if(pet->query("is_pet") != 1)
		return notify_fail("���˵��������ʲô������\n");
	j=100;
	lv = pet->query("level");
//okey we identified the target, now the cost:
	cost = (int) pet->query("level") * 10;
	gold = present("gold_money", me);
        if(!gold) return notify_fail("������û�н��ӡ�\n");
        if((int) gold->query_amount() < cost)
        return notify_fail("������û��"+chinese_number(cost)+"�����ӡ�\n");
	if((int)me->query("score") < cost)
	return notify_fail("������۲���"+chinese_number(cost)+"�㡣\n");
	if((int)me->query("level") < pet->query("level"))
		return notify_fail("��ĳ���ȼ�ֻ�ܱ���ĵȼ���һ����\n");
	for(i=0;i<lv;i++)
		j=j+j/9;
	exp = j - pet->query("combat_exp");
	if (exp>0)
	{
	if( (int)me->query("potential") - (int)me->query("learned_points") < exp )
		return notify_fail("���Ǳ�ܻ�����"+j+"�㣬���ﲻ��������\n");
	me->add("potential",-exp);
	pet->set("combat_exp",0);
	pet->add("level",1);
	pet->add("gift_point",12);
	gold->add_amount(-cost);
	me->add("score",-cost);
	command("say �㻨����"+chinese_number(cost)+"���ƽ�"+chinese_number(exp)+"��Ǳ�ܺ�"+chinese_number(cost)+"�����ۣ���ĳ���������"+chinese_number(pet->query("level"))+"���ˣ�\n");
	if (random(pet->query("chengzhang")>35))
		pet->add("gift_point",1);
	}
	else {
	pet->add("combat_exp",-j);
	pet->add("level",1);
	pet->add("gift_point",12);
	gold->add_amount(-cost);
	me->add("score",-cost);
	command("say �㻨����"+chinese_number(cost)+"���ƽ�"+chinese_number(exp)+"��Ǳ�ܺ�"+chinese_number(cost)+"�����ۣ���ĳ���������"+chinese_number(pet->query("level"))+"���ˣ�\n");
	if (random(pet->query("chengzhang")>35))
		pet->add("gift_point",1);
	}
	if (!pet->query_skill("petfangyu",1) && pet->query("title")=="�ڹ�" && random(20) == 1)
	{
		pet->set_skill("petfangyu",1);
		command("ack");
		command("say ��ϲ��ĳ��������˷�������\n");
	}
	if (!pet->query_skill("petgedang",1) && pet->query("title")=="����" && random(20) == 1)
	{
		pet->set_skill("petgedang",1);
		command("ack");
		command("say ��ϲ��ĳ��������˸�����\n");
	}
	if (!pet->query_skill("petfire",1) && pet->query("title")=="è��" && random(20) == 1)
	{
		pet->set_skill("petfire",1);
		command("ack");
		command("say ��ϲ��ĳ����������ݻ�����\n");
	}
	if (!pet->query_skill("petbisha",1) && pet->query("title")=="����" && random(20) == 1)
	{
		pet->set_skill("petbisha",1);
		command("ack");
		command("say ��ϲ��ĳ��������˱�ɱ����\n");
	}
	if (!pet->query_skill("petqiangji",1) && pet->query("title")=="Ұţ" && random(20) == 1)
	{
		pet->set_skill("petqiangji",1);
		command("ack");
		command("say ��ϲ��ĳ���������ǿ������\n");
	}
	pet->save();
	return 1;
}
