// rankd.c

#include <ansi.h>

string query_rank(object ob)
{
        string bangname,bangrank,tmpstr;
        string setname;
        int exp;
        exp = (int) ob->query("combat_exp");
        if( ob->is_ghost() ) return HIB "��  ��  ��  ��" NOR;
      if( (int) ob->query("title_race") == -1 )
        {
                if( strlen((string) ob->query("env/title_race")) ==2){
                setname = ob->query("env/title_race");
                return HIR "�����Ƶ�һ"+ setname +"��" NOR;}
                else return HIR "�� ���Ƶ�һ ��" NOR;
        }
        if( (int) ob->query("title_race") == -2 )
        {
                if( strlen((string) ob->query("env/title_race")) ==2){
                setname = ob->query("env/title_race");
                return HIR "�����Ƶڶ�"+ setname +"��" NOR;}
                else return HIR "�� ���Ƶڶ� ��" NOR;
        }
        if( (int) ob->query("title_race") == -3)
        {
                if( strlen((string) ob->query("env/title_race")) ==2){
                setname = ob->query("env/title_race");
                return HIR "�����Ƶ���"+ setname +"��" NOR;}
                else return HIR "�� ���Ƶ��� ��" NOR;
        }
        if( (int) ob->query("kainame") == 2) return HIY "�� ��͢���� ��" NOR;
        if( (int) ob->query("kainame") == 1) return HIY "�� ʵϰ���� ��" NOR;
        if( (int) ob->query("kainame") == 3) return HIY "�� ��͢��ͷ ��" NOR;
        if( (int) ob->query("kainame") == 4) return HIY "�� ���ܲ�ͷ ��" NOR;
        if( (int) ob->query("kainame") == 5) return HIY "�� �� �� ͷ ��" NOR;
        if( (int) ob->query("kainame") == 4) return HIY "�� ��ǰ���� ��" NOR;
        if( (int) ob->query("kainame") == 6) return HIY "�� ��ǰ���� ��" NOR;
        if( (int) ob->query("kainame") == 7) return HIY "�� �������� ��" NOR;
        if( (int) ob->query("kainame") == 8) return HIY "�� һ������ ��" NOR;
        if( (int) ob->query("kainame") == 9) return HIY "�� ��͢�� ��" NOR;
        if (bangname!=0) {
                tmpstr = "marks/" + bangname;
                bangrank = ob->query(tmpstr);
                return HIB"�� "+bangname+bangrank+"��" NOR;
        }
                        if (exp >= 15000000)
                                return HIW "�� �����콾 ��" NOR;
                        else if (exp >= 10000000)
                                return HIC "�� ����̩�� ��" NOR;
                        else if ( exp >= 8000000)
                                return HIC "�� ������ʦ ��" NOR;
                        else if (exp>= 5000000)
                                return HIM "�� �������� ��" NOR;
 /*                       else if (exp>= 1000000)
                                return HIM "�� ���ƴ��� ��" NOR;
                        else if (exp>= 500000)
                                return HIB "�� �������� ��" NOR;
                        else if (exp>= 250000)
                                return HIB "�� ����С�� ��" NOR;
                        else if (exp>= 100000)
                                return HIG "�� ���Ƹ��� ��" NOR;
                        else if (exp >= 50000)
                                return HIG "�� �������� ��" NOR;
 */
        switch(ob->query("gender")) {
        case "Ů��":
                switch(wizhood(ob)) {
                        case "(admin)":                 return HIG "��  ��  Ů  ��" NOR;
                        case "(arch)":                  return HIG "��  ��  Ů  ��" NOR;
                        case "(wizard)":                return HIG "��  ��  Ů  ��" NOR;
                        case "(apprentice)":    return HIG "��  С��Ů  ��" NOR;
                        case "(immortal)":              return HIC "��  ��  Ů  ��" NOR;
                        default:
                                if( ((int)ob->query("PKS") > 100) &&
                                        ((int)ob->query("PKS") > (int)ob->query("MKS")) )
                                        return "��  ɱ��ħ  ��";
                                if( (int)ob->query("thief") > 50 ) return "��  ��  ��  ��";
                                switch(ob->query("class")) {
                                        case "bonze":           return BLU"��  ��  ��  ��"NOR;
                                        case "taoist":          return RED"��  Ů  ��  ��"NOR;
                                        case "ghost":           return WHT"��  ��  ��  ��"NOR;
                                        case "bandit":          return HIR"��  Ů����  ��"NOR;
                                        case "dancer":          return MAG"��  ��  ��  ��"NOR;
                                        case "legend":          return HIC"��  ��  Ů  ��"NOR;
                                        case "scholar":         return HIG"��  ��  Ů  ��"NOR;
                                        case "official":        return RED"��  Ů  ��  ��"NOR;
                                        case "fighter":         return RED"��  Ů����  ��"NOR;
                                        case "traveller" :      return MAG"��  ��  ��  ��"NOR;
                                        case "lishi" :          return RED"��  Ů����  ��"NOR;
                                        case "swordsman":       return WHT"��  Ů��ʿ  ��"NOR;
                                        case "assassin":        return WHT"��  Ůɱ��  ��"NOR;
                                        case "ninemoon":        return BLU"��  а  Ů  ��"NOR;
                                        case "dali":            return RED"�� ����Ů�� ��"NOR;
                                        case "shaman":          return YEL"��  ��  ҽ  ��"NOR;
                                        case "lama":            return MAG"��  ��  ��  ��"NOR;
                                        case "yinshi":          return WHT"��  ��  ʿ  ��"NOR;
                                        case "beggar":          return CYN"��  �л���  ��"NOR;
                                        default:                        return CYN"��  ƽ  ��  ��"NOR;
                        }
                }
        default:
                switch(wizhood(ob)) {
                        case "(admin)":                 return HIR "��  ��  ��  ��" NOR;
                        case "(arch)":                  return HIW "��  ��  ��  ��" NOR;
                        case "(wizard)":                return HIW "��  ��  ʦ  ��" NOR;
                        case "(apprentice)":            return HIW "��  С��ʦ  ��" NOR;
                        case "(immortal)":              return HIW "��  ��  ��  ��" NOR;
                        default:
                                if( ((int)ob->query("PKS") > 100) &&
                                        ((int)ob->query("PKS") > (int)ob->query("MKS"))/100 )
                                        return HIR"��  ɱ��ħ  ��"NOR;
                                if( (int)ob->query("thief") > 10 ) return "��  ��  ��  ��"NOR;
                                switch(ob->query("class")) {
                                        case "bonze":           return WHT"��  ɮ  ��  ��"NOR;
                                        case "baihuagu":          return MAG"��  ��  ��  ��"NOR;
                                        case "taoist":          return YEL"��  ��  ʿ  ��"NOR;
                                        case "ghost":           return BLU"��  ��  ��  ��"NOR;
                                        case "bandit":          return RED"��  ��  ��  ��"NOR;
                                        case "scholar":         return WHT"��  ��  ��  ��"NOR;
                                        case "legend":          return YEL"��  ��  ��  ��"NOR;
                                        case "official":        return MAG"��  ��  ��  ��"NOR;
                                        case "fighter":         return CYN"��  ��  ��  ��"NOR;
                                        case "lishi":           return RED"��  ��  ��  ��"NOR;               
                                        case "swordsman":       return WHT"��  ��  ʿ  ��"NOR;
                                        case "traveller" :      return MAG"��  ��  ��  ��"NOR;
                                        case "assassin":        return RED"��  ɱ  ʿ  ��"NOR;
                                        case "shaman":          return WHT"��  ��  ҽ  ��"NOR;
                                        case "dali":            return MAG"�� �����Ա ��"NOR;
                                        case "yinshi":          return MAG"��  ��  ʿ  ��"NOR;
                                        case "lama":            return YEL"��  ��  ɮ  ��"NOR;
                                        case "beggar":          return CYN"��  �л���  ��"NOR;
                                        default:                return CYN"��  ƽ  ��  ��"NOR;
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
                case "Ů��":
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 18 ) return "Сʦ̫";
                                else return "ʦ̫";
                                break;
                        case "taoist":
                                if( age < 18 ) return "С�ɹ�";
                                else return "�ɹ�";
                                break;
                        default:
                                if( age < 18 ) return "С����";
                                else if( age < 50 ) return "����";
                                else return "����";
                                break;
                        }
                case "����":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 18 ) return "Сʦ��";
                                else return "��ʦ";
                                break;
                        case "taoist":
                                if( age < 18 ) return "����";
                                else return "����";
                                break;
                        case "fighter":
                        case "swordsman":
                                if( age < 18 ) return "С�ϵ�";
                                else if( age < 50 ) return "׳ʿ";
                                else return "��ǰ��";
                                break;
                        default:
                                if( age < 20 ) return "С�ֵ�";
                                else if( age < 50 ) return "׳ʿ";
                                else return "��ү��";
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
                case "Ů��":
                        switch(ob->query("class")) {
                        case "bonze":
                                return "����";
                                break;
                        case "taoist":
                                return "��Ů";
                                break;
                        default:
                                if( age < 30 ) return "С����";
                                else return "����̫��";
                                break;
                        }
                case "����":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "��ͺ¿";
                                else return "��ͺ¿";
                                break;
                        case "taoist":
                                return "��ţ����";
                                break;
                        default:
                                if( age < 20 ) return "С���˵�";
                                if( age < 50 ) return "����";
                                else return "��ƥ��";
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
                case "Ů��":
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "ƶ��";
                                else return "����";
                                break;
                        default:
                                if( age < 30 ) return "СŮ��";
                                else return "���";
                                break;
                        }
                case "����":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "ƶɮ";
                                else return "����";
                                break;
                        case "taoist":
                                return "ƶ��";
                                break;
                        default:
                                if( age < 50 ) return "����";
                                else return "��ͷ��";
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
                case "Ů��":
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "ƶ��";
                                else return "����";
                                break;
                        default:
                                if( age < 30 ) return "������";
                                else return "����";
                                break;
                        }
                case "����":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "�������";
                                else return "�Ϻ�����";
                                break;
                        case "taoist":
                                return "��ɽ��";
                                break;
                        default:
                                if( age < 50 ) return "��ү��";
                                else return "����";
                                break;
                        }
        }
}
