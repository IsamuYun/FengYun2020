// updated.c
// 自动检测升级系统

#include <ansi.h>
inherit F_DBASE;
void upgrade(object ob);

void ready_to_start()
{
        remove_call_out("check_all");
        call_out("check_all",500); // 间隔时间，300-500为宜
}
void create()
{
        seteuid(ROOT_UID);
        set("channel_id", "升级检测精灵");
        CHANNEL_D->do_channel( this_object(), "sys", "升级检测系统已经启动。\n");
        ready_to_start();
}

void upgrade(object ob)
{
        if(userp(ob))
        {
        int exp=ob->query("combat_exp");
        int level=ob->query("level"); //&&level<1
        if (exp>=5000&&level<1){
        ob->set("level",1);
        ob->add("potential",exp/100);
        tell_object(ob,WHT"\n\t\t\t"+ob->name()+"，祝贺你！\n"+GRN
        +"\t你成功的达到了5000EXP，升上了"YEL"入门级！\n"+GRN
        +"\t由于你的升级，你获得了"YEL+exp/100+GRN"点潜能点数的奖励！\n"NOR );
                }
        if (exp>=10000&&level<2){
        ob->set("level",2);
        ob->add("potential",exp/100);
        tell_object(ob,WHT"\n\t\t\t"+ob->name()+"，祝贺你！\n"+GRN
        +"\t你成功的达到了10000EXP，升上了"HIW"新秀级！\n"+GRN
        +"\t由于你的升级，你获得了"YEL+exp/100+GRN"点潜能点数的奖励！\n"NOR );
                }
        if (exp>=20000&&level<3){
        ob->set("level",3);
        ob->add("potential",exp/100);
        tell_object(ob,WHT"\n\t\t\t"+ob->name()+"，祝贺你！\n"+GRN
        +"\t你成功的达到了20000EXP，升上了"RED"小侠级！\n"+GRN
        +"\t由于你的升级，你获得了"YEL+exp/100+GRN"点潜能点数的奖励！\n"NOR );
                }
        if (exp>=50000&&level<4){
        ob->set("level",4);
        ob->add("potential",exp/100);
        tell_object(ob,WHT"\n\t\t\t"+ob->name()+"，祝贺你！\n"+GRN
        +"\t你成功的达到了50000EXP，升上了"HIY"侠客级！\n"+GRN
        +"\t由于你的升级，你获得了"YEL+exp/100+GRN"点潜能点数的奖励！\n"NOR );
                }
        if (exp>=100000&&level<5){
        ob->set("level",5);
        ob->add("potential",exp/100);
        tell_object(ob,WHT"\n\t\t\t"+ob->name()+"，祝贺你！\n"+GRN
        +"\t你成功的达到了100000EXP，升上了"HIB"大侠级！\n"+GRN
        +"\t由于你的升级，你获得了"YEL+exp/100+GRN"点潜能点数的奖励！\n"NOR );
                }
                if (exp>=500000&&level<6){
        ob->set("level",6);
        ob->add("potential",exp/100);
        tell_object(ob,WHT"\n\t\t\t"+ob->name()+"，祝贺你！\n"+GRN
        +"\t你成功的达到了500000EXP，升上了"HIY"旷世大侠级！\n"+GRN
        +"\t由于你的升级，你获得了"YEL+exp/100+GRN"点潜能点数的奖励！\n"NOR );
                }
        if (exp>=1000000&&level<7){
        ob->set("level",7);
        ob->add("potential",exp/200);
        tell_object(ob,WHT"\n\t\t\t"+ob->name()+"，祝贺你！\n"+GRN
        +"\t你成功的达到了1000000EXP，升上了"HIR"天骄级！\n"+GRN
        +"\t由于你的升级，你获得了"YEL+exp/200+GRN"点潜能点数的奖励！\n"NOR );
                }
        if (exp>=2500000&&level<8){

        ob->set("level",8);
        ob->add("potential",exp/200);
        tell_object(ob,WHT"\n\t\t\t"+ob->name()+"，祝贺你！\n"+GRN
        +"\t你成功的达到了2500000EXP，升上了"HIM"入神级！\n"+GRN
        +"\t由于你的升级，你获得了"YEL+exp/200+GRN"点潜能点数的奖励！\n"NOR );
                }
        if (exp>=5000000&&level<9){
        ob->set("level",9);
        ob->add("potential",exp/600);
        tell_object(ob,WHT"\n\t\t\t"+ob->name()+"，祝贺你！\n"+GRN
        +"\t你成功的达到了5000000EXP，升上了"HIY"进神级！\n"+GRN
        +"\t由于你的升级，你获得了"YEL+exp/600+GRN"点潜能点数的奖励！\n"NOR );
                }
        if (exp>=10000000&&level<10){
        ob->set("level",10);
        ob->add("potential",exp/1000);
        tell_object(ob,WHT"\n\t\t\t"+ob->name()+"，祝贺你！\n"+GRN
        +"\t你成功的达到了10000000EXP，升上了"HIR"超神级！\n"+GRN
        +"\t由于你的升级，你获得了"YEL+exp/1000+GRN"点潜能点数的奖励！\n"NOR );
                }
        if (exp>=15000000&&level<11){
        ob->set("level",11);
        ob->add("potential",exp/2000);
        tell_object(ob,WHT"\n\t\t\t"+ob->name()+"，祝贺你！\n"+GRN
        +"\t你成功的达到了15000000EXP，升上了"HIW"天神级！\n"+GRN
        +"\t由于你的升级，你获得了"YEL+exp/2000+GRN"点潜能点数的奖励！\n"NOR );
                }
        }
}
void check_all()
{
        object *ob = users();
        int i;
        for(i=0; i<sizeof(ob); i++)
        {
          upgrade(ob[i]);
          }
        if (i>=sizeof(ob)) ready_to_start();
}

