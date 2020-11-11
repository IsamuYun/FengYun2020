// Tie@fy
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("��һ��", ({ "yimo" }) );
        set("gender", "����" );
	set("title","һ��ȫ");
        set("age", 32);
        set("long","һ����������ͷ���������ģ�һ���������ˣ�����\n");
        set("combat_exp", 5000);
        set("chat_chance", 15);
        set("chat_msg", ({
     //          (: random_move :)
        }) );
        set("attitude", "friendly");
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
                        say( "��һ��˵������λ" + RANK_D->query_respect(ob)
                                + "����������һ����\n");
                        break;
                case 1:
                        say( "��һ��Ц������λ" + RANK_D->query_respect(ob)
                                + "��������������һ�ѣ�\n");

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
	if(!arg || sscanf(arg,"%s %s",arg,which) != 2)
        return notify_fail("��һ����������ֻ���÷���(train <pet id> <����>)���������������㣡��\n");
	pet = present(arg,environment());
	if(!objectp(pet)) return notify_fail("��һ����������Ҫ����ʲô����ѽ����\n");
	if(pet->query("possessed") != me )
		return notify_fail("��һ���������Ǻ�������İɣ���\n");
	if(pet->query("is_pet") != 1)
		return notify_fail("��һ�����������ʲô������\n");
	if(pet->query("gift_point")< 1)
		return notify_fail("��һ���������в�����ô��\n");
	switch(which) {
		case "str":
			pet->add("str",1);
			break;
		case "spi":
			pet->add("spi",1);
			pet->add("max_gin",pet->query("chengzhang")/2);
			pet->add("max_sen",pet->query("chengzhang")/2);
			break;
		case "agi":
			pet->add("agi",1);
			break;
		case "dur":
			pet->add("dur",1);
			break;
		case "con":
			pet->add("con",1);
			pet->add("max_kee",pet->query("chengzhang"));
			break;
		 default:
            return notify_fail("û����������㡣\n");
	}

	if((int)me->query("score") < 1)
		return notify_fail("������۲���һ�㡣\n");

	me->add("score",-1);
	pet->add("gift_point",-1);
	pet->save();
	command("say ���ˣ���ĳ����������������һ�㣡\n");
	return 1;
}