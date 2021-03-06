// rankd.c

#include <ansi.h>

string query_rank(object ob)
{
        string bangname,bangrank,tmpstr;
        string setname;
        int exp;
        exp = (int) ob->query("combat_exp");
        if( ob->is_ghost() ) return HIB "【  鬼  魂  】" NOR;
      if( (int) ob->query("title_race") == -1 )
        {
                if( strlen((string) ob->query("env/title_race")) ==2){
                setname = ob->query("env/title_race");
                return HIR "【风云第一"+ setname +"】" NOR;}
                else return HIR "【 风云第一 】" NOR;
        }
        if( (int) ob->query("title_race") == -2 )
        {
                if( strlen((string) ob->query("env/title_race")) ==2){
                setname = ob->query("env/title_race");
                return HIR "【风云第二"+ setname +"】" NOR;}
                else return HIR "【 风云第二 】" NOR;
        }
        if( (int) ob->query("title_race") == -3)
        {
                if( strlen((string) ob->query("env/title_race")) ==2){
                setname = ob->query("env/title_race");
                return HIR "【风云第三"+ setname +"】" NOR;}
                else return HIR "【 风云第三 】" NOR;
        }
        if( (int) ob->query("kainame") == 2) return HIY "【 朝廷捕快 】" NOR;
        if( (int) ob->query("kainame") == 1) return HIY "【 实习捕快 】" NOR;
        if( (int) ob->query("kainame") == 3) return HIY "【 朝廷捕头 】" NOR;
        if( (int) ob->query("kainame") == 4) return HIY "【 副总捕头 】" NOR;
        if( (int) ob->query("kainame") == 5) return HIY "【 总 捕 头 】" NOR;
        if( (int) ob->query("kainame") == 4) return HIY "【 御前侍卫 】" NOR;
        if( (int) ob->query("kainame") == 6) return HIY "【 御前侍卫 】" NOR;
        if( (int) ob->query("kainame") == 7) return HIY "【 二等侍卫 】" NOR;
        if( (int) ob->query("kainame") == 8) return HIY "【 一等侍卫 】" NOR;
        if( (int) ob->query("kainame") == 9) return HIY "【 朝廷神捕 】" NOR;
        if (bangname!=0) {
                tmpstr = "marks/" + bangname;
                bangrank = ob->query(tmpstr);
                return HIB"【 "+bangname+bangrank+"】" NOR;
        }
                        if (exp >= 15000000)
                                return HIW "【 风云天骄 】" NOR;
                        else if (exp >= 10000000)
                                return HIC "【 风云泰斗 】" NOR;
                        else if ( exp >= 8000000)
                                return HIC "【 风云宗师 】" NOR;
                        else if (exp>= 5000000)
                                return HIM "【 风云奇侠 】" NOR;
 /*                       else if (exp>= 1000000)
                                return HIM "【 风云大侠 】" NOR;
                        else if (exp>= 500000)
                                return HIB "【 风云少侠 】" NOR;
                        else if (exp>= 250000)
                                return HIB "【 风云小侠 】" NOR;
                        else if (exp>= 100000)
                                return HIG "【 风云高手 】" NOR;
                        else if (exp >= 50000)
                                return HIG "【 风云新秀 】" NOR;
 */
        switch(ob->query("gender")) {
        case "女性":
                switch(wizhood(ob)) {
                        case "(admin)":                 return HIG "【  巫  女  】" NOR;
                        case "(arch)":                  return HIG "【  巫  女  】" NOR;
                        case "(wizard)":                return HIG "【  巫  女  】" NOR;
                        case "(apprentice)":    return HIG "【  小巫女  】" NOR;
                        case "(immortal)":              return HIC "【  仙  女  】" NOR;
                        default:
                                if( ((int)ob->query("PKS") > 100) &&
                                        ((int)ob->query("PKS") > (int)ob->query("MKS")) )
                                        return "【  杀人魔  】";
                                if( (int)ob->query("thief") > 50 ) return "【  惯  窃  】";
                                switch(ob->query("class")) {
                                        case "bonze":           return BLU"【  尼  姑  】"NOR;
                                        case "taoist":          return RED"【  女  冠  】"NOR;
                                        case "ghost":           return WHT"【  幽  灵  】"NOR;
                                        case "bandit":          return HIR"【  女飞贼  】"NOR;
                                        case "dancer":          return MAG"【  舞  仙  】"NOR;
                                        case "legend":          return HIC"【  侠  女  】"NOR;
                                        case "scholar":         return HIG"【  才  女  】"NOR;
                                        case "official":        return RED"【  女  官  】"NOR;
                                        case "fighter":         return RED"【  女武者  】"NOR;
                                        case "traveller" :      return MAG"【  浪  子  】"NOR;
                                        case "lishi" :          return RED"【  女武者  】"NOR;
                                        case "swordsman":       return WHT"【  女剑士  】"NOR;
                                        case "assassin":        return WHT"【  女杀手  】"NOR;
                                        case "ninemoon":        return BLU"【  邪  女  】"NOR;
                                        case "dali":            return RED"【 大理女官 】"NOR;
                                        case "shaman":          return YEL"【  巫  医  】"NOR;
                                        case "lama":            return MAG"【  藏  尼  】"NOR;
                                        case "yinshi":          return WHT"【  隐  士  】"NOR;
                                        case "beggar":          return CYN"【  叫化子  】"NOR;
                                        default:                        return CYN"【  平  民  】"NOR;
                        }
                }
        default:
                switch(wizhood(ob)) {
                        case "(admin)":                 return HIR "【  天  神  】" NOR;
                        case "(arch)":                  return HIW "【  神  仙  】" NOR;
                        case "(wizard)":                return HIW "【  巫  师  】" NOR;
                        case "(apprentice)":            return HIW "【  小巫师  】" NOR;
                        case "(immortal)":              return HIW "【  仙  人  】" NOR;
                        default:
                                if( ((int)ob->query("PKS") > 100) &&
                                        ((int)ob->query("PKS") > (int)ob->query("MKS"))/100 )
                                        return HIR"【  杀人魔  】"NOR;
                                if( (int)ob->query("thief") > 10 ) return "【  惯  窃  】"NOR;
                                switch(ob->query("class")) {
                                        case "bonze":           return WHT"【  僧  人  】"NOR;
                                        case "baihuagu":          return MAG"【  花  隐  】"NOR;
                                        case "taoist":          return YEL"【  道  士  】"NOR;
                                        case "ghost":           return BLU"【  幽  灵  】"NOR;
                                        case "bandit":          return RED"【  盗  贼  】"NOR;
                                        case "scholar":         return WHT"【  书  生  】"NOR;
                                        case "legend":          return YEL"【  游  侠  】"NOR;
                                        case "official":        return MAG"【  官  差  】"NOR;
                                        case "fighter":         return CYN"【  武  者  】"NOR;
                                        case "lishi":           return RED"【  武  者  】"NOR;               
                                        case "swordsman":       return WHT"【  剑  士  】"NOR;
                                        case "traveller" :      return MAG"【  浪  子  】"NOR;
                                        case "assassin":        return RED"【  杀  士  】"NOR;
                                        case "shaman":          return WHT"【  巫  医  】"NOR;
                                        case "dali":            return MAG"【 大理官员 】"NOR;
                                        case "yinshi":          return MAG"【  隐  士  】"NOR;
                                        case "lama":            return YEL"【  藏  僧  】"NOR;
                                        case "beggar":          return CYN"【  叫化子  】"NOR;
                                        default:                return CYN"【  平  民  】"NOR;
                        }
                }
        }
}

string query_respect(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/respect")) )
                return str;

        age = ob->query("age");
        switch(ob->query("gender")) {
                case "女性":
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 18 ) return "小师太";
                                else return "师太";
                                break;
                        case "taoist":
                                if( age < 18 ) return "小仙姑";
                                else return "仙姑";
                                break;
                        default:
                                if( age < 18 ) return "小姑娘";
                                else if( age < 50 ) return "姑娘";
                                else return "婆婆";
                                break;
                        }
                case "男性":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 18 ) return "小师父";
                                else return "大师";
                                break;
                        case "taoist":
                                if( age < 18 ) return "道兄";
                                else return "道长";
                                break;
                        case "fighter":
                        case "swordsman":
                                if( age < 18 ) return "小老弟";
                                else if( age < 50 ) return "壮士";
                                else return "老前辈";
                                break;
                        default:
                                if( age < 20 ) return "小兄弟";
                                else if( age < 50 ) return "壮士";
                                else return "老爷子";
                                break;
                        }
        }
}

string query_rude(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/rude")) )
                return str;

        age = ob->query("age");
        switch(ob->query("gender")) {
                case "女性":
                        switch(ob->query("class")) {
                        case "bonze":
                                return "贼尼";
                                break;
                        case "taoist":
                                return "妖女";
                                break;
                        default:
                                if( age < 30 ) return "小贱人";
                                else return "死老太婆";
                                break;
                        }
                case "男性":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "死秃驴";
                                else return "老秃驴";
                                break;
                        case "taoist":
                                return "死牛鼻子";
                                break;
                        default:
                                if( age < 20 ) return "小王八蛋";
                                if( age < 50 ) return "臭贼";
                                else return "老匹夫";
                                break;
                        }
        }
}

string query_self(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/self")) )
                return str;

        age = ob->query("age");
        switch(ob->query("gender")) {
                case "女性":
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "贫尼";
                                else return "老尼";
                                break;
                        default:
                                if( age < 30 ) return "小女子";
                                else return "妾身";
                                break;
                        }
                case "男性":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "贫僧";
                                else return "老纳";
                                break;
                        case "taoist":
                                return "贫道";
                                break;
                        default:
                                if( age < 50 ) return "在下";
                                else return "老头子";
                                break;
                        }
        }
}

string query_self_rude(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/self_rude")) )
                return str;

        age = ob->query("age");
        switch(ob->query("gender")) {
                case "女性":
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "贫尼";
                                else return "老尼";
                                break;
                        default:
                                if( age < 30 ) return "本姑娘";
                                else return "老娘";
                                break;
                        }
                case "男性":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "大和尚我";
                                else return "老和尚我";
                                break;
                        case "taoist":
                                return "本山人";
                                break;
                        default:
                                if( age < 50 ) return "大爷我";
                                else return "老子";
                                break;
                        }
        }
}
