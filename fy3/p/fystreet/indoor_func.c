// indoor_func.c zip@hero 2000.1.27 �����ڲ�����
void enter_desc(string arg);
void init()
{  add_action("do_open","open");
   add_action("do_close","close");
   add_action("do_zhuangxiu","zhuangxiu");
   add_action("do_dazareng","dazareng");
   add_action("do_yaoqing","yaoqing");
   add_action("do_kickout","kickout");
}

int do_open(string arg)
{  object ob;
   if(arg!="door") 
   return notify_fail("��Ҫ��ʲô��\n");
   if(!ob=find_object("/p/fystreet/street"+(string)ID)) 
   ob=load_object("/p/fystreet/street"+(string)ID);
   if(ob->query("exits/enter")) return notify_fail("�Ų���������\n");
   message_vision("$N�����Ŵ򿪡�\n",this_player());
   ob->set("exits/enter",__DIR__+(string)this_object()->query("owner")+"_room");
   tell_room(ob,this_player()->name()+"�����Ŵ򿪡�\n");
return 1;
}
int do_close(string arg)
{  object ob;
   if(arg!="door") return notify_fail("��Ҫ����ʲô��\n");
   if(!ob=find_object("/p/fystreet/street"+(string)ID)) 
   ob=load_object("/p/fystreet/street"+(string)ID);
   if(!ob->query("exits/enter")) return notify_fail("�ף��ſ�����\n");
   ob->delete("exits/enter");
   message_vision("$N�����Ź��ϡ�\n",this_player());
   tell_room(ob,this_player()->name()+"�����Ź��ϡ�\n");
return 1;
}
int do_zhuangxiu()
{  if(this_object()->query("owner")!=this_player()->query("id")) return notify_fail("������ķ�����\n");
   if(this_player()->query("jiaju")<5) return notify_fail("��ļҾ߻����������\n");
   if(this_object()->query("long")!=" ����һ���ս��õĴ���,�͵���װ���ˡ�\n") 
     return notify_fail("�ⲻ���úõ��𣬾��ӼҾ߾��˰���\n");
   write("�����������ķ�����������ʮ�����ٸ������֡�\n\n");
   this_player()->edit((:enter_desc:));
return 1;}
void enter_desc(string arg)
{  if((strlen(arg)<60)||(strlen(arg)>600))
    {write("�Բ��𣬷���������������ʮ�����ٸ������֡�\n");return;}
   write("�ã����������ǣ�\n   "+arg);
   write("\n��ȷ����[yes|no]->");
   input_to("check_yes",arg);
return;}
void check_yes(string arg,string text)
{  string file,filename,bakname;
   if(arg!="yes") {write("���Ǳ𼱰ɡ�\n");return;}
   filename=__DIR__+this_player()->query("id")+"_room.c";
   file=read_file(filename);write_file(__DIR__+this_player()->query("id")+"_room.bak",file,1);
   file=replace_string(file,"����һ���ս��õĴ���,�͵���װ���ˡ�",text);
   if(!write_file(filename,file,1)) write("write file fail.\n");
   this_object()->set("long",text);this_player()->delete("jiaju");
   message_vision("$N������ú�װ����һ�����󹦸�ɣ�\n",this_player());
return;}
int do_dazareng()
{  if(this_object()->query("owner")!=this_player()->query("id")) return notify_fail("������ķ����𣿵�ʲô�ң�\n");
   if(this_object()->query("long")=="����һ���ս��õĴ���,�͵���װ���ˡ�\n") 
     return notify_fail("������տ���Ҳ�ģ���ʲô�Ұ���\n");
   message_vision("$N�������Լ��ķ�����һ�δ����ӣ�\n",this_player());
   write("Ҫ����װ�޵Ļ�����Ҫ������Ҿߵģ�����ˣ�[yes|no]->");
   input_to("check_yess");
return 1;}
void check_yess(string arg)
{  string file;
   if(arg!="yes") {message_vision("$N����Լ����ֲ��õķ��䣬������ôҲ�²����֡�\n",this_player());return;}
   file=read_file(__DIR__+this_player()->query("id")+"_room.bak");
   write_file(__DIR__+this_player()->query("id")+"_room.c",file,1);
   this_object()->set("long","����һ���ս��õĴ���,�͵���װ���ˡ�\n");
   message_vision("$N�е����ɵĲ�ȥ���µĲ�����ֻ��һ������ž��������ॣ����������̳����ң�ˬ��\n",this_player());
return;}

//added by lion@hero
//����������������.
int do_yaoqing(string arg)
 {
     string id;
    int roomid;
  object ob,room;
  object me=this_player();
  room = this_object();
  id = geteuid(me);
  if(room->query("owner")!=geteuid(me))
  return notify_fail("�㲻�����������,�����������.\n");
  if(!arg||arg=="")
  return notify_fail("�����ʽ:yaoqing <id>\n");
  ob = LOGIN_D->find_body(arg);
  if (!ob) return notify_fail("��... ���������?\n");
   if(present(arg,room))
   return notify_fail("��Ҫ������˾����������ѽ��\n");
  message_vision("$N����$n���������͡�\n",me,ob);
  tell_object(ob,HIY"\n"+me->name()+"������������"+room->query("short")+"ȥ����.\n"NOR);
   roomid=me->query("roomid");
  tell_object(ob,room->query("short")+"���ڷ��ƽ�"+chinese_number(roomid/100)+"��"+((roomid%2)?"��":"��")+"��\n");
  return 1;
 } 
 
//�Ѳ���֮�͸��ߡ�
int do_kickout(string arg)

 {
   string id;
  object ob,room;
  object me=this_player();
  room = this_object();
  id = geteuid(me);
  if(room->query("owner")!=id)
  return notify_fail("�㲻�����������,���ܸ���.\n");
  if(!arg||arg=="")
  return notify_fail("�����ʽ:kickout <id>\n");
  ob = present(arg,this_object());
  if (!ob) return notify_fail("����û��������䰡!\n");
  message_vision("$N��$n���˳�ȥ��\n",me,ob);
  tell_object(ob,HIY"\n"+me->name()+"����ӭ�����������ͣ��㻹���߰ɡ�\n"NOR);
  room=find_object("/p/fystreet/street"+(string)ID);
  if(!room)
 room=load_object("/p/fystreet/street"+(string)ID);
  ob->move(room);
  return 1;
 }  
 

