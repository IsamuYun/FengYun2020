#include <weapon.h>
inherit SWORD;
#include <ansi.h>
void create()
{
    set_name(HIY"无尘剑", ({ "wcsword" }) );
        set_weight(8000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "柄");
            set("material", "stone");
            set("long", "一把宝剑。\n");
          }
        init_sword(90);
    setup();
}
void init()
{
  if(this_player()==environment())
add_action("do_combine","mojian");
}
int do_combine()
{
int i,bk=0,sp=0,il=0;
object commcase,me, *inv;
object moshi,wcsword;
me = this_player();
inv = all_inventory(me);
i=0;
while(i<sizeof(inv))
     {
         if(base_name(inv) == "/d/wiz/fengye/moshi") {bk = 1; moshi = inv[i];}
         if(base_name(inv) == "/d/wiz/fengye/wcsword") {sp = 1; wcsword = inv[i];}
         i++;
               }
if(me->query("int")>=20) {il = 1;}
if(bk && sp && il)
{
moshi->move(environment(me));destruct(moshi);
message_vision("$N拿起磨石仔细的磨起剑来。\n",me);
message_vision("突然无尘剑发出一阵亮光。\n",me);
commcase = new(__DIR__"wcgsword");
commcase->move(me);
wcsword->move(environment(me));destruct(wcsword);
}
else
message_vision("只听见“啪”的一声，剑断了。\n",this_player());;
wcsword->move(environment(me));destruct(wcsword);
return 1;
}
