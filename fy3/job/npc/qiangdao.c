inherit NPC;
#include <ansi.h>
void move();

void create()
{
    set_name(BLU "���������" NOR, ({ "heiyi ren", "robber", "ren", "heiyi" }));
        set("gender", "����");
        set("age", 28);
        set("long", "����һ��ר�����Ӫ���ĵ�����\n");
        
        set("combat_exp",1000);
        set("score", -10);

        set("attitude", "peaceful");
        set("no_arrest", 1);
        set_temp("apply/defense", 300);
        
         set("str",20);
         set("no_arrest",1);
         set("per",1);
         set("cps",90);
         set("agi",80);
         set("food",400);
         set("water",400);

        setup();
        carry_object("/obj/cloth")->wear();
}

void init()
{
        call_out("leave",150);
}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(HIC "���������·�ߵ��Ӳݣ������ˡ�\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",10);
}

void die()
{
		int doubletime,doubletype;
        object me = this_object()->query_temp("last_damage_from");
        object corpse, money,owner;      
        int kar, exp, pot,reb;
		if (owner = me->query("possessed"))
			me = owner;
        reb = me->query("reborned");  // update by Tiandi 200712031145
        kar = random(me->query("kar"));
//        shen1 =  300+random(100);
//        shen2 =  random(50);
        exp = 500 + random(700);
        exp = exp + exp/5*reb;
		doubletime = me->query("doubletime");
		doubletype = me->query("doubletype");
		if (doubletime - time() > 0)
			exp = exp*(doubletype+1);
        pot = exp/7;

        message_vision(HIR "\n�����˵��ڵ��ϣ������˼��¾����ˡ�\n" NOR,me);
        if (me->query("kill_qiangdao") == 1 && this_object()->query_temp("owner/id") == me->query("id")) {
                message_vision(HIW "$N�������ˣ�\n"
                + chinese_number(exp) + "��ʵս���飬\n"
                + chinese_number(pot) + "��Ǳ�ܣ�\n"
               + chinese_number(2) + "�����ۡ�\n" NOR, me);
                me->add("combat_exp", exp);
                me->add("potential", pot);
              me->add("score", 2);
              me->add("killhyr",1);
                me->delete("quest");
                me->delete("kill_qiangdao");
                }
        else {
                message_vision(HIC "\n����$N����ɱ�ˣ��ٸ����������㣺\n"
                + chinese_number(2000) + "��ʵս���飬\n"
                + chinese_number(1000) + "��Ǳ�ܣ�\n"
               + chinese_number(50) + "��������Ϊ�ͷ���\n" NOR, me);
                me->add("combat_exp", -2000);
                me->add("potential", -1000);
              me->add("score",-50);
                }
        me->add("MKS", 1);

        destruct(this_object());
}