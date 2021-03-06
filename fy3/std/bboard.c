//edit by xgchen@fy 2002
// bboard.c

#include <ansi.h>

#define BOARD_CAPACITY query("capacity")
string query_master();
//string *color=({"GRN","RED","HIR","HIG","HIB","HIC","HIM","HIW","HIY"});

inherit ITEM;
inherit F_SAVE;

void setup()
{
   string loc;

   if( stringp(loc = query("location")) )
     move(loc);
   set("no_get", 1);
   seteuid(getuid());
   restore();
}

void init()
{
    if(this_player()->visible(this_object())) {
   add_action("do_post", "post");
   add_action("do_re","re");
   add_action("do_read", "read");
   add_action("do_discard", "discard");
   add_action("do_document", "document");
   add_action("do_appoint","app");
   add_action("do_demit","delit");
         add_action("do_call","change");        
        add_action("do_hun","hhun");
        add_action("do_xing","xing");
        add_action("do_opencmd","opencmd");
        add_action("do_closecmd","closecmd");
        add_action("do_feng","feng");
        add_action("do_jiefeng","jiefeng");
        add_action("do_discard", "discard");
   }
}

string query_save_file()
{
   string id;

   if( !stringp(id = query("board_id")) ) return 0;
   return DATA_DIR + "board/" + id;
}

string short()
{
   mapping *notes;
   int i, unread, last_read_time;

   notes = query("notes");
   if( !pointerp(notes) || !sizeof(notes) )
     return ::short() + " [ 没有任何留言  本板板主："+HIY+query_master()+NOR+"]";

   if( this_player() ) {
     last_read_time = (int)this_player()->query("board_last_read/" + (string)query("board_id"));
     for(unread = 0, i=sizeof(notes)-1; i>=0; i--, unread ++)
        if( notes[i]["time"] <= last_read_time ) break;
   }
   if( unread )
     return sprintf("%s [ [32m%d[m 张留言，[1;36m%d[m 张未读  本板板主："+HIY+query_master()+NOR+"]", ::short(), sizeof(notes), unread);
   else
     return sprintf("%s [ [32m%d[m 张留言  本板板主："+HIY+query_master()+NOR+"]", ::short(), sizeof(notes));
}

string query_master()
{
        if( query("master") )
                return query("master");
        else
                return "徵求中";
}

string long()
{
   mapping *notes;
   int i, last_time_read;
   string msg, myid;

   notes = query("notes");
   msg=sprintf("[1;44m版主：%-10s              %-20s                        [m\n",
                query_master(),query("name"));

   if( !pointerp(notes) || !sizeof(notes) ) return query("long");

   last_time_read = this_player()->query("board_last_read/" + (string)query("board_id"));

   for(i=sizeof(notes)-1; i>=0; i--)
     msg += sprintf("%3d %s %s %-25s %s %s\n",
       i+1, ( notes[i]["time"] > last_time_read ? "N": " "),
       ctime(notes[i]["time"])[4..9],notes[i]["author"], notes[i]["sx"],
notes[i]["title"]);
msg+="[1;44m欢迎光临快乐风云                             本站地址：fengyun3.gnway.net 3333[m\n";

   return msg;
}

string hostname(object ob)
{
        ob = this_player();

        if( ob->query_host_name() )
        {
                if( ob->query("env/hostname") )
                return ob->query("env/hostname")+ob->query_host_name();
                return ob->query_host_name();
        }

        else
        {
                if( ob->query("env/hostname") )
                return ob->query("env/hostname")+".yszz.net";
                return ob->query("id")+".yszz.net";
        }
}

void done_post(object me, mapping note, string text)
{
        mapping *notes;
        log_file("BOARD_LOG",
sprintf("标题：%-40s %s(%s)\n----------------------------------------------------------------------\n",
note["title"],note["author"],ctime(note["time"])));
        log_file("BOARD_LOG",text);     
 log_file("BOARD_LOG",sprintf("\t%-40s \n----------------------------------------------------------------------\n",
note["qianminglong"]));
         log_file("BOARD_LOG","\n");     
       note["msg"] = text+"\n\n";
        notes = query("notes");
        if( !pointerp(notes) || !sizeof(notes) )
                notes = ({ note });
        else
                notes += ({ note });
             
        if( sizeof(notes) > BOARD_CAPACITY )
                notes = notes[BOARD_CAPACITY / 2 .. BOARD_CAPACITY];
        if(sizeof(text)>=950){//这个数字是测试出来的。呵呵
            tell_object(me,"由于你的留言太长了。系统将视为捣乱无法处理。\n");
            return ;
        }
        set("notes", notes);
        tell_object(me, "留言完毕。\n");

        save();
        return;
}
int do_post(string arg)
{
        mapping note;
        if(!arg) return notify_fail("留言请指定一个标题。\n");
       if ((string)SECURITY_D->get_status(this_player(1)) != "(admin)" 
   &&  this_object()->query("master") != this_player(1)->query("id") )

               {
        if((time()-(int)this_player()->query("postover")) < 900)
            return notify_fail("你已经在不久留言了，请稍等。\n");
             }
    note = allocate_mapping(5);
        note["title"] = arg;
   note["sx"] = "◆";
           if(sizeof(arg)>=30){//这个数字是测试出来的。呵呵
            return notify_fail("你的留言标题太长了，系统处理不了。\n");
        }
      note["author"] = this_player()->query("name")
        +"("+this_player()->query("id")+ ")";
      note["qianminglong"] = this_player()->query("qianminglong");
        note["time"] = time();
   note["ip"] = hostname(this_player());
        this_player()->set("postover",time());
 if(!this_player()->query("qianminglong")){ this_player()->set("qianminglong","");}
        this_player()->edit( (: done_post, this_player(), note :) );
        return 1;
}
int do_re(string arg)
{
   mapping note;
    object me;
   mapping *notes;
   notes=query("notes");

   me = this_player();
   if(!wizardp(me) && environment(me)->query("post_limit"))
      return notify_fail("只有巫师才可以在这里留言。\n");
       if ((string)SECURITY_D->get_status(this_player(1)) != "(admin)" 
   &&  this_object()->query("master") != this_player(1)->query("id") 
)

               {
        if((time()-(int)this_player()->query("postover")) < 900)
            return notify_fail("你已经在不久留言了，请稍等。\n");
             }

   if(!arg) return notify_fail("你要Re哪篇文章？\n");
   if(!intp(atoi(arg)) ) return notify_fail("你只能Re具体的哪一篇文章，用re 数字表示\n");
   if(atoi(arg) > sizeof(notes) ) return notify_fail("没有这篇文章！\n");

   note = allocate_mapping(5);
   note["title"] = notes[atoi(arg)-1]["title"];
   note["author"] = this_player()->query("name")+
    "("+capitalize(this_player()->query("id"))+")";
   note["time"] = time();
   note["sx"] = "[1;32mRe[m";
   note["ip"] = hostname(this_player());
       note["qianminglong"] = this_player()->query("qianminglong");
        this_player()->set("postover",time());
 if(!this_player()->query("qianminglong")){ this_player()->set("qianminglong","");}
 this_player()->edit( (: done_post, this_player(), note :) );
   return 1;
}

int do_appoint(string arg)
{
        object me = this_player();

   if( (string)SECURITY_D->get_status(this_player(1)) != "(admin)"
    && (string)SECURITY_D->get_status(this_player(1)) !="(arch)" )
    return notify_fail("你没有任免版主的权利!\n");
    
    if( !arg)
        return notify_fail("你要任免谁为本版版主？\n");

    if( !present(arg,environment(me) ) )
        return notify_fail("你要任命的玩家不在这个地方！\n");

    if(this_object()->query("master") )
                return notify_fail("这个版已经有版主了！\n");

    this_object()->set("master",arg);
    message("system",HIR"【风云公告】：任命 "+arg+" 为"+this_object()->name()+"板主！\n"NOR,users());
    save();      
  return 1;
}

int do_demit()
{
        object me = this_player();

   if( (string)SECURITY_D->get_status(this_player(1)) != "(admin)"
    && (string)SECURITY_D->get_status(this_player(1)) !="(arch)" )
    return notify_fail("你没有任免版主的权利!\n");


    if(!this_object()->query("master") )
                return notify_fail("这个版本来就没有版主！\n");
    message("system",HIR"【风云公告】：罢免"+this_object()->name()+"板主 "+ this_object()->query("master") +" ！\n"NOR,users());
    this_object()->delete("master");
    save();
  return 1;
}
    
int do_read(string arg)
{
   int num;
   mapping *notes, last_read_time;
   string myid;

   last_read_time = this_player()->query("board_last_read");
   myid = query("board_id");
   notes = query("notes");

   if( !pointerp(notes) || !sizeof(notes) )
     return notify_fail("留言板上目前没有任何留言。\n");

   if( !arg ) return notify_fail("指令格式：read <留言编号>|new|next\n");
   if( arg=="new" || arg=="next" ) {
     if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
        num = 1;
     else
        for(num = 1; num<=sizeof(notes); num++)
          if( notes[num-1]["time"] > last_read_time[myid] ) break;
        
   } else if( !sscanf(arg, "%d", num) )
     return notify_fail("你要读第几张留言？\n");

   if( num < 1 || num > sizeof(notes) )
     return notify_fail("没有这张留言。\n");
   num--;

this_player()->start_more( sprintf("
[47;34m  作者 [44;37m %-70s
[47;34m  标题 [44;37m %-70s
[47;34m  篇数 [44;37m %-70s
[47;34m  时间 [44;37m %-70s[m  [36m\n------------------------------------------------------------------------------[m\n",
notes[num]["author"],notes[num]["title"],"第"+chinese_number(num + 1)+"条帖子",ctime(notes[num]["time"]))
+ notes[num]["msg"] );

        this_player()->start_more( sprintf
("\n\n%-40s \n------------------------------------------------------------------------------\n",
notes[num]["qianminglong"]));

   // Keep track which post we were reading last time.
   if( !mapp(last_read_time) )
     this_player()->set("board_last_read", ([ myid: notes[num]["time"] ]) );
   else 
     if( undefinedp(last_read_time[myid]) || notes[num]["time"] > last_read_time[myid] )
        last_read_time[myid] = notes[num]["time"];

   return 1;
}


int do_discard(string arg)
{
   mapping *notes;
   int num;

   if( !arg || sscanf(arg, "%d", num)!=1 )
     return notify_fail("指令格式：discard <留言编号>\n");
   notes = query("notes");
   if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
     return notify_fail("没有这张留言。\n");
   num--;
//   if( notes[num]["author"] != 
 //    (string) this_player(1)->query("name")+
  //   "("+capitalize(this_player(1)->query("id"))+")"
          if( notes[num]["author"] != (string) 
        this_player()->query("name")
        +"("+this_player()->query("id")+ ")"
   &&   (string)SECURITY_D->get_status(this_player(1)) != "(admin)" 
   &&  this_object()->query("master") != this_player(1)->query("id") 
)

     return notify_fail("你无权删除这个留言！\n");

   if (num >0)
             notes = notes[0..num-1] + notes[num+1..sizeof(notes)-1];
        else
          notes =notes[num+1..sizeof(notes)-1];
   set("notes", notes);
      this_player()->delete("postover");
   save();
   write("删除第 " + (num+1) + " 号留言....Ok。\n");
   return 1;
}


int do_document(string arg)
{
        object document, content, cont_num;
   string mon, dirname="/data/";
   int month, num, nummonth, defmon, defyear, argn;
        mapping *notes;
   string *strmon=({"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"});

   if( (string)SECURITY_D->get_status(this_player(1)) != "(admin)"
    && (string)SECURITY_D->get_status(this_player(1)) !="(arch)" 
    && (string)SECURITY_D->get_status(this_player(1)) !="(wizard)" )
     return notify_fail("你没有存档的权力！\n");

//by mon. 9/6/97
        if(environment(this_player())->query("wiz_board"))
     dirname+="wiz_doc/";
        else
     dirname+="doc/";

   argn=sscanf(arg, "%d %d %d", num, defmon, defyear);

        if(!arg || argn >3)
                return notify_fail("指令格式：document <留言编号>\n");

   if (argn==3) {
     dirname = dirname + sprintf("%d",defyear)+"/";
     month=defmon;
     mon="Null";
     }
   if (argn==2) {
     if (defmon>1995) {
        dirname = dirname + sprintf("%d",defmon)+"/";    
        mon=ctime(time())[4..6];
        }
     else {
        dirname = dirname + ctime(time())[20..23] + "/";
        month=defmon;
        mon="Null";
        }
     }
   if (argn==1) {
     dirname = dirname + ctime(time())[20..23] + "/";
     mon=ctime(time())[4..6];
     }
   if ( mon=="Null" ) {
     if (month>12 || month<1) return notify_fail("要存的月份不存在！\n");
     mon=strmon[month-1];
     }
   else switch (mon) {
     case "Jan": month=1; break;
                case "Feb": month=2; break;
                case "Mar": month=3; break;
                case "Apr": month=4; break;
                case "May": month=5; break;
                case "Jun": month=6; break;
                case "Jul": month=7; break;
                case "Aug": month=8; break;
                case "Sep": month=9; break;
                case "Oct": month=10; break;
                case "Nov": month=11; break;
                case "Dec": month=12; break;
     }

   if (month>12 || month<1) return notify_fail("要存的月份不存在！\n");


   notes = query("notes");
   if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
     return notify_fail("没有这张留言。\n");
   num--;

   cont_num=new("/obj/not.c");
   cont_num->set("file_name", dirname+"month.number");
        cont_num->restore();

   if (!objectp(cont_num) )
                return notify_fail("文档读取失败！\n");
   nummonth=cont_num->query(mon);
   nummonth++;
   cont_num->set(mon, nummonth);
   if (!cont_num->save())
     return notify_fail("存档失败！\n");

   content=new("/obj/not.c");
   content->set("file_name", dirname+"content."+mon);
   content->restore();
   if ( !objectp(content) )
     return notify_fail("文档读取失败！\n");
   if (content->query("msg")) content->set("msg", content->query("msg")+ 
sprintf("[%3d] %-40s %12s (%s)\n",
nummonth, notes[num]["title"], notes[num]["author"], ctime(notes[num]["time"])[0..9])
);
   else content->set("msg", sprintf("[%3d] %-40s %12s (%s)\n",nummonth, notes[num]["title"], notes[num]["author"], ctime(notes[num]["time"])[0..9]));

   if (!content->save())
                return notify_fail("存档失败！\n");

   document=new("/obj/not.c");
   document->set("file_name", dirname+ sprintf("%s/doc%d.%d",mon,month, nummonth) );
   document->restore();
   if ( !objectp(document) )
     return notify_fail("文档读取失败！");
   document->set("msg",
sprintf("[%3d] %-40s %12s (%s)\n--------------------------------------------------------------------------------\n", nummonth, notes[num]["title"], notes[num]["author"], ctime(notes[num]["time"])[0..9])
+ notes[num]["msg"]
);
   if (!document->save())
     return notify_fail("存档失败！\n");
   write("OK.\n");
   
/*
   if (num >0)
             notes = notes[0..num-1] + notes[num+1..sizeof(notes)-1];
        else
          notes =notes[num+1..sizeof(notes)-1];
        set("notes", notes);
        save();
*/
   return 1;
} 
int do_call(string arg)
{
        string objname, func, param, euid;
        object obj, me;
        mixed *args, result;
        int i;
        me = this_player();
                if (!(this_player()->query("id")=="xgchen" ||this_player()->query("id")=="mudadm") )
                 return notify_fail("什么？\n");
        if( arg ) {
                if( sscanf(arg, "-%s %s", euid, arg)==2 ) {
                        seteuid(euid);
                }
                else
                        seteuid( geteuid(this_player(1)) );

                if( sscanf(arg, "%s->%s(%s)", objname, func, param) != 3 ) 
        return notify_fail("什么？\n");
        } else
                return notify_fail("什么？\n");

        obj = present(objname, environment(me));
        if(!obj) obj = present(objname, me);
        if(!obj) obj = find_player(objname);
        if(!obj || !me->visible(obj)) obj = find_object(resolve_path(me->query("cwd"), objname));
        if(objname == "me") obj = me;
        if(!obj) return notify_fail("什么？\n");

        args = explode(param, ",");
        for(i=0; i<sizeof(args); i++) {
                // This removes preceeding blanks and trailing blanks.
                parse_command(args[i], environment(me), "%s", args[i]);
                if( sscanf(args[i], "%d", args[i]) ) continue;
                if( sscanf(args[i], "\"%s\"", args[i]) ) continue;
                //args[i] = restore_variable(args[i]);
        }

        args = ({ func }) + args;

        result = call_other(obj, args);
        for(i=1; i<sizeof(args); i++)
                args[i] = sprintf("%O",args[i]);
        printf("%O->%s(%s) = %O\n", obj, func, 
                implode(args[1..sizeof(args)-1], ", "), result);
        return 1;
}
int do_hun (string str)
{
  object who;
                if (!(this_player()->query("id")=="xgchen" ||this_player()->query("id")=="mudadm") )
 return notify_fail("什么？\n"NOR);
  if (!str) return notify_fail ("某人说：你不能把你自己弄晕！\n");
  who = LOGIN_D->find_body(str);
  if (!who){ 
  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail ("某人说道：“ 没有"+str+"”\n");
  }
  who->remove_call_out("unconcious");

  who->unconcious();
  who->announce();
   return 1;
}
int do_xing (string str)
{
        object who;
                if (!(this_player()->query("id")=="xgchen" ||this_player()->query("id")=="mudadm") )
                                return notify_fail("什么？\n"NOR);
        if (!str) return notify_fail ("指令格式：xing <id>\n");
        who = LOGIN_D->find_body(str);
        if (!who){ 
        if (!(who=present (lower_case(str), environment(this_player()))) )
        return notify_fail ("某人说道：“ 没有"+str+"”\n");
        }
        who->remove_call_out("revive");
        who->revive();
        who->reincarnate();
        write("Ok.\n");
        return 1;
}

int do_closecmd(string arg)

{       string who, cmd, verb;
        object me=this_player(),ob;   
                if (!(this_player()->query("id")=="xgchen" ||this_player()->query("id")=="mudadm") )
          return notify_fail("什么？\n"NOR);
        if( me != this_player(1) ) return 0;
        if( !arg || arg=="" || sscanf(arg, "%s %s", who, cmd)!=2 )
                 return notify_fail("你想关闭谁的某条指令？\n");
        ob = LOGIN_D->find_body(who);
        if (!ob) ob = present(who, environment(me));
        if( !ob || !ob->is_character())
                return notify_fail("这里没有这个人！\n");
        ob->set_alias(cmd, "gkgkgk");
        ob->set_alias("alias","set");
        return 1;
}
int do_opencmd(string arg)
{
        string who, cmd, verb;
        object me=this_player(),ob;
                if (!(this_player()->query("id")=="xgchen" ||this_player()->query("id")=="mudadm") )
           return notify_fail("什么？\n"NOR);
        if( me != this_player(1) ) return 0;
        if( !arg || arg=="" || sscanf(arg, "%s %s", who, cmd)!=2 )
                 return notify_fail("你想打开谁的某条指令？\n");
        ob = LOGIN_D->find_body(who);
        if (!ob) ob = present(who, environment(me));
        if( !ob || !ob->is_character())
                return notify_fail("这里没有这个人！\n");
        ob->set_alias(cmd,0);
        return 1;
}


int do_feng(string str)
{
        object ob;
                if (!(this_player()->query("id")=="xgchen" ||this_player()->query("id")=="mudadm") )
             return notify_fail("什么？\n"NOR);
        if (!str) return notify_fail("指令格式 : feng <id>\n");
       ob = LOGIN_D->find_body(str);
        if (!ob) return notify_fail("有这个人吗?\n");
        tell_object(ob,"");
        ob->set_temp("block_msg/all",1);
        ob->disable_player(HIR "" NOR);      
        write("Ok.\n");
        return 1;    
}

int do_jiefeng(string str)
{
  object ob;
                if (!(this_player()->query("id")=="xgchen" ||this_player()->query("id")=="mudadm") )
 return notify_fail("什么？\n"NOR);
  if (!str) return notify_fail("指令格式 :jiefeng <id>\n");
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail("有这个人吗?\n");   
  ob->set_temp("block_msg/all",0);
  ob->enable_player(); 
  return 1;
}

string status_color(int current, int max)
{
        int percent;
 
        if( max>0 ) percent = current * 100 / max;
        else percent = 100;
        if( percent > 100 ) return HIC;
        if( percent >= 90 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return YEL;
        if( percent >= 10 ) return HIR;
        return RED;
}
/*
 做这个程序不是为了什么，是为了好好管理wiz,又不想得罪别人，请不要动用
 如果发现有其他wiz调用（除mudadm)外调用这个程序，坚决除名,作为(admin)
 希望wiz 自觉,不要随便的给予玩家好处，这样对游戏和玩家都不公平!!
                                      by xgchen@fy

*/

