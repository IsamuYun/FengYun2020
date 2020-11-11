//xgchen@zzfy
#include <ansi.h>
inherit NPC;
int do_hunli();
int do_begin();
int do_jz();
void create()
{
        set_name("助产使", ({ "angel" }) );
        set("gender", "女性" );
        set("age", 22);
        set("long", "这是一个漂亮的助产使。 \n");
        set("inquiry", ([
                "开始接生": (: do_begin :),
                "准备好了"    : (: do_jz :),
        ])); 

        set("combat_exp", 100000000);
        set_skill("unarmed", 30);
        set_skill("parry", 30);
        set_skill("dodge", 30);
        set_skill("sword",30);
        setup();
        carry_object("/obj/cloth")->wear();
        
}
void init()
{
        object ob;
        ::init();
        add_action("do_begin", "begin");
        add_action("do_jz", "jz");
}
int do_begin()
{
       object me,ob,obj,ke,check;
       ob = this_object();
             me = this_player();
              if(!me->query("jiesheng/begin")) return 0;
         say (HIR"\n助产使对你说：为了安全，请在期间不要说话。\n" NOR); 
            me->delete("jiesheng/begin");
     call_out("ke1", 5, ob);
       return 1;
} 
            
int do_jz()
{     
       object me,obj,check,dress;
       me = this_player();
       if(!me->query("jiesheng-ok")) return 0;
          me->delete("jiesheng-ok");
          me->set("jiesheng/begin",1);
          message_vision(HIY "$N对$n说：“准备好了，好那你觉得应该开始吗？”\n" NOR,this_object(),me); 
      return 1;
}

int ke1(object ob)
{
         string xingren1,xingren2;
         xingren1= (string)ob->query("xingren1");
         xingren2= (string)ob->query("xingren2");
         ob = this_object();
         say (RED"\n你用尽力气，企图将小孩子从肚子里逼出来。\n" NOR); 
         call_out("ke2",5,ob);
         return 1;
}

int ke2(object ob)
{
        string xingren1,xingren2;
        xingren1= (string)ob->query("xingren1");
        xingren2= (string)ob->query("xingren2");
        ob = this_object();
         say (RED"\n你下体仿佛将要破裂了，你感觉十分痛苦。\n" NOR); 
        call_out("ke3",5,ob);
        return 1;
}

int ke3(object ob)
{
       string xingren1,xingren2;
       xingren1= (string)ob->query("xingren1");
       xingren2= (string)ob->query("xingren2");
       ob = this_object();
         say (RED"\n你好象看不清所有的东西，但是好象听见小孩的哭声。\n" NOR); 
       call_out("sanhua",5,ob);
       return 1;
}

int sanhua(object ob)
{   
       object flower;
         say (RED"\n小孩的哭声越来越大了。\n" NOR); 
          say (RED"\n助产士说：成功了，恭喜夫人孩子和你平安无事，太好了。\n" NOR); 
      flower=new("obj/baby");
       flower->move(this_player());
       return 1;
}


