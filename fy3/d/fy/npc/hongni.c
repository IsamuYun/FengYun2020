#include <ansi.h>
inherit NPC;
int do_hunli();
int do_qingtie();
int do_begin();
int do_jz();
void create()
{
        set_name("媒婆孙女", ({ "sunnv", "nv" }));
        set("long", 
                "她是一个长得很好看的小姑娘。\n"
                "她是媒婆的好帮手，你可以让他帮你举行大型婚礼。\n");
        set("title", "鸳鸯亭");
        set("gender", "女性");
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
                "发请贴"    : (: do_qingtie :),
                "开始婚礼": (: do_begin :),
                "打扮"    : (: do_jz :),
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
        say ("媒婆孙女说：“请贴是结婚当天才可以用了。”\n");
        return 1;
       }
  message_vision(HIW "$N拍了拍手，无数的白鸽带着请贴噼里啪啦冲天而去。\n" NOR,this_object()); 
       for(i=0; i<sizeof(all); i++) 
        {
          ke = all[i];
          tie =new(__DIR__"obj/qingtie");
          tie->set("name",HIR+(string)me->query("name")+"和"+(string)me->query("marryname")+"的结婚请贴" NOR);
          tell_object(ke,HIR"一只白鸽飞到你身上，带给你一张请贴，然后飞走了。\n\n"NOR); 
          tie->move(ke);
        }
       me->set("jiehun/dress_begin",1);
       me->delete("jiehun/qingtie");
       ma=new(__DIR__"mafu1");
         ob->set("xingren1",me->query("name"));
        ob->set("xingren2",me->query("marryname"));
      ma->move("/d/fy/marry_room");
       say(HIR "红娘轻笑一声说：“客人到齐了就告诉我一声。开始前新娘子可要『打扮』一下喔。”\n" NOR);
       return 1;
}

int do_begin()
{
       object me,ob,obj,ke,check;
       ob = this_object();
             me = this_player();
              if(!me->query("jiehun/begin")) return 0;
        message("shout", HIR "【婚礼】：媒婆：有请大会司仪罗曼蒂克！\n" NOR,users());
   message("shout", HIR "【婚礼】：罗曼蒂克高叫：“" + me->query("name") + "和" 
         + me->query("marryname") + "婚礼现在开始！”\n" NOR,users());
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
       if (me->query("gender")!="男性")
          { check = me; }
        else { check = obj; }
       if (check->query("jiehun/begin")) 
         { 
           say ("红娘叹了口气说：“我可只有一套妆衣。”\n");
           return 1;
         }

       if ( me->query("gender")=="男性")

       { 
          dress=new(__DIR__"obj/clasp");
          dress->move(obj);
          dress=new(__DIR__"obj/marry_cloth");
          dress->move(obj);
          dress=new(__DIR__"obj/bracelet");
          dress->move(obj);
          message_vision(HIW "$N拍了拍手，一位青衣小厮送上了一套妆衣。\n" NOR,this_object()); 
          message_vision(HIB "$N对$n说新娘子可要好好打扮一下。\n" NOR,this_object(),obj); 
          message_vision(HIY "$N给$n一只凤翅金钗。\n" NOR,this_object(),obj); 
          message_vision(HIW "$N给$n一件白色婚纱。\n" NOR,this_object(),obj); 
          message_vision(HIG "$N给$n一只翡翠手镯。\n" NOR,this_object(),obj); 
          me->delete("jiehun/dress_begin");
          me->set("jiehun/begin",1);
          message_vision(HIY "$N对$n说：“快穿起来吧。”\n" NOR,this_object(),obj); 
       }
       else
        {
          dress=new(__DIR__"obj/clasp");
          dress->move(me);
          dress=new(__DIR__"obj/marry_cloth");
          dress->move(me);
          dress=new(__DIR__"obj/bracelet");
          dress->move(me);
          message_vision(HIW "$N拍了拍手，一位青衣小厮送上了一套妆衣。\n" NOR,this_object()); 
          message_vision(HIB "$N对$n说新娘子可要好好打扮一下。\n" NOR,this_object(),me); 
          message_vision(HIY "$N给$n一只凤翅金钗。\n" NOR,this_object(),me); 
          message_vision(HIW "$N给$n一件白色婚纱。\n" NOR,this_object(),me); 
          message_vision(HIG "$N给$n一只翡翠手镯。\n" NOR,this_object(),me); 
          me->delete("jiehun/dress_begin");
          me->set("jiehun/begin",1);
          message_vision(HIY "$N对$n说：“新娘子快穿起来吧。”\n" NOR,this_object(),me); 
        }
      return 1;
}

int ke1(object ob)
{
         string xingren1,xingren2;
         xingren1= (string)ob->query("xingren1");
         xingren2= (string)ob->query("xingren2");
         ob = this_object();
         message("shout", HIR "【婚礼】：罗曼蒂克高叫：“一拜天地”\n" NOR,users());
         say ("\n"+ HIW + xingren1 + "和" + xingren2 + "对天磕了一个头。\n" NOR); 
         call_out("ke2",3,ob);
         return 1;
}

int ke2(object ob)
{
        string xingren1,xingren2;
        xingren1= (string)ob->query("xingren1");
        xingren2= (string)ob->query("xingren2");
        ob = this_object();
        message("shout", HIR "【婚礼】：罗曼蒂克高叫：“二拜高堂”\n" NOR,users());
        say ("\n"+HIB + xingren1 + "和" + xingren2 + "对各位巫师磕了一个头。\n" NOR);
        call_out("ke3",3,ob);
        return 1;
}

int ke3(object ob)
{
       string xingren1,xingren2;
       xingren1= (string)ob->query("xingren1");
       xingren2= (string)ob->query("xingren2");
       ob = this_object();
       message("shout", HIR "【婚礼】：罗曼蒂克高叫：“夫妻对拜”\n" NOR,users());
       say ("\n"+HIY + xingren1 + "和" + xingren2 + "含情脉脉的相互对拜。\n" NOR);
       call_out("sanhua",3,ob);
       return 1;
}

int sanhua(object ob)
{   
       object flower;
       message("shout", HIR "【婚礼】：罗曼蒂克高叫：“花童散花”\n" NOR,users());
       message("shout", HIR "整个风云城的街道下起了一阵缤纷的花雨。\n\n" NOR,users());
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
      message("shout", HIR "【婚礼】：罗曼蒂克高叫：“夫妻洞房,大宴宾客”\n" NOR,users());
      for(i=0; i<sizeof(all); i++) 
        {
          ke = all[i];
          food1 = new(__DIR__"obj/wlywine");
            food1->move(ke);
           tell_object(ke,"你得到一瓶"+(string)food1->query("name")+"。\n");
          food2 = new(__DIR__"obj/yan");
              food2->move(ke);
           tell_object(ke,"你得到一包"+(string)food2->query("name")+"。\n");
          food3 = new(__DIR__"obj/sugar"); 
           food3->move(ke);
          tell_object(ke,"你得到一粒"+(string)food2->query("name")+"。\n");
        }
     message("shout", HIR "【婚礼】：罗曼蒂克高叫：“婚礼完毕”\n" NOR,users());
}   
