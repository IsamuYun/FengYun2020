#include <ansi.h>
inherit ITEM;
void create()
{	set_name("����",({"table","dinner table"}));
	set("long","һ�Ŵ���������źö�óԵģ�\n");
	set_max_encumbrance(8000);
	set("unit","��");
	set("value",99);
	set("no_get", 1);
	set("prep","on");
	new(__DIR__"menu")->move(this_object());
}
int is_container() {return 1;}
void init()
{  add_action("do_eat","eat");
   add_action("do_drink","drink");}

int do_eat(string arg)
{  string *msg=({

 "$N����һ��$n����óԡ�\n",
 "$N����һ��$nһ��������ȥ�����������Աߵ��ˣ�ʲôζ������\n" 
                });
   object me,ob; 
   me=this_player();
   if(!arg||arg=="") 
  {message_vision("$N����������������ʲô����O~~~~~~~~~~\n",me);
   return 1;}
   if(!(objectp(ob=present(arg,this_object()))))
  {message_vision("$N����������������ʲô����O~~~~~~~~~~\n",me);
   return 1;}
   if(me->query("food")>me->max_food_capacity()*1.5)
  {message_vision("$N��������������ȴ�������ش��˸����ã��ҳԡ�����\n",me);
   return 1;} 
   if(ob->query("type")!="food")
  {message_vision("$N����һ������ȥ��$n������ҼУ�$n�����������ˡ�\n",me,ob);
   return 1;}
   message_vision(msg[random(sizeof(msg))],me,ob);
   me->add("food",10);ob->add("amount",-1);
   if(ob->query("amount")<1) destruct(ob);
return 1;}
int do_drink(string arg)
{  string *drunk=({

 "$Nҡҡ�λε�˵�������Ƕ����ˣ�������һ�������������ˡ�����\n",
 "$N˵������~~~û~��~~����~~~��~һ��~~~~~~\n",
 "$N������������һ�����ȣ������ɡ�����\n"
                 });
   string *msg=({

 "$N����һ��$n����һС�ڣ�����ֱ����ͷ��\n",
 "$N����һ��$n��ཹ��һ��������\n",
 "$Nһ�ߺߺߡ�$n�ӿ��ȣ���һ����һ������˵������һ����\n"
                });
   object me,ob,id;
   string obb,idd; 
   me=this_player();
   if(!arg||arg=="") 
  {message_vision("$N��������ƿ�ӣ��ȵ�ʲô��O~~~~~~~~~~\n",me);
   return 1;}
   if(sscanf(arg,"%s with %s",obb,idd)==2) arg=obb;
   if(!(objectp(ob=present(arg,this_object()))))
  {message_vision("$N��������ƿ�ӣ��ȵ�ʲô��O~~~~~~~~~~\n",me);
   return 1;}
   if(me->query("water")>me->max_water_capacity()*1.2)
  {message_vision(drunk[random(sizeof(drunk))],me);
   return 1;} 
   if(ob->query("type")!="drink")
  {message_vision("$N����$n��ȴ��С�Ĺൽ�˱�����^*^\n",me,ob);
   return 1;}
   if(arg==obb) id=present(idd,environment(me));
   if(objectp(id))
     message_vision("$N����"+id->query("name")+"����һ��$n˵�����ɣ�˵��һ��������\n",me,ob);
   else message_vision(msg[random(sizeof(msg))],me,ob);
   me->add("water",10);ob->add("amount",-1);
   if(ob->query("amount")<1) destruct(ob);
return 1;}
