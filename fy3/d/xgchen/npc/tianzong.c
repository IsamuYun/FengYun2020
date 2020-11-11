//written by xgchen
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("天宗狂徒", ({ "tiankuang tu" }) );
        set("gender", "男性" );
        set("age", 27);
        set("int", 12);
        set("spi", 40);
        set("str", 40);
        set("con", 40);
        set("kar", 40);
        set("cps", 40);
        set("per", 10);
        set("long", @LONG
这是天宗派来的杀手，一脸凶狠而霸道的样子。
LONG
);
        set("no_arrest",1);
        set("attitude", "heroism");

        set("chat_chance", 50);
        set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
              "天宗万岁。\n",
              "哈哈哈。。。。。\n",
        }) );

        setup();
}
void init()
{
        object ob;

        ::init();

        ob = this_player();

        if (interactive(ob) && (ob->query("job/sxy"))&& query("sxy-name")==ob->query("id"))
        {
                        command("heihei");
                        command("say 你竟然来送死，好吧，我就成全了你！\n");
                          command("kill "+ob->query("id"));
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob); 
        }
        else 
        {
        call_out("leave",30*6);

}
}
int leave()
{
        if(!is_fighting() ) {
                message_vision("天宗狂徒急急忙忙地逃跑了。\n",this_object() );
                destruct(this_object());
        }
        else call_out("leave",120);
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

                ob->set("str", hp_status["str"]);
                ob->set("int", hp_status["int"]);
                ob->set("con", hp_status["con"]);
                ob->set("spi", hp_status["spi"]);
                ob->set("per", hp_status["per"]);
                ob->set("kar", hp_status["kar"]);
                ob->set("cor", hp_status["cor"]);
                ob->set("cps", hp_status["cps"]);

}




