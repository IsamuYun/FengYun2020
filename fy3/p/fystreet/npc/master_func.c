//master_func.c      zip@hero  2000.1.27 ���ܹ���
#include <ansi.h>
#define __ROOMDIR__ "/p/fystreet/"
void init()
{  add_action("do_ask","ask");}

int do_ask(string arg)
{ object ob,me,key,gold,builder;
  string dest,topic,topicowner,owner,roomid,rest,dir,dir1;
  int i;
  me=this_object();ob=this_player();
  if(!arg||sscanf(arg,"%s about %s",dest,topic)!=2) return 0;
  if(dest!="room master"&&dest!="master") return 0;
  message_vision("$N��$nѯ���йء�"+topic+"�����¡�\n",ob,me);
  if(topic=="����")
    {message_vision("\n$N˵��������ֻҪ�����㹻��gold���ۺ����ۣ��Ϳ����ڷ��ƽֽ�һ���Լ��ķ��ӡ�\n",me);
     message_vision("$N˵����������Կ��Ǳߵ�(note)��\n",me);return 1;}
  if(topic=="key")
    {if(!(ob->query("roomid"))) {message_vision("$N˵�����ף���������з�����\n",me);return 1;}
     key=new(__DIR__"obj/key");key->set("owner",ob->query("id"));
     key->set("long","һ�Ѿ��µ�Կ�ס�һ��д�ţ����ƽ֣���һ��д�ţ�"+ob->query("name")+"��\n");
     message_vision("$N�ݸ�$nһ��Կ�ף�������ķ���Կ�ף��ú��ˡ�\n",me,ob);
     key->move(ob);return 1;}
  if(topic=="��Ҫ����")
    {if(ob->query_temp("inbuild")) {message_vision("$N��$n˵�����㻹ûѡ�õط���\n",me,ob);return 1;}
     if(ob->query("roomid")>0) 
       {message_vision("$N��$n˵�����㲻���з����𣿻�������Ҫ����Կ�װɡ�\n",me,ob);return 1;}
     message_vision("$N��$n˵����Ҫ�ڷ��ƽ�ס�°��������ġ�\n",me,ob);
     message_vision("$N˵��������Ҫ300gold��500�ۺ����۵Ķ���\n",me);
     gold=present("gold_money",ob);
     if(!gold) {message_vision("$N��$n˵����������û��goldҮ��\n",me,ob);return 1;}
     if(gold->query_amount()<300||ob->query("score")<500)
      {message_vision("$N��$n˵�������gold���ۺ����ۺ��񲻹�Ү��\n",me,ob);
       return 1;}
     ob->add("score",-500);gold->add_amount(-300);
     builder=new(__DIR__"builder");builder->set("owner",ob->query("id"));
     builder->move(environment(ob));builder->set_leader(ob);
     message_vision("$N���˵�ͷ�������ں�����$n��\n",me,builder);
     message_vision("$N�������߳�����\n",builder);ob->set_temp("inbuild",1);
     message_vision("$N��$n˵����������ȥѡ�ط��ɡ�\n\n",me,ob);
     return 1;
    }
   rest=read_file(__DIR__"room.list");
   if(topic=="����ס��")
    {message_vision("$N˵����Ŀǰ�Ѿ��ڷ��ƽ�ס�µ��кպ������ģ�\n",me);   
     while(rest!="")
      {sscanf(rest,":%s,%s:%s",owner,roomid,rest);message_vision("  "+owner,me);}
     message_vision("\n$N˵���������ѯ�����ǵķ������Ķ���\n\n",me);
     return 1;
    }
   if(sscanf(topic,"%s�ķ���",topicowner)==1)
    {if(topicowner=="��") topicowner=ob->query("name");
      while(rest!="")
      {sscanf(rest,":%s,%s:%s",owner,roomid,rest);
       if(topicowner==owner)
        {sscanf(roomid,"%d",i);
	dir1="��";if(i%2) dir1="��";
        message_vision("$N˵����"+owner+"�ķ����Ƿ��ƽ�"+
             chinese_number((i)/100)+"��"+dir1+"��",me);
        message_vision("���콾�Ž�ȥ����"+chinese_number((i)/100)+"��"+dir1+"���������ǡ�\n\n",me);
        return 1;
      } }
     message_vision("$N˵����"+topicowner+"Ŀǰ�ڷ��ƽֻ�û���Լ��ķ��ӡ�\n\n",me);
     return 1;
    }
message_vision("$N˵������������ң���������Ҫ����������ס����key��\n\n",me);
return 1;
}