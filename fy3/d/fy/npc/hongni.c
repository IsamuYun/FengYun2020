#include <ansi.h>
inherit NPC;
int do_hunli();
int do_qingtie();
int do_begin();
int do_jz();
void create()
{
        set_name("ý����Ů", ({ "sunnv", "nv" }));
        set("long", 
                "����һ�����úܺÿ���С���\n"
                "����ý�ŵĺð��֣����������������д��ͻ���\n");
        set("title", "ԧ��ͤ");
        set("gender", "Ů��");
        set("age", 16);
        set_skill("unarmed", 20);
        	  set_temp("kf_tufei",25);
        set("pursuer", 1);
set_skill("dodge", 20);
        set_skill("parry", 20);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set_temp("apply/damage", 5);
        set("combat_exp", 3000);
        set("inquiry", ([
                "������"    : (: do_qingtie :),
                "��ʼ����": (: do_begin :),
                "���"    : (: do_jz :),
        ])); 
        setup();
}

void init()
{
        object ob;
        ::init();
        add_action("do_qingtie", "fatie");
        add_action("do_begin", "begin");
        add_action("do_jz", "jz");
}
int do_qingtie()
{
       object me, tie, ob, *all, ke, ma;
       int i;
       object xingren1 ,xingren2;
       me=this_player();
       ob=this_object();
       all = users();
       if (!me->query("jiehun/qingtie")) 
       {
        say ("ý����Ů˵���������ǽ�鵱��ſ������ˡ���\n");
        return 1;
       }
  message_vision(HIW "$N�������֣������İ׸������������ž�������ȥ��\n" NOR,this_object()); 
       for(i=0; i<sizeof(all); i++) 
        {
          ke = all[i];
          tie =new(__DIR__"obj/qingtie");
          tie->set("name",HIR+(string)me->query("name")+"��"+(string)me->query("marryname")+"�Ľ������" NOR);
          tell_object(ke,HIR"һֻ�׸�ɵ������ϣ�������һ��������Ȼ������ˡ�\n\n"NOR); 
          tie->move(ke);
        }
       me->set("jiehun/dress_begin",1);
       me->delete("jiehun/qingtie");
       ma=new(__DIR__"mafu1");
         ob->set("xingren1",me->query("name"));
        ob->set("xingren2",me->query("marryname"));
      ma->move("/d/fy/marry_room");
       say(HIR "������Цһ��˵�������˵����˾͸�����һ������ʼǰ�����ӿ�Ҫ����硻һ��ม���\n" NOR);
       return 1;
}

int do_begin()
{
       object me,ob,obj,ke,check;
       ob = this_object();
             me = this_player();
              if(!me->query("jiehun/begin")) return 0;
        message("shout", HIR "�����񡿣�ý�ţ�������˾�������ٿˣ�\n" NOR,users());
   message("shout", HIR "�����񡿣������ٿ˸߽У���" + me->query("name") + "��" 
         + me->query("marryname") + "�������ڿ�ʼ����\n" NOR,users());
       me->delete("jiehun/begin");
       call_out("ke1", 3, ob);
       return 1;
} 
            
int do_jz()
{     
       object me,obj,check,dress;
       me = this_player();
       if(!me->query("jiehun/dress_begin")) return 0;
       if(!(obj = find_player(me->query("marry")))) return 0;
       if (me->query("gender")!="����")
          { check = me; }
        else { check = obj; }
       if (check->query("jiehun/begin")) 
         { 
           say ("����̾�˿���˵�����ҿ�ֻ��һ��ױ�¡���\n");
           return 1;
         }

       if ( me->query("gender")=="����")

       { 
          dress=new(__DIR__"obj/clasp");
          dress->move(obj);
          dress=new(__DIR__"obj/marry_cloth");
          dress->move(obj);
          dress=new(__DIR__"obj/bracelet");
          dress->move(obj);
          message_vision(HIW "$N�������֣�һλ����С��������һ��ױ�¡�\n" NOR,this_object()); 
          message_vision(HIB "$N��$n˵�����ӿ�Ҫ�úô��һ�¡�\n" NOR,this_object(),obj); 
          message_vision(HIY "$N��$nһֻ�����Ρ�\n" NOR,this_object(),obj); 
          message_vision(HIW "$N��$nһ����ɫ��ɴ��\n" NOR,this_object(),obj); 
          message_vision(HIG "$N��$nһֻ�������\n" NOR,this_object(),obj); 
          me->delete("jiehun/dress_begin");
          me->set("jiehun/begin",1);
          message_vision(HIY "$N��$n˵�����촩�����ɡ���\n" NOR,this_object(),obj); 
       }
       else
        {
          dress=new(__DIR__"obj/clasp");
          dress->move(me);
          dress=new(__DIR__"obj/marry_cloth");
          dress->move(me);
          dress=new(__DIR__"obj/bracelet");
          dress->move(me);
          message_vision(HIW "$N�������֣�һλ����С��������һ��ױ�¡�\n" NOR,this_object()); 
          message_vision(HIB "$N��$n˵�����ӿ�Ҫ�úô��һ�¡�\n" NOR,this_object(),me); 
          message_vision(HIY "$N��$nһֻ�����Ρ�\n" NOR,this_object(),me); 
          message_vision(HIW "$N��$nһ����ɫ��ɴ��\n" NOR,this_object(),me); 
          message_vision(HIG "$N��$nһֻ�������\n" NOR,this_object(),me); 
          me->delete("jiehun/dress_begin");
          me->set("jiehun/begin",1);
          message_vision(HIY "$N��$n˵���������ӿ촩�����ɡ���\n" NOR,this_object(),me); 
        }
      return 1;
}

int ke1(object ob)
{
         string xingren1,xingren2;
         xingren1= (string)ob->query("xingren1");
         xingren2= (string)ob->query("xingren2");
         ob = this_object();
         message("shout", HIR "�����񡿣������ٿ˸߽У���һ����ء�\n" NOR,users());
         say ("\n"+ HIW + xingren1 + "��" + xingren2 + "�������һ��ͷ��\n" NOR); 
         call_out("ke2",3,ob);
         return 1;
}

int ke2(object ob)
{
        string xingren1,xingren2;
        xingren1= (string)ob->query("xingren1");
        xingren2= (string)ob->query("xingren2");
        ob = this_object();
        message("shout", HIR "�����񡿣������ٿ˸߽У������ݸ��á�\n" NOR,users());
        say ("\n"+HIB + xingren1 + "��" + xingren2 + "�Ը�λ��ʦ����һ��ͷ��\n" NOR);
        call_out("ke3",3,ob);
        return 1;
}

int ke3(object ob)
{
       string xingren1,xingren2;
       xingren1= (string)ob->query("xingren1");
       xingren2= (string)ob->query("xingren2");
       ob = this_object();
       message("shout", HIR "�����񡿣������ٿ˸߽У������޶԰ݡ�\n" NOR,users());
       say ("\n"+HIY + xingren1 + "��" + xingren2 + "�����������໥�԰ݡ�\n" NOR);
       call_out("sanhua",3,ob);
       return 1;
}

int sanhua(object ob)
{   
       object flower;
       message("shout", HIR "�����񡿣������ٿ˸߽У�����ͯɢ����\n" NOR,users());
       message("shout", HIR "�������ƳǵĽֵ�������һ���ͷ׵Ļ��ꡣ\n\n" NOR,users());
       flower=new(__DIR__"obj/flower"+random(6));
       flower->move("/d/fy/swind1");
       flower=new(__DIR__"obj/flower"+random(6));
       flower->move("/d/fy/swind2");
       flower=new(__DIR__"obj/flower"+random(6));
       flower->move("/d/fy/swind3");
       flower=new(__DIR__"obj/flower"+random(6));
       flower->move("/d/fy/swind4");
       flower=new(__DIR__"obj/flower"+random(6));
       flower->move("/d/fy/swind5");
       flower=new(__DIR__"obj/flower"+random(6));
       flower->move("/d/fy/nwind1");
       flower=new(__DIR__"obj/flower"+random(6));
       flower->move("/d/fy/nwind2");
       flower=new(__DIR__"obj/flower"+random(6));
       flower->move("/d/fy/nwind3");
       flower=new(__DIR__"obj/flower"+random(6));
       flower->move("/d/fy/nwind4");
       flower=new(__DIR__"obj/flower"+random(6));
       flower->move("/d/fy/nwind5");
       flower=new(__DIR__"obj/flower"+random(6));
       flower->move("/d/fy/ecloud1");
       flower=new(__DIR__"obj/flower"+random(6));
       flower->move("/d/fy/ecloud2");
       flower=new(__DIR__"obj/flower"+random(6));
       flower->move("/d/fy/ecloud3");
       flower=new(__DIR__"obj/flower"+random(6));
       flower->move("/d/fy/ecloud4");
       flower=new(__DIR__"obj/flower"+random(6));
       flower->move("/d/fy/ecloud5");
       flower=new(__DIR__"obj/flower"+random(6));
       flower->move("/d/fy/wcloud1");
       flower=new(__DIR__"obj/flower"+random(6));
       flower->move("/d/fy/wcloud2");
       flower=new(__DIR__"obj/flower"+random(6));
       flower->move("/d/fy/wcloud3");
       flower=new(__DIR__"obj/flower"+random(6));
       flower->move("/d/fy/wcloud4");
       flower=new(__DIR__"obj/flower"+random(6));
       flower->move("/d/fy/wcloud5");
       ob = this_object();
       call_out("eateat",3,ob);
       return 1;

}

int eateat(object ob)
{
      object food1, food2,food3,ke,*all;
      int i;
      all=users();
      message("shout", HIR "�����񡿣������ٿ˸߽У������޶���,������͡�\n" NOR,users());
      for(i=0; i<sizeof(all); i++) 
        {
          ke = all[i];
          food1 = new(__DIR__"obj/wlywine");
            food1->move(ke);
           tell_object(ke,"��õ�һƿ"+(string)food1->query("name")+"��\n");
          food2 = new(__DIR__"obj/yan");
              food2->move(ke);
           tell_object(ke,"��õ�һ��"+(string)food2->query("name")+"��\n");
          food3 = new(__DIR__"obj/sugar"); 
           food3->move(ke);
          tell_object(ke,"��õ�һ��"+(string)food2->query("name")+"��\n");
        }
     message("shout", HIR "�����񡿣������ٿ˸߽У���������ϡ�\n" NOR,users());
}   
