// outdoor_func.c zip@hero 2000.1.27 �����ſڹ���
void close_door();
void init()
{  add_action("do_open","open");
   add_action("do_close","close");
  add_action("do_knock","knock");
}

int do_open(string arg)
{ 
   int i;
   object me,key,*inv;
   me=this_player();
   if(arg!="door") 
   return notify_fail("��Ҫ��ʲô��\n");
   if(query("exits/enter")) 
   return notify_fail("�Ų���������\n");
//modified by lion@hero here,��������в�ͬ��Կ�ײ��ܿ��ŵ����⡣
   inv = all_inventory(me);
   i=sizeof(inv);
   while(i--)
   {
   	if(((inv[i]->query("id"))=="door key")
   	 &&((inv[i]->query("owner"))==(this_object()->query("owner"))))
   	{
   message_vision("$N�ͳ�һ��Կ�״򿪷��š�\n",me);
   set("exits/enter",__DIR__"room/"+(string)this_object()->query("owner")+"_room");
   call_out("close_door",30);
   return 1;
  			}
   	}
message_vision("$N�뿪�Ž�ȥ�����ǣ�û����������Կ�ס�\n",me);
return 1;
}

//added by lion@hero ���Ź��ܡ�
int do_knock(string arg)
{
  int i,flag=0;
object *inv;
object room,me;
if(arg!="door")
return notify_fail("��Ҫ��ʲô��\n");
me=this_player();
if(me->query("id")==this_object()->query("owner"))
  {
    tell_object(me,"�������Լ��ķ���ѽ������ʲô�ã�\n");
return notify_fail("�ǲ�������Կ���ˣ�����ȥ���ܴ�Ҫ��(ask master about key)��\n");
  }
room=find_object(__DIR__"room/"+this_object()->query("owner")+"_room");
if(!room)
room=load_object(__DIR__"room/"+this_object()->query("owner")+"_room");
if(!room)
return notify_fail("����û���ţ�������ʲô��\n");
inv=all_inventory(room);
i = sizeof(inv);
while(i--)
{
if(userp(inv[i]))
{
flag=1;
break;
  }
}
message_vision("$N������������š�\n",me);
if(!flag)
return notify_fail("�������������û���κ��ˣ�������Ҳû�á�\n");
tell_room(room,"������������أ�Ҫ��Ҫ�����أ�\n",this_object());
tell_room(room,"��look out���˭����ߣ���open door����š�\n",this_object());
tell_object(me,"�Ե�һ���������������ǲ�������Ը����㿪���ˡ�\n");
return 1;
}

int do_close(string arg)
{  object me=this_player();
   if(arg!="door") return notify_fail("��Ҫ����ʲô��\n");
   if(!query("exits/enter")) return notify_fail("�ף��ſ�����\n");
   delete("exits/enter");
   message_vision("$N�����ŵķ��Ź��ϡ�\n",me);
return 1;
}
void close_door()
{ if(!query("exits/enter")) return;
  message_vision("С������쵽���ֲ����š�����\nС���罫���ŵķ��Ź��ϡ�\n",this_object());
  delete("exits/enter");
return;
} 
