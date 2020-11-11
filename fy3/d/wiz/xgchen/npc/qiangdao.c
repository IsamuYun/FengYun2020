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
        
        set_skill("sword", 20);
        set_skill("dodge", 20);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
        
         set("str",30);
         set("per",18);
         set("food",400);
         set("water",400);

        setup();
        carry_object("/obj/cloth")->wear();
}

void init()
{
        remove_call_out("leave");
        call_out("leave",300);
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
        object me = this_object()->query_temp("last_damage_from");
        object corpse, money;      
        int kar, exp, pot;
        kar = random(1000)+500;
//        shen1 =  300+random(100);
//        shen2 =  random(50);
        exp = kar;
        pot = 100 + random(100);

        message_vision(HIR "\n�����˵��ڵ��ϣ������˼��¾����ˡ�\n" NOR,me);
        if (me->query("kill_qiangdao") == 1 && this_object()->query_temp("owner/id") == me->query("id")) {
                message_vision(HIW "$N�������ˣ�\n"
                + chinese_number(exp) + "��ʵս���飬\n"
                + chinese_number(pot) + "��Ǳ�ܣ�\n"
               + chinese_number(2) + "�����ۡ�\n" NOR, me);
                me->add("combat_exp", exp);
                me->add("potential", pot);
              me->add("score", 2);
                me->delete("quest");
                me->delete("kill_qiangdao");
                }
        else {
                message_vision(HIC "\n����$N����ɱ�ˣ��ٸ����������㣺\n"
                + chinese_number(200) + "��ʵս���飬\n"
                + chinese_number(100) + "��Ǳ�ܣ�\n"
               + chinese_number(5) + "��������Ϊ�ͷ���\n" NOR, me);
                me->add("combat_exp", -200);
                me->add("potential", -100);
              me->add("score",-5);
                }
        me->add("MKS", 1);

        destruct(this_object());
}
