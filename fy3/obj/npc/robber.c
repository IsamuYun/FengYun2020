// robber.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("����ǿ��", ({ "mask robber", "robber" }) );
        set("long","����һ������ǿ�������Ӻ����ء�\n");

        set("attitude", "heroism");

        set("str", 20 + random(11));            // ����         
        set("cps", 20 + random(11));            // ����
        set("cor", 20 + random(11));            // ��ʶ         
        set("per", 20 + random(11));            // ��ò
        set("int", 20 + random(11));            // ����         
        set("con", 20 + random(11));            // ����
        set("spi", 20 + random(11));            // ����         
        set("kar", 20 + random(11));            // ��Ե

        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "����ǿ���ȵ���߾����·���ҿ������������ԣ�Ҫ��Ӵ˹���������·Ǯ��\n",
                "����ǿ���ȵ��������¶���������һ����·��\n",
                "����ǿ���ȵ������ӿ�����ҪǮ����Ҫ����\n"
                "����ǿ���ȵ���ǮҲҪ����ҲҪ��\n"
        }) );

        set("force", 500);      set("max_force", 500);          set("force_factor", 10);
        set("SEN", -10);

        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set_temp("apply/damage", 40);
        set_temp("apply/armor", 40);
        set_temp("apply/move", 40);

        setup();

        carry_object("/obj/cloth/cloth")->wear();
        carry_object("/obj/weapon/blade")->wield();

        add_money("gold", 3);
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("checking");
                call_out("checking", 0, ob);
        }
}

void checking(object ob)
{
        int n;

        if( !ob || !present(ob, environment(this_object())) || !present("mi han", ob) ) {
                if(ob == query_leader() )  set_leader(0);
                return;
        }

        // �Զ������书����

        n = ob->query("combat_exp") + random(10000) - 7000;
        if( n <= 0 ) n = random(3000) + 1;
        set("combat_exp", n );

        n = ob->query_skill("force", 1) + random(10) - 7;
        if( n <= 0 ) n = random(3) + 1;
        set_skill("force", n );
        n = ob->query_skill("unarmed", 1) + random(10) - 7;
        if( n <= 0 ) n = random(3) + 1;
        set_skill("unarmed", n );
        n = ob->query_skill("force", 1) + random(10) - 7;
        if( n <= 0 ) n = random(3) + 1;
        set_skill("blade", n );                 // ������������ȡ��������ǿ��һ�Ϊ�˼򵥣�������forceȡ��
        n = ob->query_skill("parry", 1) + random(10) - 7;
        if( n <= 0 ) n = random(3) + 1;
        set_skill("parry", n );
        n = ob->query_skill("dodge", 1) + random(10) - 7;
        if( n <= 0 ) n = random(3) + 1;
        set_skill("dodge", n );
        set_skill("move", 100 + random(100) );  // ��������move������ҵ���ֵ

        n = ob->query_skill(ob->query_skill_mapped("force"), 1) + random(10) - 7;
        if( n <= 0 ) n = random(3) + 1;
        set_skill("hunyuan-force", n );
        n = ob->query_skill(ob->query_skill_mapped("force"), 1) + random(10) - 7;
        if( n <= 0 ) n = random(3) + 1;
        set_skill("ruyi-blade", n );
        n = ob->query_skill(ob->query_skill_mapped("dodge"), 1) + random(10) - 7;
        if( n <= 0 ) n = random(3) + 1;
        set_skill("taxue-steps", n );

        map_skill("dodge", "taxue-steps");
        map_skill("move",  "taxue-steps");
        map_skill("force", "hunyuan-force");
        map_skill("blade", "ruyi-blade");
        map_skill("parry", "ruyi-blade");

        command("say "+ob->name()+"�����ܺ����£�������·����\n");
        set_leader(ob);

        command("kill "+ob->query("id") );
}

int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}

void leave()
{
        message("vision",HIB + name() + "����ææ���߿��ˡ�\n" NOR, environment(), this_object() );
        destruct(this_object());
}
