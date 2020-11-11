// help.c
// created by host ,98.8.20
#include <ansi.h>
#include <login.h>
#include <mudlib.h>
#include "/doc/help.h"
inherit ITEM;
string *default_search = DEFAULT_SEARCH_PATHS;
string depart = read_file("/doc/help/menu/menpai.menu");
string map = read_file("/doc/help/menu/map.menu");
string intro = read_file("/doc/help/menu/intro.menu");
string board = read_file("/doc/help/menu/board.menu");
void m_display();
void a_display();
void b_display();
void c_display();
void u_display();
void o_display();
void auto_load();
void view_main();
void view_main_1();
private void a(string arg, string register);
private void b(string arg, string register);
private void c(string arg, string register);
private void d(string arg, string register);
private void e(string arg, string register);
private void f(string arg, string register);
private void g(string arg, string register);
private void confirm_main_choice(string arg);
private void confirm_a_choice(string arg);
private void confirm_b_choice(string arg);
private void confirm_c_choice(string arg);
private void confirm_u_choice(string arg);
private void confirm_o_choice(string arg);
private void y(string arg, string register);
int check_user();
int check_nowait();
int wizlist();
int message();
int message1();
string age_string(int time);
int helpmore(string cmd, string *text, int line)
{
        int i;

        switch(cmd) {
         case "":
               for(i=line + 23; line<sizeof(text) && line<i; line++)
                   write(text[line] + "\n");
             if( line>=sizeof(text) ) {
                   printf("== 全文完" HIY "%d%%" NOR " == (ENTER 返回上个选单)",(line*100/sizeof(text)) );
                   check_user();
                   return 1; }
                   break; 
        case "b":
                   line = line - 46;
        if(line<-22) return 1;
        for(i=line + 23; line < i;line++)
                   write(text[line]+"\n");
                   break;
        case "q":
                   check_nowait();
                   return 1;
        }
           printf("== 未完继续 " HIY "%d%%" NOR " == (ENTER 继续下一页，q 离开，b 前一页)",(line*100/sizeof(text)) );
           input_to("helpmore", text, line);
}
int register()
{
   object me;
   me = this_player();
   if(!me->query("register")) {
         write(CLR"\n");
         write(HIW"【使用者设定】        "HIY"【一世风云注册单】\n"NOR);
         write("\n");
         write(YEL"目前选择：\n\n"NOR);
         write(HIW"    您的代号     : "NOR);
         input_to((:a:),this_player());
         return 1;
        }
    write("你已经填写过注册单。\n");
    check_user();
 }
private void a(string arg, string register)
{
   register = "代号     : "+arg+"\n";
   this_player()->add_temp("register",register);
   write(HIW"    您的昵称     : "NOR);
   input_to((:b:),this_player(),register);
}
private void b(string arg, string register)
{
   register = "昵称     : "+arg+"\n";
   this_player()->add_temp("register",register);
   write(HIW"    真实姓名     : "NOR);
   input_to((:c:),this_player());
}
private void c(string arg, string register)
{
   register = "姓名     : "+arg+"\n";
   this_player()->add_temp("register",register);
   write(HIW"    联系地址     : "NOR);
   input_to((:d:),this_player());
}
private void d(string arg, string register)
{
   register = "联系地址     : "+arg+"\n";
   this_player()->add_temp("register",register);
   write(HIW"    工作单位/学校: "NOR);
   input_to((:e:),this_player());
}
private void e(string arg, string register)
{
   register = "工作单位/学校: "+arg+"\n";
   this_player()->add_temp("register",register);
   write(HIW"    电子信箱: "NOR);
   input_to((:f:),this_player());
}
private void f(string arg, string register)
{
   register = "电子信箱: "+arg+"\n";
   this_player()->add_temp("register",register);
   write(HIW"    联系电话: "NOR);
   input_to((:g:),this_player());
}
private void g(string arg, string register)
{
   register = "联系电话: "+arg+"\n";
   this_player()->add_temp("register",register);
   write(HIW"\n\n\n\n\n\n以上资料是否正确(Y/N)？(Q)取消注册 [N]:"NOR);
   input_to((:y:),this_player());
}
private void y(string arg, string register) 
{
   string table;
   if(arg=="") {
   this_player()->delete_temp("register");
   register();
   return ;
   }
switch(arg[0]){
   case 'n':
           this_player()->delete_temp("register");
           register();
           return ;
   case 'y': 
           this_player()->set("register",1);
           table =  this_player()->query_temp("register");
           this_player()->delete_temp("register");
           write_file("/log/doc/register/"+this_player()->query("id"),table,1);
           write("◇设置一切正确。\n"); 
           check_user();
           return ;
   case 'q':
           this_player()->delete_temp("register");
           u_display();
           write(YEL"\r请输入您的选择:"NOR);
           input_to((:confirm_u_choice:),this_player());
           return ;
   default:
           this_player()->delete_temp("register");
           register();
           return ;
     }
  return ;
}
int check_nowait()
{
 if( this_player()->query_temp("help_a"))
 confirm_a_choice("");
 if( this_player()->query_temp("help_b"))
 confirm_b_choice("");
 if( this_player()->query_temp("help_c"))
 confirm_c_choice("");
 if( this_player()->query_temp("help_u"))
 confirm_u_choice("");
if( this_player()->query_temp("help_o"))
 confirm_o_choice("");
}
int check_user()
{
 if( this_player()->query_temp("help_a"))
 input_to("confirm_a_choice",this_player());
 if( this_player()->query_temp("help_b"))
 input_to("confirm_b_choice",this_player());
 if( this_player()->query_temp("help_c"))
 input_to("confirm_c_choice",this_player());
 if( this_player()->query_temp("help_u"))
 input_to("confirm_u_choice",this_player());
 if( this_player()->query_temp("help_o"))
 input_to("confirm_o_choice",this_player());
}
int start_help(string msg)
{
        helpmore("", explode(msg, "\n"), 0);
}
int main(object me, string arg)
{
        int i;
	string file, *search;
       	if( !arg ) {
                me->set_temp("help",1);
                m_display();
                write(YEL"你现在的打算："NOR);
                input_to((:confirm_main_choice:),this_player());
                return 1; 
        }
          	seteuid(getuid());
	if( stringp(file = me->find_command(arg)) ) {
		notify_fail("有这个指令存在，但是并没有详细的说明文件。\n");
		return file->help(me);
	}
       if( pointerp(search = me->query("help_search_path")) ) {
		i = sizeof(search);
		while(i--) if( file_size(search[i] + arg)>0 ) {
			me->start_more( read_file(search[i] + arg) );
			return 1;
		}
	}
	sscanf(arg, "%s()", arg);
	if( pointerp(default_search) ) {
		i = sizeof(default_search);
		while(i--) if( file_size(default_search[i] + arg)>0 ) {
			me->start_more( read_file(default_search[i] + arg) );
			return 1;
		}
  	  }
	return notify_fail("没有针对这项主题的说明文件。\n");
	}

void view_main()
{
     object me;
     string name,select;
     me = this_player();
     select = me->query_temp("select");
     write(CLR"\n");
     if(select== "main") name = BRED HIY"江湖指南"NOR;
     else if( select== "intro") name = "游戏概况";
     else if( select== "depart") name = "门派介绍";
     else if( select== "map") name = "地形指南";
     else if( select== "user") name = "个人设定区";
     else if( select== "board") name = "重要布告栏";
     write(BBLU HIY"分类选单"NOR"                   " HIR"〖 "+HIG+BRED+"一世风云"+NOR+HIR" 〗""                  "BBLU HIY"选单["+select+"]\n"NOR);
     write("目前选择：[ "+name+" ]\n");
     write(HIG"◎"NOR CYN"━━━━━━━━━━━━━━"HIR"┃"BLINK BBLU HIR" 公告版 "NOR HIR"┃"NOR CYN"━━━━━━━━━━━━━━"NOR HIG"◎\n"NOR);
     auto_load();
     write(HIG"◎"NOR CYN"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"NOR HIG"◎	\n"NOR);  
     write("\n");
}
void view_main_1()
{
     int i,ppl_cnt;
     object *usr;
     usr = users();
     ppl_cnt=0;
     for(i=0; i<sizeof(usr); i++)
       {
          ppl_cnt++;
       }
     write("\n");   
     write(YEL"_.-*```*-.__.-*```*-.__.-*```*-.__.-*```*-.__.-*```*-.__.-*```*-.__.-*\n"NOR);
     write("\n");     
     write(BCYN RED"北京时间: "+MAG+ctime(time())+"    "NOR+BCYN RED"在线玩家: "+MAG+ppl_cnt+"    "NOR+BCYN RED"用户等级: "+MAG+wizhood(this_player())+"\n"NOR,);
     write("\n");
}
void a_display()
{
     view_main();
     write(HIW+intro+NOR);
     view_main_1();
}
void b_display()
{
     view_main();
     write(HIW+depart+NOR);
     view_main_1();
}
void c_display()
{
     view_main();
     write(HIW+map+NOR);
     view_main_1();
}
void o_display()
{
     write(CLR"\n");
     write(HIY"\n  编号   问题板            中   文   叙   述          管理员"NOR"\n\n");
     write(HIW+board+NOR);
     view_main_1();
}
void m_display()
 {
     this_player()->set_temp("select","main");
     view_main();
     write("                        "HIR"(i)"NOR"ntro  　〖  "BGRN HIW"游戏概况"NOR"  〗\n");
     write("                        "HIR"(d)"NOR"epart 　〖  "BRED HIW"门派介绍"NOR"  〗\n");
     write("                        "HIR"(m)"NOR"ap    　〖  "BCYN HIW"地形指南"NOR"  〗\n");
     write("                        "HIR"(u)"NOR"ser     〖 "BBLU HIW"个人设定区"NOR" 〗\n");
     write("                        "HIR"(b)"NOR"board 　〖 "BMAG HIW"重要布告栏"NOR" 〗\n");
     write("                        "HIR"(x)"NOR"yz      〖 "BYEL HIW"系统设定区"NOR" 〗\n"); 
     write("                        "HIR"(g)"NOR"oodbye　〖  "HBWHT RED"重归江湖"NOR"  〗\n");
     view_main_1();
}
void u_display()
{
      view_main();
      write("                       "HIC"(Ｉ)"NOR"nfo        个人资料\n");
      write("                       "HIC"(Ｋ)"NOR"ill        完全自杀手册\n");
      if (wizardp(this_player()))
      write("                       "HIC"(Ｃ)"NOR"loak       隐身术\n");
      write("                       "HIC"(Ｌ)"NOR"ockScreen  锁定萤幕\n");
      write("                       "HIC"(Ｒ)"NOR"egister    填写《注册申请单》\n");
      write("                       "HIC"(Ｐ)"NOR"ager       切换呼叫器\n");
      write("                       "HIC"(Ｇ)"NOR"return     返回主菜单\n");
      view_main_1();
}
int pager()
{
    object me;
    me = this_player();
    if(me->query_temp("call_on")) {
    write("打开 Pager 频道\n");
    me->delete_temp("call_on");
    }
   else{
   write("关闭 Pager 频道\n");
   me->set_temp("call_on",1);
   }
  return 1;
}

void auto_load()
{
    if(random(10) > 5)
    wizlist();
    else if( random(20) >  10)
    message(); 
    else 
    message1();
}
int message1()
{
       object me;
      int i;
      me = this_player();
      i = me->query("MKS")+me->query("PKS");
      write(HIC"      "+HIW+me->name()+NOR HIY"大侠"+NOR": 你行走江湖已经 "+BBLU MAG+age_string((int)me->query("mud_age"))+NOR" 之久!!\n");
      write(NOR"                在你江湖生涯的日日夜夜里, 你已经累积了 "+BYEL HIR+chinese_number(me->query("combat_exp"))+NOR" \n");
      write(NOR"                点经验, 共击倒 "+BCYN HIM+chinese_number(i)+NOR" 个对手,前途不可限量!\n");
    
}
string age_string(int time)
{
        int month, day, hour, min, sec;

        sec = time % 60;
        time /= 60;
        min = time % 60;
        time /= 60;
        hour = time % 24;
        time /= 24;
        day = time % 30;
        month = time / 30;
        return (month?month + "月":"") + (day?day + "天":"") +
        (hour?hour + "小时":"") + min + "分";
}
int message()
{
 write(HIR"   ●    （ ● ）  （●）      ●）     ●     （●）   □●□   （●\n"NOR);
 write(HIB" ＜｜＞   └｜┘    （（（   （｜     （｜）   　｜）     ｜      （□\n"NOR);
 write(HIY"  ／＼    ＜  □   （         ／ ）    （□     （ ＼   □  □    ＜））\n"NOR);
 write(HIC""+this_player()->name()+",玩累了吧？来,我们一起做运动---左三圈，右三圈，脖子扭扭，屁股扭扭...\n"NOR);
}
int wizlist()
{
        string *wizlist,*list,wiz_name,wiz_level,str1,str2,str3,str4;
        int i,s1,s2,s3,s4;
        str1="",str2="",str3="",str4="";
        s1=0;s2=0;s3=0;s4=0;

        list = sort_array(SECURITY_D->query_wizlist(),1);
        wizlist = explode(read_file(WIZLIST), "\n");
        for(i=0; i<sizeof(wizlist); i++)  {
        sscanf(wizlist[i], "%s %s", wiz_name, wiz_level);
                switch(wiz_level)
                {
                        case "(apprentice)":
                                str1 += (s1?"\t":"")+wiz_name;
                                s1++;
                                if(s1%6==0) str1 += "\n \t\t ";
                                break;
                        case "(wizard)":
                                str2 += (s2?"\t":"")+wiz_name;
                                s2++;
                                if(s2%6==0) str2 += "\n \t\t ";
                                break;
                        case "(arch)":
                                str3 += (s3?"\t":"")+wiz_name;
                                s3++;
                                if(s3%6==0) str3 += "\n \t\t ";
                                break;
                        case "(admin)":
                                str4 += (s4?"\t":"")+wiz_name;
                                s4++;
                                if(s4%6==0) str4 += "\n \t\t";
                                break;

                }
        }
        write(HIR"   【 散 仙 】: "NOR+str1+"\n");
        write(HIY"   【 神 仙 】: "NOR+str2+"\n");
        write(HIG"   【 大 神 】: "NOR+str3+"\n");
        write(HIW"   【 天 帝 】: "NOR+str4+"\n");
}
private void confirm_a_choice(string arg)
{
    this_player()->set_temp("help_a",1);
   if(arg=="") {
 a_display();
 write(YEL "\r请从新输入您得选择:"NOR);
 input_to((:confirm_a_choice:),this_player());
 return ; }
 switch(arg){
    case "1":
              start_help(read_file("/doc/help/goal.txt"));
              return ;
    case "2":
             start_help(read_file("/doc/help/commands.txt"));
             return ;
    case "3":
             start_help(read_file("/doc/help/newbie.txt"));
             return ;
    case "4":
             start_help(read_file("/doc/help/laws.txt"));
             return ;
    case "5": 
             start_help(read_file("/doc/help/settings.txt"));
             return ;
    case "6":
             start_help(read_file("/doc/help/change.txt"));
             return ;
    case "7":
             start_help(read_file("/doc/help/wizrules"));
             return ;
    case "8":
             start_help(read_file("/doc/help/neima"));
             return ;
    case "b":
             this_player()->delete_temp("help_a");
             m_display();
             write(YEL "\r请输入您得选择:"NOR);
             input_to((:confirm_main_choice:),this_player());
             return ;
    default:
           a_display();
           write(YEL"\r请输入您的选择:"NOR);
           input_to((:confirm_a_choice:),this_player());
           return ;
        }
  return;
}
private void confirm_b_choice(string arg)
{
   this_player()->set_temp("help_b",1);
   if(arg=="") {
       b_display();
       write(YEL "\r请从新输入您得选择:"NOR);
       input_to((:confirm_b_choice:),this_player());
       return ; }

 switch(arg){
    case "1":
              start_help(read_file("/doc/menpai/baiyun.txt"));
              return ;
    case "2": 
              start_help(read_file("/doc/menpai/chaoting.txt"));
              return ;    
    case "3":
              start_help(read_file("/doc/menpai/dazhaosi.txt"));
             return ;
    case "4":
              start_help(read_file("/doc/menpai/diwanggu.txt"));
             return ;
    case "5":
              start_help(read_file("/doc/menpai/jinqian.txt"));
             return ; 
    case "8":
              start_help(read_file("/doc/menpai/shenshui.txt"));
             return ; 
    case "6":
              start_help(read_file("/doc/menpai/mojiao.txt"));
             return ; 
    case "7":
              start_help(read_file("/doc/menpai/sanqing.txt"));
             return ;
    case "9":
              start_help(read_file("/doc/menpai/tianchui.txt"));
             return ;
    case "12":
              start_help(read_file("/doc/menpai/qingping.txt"));
             return ; 
    case "10":
              start_help(read_file("/doc/menpai/tianfeng.txt"));
             return ;
    case "11":
              start_help(read_file("/doc/menpai/tiexue.txt"));
             return ;
    case "13":
              start_help(read_file("/doc/menpai/wanmei.txt"));
             return ;
    case "14":
              start_help(read_file("/doc/menpai/wudang.txt"));
             return ;
    case "15":
              start_help(read_file("/doc/menpai/xingguo.txt"));
             return ;
    case "16":
              start_help(read_file("/doc/menpai/daqi.txt"));
             return ;
    case "17":
              start_help(read_file("/doc/menpai/youling.txt"));
             return ;
    case "18":
              start_help(read_file("/doc/menpai/shenjian.txt"));
             return ;
    case "19":
              start_help(read_file("/doc/menpai/gaibang.txt"));
             return ;
    case "20":
              start_help(read_file("/doc/menpai/huangshan.txt"));
             return ;
    case "21":
              start_help(read_file("/doc/menpai/songgu.txt"));
             return ;
    case "22":
              start_help(read_file("/doc/menpai/shaolin.txt"));
             return ;
    case "23":
              start_help(read_file("/doc/menpai/baihuagu.txt"));
             return ;
    case "24":
              start_help(read_file("/doc/menpai/wudujiao.txt"));
             return ;
    case "25":
              start_help(read_file("/doc/menpai/qingfeng.txt"));
             return ;
    case "26":
              start_help(read_file("/doc/menpai/fulong.txt"));
             return ;
    case "27":
              start_help(read_file("/doc/menpai/dali.txt"));
             return ;
    case "b":
             this_player()->delete_temp("help_b");
             m_display();
             write(YEL "\r请从新输入您得选择:"NOR);
             input_to((:confirm_main_choice:),this_player());
             return ;
    default:
           b_display();
           write(YEL"\r请输入您的选择:"NOR);
           input_to((:confirm_b_choice:),this_player());
           return ;
        }
  return;
}
private void confirm_c_choice(string arg)
{
 this_player()->set_temp("help_c",1);
 if(arg=="") {
     c_display();
     write(YEL "\r请从新输入您得选择:"NOR);
     input_to((:confirm_c_choice:),this_player());
     return; }
 switch(arg) {
    case "1":
             start_help(read_file("/doc/help/fengyun.txt"));
             return ;
    case "2":
             start_help(read_file("/doc/help/chenxiang.txt"));
             return ;
    case "3":
             start_help(read_file("/doc/help/daimiao.txt"));
             return ;
    case "4":
             start_help(read_file("/doc/help/guanwai.txt"));
             return ;
    case "5":
             start_help(read_file("/doc/help/laowu.txt"));
             return ;
    case "6":
             start_help(read_file("/doc/help/qianjin.txt"));
             return ;
    case "7":
             start_help(read_file("/doc/map/wulapo.txt"));
             return ;
    case "8":
             start_help(read_file("/doc/map/dali.txt"));
             return ;
    case "a":
             start_help(read_file("/doc/help/map.txt"));
             return ;
/*    case "10":
             start_help(read_file("/doc/help/map/chengdu-map"));
             return ;
    case "11":
             start_help(read_file("/doc/help/map/kunlun-map"));
             return ;
    case "12":
             start_help(read_file("/doc/help/map/emei-map"));
             return ;
    case "13":
             start_help(read_file("/doc/help/map/huashancun-map"));
             return ;
    case "14":
             start_help(read_file("/doc/help/map/chengdu-map"));
             return ;
    case "15":
             start_help(read_file("/doc/help/map/quanzhen-map"));
             return ;
    case "16":
             start_help(read_file("/doc/help/map/mingjiao-map"));
             return ;
    case "17":
             start_help(read_file("/doc/help/map/wangfu-map"));
             return ;
    case "18":
             start_help(read_file("/doc/help/map/tianlongsi-map"));
             return ;
    case "19":
             start_help(read_file("/doc/help/map/dali-map"));
             return ;
    case "20":
             start_help(read_file("/doc/help/map/suzhou-map"));
             return ;
    case "21":
             start_help(read_file("/doc/help/map/yanziwu-map"));
             return ;
    case "22":
             start_help(read_file("/doc/help/map/hangzhou-map"));
             return ;
    case "23":
             start_help(read_file("/doc/help/map/fuzhou-map"));
             return ;
    case "24":
             start_help(read_file("/doc/help/map/qz-map"));
             return ;
    case "25":
             start_help(read_file("/doc/help/map/xinjiang-map"));
             return  */
    case "b":
             m_display();
             write(YEL "\r请输入您得选择:"NOR);
             this_player()->delete_temp("help_c");
             input_to((:confirm_main_choice:),this_player());
             return ;
    default:
           c_display();
           write(YEL"\r请输入您的选择:"NOR);
           input_to((:confirm_c_choice:),this_player());
           return ;
        }
  return;
}
int lock()
{
    object me,ob;
    me = this_player();
    ob = me->query_temp("link_ob"); 
    write(HIW"▲ 请输入密码，以解除萤幕锁定："NOR);
    input_to("get_old_pass", 1, ob);
    return 1;
}
void get_old_pass(string pass, object ob)
{
        string old_pass;
        old_pass = ob->query("password");
        if( crypt(pass, old_pass)!=old_pass ) {
        lock();
        return ; }
        u_display();
        write(YEL"\r请输入您的选择:"NOR);
        input_to((:confirm_u_choice:),this_player());
        return ;
} 
         
int cloak()
{
   object me;
   me = this_player();
   if(!wizardp(me))
    {
           u_display();
           write(YEL"\r请输入您的选择:"NOR);
           input_to((:confirm_u_choice:),this_player());
           return 1;
   } 
   if(me->query("env/invisibility")) 
   {
    write("我要重现江湖...\n");
    me->delete("env/invisibility");
    }
   else {
    write("哈哈！我隐形起来了。\n");
    me->set("env/invisibility",5);
   }
  return 1;
}
private void confirm_u_choice(string arg)
{

 this_player()->set_temp("help_u",1);
 if(arg=="") {
     u_display();
     write(YEL "\r请从新输入您得选择:"NOR);
     input_to((:confirm_u_choice:),this_player());
     return ; }

 switch(arg[0]){
    case 'r':
            register();
            return ;
    case 'p':
            pager();
            check_user();
             return ;
    case 'c':
            cloak();
            check_user();
            return ;
    case 'l':
            lock();
            return ;
    case 'f':
    case 'g':
    case 'h':
    case 'g':
             m_display();
             write(YEL "\r请输入您得选择:"NOR);
             this_player()->delete_temp("help_u");
             input_to((:confirm_main_choice:),this_player());
             return ;
    default:
           u_display();
           write(YEL"\r请输入您的选择:"NOR);
           input_to((:confirm_u_choice:),this_player());
           return ;
        }
  return;
}
private void confirm_o_choice(string arg)
{
 this_player()->set_temp("help_o",1);
 if(arg=="") {
      o_display();
      write(YEL "\r请从新输入您得选择:"NOR);
      input_to((:confirm_o_choice:),this_player());
      return ; }
 switch(arg){
    case "1":
             start_help(read_file("/doc/help/applywiz"));
             return ;
    case "2":
             start_help(read_file("/doc/help/pet.txt"));
             return ;
    case "3":
             start_help(read_file("/doc/help/tasking.txt"));
             return ;
    case "4":
             start_help(read_file("/doc/help/force"));
             return ;
    case "5":
             start_help(read_file("/doc/help/sboard.txt"));
             return ;
    case "6":
             start_help(read_file("/doc/help/banking.txt"));
             return ;
    case "7":
             start_help(read_file("/doc/help/buildroom.txt"));
             return ;
    case "8":
             start_help(read_file("/doc/help/armors.txt"));
             return ;
    case "9":
             start_help(read_file("/doc/help/attributes.txt"));
             return ;
    case "10":
             start_help(read_file("/doc/help/health.txt"));
             return ;
    case "11":
             start_help(read_file("/doc/help/theme.txt"));
             return ;
    case "b":
             m_display();
             write(YEL "\r请输入您得选择:"NOR);
             this_player()->delete_temp("help_o");
             input_to((:confirm_main_choice:),this_player());
             return ;
    default:
             o_display();
             write(YEL"\r请输入您的选择:"NOR);
             input_to((:confirm_o_choice:),this_player());
             return ;
        }
  return;
}
private void confirm_main_choice(string arg)
{
  if(arg=="") {
       m_display();
       write(YEL "\r请从新输入您得选择:"NOR);
       input_to((:confirm_main_choice:),this_player());
       return ; }
 switch(arg[0]){
    case 'g':
             this_player()->delete_temp("select");
             this_player()->delete_temp("help");
             return;
    case '6':
             this_player()->delete_temp("select");
             return;
    case 'u':
             this_player()->set_temp("select","user");
             u_display();
             write(YEL"\r请输入您的选择:"NOR);
             input_to((:confirm_u_choice:),this_player());
             return ;             
    case 'b':
             this_player()->set_temp("select","board");
             o_display();
             write(YEL"\r请输入您的选择:"NOR);
             input_to((:confirm_o_choice:),this_player());
             return ;
    case 'i':
             this_player()->set_temp("select","intro");
             a_display();
             write(YEL"\r请输入您的选择:"NOR);
             input_to((:confirm_a_choice:),this_player());
             return ;
    case 'd':
             this_player()->set_temp("select","depart");
             b_display();
             write(YEL"\r请输入您的选择:"NOR);
             input_to((:confirm_b_choice:),this_player());
             return ;
    case 'm':
             this_player()->set_temp("select","map");
             c_display();
             write(YEL"\r请输入您的选择:"NOR);
             input_to((:confirm_c_choice:),this_player());
             return ;    
     default:
           m_display();
           write(YEL"\r请输入您的选择:"NOR);
           input_to((:confirm_main_choice:),this_player());
           return;
        }
  return;
}

int help(object me)
{
	write(@HELP
指令格式 : help

可以用此命令来详细了解本游戏。
HELP
    );
    return 1;
}
