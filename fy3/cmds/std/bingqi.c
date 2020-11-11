#include <ansi.h>
#include <mudlib.h>

inherit F_CLEAN_UP;
int top_list(object ob1,object ob2);
int get_score(object ob);
int main(object me, string arg)
{
        
        object *list,*ob;
        int i;
        string msg;

      ob = filter_array(objects(), (: userp($1) && !wizardp($1) :));
        list = sort_array(ob, (: top_list :));
      msg =  HIY"\n          �� "+HIR+" �� �� �� �� �� �� �� "NOR+ HIY" ��\n"NOR;
      msg += WHT WHT"���������������ө��������������������ө�������������\n";
      msg += WHT WHT"��   ��   ��  ��    ��        ��    �� ��      �� ��\n"NOR;
      msg += WHT WHT"�ĩ������������ة��������������������ة�������������\n";    
        for (i = 0 ;i < 10 ; i++) {
        if( i >= sizeof(list)) msg += "����ʱ��ȱ��                                      �� \n";
                else {
                if(list[i] != me) msg += WHT;
                if(list[i] == me) msg += WHT;
              msg += sprintf("��"CYN"  %-13s %-22s%-10s"WHT"��\n"NOR+WHT,"�� "+list[i]->query("biqi_top")+" ��",list[i]->query("name")+"("+
        capitalize(list[i]->query("id"))+")", list[i]->query("skname"));
                }
                         }
      msg += "����������������������������������������������������\n";
      msg += MAG"  �����ڵı����������ǵ�"+this_player()->query("biqi_top")+"����\n"NOR; 
      write(msg);
        return 1;

}
int top_list(object ob1, object ob2)
{
      int score1,score2;

        score1 = get_score(ob1);
        score2 = get_score(ob2);

      return score2 - score1;
}

int get_score(object ob)
{
        int tlvl,i,score;
        string *ski;
        mapping skills;

      reset_eval_cost();
        if (!(int)ob->query("biqi_top")) {
score = time()/1000;
}else
{
  score = time()/(int)ob->query("biqi_top");
}
      return score;
}

int help(object me)
{
write(@HELP
ָ���ʽ : top 
 
���ָ���������֪��������ҵı����������� 
 
HELP
    );
    return 1;
}
 

