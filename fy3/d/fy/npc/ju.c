#include <ansi.h>
inherit NPC;
int ask_job();
int ask_pei();

void create()
{
        set_name("菊不平", ({ "ju buping", "ju", "buping" }));
        set("title", HIY "金狮镖局少当家" NOR );
              set("gender", "男性");
        set("age", 20);
        set("long", "他就是「金狮镖局」的少当家－－菊不平。\n");

        set("combat_exp", 300000);
        set("max_atman", 300);
        set("atman", 300);
        set("max_force", 3000);
        set("force", 3000);
        set("max_mana", 300);
        set("mana", 300);

        set_skill("force", 40);
        set_skill("sword", 50);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);

        set("inquiry", ([
                "失败" : (:ask_pei:),
                "运镖" : (:ask_job:),
                             "工作" : (:ask_job:),
         ]) );


        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 15);

        setup();
        carry_object("/obj/weapon/sword")->wield();
        carry_object("/obj/cloth")->wear();
}


int ask_job()
{
        object me = this_player(), ob; 
        
        if (file_name(environment(this_object())) !="/d/fy/ginhall") {
                command("shrug");
                command("say 我不在镖局，不知道有没有工作给你啊!");
                return 1;
                }                               

        if (me->query("combat_exp") < 1000000) {
                command("say "+ me->query("name")+"这点身手就来要工作？！");
                return 1;
                }
       
        if (me->query("quest/yunbiao")==1) {
                command("say 回来做什么？快去运镖啦!不然不给工资你的!!");
                return 1;
                }
                
        me->set("quest/yunbiao",1);
        ob = new("/quest/biaotou");
        ob->move(environment(me));
        ob->set_temp("owner/id", me->query("id"));
        ob->set("combat_exp", me->query("combat_exp"));

        ob->set("max_mana",me->query("mana") * 5);
        ob->set("mana", me->query("mana") * 5); 
        ob->set("eff_force",me->query("eff_force") * 5);
        ob->set("max_force",me->query("max_force"));
        ob->set("force",me->query("force"));
        ob->set_skill("dodge",me->query_skill("dodge"));
        ob->set_skill("changquan",me->query_skill("unarmed"));
        ob->map_skill("unarmed", "chuanquan");
        if(random(2)==0){
                command("say " + RANK_D->query_respect(me) +"来得正好，我有一宗镖要运到南宫十一郎手中。");
                ob->set_temp("yangzhou",1);
                }
          else  {
                command("say " + RANK_D->query_respect(me) +"来得正好，我有一宗镖要运到马老四手中。");
                ob->set_temp("taishan",1);
            
                }
         
 
       command("say 你就和这位镖师一起出发吧,记住要保护镖头。");
       command("chat "+ me->query("name") + "替我们金狮镖局运镖，各路英雄豪杰多多关照。");
       return 1;
}       

int ask_pei()
{
        object me = this_player();
        int kar, dot, balance;
        kar = me->query("kar");
        dot = (50 - random(kar)) * (50 - random(kar)) * 250;
        balance = me->query("balance");
        
        if (balance < dot ) {
                command("?");
                command("say 你需要用" + chinese_number(dot / 10000) + "两黄金来赔偿我们的损失。");
                }
        else {
                me->add("balance",-dot);
                command("nod");
                command("say 好的，你回去等消息吧！");
                call_out("cancel",120);
                }
        return 1;
}
                
int cancel()
{
        object me = this_player();
        me->set("quest/yunbiao",0);
        command("tell " + me->query("id") + " 你的赔偿手续已经办妥了。");
}
