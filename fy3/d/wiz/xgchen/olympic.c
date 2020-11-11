inherit NPC;
int do_liwu();
#include <ansi.h>

void create()
{
        set("inquiry", ([
                "liwu" : (: do_liwu :),
                ]));
        set_name(HIC"奥"HIY"运"HIG"使"HIM"者"NOR, ({ "olympic" }));
        set("long", 
              "她是专程从国际奥委会赶来为大家发红包的！\n"
              );
        set("gender", "女性" );
        set("age", 60);
        set("con",100); 
        set("dex",100);
        set("max_kee",10000000);
        set("eff_kee",10000000);
        set("kee",10000000);
        set("max_gin",10000000);
        set("eff_gin",10000000);
        set("gin",10000000);
        set("max_sen",10000000);
        set("eff_sen",10000000);
        set("sen",10000000);

        set("per",100);
        set("int",100);
        set("str",2000);
        set("fle",2000);
        set("combat_exp", 2100000000);
        set("attitude", "friendly");
        setup();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say(HIC"奥"HIY"运"HIG"使"HIM"者"NOR"咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，祝贺北京申奥成功，快来领红包！我只在这里呆一周。\n"NOR);
                        break;
        }
}

int do_liwu()
{ 
        object ob,me;
        me = this_player();

        if(me->query("mud_age")<=43200)
        {
        message_vision(HIM"$N说道：你连线时间还不够十二小时，再去锻炼锻炼吧？\n"NOR,this_object(), me);
        return 1;
        }
        if(me->query("olympic")==1)
        {
        message_vision(HIM"$N说道：你已经拿过红包了吧，想占便宜呀？\n"NOR,this_object(), me);
        return 1;
        }
        ob = new("d/wiz/xgchen/bao");
        message_vision(HIR"$N微笑道：热烈庆祝北京申办2008年奥运主办权成功!!\n"NOR,this_object(), me);
        me->set("olympic",1);
        ob->move(this_player());
        tell_object(me,HIR"你得到了一个。" + ob->query("name") +"\n"NOR);
       return 1;
} 


