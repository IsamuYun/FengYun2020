//build_func.c      zip@hero  2000.1.27 ��������
#include <ansi.h>
#define __ROOMDIR__ "/p/fystreet/"
int fileoperate(object ob,object me);
void init()
{  add_action("do_build","build");
   add_action("do_sign","sign");}

int do_build(string arg)
{ int roomid;
  if(arg!="here") return 0;
  if(this_object()->query("owner")!=this_player()->query("id")) return 0;
  this_object()->set_temp("buildfinish",0);
  roomid=(int)environment(this_object())->query("roomid");
  if(!roomid) {command("say ������ǲ��ʺϽ����ӣ��ұ�ĵط��ɣ�");return 1;}
  this_object()->set("roomid",roomid);
  command("say �ã�������ˡ�");
  command("emote �ͳ�һ���ļ��з��������ϼ���Щʲô��");
  command("say ����ķ���ȡһ�������ְɣ������3��7�����ģ�������(help color)������ɫ��");
  write("�����뷿������");
  input_to("get_room_name");
return 1;
}
int get_room_name(string arg)  //���뷿������
{ if(!arg||arg=="") {command("say �ţ���������ðɡ��������(build here)��");return 1;}
  if(arg=="help color") 
  { write("Zmud4�������𲻳���ͨ����ɫ�����ϵİ汾��������
$RED$ - "+RED"��ɫ"NOR+"		$HIR$ - "+HIR"����ɫ"NOR+"
$GRN$ - "+GRN"��ɫ"NOR+"		$HIG$ - "+HIG"����ɫ"NOR+"
$YEL$ - "+YEL"����ɫ"NOR+"		$HIY$ - "+HIY"��ɫ"NOR+"
$BLU$ - "+BLU"����ɫ"NOR+"		$HIB$ - "+HIB"��ɫ"NOR+"
$MAG$ - "+MAG"ǳ��ɫ"NOR+"		$HIM$ - "+HIM"�ۺ�ɫ"NOR+"
$CYN$ - "+CYN"����ɫ"NOR+"		$HIC$ - "+HIC"����ɫ"NOR+"
$WHT$ - "+WHT"ǳ��ɫ"NOR+"		$HIW$ - "+HIW"��ɫ"NOR+"
ϵͳ�Զ������ִ�β�˼�һ��$NOR$�ָ�������ɫ��\n");
  write("�����뷿������");input_to("get_room_name");return 1;}
  arg=replace_string(arg,"$RED$",RED);arg=replace_string(arg,"$GRN$",GRN);
  arg=replace_string(arg,"$YEL$",YEL);arg=replace_string(arg,"$BLU$",BLU);
  arg=replace_string(arg,"$MAG$",MAG);arg=replace_string(arg,"$CYN$",CYN);
  arg=replace_string(arg,"$WHT$",WHT);arg=replace_string(arg,"$HIR$",HIR);
  arg=replace_string(arg,"$HIG$",HIG);arg=replace_string(arg,"$HIY$",HIY);
  arg=replace_string(arg,"$HIB$",HIB);arg=replace_string(arg,"$HIM$",HIM);
  arg=replace_string(arg,"$HIC$",HIC);arg=replace_string(arg,"$HIW$",HIW);
  arg=replace_string(arg,"$NOR$",NOR);arg+=NOR;
  this_object()->set("roomname",arg);
  command("say �����֣�"+arg);
  command("emote ���ļ�������д�˼��ʡ�");
  command("say ����Ҫʲô���ķ����أ�����һ����۰ɣ�ֻҪһ�оͺá�");
  write("�����뷿����ۣ�");input_to("get_room");
return 1;
}
int get_room(string arg) //�����������
{ string *dir=({"��","��"});
  string msg;object me=this_object();
  if(!arg||arg=="") {command("say ���ȷ���˾Ͳ����ٸ��ˣ��������(build here)�ɡ�");return 1;}
// ������չ����select()
  me->set("roomlong",arg);
  command("emote �ı����ļ������Ϸɿ�ؼ��š�");
  command("say ���ˣ��㿴���Բ��ԡ�");
  msg ="\n      �ص㣺���ƽ�"+chinese_number((int)me->query("roomid")/100)+"��"+dir[(int)me->query("roomid")%2];
  msg+="\n      ������"+(string)me->query("roomname");
  msg+="\n      ��ۣ�"+"���ƽ֣����Ƴ��ڷ��������ס�ĵط�����������ӵ��һ�䷿���������˵�
      ���롣"+this_player()->query("name")+"��"+(string)me->query("roomname")+"������������де����֣����ﻨ�㡣
      "+me->query("roomlong");
  write(msg+"\n\n");
  command("say ���ûʲô���⣬�������ǩ����(sign)��");
  this_object()->set_temp("buildfinish",1);
return 1;
}

int do_sign(string arg)
{ object ob,me;
  me=this_player();ob=this_object();
  if(ob->query("owner")!=me->query("id")) return 0;
  if(!(ob->query_temp("buildfinish"))) return 0;
  message_vision("$N���һ�ӣ�ǩ���Լ�������"+me->query("name")+"��\n",me);
  command("say ��ķ���Ҫ����º���ܸǺã���ȥ�̳�������ʲô�Ҿ߰ɣ���װ��һ�·��ӡ�");
  command("say �̳����ڽֿ����������Ȼ�ȥ�ˡ�");
  fileoperate(me,ob);
  me->delete_temp("inbuild");
  me->set("roomid",ob->query("roomid"));
  me->add("created_room",ob->query("roomid"));
destruct(ob);  
return 1;
}
int fileoperate(object ob,object me)
{ string *dir=({"��","��"});
  string file,writefile;
  file=read_file(__ROOMDIR__"outdoor.c");
  file=replace_string(file,"#define ID 109","#define ID "+(string)me->query("roomid"));
  if((int)me->query("roomid")%2) file=replace_string(file,"west","east");
  file=replace_string(file,"����",ob->query("name"));
  file=replace_string(file,"�Խ�����",me->query("roomname"));
  file=replace_string(file,"owner_id",ob->query("id"));
  file=replace_string(file,"���й�Ȼ��һ�����ӣ�",me->query("roomlong"));
  writefile=__ROOMDIR__+"street"+(string)me->query("roomid");
  find_object(writefile)->delete("roomid");writefile+=".c";
  write_file(writefile,file,1);
  //added by lion@hero here
  //�������Ӹ������԰塣
  file=read_file(__ROOMDIR__"std_board.c");
  file=replace_string(file,"/p/fystreet/indoor.c","/p/fystreet/room/"+ob->query("id")+"_room.c");
  file=replace_string(file,"std_board",ob->query("id")+"_board");
  writefile=__ROOMDIR__+"board/"+ob->query("id")+"_board.c";
  write_file(writefile,file,1);
  file=read_file(__ROOMDIR__"indoor.c");
  file=replace_string(file,"#define ID 109","#define ID "+(string)me->query("roomid"));
  file=replace_string(file,"owner_id",ob->query("id"));
  file=replace_string(file,"����",me->query("roomname"));
  file=replace_string(file,"/p/fystreet/board/std_board","/p/fystreet/board/"+ob->query("id")+"_board");
  //modified by lion@hero here
  //��ҷ��䵥��һ��Ŀ¼��š�
  writefile=__ROOMDIR__+"room/"+ob->query("id")+"_room.c";
  write_file(writefile,file,1);
  writefile=__DIR__"room.list";file=read_file(writefile);
  file+=":"+ob->query("name")+","+me->query("roomid")+":";
  write_file(writefile,file,1);
return 1;
}
