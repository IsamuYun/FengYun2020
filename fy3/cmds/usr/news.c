#include <ansi.h>;
inherit BULLETIN_BOARD;
int do_post(string arg);

void create()
{
    set_name("������", ({ "news_board"}) );
        set("board_id", "news_b");    
    set("long","�������д��д�˾ͻ���Ч���Ҳ���ɾ��ԭ code ����xgchen��д\n\n");         
        setup();
        set("capacity", 1000);
}

int check_news(object me)
{
        int num,i,last_time_read;
        mapping *notes, last_read_time;
        string myid,msg="";
        
        notes = query("notes");
        last_read_time = me->query("board_last_read");
        myid = query("board_id");
        
        if( !pointerp(notes) || !sizeof(notes) ) return 1;

        if(userp(me))
        {
                i=sizeof(notes)-me->query("LastReadNews");
                
                if(i < 6 && i > 0) // С��6�����Ų���ʾ���⣬��Ȼ��FLOOD
                {
                        msg = "\n\n    ������������������������ "HIW"���ַ���2������Ϣ"NOR" ������������������������    \n";
                        
                        if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
                                num = 1;
                                
                        else
                                for(num = 1; num<=sizeof(notes); num++)
                                        if( notes[num-1]["time"] > last_read_time[myid] ) break;
                                        
                        if (mapp(last_read_time)) last_time_read = last_read_time[myid];
                        for(i=sizeof(notes)-1 ; i>num-2 ; i--)
                        {
                                msg += sprintf("<%3d>"NOR,i+1);
                                msg += sprintf("     %-=36s %18s (%s)\n",
                                        notes[i]["title"], notes[i]["author"],
                                        CHINESE_D->chinese_time(5, ctime(notes[i]["time"])));
                        }
                        
                        msg += "    ����������������������������������������������������������������    \n\n";
                        
                        me->start_more(msg);
                }
                
                i=sizeof(notes)-me->query("LastReadNews");
      if (i<0) i=0;
                write("\n�����ϴ��Ķ�������"+((i==0)? "û���κ�":"����"+HIY+chinese_number(i)+NOR"��")+"���š�\n\n");
                if(i>10) 
  //             me->start_call_out(bind((: call_other, __FILE__, "auto_notice", me :), me), 10 + random(10));
write("\n����� Help news ���鿴���ַ���2����ϵͳ��ʹ�÷�����\n"); // ���Ѳ�֪����NEWSϵͳ�����ʹ��news
        }
}
int main(object me, string arg)
{
        int num,i,last_time_read;
        mapping *notes, last_read_time;
        string myid,msg;

        last_read_time = me->query("board_last_read");
        myid = query("board_i");
        notes = query("notes");
        i=sizeof(notes)-me->query("LastReadNews");
        if( !pointerp(notes) || !sizeof(notes) )
                return notify_fail("�����ַ���2��Ŀǰû���κ����š�\n");
                
        if( !arg ) 
      {
      if (i<0) i=0;
                if(i>10) write("����� Help news ���鿴���ַ���2����ϵͳ��ʹ�÷�����\n"); 
                        return notify_fail(
                                "�����ַ���2��Ŀǰ����"+HIW+chinese_number(sizeof(notes))+NOR"������"+((i==0)? "��":"������"+HIY+chinese_number(i)+NOR"��������δ�Ķ���")+"\n"); }
                                
if(arg=="jia")
{
return do_post("���ַ���2");
}
                if( arg=="all") // ��ʾ��������
                {
                        msg = "\n\n    ������������������������ "HIW"���ַ���2����һ��"NOR" ������������������������    \n";
                        notes = query("notes");
                        
                        if (mapp(last_read_time)) last_time_read = last_read_time[myid];
                        for(i=sizeof(notes)-1 ; i>-1 ; i--)
                        {
                                msg += sprintf("%s<%3d>" NOR,
                                notes[i]["time"] > last_time_read ? HIY: "", i+1);
                                msg += sprintf("     %-=36s %18s (%s)\n",
                                        notes[i]["title"], notes[i]["author"],
                                        CHINESE_D->chinese_time(5, ctime(notes[num]["time"])));
                        }
                        msg += "\n";
                        me->start_more(msg);
                        return 1;
                        
                }
                else
                if ( arg=="new" )  // ��ʾ��������
                {
                        if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
                                num = 1;
                        else
                                for(num = 1; num<=sizeof(notes); num++)
                                        if( notes[num-1]["time"] > last_read_time[myid] ) break;
                                        
                } else if( !sscanf(arg, "%d", num) )
                
        return notify_fail("�㵽��Ҫ���ڼ�������ѽ��\n");
        
        if( num < 1 || num > sizeof(notes) )
                return notify_fail("������㣬����û����������Ү��\n");
                
        num--;
     me->start_more( sprintf("\n\n%s\n
[47;34m  ���� [44;37m %-70s
[47;34m  ���� [44;37m %-70s
[47;34m  ʱ�� [44;37m %-70s[m  [36m\n------------------------------------------------------------------------------[m\n\n\n",
               BBLU HIY"����"HIR"����"HIG"��"+chinese_number(num + 1)+"������"NOR, 
notes[num]["author"],notes[num]["title"],ctime(notes[num]["time"]))
+ notes[num]["msg"]+
        HIY"\n\n\t\t\t���ַ���2"NOR"\n-------------------------------------------------------------------------------\n\n", );

        if( !mapp(last_read_time) )
                me->set("board_last_read", ([ myid: notes[num]["time"] ]) );
        else 
                if( undefinedp(last_read_time[myid]) || notes[num]["time"] > last_read_time[myid] )
                        last_read_time[myid] = notes[num]["time"];

        if(me->query("LastReadNews") < num + 1)
                me->set("LastReadNews",num+1);

        return 1;
}

void init()
{
        object me=this_player();
// ֻ��apprentice�������ϵ���ʦ�޸�����
       if (wizardp(me) &&  wiz_level(me) > wiz_level("(apprentice)") )
        {
                add_action("do_post", "jia");
             //   add_action("do_discard", "qu");
      } 
}

int do_post(string arg)
{
        mapping note;

        if(!arg) return notify_fail("����Ҫ������Ŀ��\n");

        note = allocate_mapping(4);
        note["title"] = arg;
      note["author"] = this_player()->query("name")+"("+this_player()->query("id")+")";
        note["id"] = this_player()->query("id"); 
        note["qianminglong"] = this_player()->query("qianminglong"); 
        this_player()->edit( (: done_post, this_player(), note :) );
        return 1;
}

void done_post(object me, mapping note, string text)
{
        mapping *notes;

        note["time"] = time();
        note["msg"] = text;
        notes = query("notes");
        if( !pointerp(notes) || !sizeof(notes) )
                notes = ({ note });
        else
                notes += ({ note });

        if( sizeof(notes) > query("capacity"))
                notes = notes[query("capacity")/2 .. query("capacity")];

        set("notes", notes);
        save();
        restore();
// ʹ��channel��ʾ��ʾ������������
        CHANNEL_D->do_channel(me, "fy", BLINK HIR"\n\n�����ַ���2�������������ţ�����(news new)�鿴��\n" NOR);

        tell_object(me, "���ŷ�����ϡ�\n");

        return;
}
/*
void auto_notice(object me)
{
        int num;
        mapping *notes;
        string msg;
        int last_read_time;

        if (! objectp(me))
                return;

        last_read_time = me->query("last_read_news");
        notes = query("notes");

        if (! pointerp(notes) || ! sizeof(notes))
                return;

        num = sizeof(notes) - 1;
        if (notes[num]["time"] <= last_read_time)
                return;

        // some news need read, start next call out
        me->start_call_out(bind((: call_other, __FILE__, "auto_notice", me :), me), 30 + random(30));

        if (! living(me) || me->query_temp("block_msg/all"))
                return;

        while (num-- > 0)
        {
                if (notes[num]["time"] <= last_read_time)
                {
                        num++;
                        break;
                }

                // contine to find next
        }

        if (num < 0) num = 0;

        switch (random(5))
        {
        case 0:
                msg = HIM "һ�������������ž�������������ǰ������"
                      "����һ���������õ�ֽͷ����������������\n" NOR;
                break;
        case 1:
                msg = HIM "����ͻȻ����һ���ѷ죬ð��һ�������������"
                      "�ž��飬��������ੲ��ݵ�����������\n" NOR;
                break;
        case 2:
                msg = HIM "���Ȼ�������˺��㣬���ͷһ����ԭ��������"
                      "������ͷ�󺹵����˹�����\n" NOR;
                break;
        case 3:
                msg = HIM "��մ���һ����Ƿ����Ȼǰ��ð��һ��������ɢ"
                      "ȥ�Ժ�ֻ��һ�����ž���������Ŀ����㣬���������дʡ�\n" NOR;
                break;
        default:
                msg = HIM "��ž����һ�������ž����Ǳ�������ˤ�ڵ��ϣ�"
                      "����æ��������\n" NOR;
                break;
        }

        msg += HIG "���ž����������������������Ϣ��\n" NOR;
        tell_object(me, msg);
     me->start_more( sprintf("\n\n%s\n
[47;34m  ���� [44;37m %-70s
[47;34m  ���� [44;37m %-70s
[47;34m  ʱ�� [44;37m %-70s[m  [36m\n------------------------------------------------------------------------------[m\n\n\n",
               BBLU HIY"һ��"HIR"����"HIG"��"+chinese_number(num + 1)+"������"NOR, 
notes[num]["author"],notes[num]["title"],ctime(notes[num]["time"]))
+ notes[num]["msg"]+
        HIY"\n\n\t\t\t���ַ���2"NOR"\n-------------------------------------------------------------------------------\n\n", );

        // Keep track which post we were reading last time.
        if (notes[num]["time"] > (int)last_read_time)
                me->set("last_read_news", notes[num]["time"]);
        tell_object(me, HIM "���ž���˵�����ʧ��һ������֮�С�\n" NOR);
}

*/
int help(object me)
{
    write(@HELP
�����ַ���2������ϵͳָ�� 

ָ���ʽ :
news                    �鿴���еĺ����·��������š�
news all                ���ַ���2����һ���� 
news new                �Ķ����µ����š� 
news <���ű��>         �鿴�˱�����ŵ���ϸ���ݡ� 
HELP
    );
    return 1;
}