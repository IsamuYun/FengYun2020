//written by xgchen

inherit NPC;
void init();
void create()
{
        set_name("������ʿ", ({ "youling fighter","youling" }) );
        set("gender", "����" );
        set("age", 27);
        set("int", 12);
        set("per", 10);
        set("long", @LONG
��������ħ��ѵ������ʿ���书�쳣������
LONG
);
        set("vendetta/authority",1);
        set("attitude", "heroism");

        set("chat_chance", 5);
        set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
                (: perform_action, "pofuchenzhou" :),
                (: perform_action, "yuhuan" :),
                (: perform_action, "luori" :),
                (: perform_action, "liumang" :),
        }) );

        setup();
        add_money("silver", 10); 
        carry_object("/obj/cloth")->wear();
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

void checking()
{
         call_out("leave",600);
}
 
int leave()
{
        if(!is_fighting() ) {
                message_vision("������ʿ���������߿��ˡ�\n",this_object() );
                destruct(this_object());
        }
        else call_out("leave",300);
}
void invocation(object who)
{
        object ob;
        mapping hp_status, skill_status, map_status;
        string *sname, *mname;
        int i, temp;

        ob = this_object();

        if ( mapp(skill_status = who->query_skills()) ) {
                skill_status = who->query_skills();
                sname  = keys(skill_status);

                for(i=0; i<sizeof(skill_status); i++) 
                        ob->set_skill(sname[i], skill_status[sname[i]]);
        }

        if ( mapp(map_status = who->query_skill_map()) ) {
                mname  = keys(map_status);
                for(i=0; i<sizeof(map_status); i++) 
                        ob->map_skill(mname[i], map_status[mname[i]]);
        }

        hp_status = who->query_entire_dbase();

                ob->set("str", 400);
                ob->set("int", hp_status["int"]);
                ob->set("con", hp_status["con"]);
                ob->set("spi", hp_status["spi"]);
                ob->set("per", hp_status["per"]);
                ob->set("kar", hp_status["kar"]);
                ob->set("cor", hp_status["cor"]);
                ob->set("cps", hp_status["cps"]);

                ob->set("max_mana",    10*hp_status["max_mana"]);
                ob->set("max_kee",    3*hp_status["max_kee"]);
                ob->set("kee", 3*hp_status["max_kee"]);
                ob->set("sen", 3*hp_status["max_sen"]);
                ob->set("eff_sen", 3*hp_status["max_sen"]);
                ob->set("eff_kee", 3*hp_status["max_kee"]);
                ob->set("eff_gin", 3*hp_status["max_gin"]);
                ob->set("max_sen", 3*hp_status["max_sen"]);
                ob->set("max_gin", 3*hp_status["max_gin"]);
                ob->set("gin", 3*hp_status["max_gin"]);
                ob->set("eff_mana",    hp_status["eff_mana"]);
                ob->set("mana",        hp_status["mana"]);
                ob->set("max_atman",  hp_status["max_atman"]);
                ob->set("eff_atman",  hp_status["eff_atman"]);
                ob->set("atman",      hp_status["atman"]);
                ob->set("max_force", 3*hp_status["max_force"]);
                ob->set("force", 3*hp_status["max_force"]);
                ob->set("force_factor", 500);
                ob->set("combat_exp",hp_status["combat_exp"]/10*9);
}
void die()
{
    message_vision("$N������ʿ�ҽ�һ�������ˣ�\n", this_object());
    destruct(this_object());
}



