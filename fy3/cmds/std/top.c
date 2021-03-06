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
      msg =  HIY"\n          □ "+HIR+" 一 世 风 云 在 线 十 大 高 手 "NOR+ HIY" □\n"NOR;
      msg += WHT MAG"┏━━━┯━━━━━━━━━━┯━━━━━━┯━━━━━┓\n";
      msg += WHT MAG"┃ 名次      高        手    │ 门     派 │ 战 斗 力 ┃\n"NOR;
      msg += WHT MAG"┠───┴──────────┴──────┴─────┨\n";
        for (i = 0 ;i < 10 ; i++) {
        if( i >= sizeof(list)) msg += "┃暂时空缺。                                            ┃ \n";
                else {
                if(list[i] != me) msg += MAG;
                if(list[i] == me) msg += MAG;
              msg += sprintf("┃"YEL"  %-5s %-22s%-16s %5d  "MAG"┃\n"NOR+MAG,chinese_number(i+1),list[i]->query("name")+"("+
        capitalize(list[i]->query("id"))+")", list[i]->query("family")?  list[i]->query("family/family_name"):"普通百姓",
        get_score(list[i]));
                }
                         }
      msg += "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
      msg += HIW"  您现在的战斗力是："+sprintf("%5d",get_score(me))+"。\n"NOR; 
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
        skills = ob->query_skills();
        if (!sizeof(skills)) return 1; 
        ski  = keys(skills);
        for(i = 0; i<sizeof(ski); i++) {
                        tlvl += skills[ski[i]];
                        }  // count total skill levels
 score = tlvl/10;
          score += ob->query("max_force")/100;
        score += ob->query("str")/2 + ob->query("int")/2 + ob->query("dex")/2 + ob->query("con")/2;
        score += ob->query("spi")/2 + ob->query("cps")/2 + ob->query("kar")/5;
        score += (int)ob->query("level")*100;
        return score;
}

int help(object me)
{
write(@HELP
指令格式 : top 
 
这个指令可以让你知道在线十大高手是哪些，别去惹他们。 
 
HELP
    );
    return 1;
}
 
