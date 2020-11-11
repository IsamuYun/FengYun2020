inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int give_him();

void create()
{
        set_name("��ë��", ({ "you chai", "you"}) );
        set("title","�����ʲ�");
        set("gender", "����" );
        set("age", 46);
        set("agi",30);
        set("str", 22);
        set("per", 28);
        set("int",24);
        set("attitude","friendly");
        set("max_force", 5000);
        set("force", 5000);
        set("force_factor", 40);
        set("max_mana", 5000);
        set("mana", 5000);
        set("max_atman", 5000);
        set("atman", 5000);
        set("long",
"���Ƴǵ��ʲ��˵�����ʱ���ܵķǳ��졣�����з�ë�ȵ���š�\n"
        );
        set("chat_chance_combat", 20);
        set("combat_exp", 1000000);
        set_skill("dodge", 110);
        set_skill("move",140);
        set_skill("force", 140);
        set_skill("sword", 110);
        set_skill("literate", 120);
        set_skill("unarmed",110);
        set_skill("yiyang-zhi", 110);
        map_skill("force", "tianlong-shengong");
        map_skill("unarmed", "yiyang-zhi");
        set("inquiry", 
([ "�ܺ�" : (: give_him :), "letter" : (: give_him :)  ]));
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
        switch( random(10) ) {
                case 0:
message_vision("$N˵������ÿ��Ҫ�͵��ż�̫���ˣ�������\n",this_object(),ob);
                        break;
                case 1:
message_vision("$N����$nһ�ۣ��ʵ������ܰ������Ҳ��������ģ�����\n",this_object(),ob);
                        break;
        }
}

int give_him()
{
        string *order1 = ({"/d/dali/quan5","/u/wudang/farm4","/u/wudang/farm5","/d/dali/quan6","/d/manglin/center2","/u/wudang/farm6","/d/manglin/center4","/d/dali/quan7","/u/wudang/farm7","/d/manglin/center1","/d/dali/quan2","/u/wudang/farm9","/d/dali/quan3"});
        string time11;
        object me , obj ,room1;
        int xintime,m,s;
        me = this_player();        
        if(me->query("lettertime") > time()) 
           {
    tell_object(me,"��ë��˵���������һ���Ż�û�͵�����ô��������Ҫ����\n");
            return 1;
           }
        obj = new("/d/dali/obj/letter");
        xintime = 100+me->query("kar")*10+random(50);
        s = xintime % 60;             m = xintime / 60;
        room1 = load_object(order1[random(16)]);
        me->set("lettertime",time()+xintime);
        obj->set("pname",me->query("name"));
        time11 = "��ë��˵����";
        time11 += room1->query("short");
        time11 += "��һ���ܺ���һ��Ҫ��"HIW;
        time11 += chinese_number(m) + "��";
        time11 += chinese_number(s) + "��" ;
        time11 += NOR "���ͽ���" HIW ;
        time11 += obj->query("toname") + NOR"����������ȥ���\n";
        tell_object(me, time11);
        me->set("letter",time()+600+random(300));
        me->add("giveletter",1);        
        obj->move(me);
        me->move(room1);
        tell_object(me,"һ�����������˸�����һ���ܺ���\n");
        me->set_temp("nofly",1);
        me->set_temp("noburn",1);
        return 1;
}

int accept_object(object who, object ob)
{
  int  exp, pot,score;
  exp = random(200)+300;
  pot = exp / 10;
  score = exp / 100 + random(10) ;
  if(ob->query("name") == "�غ�")
    {
     who->delete("lettertime");
     if(!(ob->query("pname") == who->query("name")) )
      {
       write("��ë��˵��:�������������Ķ�����û���ˣ�\n");
       return 1;
      }
     command("nod");     
     command("say ��! лл������ҡ���˵���Ҳ��������ģ�\n");
        who->add("LQUEST",1);
        who->add("combat_exp",exp);
        who->add("potential",pot);
        who->add("score",score);
        who->delete_temp("lettertime");
        tell_object(who,HIW"�㱻�����ˣ�\n" +
        chinese_number(exp) + "��ʵս����\n"+
        chinese_number(pot) + "��Ǳ��\n"+
        chinese_number(score) + "���ۺ����ۡ�\n" NOR);
        return 1;
    }
  tell_object(who,"��ë��˵����л�ͣ�\n");
  return 1;
}

