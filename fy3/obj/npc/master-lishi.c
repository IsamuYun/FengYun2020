// master-lishi.c
// ��̣���(Zen)

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
        set_name("ʦ����", ({ "master lishi", "master" }));

        set("long",@LONG
�����Դ���,�ճ�����ɽׯ��תս������ʮ���գ���ø�·��ʦָ��.
���񹦴��,�۰�һ���������Ż�������Ѫ��ɽׯ�����������ݺ�����
��������,�������ҡ�
LONG
        );

	set("title",HIR"Ѫ��ɽׯׯ��"NOR);
        set("gender", "Ů��" );
        set("marry","mud");
        set("faction/name","Ѫ��ɽׯ");
        set("faction/master","lishi");
        set("faction/generation",-1);

        set("age", 40);

        if ( !restore() ) {
        set("str", 1);         // ����         
        set("cps", 1);         // ����
        set("cor", 1);         // ��ʶ         
        set("per", 1);         // ��ò
        set("int", 1);         // ����         
        set("con", 1);         // ����
        set("spi", 1);         // ����         
        set("kar", 1);         // ��Ե

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
		"����"      : (: refrash :),
	]));
        setup();

        carry_object("/obj/cloth/cloth")->wear();
        carry_object("/obj/weapon/longsword")->wield();
}

void attempt_apprentice(object ob)
{
        command("smile");
        command("say �ܺã���־����Ѫ��ɽׯ������ȥ��ׯ�����ˡ�\n");
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
               tell_object(ob, me->query("name")+"��Ц˵�������㵱����˭ѽ����\n");
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

        tell_object(ob, "״̬������ϡ�\n");
        return 1;
}

