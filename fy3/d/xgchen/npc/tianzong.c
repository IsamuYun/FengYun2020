//written by xgchen
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("���ڿ�ͽ", ({ "tiankuang tu" }) );
        set("gender", "����" );
        set("age", 27);
        set("int", 12);
        set("spi", 40);
        set("str", 40);
        set("con", 40);
        set("kar", 40);
        set("cps", 40);
        set("per", 10);
        set("long", @LONG
��������������ɱ�֣�һ���׺ݶ��Ե������ӡ�
LONG
);
        set("no_arrest",1);
        set("attitude", "heroism");

        set("chat_chance", 50);
        set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
              "�������ꡣ\n",
              "����������������\n",
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
                        command("say �㾹Ȼ���������ðɣ��Ҿͳ�ȫ���㣡\n");
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
                message_vision("���ڿ�ͽ����ææ�������ˡ�\n",this_object() );
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




