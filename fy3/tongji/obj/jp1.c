inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIY"把手"NOR, ({ "jianb"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "这是一个纯金打造的东西,好象是剑或者刀的把手,你的勋章
好象和这东西的凹槽很吻合,你可以试着拼装(zuo)一下.\n");
                set("value", 1);
        }
}

void init()
{
  if(this_player()==environment())
  add_action("do_zuo","zuo");
}

int do_zuo(string arg)
{
int i,da=0,xiao=0,fang=0,yuan=0,hou=0,bo=0,chang=0,duan=0,wu=0,liu=0;
object jade,me, *inv;
object daxz,xiaoxz,changxz,duanxz,fangxz,yuanxz,houxz,boxz,wuxz,liuxz;
me = this_player();
if (!(me->query("m_success/通缉")))
{
message_vision(HIC"只有通缉十大恶人的功臣才有资格组装这种武器!\n"NOR,this_player());
return 1;
}
inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
                        if(inv[i]->query("name") == "大勋章") {da = 1; daxz = inv[i];}
                        if(inv[i]->query("name") == "小勋章") {xiao = 1; xiaoxz = inv[i];}
                        if(inv[i]->query("name") == "方勋章") {fang = 1; fangxz = inv[i];}
                        if(inv[i]->query("name") == "圆勋章") {yuan = 1; yuanxz = inv[i];}
                        if(inv[i]->query("name") == "长勋章") {chang = 1; changxz = inv[i];}
                        if(inv[i]->query("name") == "短勋章") {duan = 1; duanxz = inv[i];}
                        if(inv[i]->query("name") == "厚勋章") {hou = 1; houxz = inv[i];}
                        if(inv[i]->query("name") == "薄勋章") {bo = 1; boxz = inv[i];}
                        if(inv[i]->query("name") == "五角勋章") {wu = 1; wuxz = inv[i];}
                        if(inv[i]->query("name") == "六角勋章") {liu = 1; liuxz = inv[i];}

                }
if( !(da && xiao && fang && yuan && chang && duan && hou && bo && wu && liu ))
{message_vision("$N把手里的几枚勋章摆弄了几下,发现还少一些部件．\n",this_player());
return 1;
}


if (!(arg=="blade"||arg=="sword")) 
{
                tell_object(me,"你要做什么?刀(blade)还是剑(sword)?\n" NOR);
                return 1;
        }


if(arg=="sword")        
{
       me->start_busy(6);
        if(random(5)) 
        {
                message_vision("$N盘腿坐在地上,摆开十枚勋章拼对起来,喀...喀....一阵响却拼成了一把刀．\n",this_player());
                return 1;
        }
        else
        {
        jade = new("/tongji/obj/sword");
        jade->move(me);
        destruct(daxz);
        destruct(xiaoxz);
        destruct(fangxz);
        destruct(yuanxz);
        destruct(changxz);
        destruct(duanxz);
        destruct(houxz);
        destruct(boxz);
        destruct(wuxz);
        destruct(liuxz);
        message_vision("$N急的满头大汉,重新摆开十枚勋章拼对起来,喀...喀....一阵响终于拼成了一柄剑．\n",me);
        command("jump");
        destruct(this_object());
}}
if (arg=="blade")
{
        me->start_busy(6);
        if(random(5)) 
        {       message_vision("$N盘腿坐在地上,摆开十枚勋章拼对起来,喀...喀....一阵响却拼成了一柄剑．\n",this_player());
                return 1;
        }
        else 
        {
        jade = new("/tongji/obj/blade1");
        jade->move(me);
        destruct(daxz);
        destruct(xiaoxz);
        destruct(fangxz);
        destruct(yuanxz);
        destruct(changxz);
        destruct(duanxz);
        destruct(houxz);
        destruct(boxz);
        destruct(wuxz);
        destruct(liuxz);
        message_vision("$N急的满头大汉,重新摆开十枚勋章拼对起来,喀...喀....一阵响终于拼成了一把刀．\n",me);
        command("jump");
        destruct(this_object());

        }
}
return 1;
}
