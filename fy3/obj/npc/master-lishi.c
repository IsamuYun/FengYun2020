// master-lishi.c
// 编程：禅(Zen)

#include <login.h>
#include <command.h>
#include <ansi.h>

#define MASTER_LISHI "/data/npc/master-lishi"

inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
inherit F_SAVE;
int refrash(object ob);
int do_clone(object me, object ob);

string query_save_file()
{
        return MASTER_LISHI;
}

void create()
{
        set_name("师妃暄", ({ "master lishi", "master" }));

        set("long",@LONG
她来自大唐,艺出神仙山庄，转战天下三十余哉，多得各路名师指点.
终神功大成,雄霸一方。自立门户开创《血龙山庄》带领门人纵横天下
威震武林,所向披靡。
LONG
        );

	set("title",HIR"血龙山庄庄主"NOR);
        set("gender", "女性" );
        set("marry","mud");
        set("faction/name","血龙山庄");
        set("faction/master","lishi");
        set("faction/generation",-1);

        set("age", 40);

        if ( !restore() ) {
        set("str", 1);         // 膂力         
        set("cps", 1);         // 定力
        set("cor", 1);         // 胆识         
        set("per", 1);         // 容貌
        set("int", 1);         // 悟性         
        set("con", 1);         // 根骨
        set("spi", 1);         // 灵性         
        set("kar", 1);         // 福缘

        set("max_atman", 1);         set("atman", 1);
        set("max_force", 1);         set("force", 1);     set("force_factor", 1);
        set("max_mana", 1);          set("mana", 1);

        set("combat_exp", 1);
        // set("SEN",10000000);


        set_skill("perception",1);
        set_skill("sword",1);
        set_skill("essencemagic",1);
        set_skill("buddhism",1);
        set_skill("parry",1);
        set_skill("spells",1);
        set_skill("dodge",1);
        set_skill("move",1);
        set_skill("lingbo-steps",1);
        set_skill("dugu-sword",1);
        set_skill("stick",1);
        set_skill("unarmed",1);
        set_skill("blade",1);
        set_skill("force",1);
        set_skill("literate",1);
        set_skill("magic",1);
        set_skill("liumai-sword",1);
        set_skill("taoism",1);
        set_skill("taiji-force",1);

        map_skill("move","lingbo-steps");
        map_skill("parry","dugu-sword");
        map_skill("unarmed","liumai-sword");
        map_skill("sword","dugu-sword");
        map_skill("force","taiji-force");
        map_skill("magic","essencemagic");
        map_skill("dodge","lingbo-steps");
}
	set("inquiry", ([
		"更新"      : (: refrash :),
	]));
        setup();

        carry_object("/obj/cloth/cloth")->wear();
        carry_object("/obj/weapon/longsword")->wield();
}

void attempt_apprentice(object ob)
{
        command("smile");
        command("say 很好，有志加入血龙山庄，可以去找庄主本人。\n");
}

void init()
{
        add_action("give_quest", "quest");
}
int refrash(object ob)
{
        object me;
        me  = this_object();
        ob  = this_player();

        if( ob->query("id") != me->query("faction/master")){
               tell_object(ob, me->query("name")+"冷笑说道：“你当你是谁呀！”\n");
        return 1;
        }
                do_clone( me, ob );
        
        return 1;
}


int do_clone(object me, object ob)
{
        mapping hp_status, skill_status;

        hp_status = ob->query_entire_dbase();

        me->set("str", hp_status["str"]);
        me->set("cor", hp_status["cor"]);
        me->set("int", hp_status["int"]);
        me->set("spi", hp_status["spi"]);
        me->set("cps", hp_status["cps"]);
        me->set("per", hp_status["per"]);
        me->set("con", hp_status["con"]);
        me->set("kar", hp_status["kar"]);

        me->set("max_gin", hp_status["max_gin"]);       me->set("eff_gin", hp_status["max_gin"]);	me->set("gin", hp_status["max_gin"]);
        me->set("max_kee", hp_status["max_kee"]);       me->set("eff_kee", hp_status["max_kee"]);   me->set("kee", hp_status["max_kee"]);
        me->set("max_sen", hp_status["max_sen"]);       me->set("eff_sen", hp_status["max_sen"]);	me->set("sen", hp_status["max_sen"]);

        me->set("max_force", hp_status["max_force"]);
        me->set("force", hp_status["force"]);
        me->set("max_atman", hp_status["max_atman"]);
        me->set("atman", hp_status["atman"]);
        me->set("max_mana", hp_status["max_mana"]);
        me->set("mana", hp_status["mana"]);
        me->set("long",      hp_status["long"]);
        me->set("combat_exp",hp_status["combat_exp"]);
        me->set("force_factor", hp_status["force_factor"]);

        skill_status = ob->query_skills();
        me->set_skill("perception",skill_status["perception"]);
        me->set_skill("sword",skill_status["sword"]);
        me->set_skill("essencemagic",skill_status["essencemagic"]);
        me->set_skill("buddhism",skill_status["buddhism"]);
        me->set_skill("parry",skill_status["parry"]);
        me->set_skill("spells",skill_status["spells"]);
        me->set_skill("dodge",skill_status["dodge"]);
        me->set_skill("move",skill_status["move"]);
        me->set_skill("lingbo-steps",skill_status["lingbo-steps"]);
        me->set_skill("dugu-sword",skill_status["dugu-sword"]);
        me->set_skill("unarmed",skill_status["unarmed"]);
        me->set_skill("force",skill_status["force"]);
        me->set_skill("literate",skill_status["literate"]);
        me->set_skill("magic",skill_status["magic"]);
        me->set_skill("liumai-sword",skill_status["liumai-sword"]);
        me->set_skill("taoism",skill_status["taoism"]);
        me->set_skill("taiji-force",skill_status["taiji-force"]);
        
        me->map_skill("move","lingbo-steps");
        me->map_skill("parry","dugu-sword");
        me->map_skill("unarmed","liumai-sword");
        me->map_skill("sword","dugu-sword");
        me->map_skill("force","taiji-force");
        me->map_skill("magic","essencemagic");
        me->map_skill("dodge","lingbo-steps");

        save();

        tell_object(ob, "状态储存完毕。\n");
        return 1;
}

