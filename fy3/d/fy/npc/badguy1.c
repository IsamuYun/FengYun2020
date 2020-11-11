#include <ansi.h>
inherit NPC;
void create()
{
        set_name("ɽ������", ({ "tufei", "shanxi tufei" }) );
        set("long",
"һ�������˰̼Ӻ���ļһ\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
        set("per", 1);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 100000+random(4000000));
	set("bellicosity", 10000);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                "ɽ�����˺ȵ�����������ҪǮ��Ҫ������\n",
                "ɽ������Ц��������ģ�ȥ���ɣ�\n",
		(: random_move :),
        }) );
        set("chat_chance", 80);
        set("chat_msg", ({
                (: random_move :),
        }) );

        set_skill("unarmed", 70+random(200));
        set_skill("blade", 70+random(200));
        set_skill("parry", 70+random(200));
        set_skill("dodge", 70+random(200));
        set_skill("move", 100+random(200));

        set_temp("apply/attack", 70);
        set_temp("apply/defense", 70);
        set_temp("apply/armor", 70);
        set_temp("apply/damage", 30+random(400));
        set_temp("apply/move", 100);

        setup();

        carry_object("/obj/cloth")->wear();
        carry_object(__DIR__"obj/guiblade")->wield();
}
void init()
{
        remove_call_out("hunting");
	if(!environment()->query("no_fight"))
        call_out("hunting",1);
}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
                if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
		if(ob[i]->query("vendetta/authority")) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}
void die()
{
        object me = this_object()->query_temp("last_damage_from");
        object corpse, money,book;      
        int kar, exp, pot;
        kar = random(me->query("kar"));
        exp = 100 + random(200);
        pot = 50 + random(50);

        message_vision(HIR "\nɽ�����˵��ڵ��ϣ������˼��¾����ˡ�\n" NOR,me);
                message_vision(HIW "$N�������ˣ�\n"
                + chinese_number(exp) + "��ʵս���飬\n"
                + chinese_number(pot) + "��Ǳ�ܣ�\n"
               + chinese_number(2) + "�����ۡ�\n" NOR, me);
                me->add("combat_exp", exp);
                me->add("potential", pot);
              me->add("score", 2);
        me->add("MKS", 1);
        switch(random(3))
        {
        case 1:
        book = new("/d/huangshan/obj/swordbook2.c");
        message_vision("$N�İ����������˵�ʲô������\n",me);
        book->move(me);
      break;
        case 2:
        book = new("/d/huangshan/obj/bladebook2.c");
        message_vision("$N�İ����������˵�ʲô������\n",me);
        book->move(me);
        break;
        default:
        break;
       }
        destruct(this_object());
}

