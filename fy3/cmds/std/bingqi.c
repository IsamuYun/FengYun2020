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
      msg =  HIY"\n          □ "+HIR+" 兵 器 谱 在 线 高 手 "NOR+ HIY" □\n"NOR;
      msg += WHT WHT"┏━━━━━━┯━━━━━━━━━━┯━━━━━━┓\n";
      msg += WHT WHT"┃   名   次  │    姓        名    │ 武      功 ┃\n"NOR;
      msg += WHT WHT"┠──────┴──────────┴──────┨\n";    
        for (i = 0 ;i < 10 ; i++) {
        if( i >= sizeof(list)) msg += "┃暂时空缺。                                      ┃ \n";
                else {
                if(list[i] != me) msg += WHT;
                if(list[i] == me) msg += WHT;
              msg += sprintf("┃"CYN"  %-13s %-22s%-10s"WHT"┃\n"NOR+WHT,"第 "+list[i]->query("biqi_top")+" 名",list[i]->query("name")+"("+
        capitalize(list[i]->query("id"))+")", list[i]->query("skname"));
                }
                         }
      msg += "┗━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
      msg += MAG"  您现在的兵器谱排名是第"+this_player()->query("biqi_top")+"名。\n"NOR; 
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
指令格式 : top 
 
这个指令可以让你知道在线玩家的兵器谱排名。 
 
HELP
    );
    return 1;
}
 

