inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIY"����"NOR, ({ "jianb"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���������Ķ���,�����ǽ����ߵ��İ���,���ѫ��
������ⶫ���İ��ۺ��Ǻ�,���������ƴװ(zuo)һ��.\n");
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
if (!(me->query("m_success/ͨ��")))
{
message_vision(HIC"ֻ��ͨ��ʮ����˵Ĺ��������ʸ���װ��������!\n"NOR,this_player());
return 1;
}
inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
                        if(inv[i]->query("name") == "��ѫ��") {da = 1; daxz = inv[i];}
                        if(inv[i]->query("name") == "Сѫ��") {xiao = 1; xiaoxz = inv[i];}
                        if(inv[i]->query("name") == "��ѫ��") {fang = 1; fangxz = inv[i];}
                        if(inv[i]->query("name") == "Բѫ��") {yuan = 1; yuanxz = inv[i];}
                        if(inv[i]->query("name") == "��ѫ��") {chang = 1; changxz = inv[i];}
                        if(inv[i]->query("name") == "��ѫ��") {duan = 1; duanxz = inv[i];}
                        if(inv[i]->query("name") == "��ѫ��") {hou = 1; houxz = inv[i];}
                        if(inv[i]->query("name") == "��ѫ��") {bo = 1; boxz = inv[i];}
                        if(inv[i]->query("name") == "���ѫ��") {wu = 1; wuxz = inv[i];}
                        if(inv[i]->query("name") == "����ѫ��") {liu = 1; liuxz = inv[i];}

                }
if( !(da && xiao && fang && yuan && chang && duan && hou && bo && wu && liu ))
{message_vision("$N������ļ�öѫ�°�Ū�˼���,���ֻ���һЩ������\n",this_player());
return 1;
}


if (!(arg=="blade"||arg=="sword")) 
{
                tell_object(me,"��Ҫ��ʲô?��(blade)���ǽ�(sword)?\n" NOR);
                return 1;
        }


if(arg=="sword")        
{
       me->start_busy(6);
        if(random(5)) 
        {
                message_vision("$N�������ڵ���,�ڿ�ʮöѫ��ƴ������,��...��....һ����ȴƴ����һ�ѵ���\n",this_player());
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
        message_vision("$N������ͷ��,���°ڿ�ʮöѫ��ƴ������,��...��....һ��������ƴ����һ������\n",me);
        command("jump");
        destruct(this_object());
}}
if (arg=="blade")
{
        me->start_busy(6);
        if(random(5)) 
        {       message_vision("$N�������ڵ���,�ڿ�ʮöѫ��ƴ������,��...��....һ����ȴƴ����һ������\n",this_player());
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
        message_vision("$N������ͷ��,���°ڿ�ʮöѫ��ƴ������,��...��....һ��������ƴ����һ�ѵ���\n",me);
        command("jump");
        destruct(this_object());

        }
}
return 1;
}
