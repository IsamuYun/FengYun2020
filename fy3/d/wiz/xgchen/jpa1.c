inherit ITEM;
#include <ansi.h>
int do_zuo(string lx);
void create()
{
        set_name(HIY"把手", ({ "jianb"}) );
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

int do_zuo(string lx)
{
if (lx==""||lx!="sword"||lx!="blade")
{       wirte("你要做什么,剑还是刀?);
        return 0;
}

        int wait;
        wait = 6;

int i,da=0,xiao=0,fang=0,yuan=0,hou=0,bo=0,chang=0,duan=0,wu=0,liu=0;
object jade,me, *inv;
object daxz,xiaoxz,changxz,duanxz,fangxz,yuanxz,houxz,boxz,wuxz,liuxz;
me = this_player();
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
if( da && xiao && fang && yuan && chang && duan && hou && bo && wu && liu )
{
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
        if(lx=="sword") 
        {
        me->start_busy(6);
         message_vision("$N盘腿坐在地上,摆开十枚勋章拼对起来,喀...喀....一阵响却拼成了一把刀．\n",this_player());
//        call_out("zuo2", wait, this_player());
        }
        else
        {
        me->start_busy(6);
         message_vision("$N盘腿坐在地上,摆开十枚勋章拼对起来,喀...喀....一阵响却拼成了一柄剑．\n",this_player());
//        call_out("zuo3", wait, this_player());
        }
        
//      destruct(this_object());

}
else 
message_vision("$N把手里的几枚勋章摆弄了几下．\n",this_player());

return 1;
}}

//void zuo2(object me)
//{
//      jade = new("/tongji/obj/sword");
//              jade->move(me);
//              message_vision("$N急的满头大汉,重新摆开十枚勋章拼对起来,喀...喀....一阵响终于拼成了一柄剑．\n",this_player());
//      return;
//}
//void zuo3(object me)
//{
//      jade = new("/tongji/obj/blade");
//              jade->move(me);
//              message_vision("$N急的满头大汉,重新摆开十枚勋章拼对起来,喀...喀....一阵响终于拼成了一把刀．\n",this_player());
//      return;
/}
