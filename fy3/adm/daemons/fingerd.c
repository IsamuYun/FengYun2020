// fingerd.c
// 修改于2002-2-10 xgchen@zzfy

#pragma optimize
#pragma save_binary

#include <mudlib.h>
#include <ansi.h>
#include <net/dns.h>
int sort_user(object,object);
int query_only_ip(object *ob);
int online_time(object);
int online_time_total(object);
 
void create() { seteuid( getuid() ); }

string remove_ansi(string str)
{
        int i;
        string *color = ({ BLK, RED, GRN, YEL, BLU, MAG, CYN, WHT,
                        HIR, HIG, HIY, HIB, HIM, HIC, HIW,
                        HBRED, HBGRN, HBYEL, HBBLU, HBMAG, HBCYN, HBWHT,
                        BBLK, BRED, BYEL, BBLU, BMAG, BCYN,
                        NOR, BOLD });
                        
        if( !str || !stringp(str) ) return 0;
        i = sizeof(color);
        while( i-- ) {
                str = replace_string(str, color[i], "");
        }
        return str;
}
string age_string(int time)
{
        int month, day, hour;

        time /= 3600;
        hour = time % 24;
        time /= 24;
        day = time % 30;
        month = time / 30;
        return (month?month + "月":"") + (day?day + "天":"") + hour + "小时";
}
int online_time(object body)
{
        return time() - (int)body->query_temp("login_time");
}

int online_time_total(object body)
{
        return body->query("time_aged")+time()-(int)body->query_temp("login_time");
}
string finger_all()
{
        object *ob, *list, me;
        string msg,  str;
        int i,ips,obs;

        obs = 0;
        ob = filter_array(objects(), (: userp :));
        list = sort_array(ob, (: sort_user :));
        me = this_player();
        msg = "";
        if(wizardp(me))  // player finger
        {
                for(i=0; i<sizeof(list); i++) {
                        reset_eval_cost();
                        if( this_player() && !this_player()->visible(list[i]) ) continue;
                        msg = sprintf("%s%-14s%-14s%-14s%-7s%s\n",
                                msg, list[i]->query("name"), list[i]->query("id"),
                                age_string( (int)list[i]->query("mud_age")),
                                !interactive(list[i])?"断线中":query_idle(list[i]) + "s", query_ip_name(list[i]));
                        if (environment(ob[i]))  obs++;
                }
                ips=query_only_ip(list);
                str = HIR" "MUD_NAME + " \n" NOR +
                "—————————————————————————————————————\n"
                + "姓名          帐号          年龄          发呆     连线\n" +
                "—————————————————————————————————————\n"
                + msg +
                "—————————————————————————————————————\n"
                +HIR"实际有"+ips+"个IP连线进入。\n"NOR;
                me->start_more(str);
                return"\n";
        }
        else
        {
                for(i=0; i<sizeof(list); i++) {
                        reset_eval_cost();
                        if( this_player() && !this_player()->visible(list[i]) ) continue;
                        msg = sprintf("%s%-14s%-14s%-14s\n",
                                msg, list[i]->query("name"), list[i]->query("id"),
                                !interactive(list[i])?"断线中":query_idle(list[i]) + "s");

                }
                str = HIR" "MUD_NAME + " \n" NOR +
                "——————————————————\n"
                + "姓名          帐号          发呆\n" +
                "——————————————————\n"
                   + msg +
                   "——————————————————\n"NOR;
                me->start_more(str);
                return"\n";
        }
}

string finger_user(string name, int wizship)
{
        object ob, body;
        string msg="", mud;
        int public_email;

        if( sscanf(name, "%s@%s", name, mud)==2 ) {
                GFINGER_Q->send_finger_q(mud, name, this_player(1));
                return "网路指令传送过程可能需要一些时间，请稍候。\n";
        }

        ob = new(LOGIN_OB);
        ob->set("id", name);
        if( !ob->restore() ) return "没有这个玩家。\n";
        if( wizship ) {
        if( objectp(body = find_player(name)) && geteuid(body)==name
                && interactive(body) ) {
                msg = sprintf("\n%s目前正在从 %s 连线中。\n", body->name(1),
                        query_ip_name(body));
        }
        msg +=  sprintf("\n英文代号：\t%s\n姓    名：\t%s\n权限等级：\t%s\n"
                "电子邮件地址：\t%s\n上次连线地址：\t%s( %s )\n"
                "合计在线时间：\t%s\n\n",
                ob->query("id"),
                ob->query("name"),
                SECURITY_D->get_status(name),
                ob->query("email"),
                ob->query("last_from"),
                ctime(ob->query("last_on")),
        (body ? (age_string( (int)body->query("mud_age"))) : "不告诉你")
        );
                    }
        else
        {
        if( objectp(body = find_player(name)) && geteuid(body)==name && interactive(body) 
                && (!wizardp(body) || !body->query("env/invisibility")) ) {
                msg = sprintf("\n%s目前正在连线中。\n", body->name(1),
                        ); }
        msg +=  sprintf("\n英文代号：\t%s\n姓    名：\t%s\n权限等级：\t%s\n"
                "电子邮件地址：\t%s\n上次连线时间：\t%s\n\n",
                ob->query("id"),
                ob->query("name"),
                SECURITY_D->get_status(name),
                public_email?ob->query("email"):"不告诉你",
                ctime(ob->query("last_on"))
        );
                }
        destruct(ob);
        return msg;
}

varargs string remote_finger_user(string name, int chinese_flag)
{
        object ob, body;
        string msg;

        ob = new(LOGIN_OB);
        ob->set("id", name);
        if( !ob->restore() )
                return chinese_flag ? "没有这个玩家。\n" : "No such user.\n";
        if( chinese_flag ) msg =  sprintf(
                "\n英文代号：\t%s\n姓    名：\t%s\n权限等级：\t%s\n"
                "电子邮件地址：\t%s\n上次连线地址：\t%s( %s )\n\n",
                ob->query("id"),
                ob->query("name"),
                SECURITY_D->get_status(name),
                ob->query("email"),
                ob->query("last_from"),
                ctime(ob->query("last_on"))
        );
        else msg =  sprintf(
                "\nName\t: %s\nStatus\t: %s\nEmail\t: %s\nLastOn\t: %s( %s )\n\n",
                capitalize(ob->query("id")),
                SECURITY_D->get_status(name),
                ob->query("email"),
                ob->query("last_from"),
                ctime(ob->query("last_on"))
        );
        if( body = find_player(name) ) {
                if( !this_player() || this_player()->visible(body) )
                        msg += chinese_flag ?
                                ("\n" + ob->query("name") + "目前正在线上。\n"):
                                ("\n" + capitalize(name) + " is currently connected.\n");
        }

        destruct(ob);
        return msg;
}

object acquire_login_ob(string id)
{
        object ob;

        if( ob = find_player(id) ) {
                // Check if the player is linkdead
                if( ob->query_temp("link_ob") )
                        return ob->query_temp("link_ob");
        }
        ob = new(LOGIN_OB);
        ob->set("id", id);
        return ob->restore() ? ob : 0;
}
int query_only_ip(object *ob)
{
        int i,j,k,count,total;

        total=sizeof(ob);
        for ( i=0; i<sizeof(ob); i++)
        {
                reset_eval_cost();
                count=1;k=sizeof(ob);
                for (j=0; j<k;j++)
                        if (j!=i&&query_ip_name(ob[i])==query_ip_name(ob[j]) )
                        {
                                ob=ob-({ob[j]});
                                count++;
                                k=sizeof(ob);
                        }
                total=total-count+1;
        }
        return total;
}

int ip_name(object ob1, object ob2)
{
        string name1, name2;
        
        name1 = query_ip_name(ob1);
        name2 = query_ip_name(ob2);

        if (intp(name1)) name1 = "";
        if (intp(name2)) name2 = "";
        if (name1 > name2) return -1;
        if (name1 < name2) return 1;

        return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
}

int sort_user(object ob1, object ob2)
{
        string name1, name2;

        name1 = query_ip_number(ob1);
        name2 = query_ip_number(ob2);

        if (intp(name1)) name1 = "";
        if (intp(name2)) name2 = "";
        if (name1 > name2) return -1;
        if (name1 < name2) return 1;

        return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
}

varargs string zclan_finger_user(string name, int chinese_flag)
{
    object ob, body;
    string msg;

    ob = new(LOGIN_OB);
    ob->set("id", name);
    if( !ob->restore() ) {
        destruct(ob);
        return chinese_flag ? "没有这个玩家。\n" : "No such user.\n";
    }
    msg =  sprintf(
      "\n英文代号：\t%s\n姓    名：\t%s\n"
      "权限等级：      (player)\n"
      "电子邮件地址：  不告诉你\n"
      
      
      "上次连线地址：\t%s\n\n",
      ob->query("id"),
      ob->query("name"),
      ctime(ob->query("last_on"))
    );
    if( body = find_player(name) ) {
        if( !this_player() || this_player()->visible(body) )
            msg +=     ("\n" + ob->query("name") + "目前正在线上。\n");
    }

    destruct(ob);
    return msg;
}