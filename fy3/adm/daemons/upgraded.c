// updated.c
// �Զ��������ϵͳ

#include <ansi.h>
inherit F_DBASE;
void upgrade(object ob);

void ready_to_start()
{
        remove_call_out("check_all");
        call_out("check_all",500); // ���ʱ�䣬300-500Ϊ��
}
void create()
{
        seteuid(ROOT_UID);
        set("channel_id", "������⾫��");
        CHANNEL_D->do_channel( this_object(), "sys", "�������ϵͳ�Ѿ�������\n");
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
        tell_object(ob,WHT"\n\t\t\t"+ob->name()+"��ף���㣡\n"+GRN
        +"\t��ɹ��Ĵﵽ��5000EXP��������"YEL"���ż���\n"+GRN
        +"\t�������������������"YEL+exp/100+GRN"��Ǳ�ܵ����Ľ�����\n"NOR );
                }
        if (exp>=10000&&level<2){
        ob->set("level",2);
        ob->add("potential",exp/100);
        tell_object(ob,WHT"\n\t\t\t"+ob->name()+"��ף���㣡\n"+GRN
        +"\t��ɹ��Ĵﵽ��10000EXP��������"HIW"���㼶��\n"+GRN
        +"\t�������������������"YEL+exp/100+GRN"��Ǳ�ܵ����Ľ�����\n"NOR );
                }
        if (exp>=20000&&level<3){
        ob->set("level",3);
        ob->add("potential",exp/100);
        tell_object(ob,WHT"\n\t\t\t"+ob->name()+"��ף���㣡\n"+GRN
        +"\t��ɹ��Ĵﵽ��20000EXP��������"RED"С������\n"+GRN
        +"\t�������������������"YEL+exp/100+GRN"��Ǳ�ܵ����Ľ�����\n"NOR );
                }
        if (exp>=50000&&level<4){
        ob->set("level",4);
        ob->add("potential",exp/100);
        tell_object(ob,WHT"\n\t\t\t"+ob->name()+"��ף���㣡\n"+GRN
        +"\t��ɹ��Ĵﵽ��50000EXP��������"HIY"���ͼ���\n"+GRN
        +"\t�������������������"YEL+exp/100+GRN"��Ǳ�ܵ����Ľ�����\n"NOR );
                }
        if (exp>=100000&&level<5){
        ob->set("level",5);
        ob->add("potential",exp/100);
        tell_object(ob,WHT"\n\t\t\t"+ob->name()+"��ף���㣡\n"+GRN
        +"\t��ɹ��Ĵﵽ��100000EXP��������"HIB"��������\n"+GRN
        +"\t�������������������"YEL+exp/100+GRN"��Ǳ�ܵ����Ľ�����\n"NOR );
                }
                if (exp>=500000&&level<6){
        ob->set("level",6);
        ob->add("potential",exp/100);
        tell_object(ob,WHT"\n\t\t\t"+ob->name()+"��ף���㣡\n"+GRN
        +"\t��ɹ��Ĵﵽ��500000EXP��������"HIY"������������\n"+GRN
        +"\t�������������������"YEL+exp/100+GRN"��Ǳ�ܵ����Ľ�����\n"NOR );
                }
        if (exp>=1000000&&level<7){
        ob->set("level",7);
        ob->add("potential",exp/200);
        tell_object(ob,WHT"\n\t\t\t"+ob->name()+"��ף���㣡\n"+GRN
        +"\t��ɹ��Ĵﵽ��1000000EXP��������"HIR"�콾����\n"+GRN
        +"\t�������������������"YEL+exp/200+GRN"��Ǳ�ܵ����Ľ�����\n"NOR );
                }
        if (exp>=2500000&&level<8){

        ob->set("level",8);
        ob->add("potential",exp/200);
        tell_object(ob,WHT"\n\t\t\t"+ob->name()+"��ף���㣡\n"+GRN
        +"\t��ɹ��Ĵﵽ��2500000EXP��������"HIM"���񼶣�\n"+GRN
        +"\t�������������������"YEL+exp/200+GRN"��Ǳ�ܵ����Ľ�����\n"NOR );
                }
        if (exp>=5000000&&level<9){
        ob->set("level",9);
        ob->add("potential",exp/600);
        tell_object(ob,WHT"\n\t\t\t"+ob->name()+"��ף���㣡\n"+GRN
        +"\t��ɹ��Ĵﵽ��5000000EXP��������"HIY"���񼶣�\n"+GRN
        +"\t�������������������"YEL+exp/600+GRN"��Ǳ�ܵ����Ľ�����\n"NOR );
                }
        if (exp>=10000000&&level<10){
        ob->set("level",10);
        ob->add("potential",exp/1000);
        tell_object(ob,WHT"\n\t\t\t"+ob->name()+"��ף���㣡\n"+GRN
        +"\t��ɹ��Ĵﵽ��10000000EXP��������"HIR"���񼶣�\n"+GRN
        +"\t�������������������"YEL+exp/1000+GRN"��Ǳ�ܵ����Ľ�����\n"NOR );
                }
        if (exp>=15000000&&level<11){
        ob->set("level",11);
        ob->add("potential",exp/2000);
        tell_object(ob,WHT"\n\t\t\t"+ob->name()+"��ף���㣡\n"+GRN
        +"\t��ɹ��Ĵﵽ��15000000EXP��������"HIW"���񼶣�\n"+GRN
        +"\t�������������������"YEL+exp/2000+GRN"��Ǳ�ܵ����Ľ�����\n"NOR );
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

