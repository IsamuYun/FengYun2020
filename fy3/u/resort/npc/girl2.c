// girl.c

inherit NPC;

void create()
{
        set_name("�����", ({"shunv"}));
        set("gender", "Ů��" );
        set("title", "��ѩɽׯ�ڶ�������");
        set("age", 25);
        set("str", 60);
        set("cor", 40);
        set("cps", 11);
        set("agi", 30);
        set("per", 27);
        set("int", 27);
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "sword.caideikuangwu" :),
        }) );

        set("attitude", "friendly");

        set("long", "������ѩɽׯ�Ĵ�ʦ�㣬Ҳ��ѩ�������Ů���书�������ĸ�洫�Ѿ����ࡣ\n");
  
        set("max_force", 50000);
        set("force", 50000);
        set("force_factor", 0);
        set("max_kee",49990);
        set("max_gin",49990);
        set("max_sen",59990);
        set("eff_kee",49990);
        set("kee",49990);
        set("chat_chance", 10);
        set("chat_msg", ({
               "��������ɵ�ת�������ϵ�÷����\n",
               "���������÷�������:���˳��ã�ǧ�ﹲ濾ꡣ\n"
        }) );
      
        set("combat_exp", 4800000);

        set_skill("unarmed", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("sword", 250);
        set_skill("force", 190);
        set_skill("literate", 220);

        set_skill("qidaoforce", 120);
        set_skill("deisword", 150);
        set_skill("meihua-shou", 180);
        set_skill("fall-steps", 180);

        map_skill("unarmed", "meihua-shou");
        map_skill("sword", "deisword");
        map_skill("parry", "deisword");
        map_skill("dodge", "fall-steps");

        setup();

        carry_object(__DIR__"obj/ssword")->wield();
        carry_object(__DIR__"obj/yellowcloth")->wear();
        carry_object(__DIR__"obj/shoe")->wear();

}

 
