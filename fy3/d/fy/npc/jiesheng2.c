//xgchen@zzfy
#include <ansi.h>
inherit NPC;
int do_hunli();
int do_begin();
int do_jz();
void create()
{
        set_name("����ʹ", ({ "angel" }) );
        set("gender", "Ů��" );
        set("age", 22);
        set("long", "����һ��Ư��������ʹ�� \n");
        set("inquiry", ([
                "��ʼ����": (: do_begin :),
                "׼������"    : (: do_jz :),
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
         say (HIR"\n����ʹ����˵��Ϊ�˰�ȫ�������ڼ䲻Ҫ˵����\n" NOR); 
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
          message_vision(HIY "$N��$n˵����׼�����ˣ����������Ӧ�ÿ�ʼ�𣿡�\n" NOR,this_object(),me); 
      return 1;
}

int ke1(object ob)
{
         string xingren1,xingren2;
         xingren1= (string)ob->query("xingren1");
         xingren2= (string)ob->query("xingren2");
         ob = this_object();
         say (RED"\n���þ���������ͼ��С���ӴӶ�����Ƴ�����\n" NOR); 
         call_out("ke2",5,ob);
         return 1;
}

int ke2(object ob)
{
        string xingren1,xingren2;
        xingren1= (string)ob->query("xingren1");
        xingren2= (string)ob->query("xingren2");
        ob = this_object();
         say (RED"\n������·�Ҫ�����ˣ���о�ʮ��ʹ�ࡣ\n" NOR); 
        call_out("ke3",5,ob);
        return 1;
}

int ke3(object ob)
{
       string xingren1,xingren2;
       xingren1= (string)ob->query("xingren1");
       xingren2= (string)ob->query("xingren2");
       ob = this_object();
         say (RED"\n����󿴲������еĶ��������Ǻ�������С���Ŀ�����\n" NOR); 
       call_out("sanhua",5,ob);
       return 1;
}

int sanhua(object ob)
{   
       object flower;
         say (RED"\nС���Ŀ���Խ��Խ���ˡ�\n" NOR); 
          say (RED"\n����ʿ˵���ɹ��ˣ���ϲ���˺��Ӻ���ƽ�����£�̫���ˡ�\n" NOR); 
      flower=new("obj/baby");
       flower->move(this_player());
       return 1;
}


