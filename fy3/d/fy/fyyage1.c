//xgchen@fy
// 2002 
#include <ansi.h>
inherit ROOM;
void close_path();
void create()
{
        set("short", "�����Ÿ�");
        set("long", @LONG
����ר���д�����������������������������������ģ�����һ��ǧ��ĺ��ͣ�
���Ƕ��Ž����Ĳ���һ�����������䷿�ӵ�����ֻ��һ���ϵȴ����ĥ�ɵİ�������
���Ϸ�����ֻ���ͽ𱭡������ǽ�Ϲ������ֻ���ʣ�µ�һ����һ��һ�����صĺ첼
������
LONG
        );
        set("exits", ([
                "down" : __DIR__"fyge",
                "east" : __DIR__"fysf",
        ]));
        set("objects", ([
                __DIR__"npc/servent": 1,
                __DIR__"npc/champion":1,
        ]) );
        set("item_desc", ([
                "curtain": "����첼�����ƺ������ƿ�(open)��\n",
                "����" : "����첼�����ƺ������ƿ�(open)��\n",
                "�첼����" : "����첼�����ƺ������ƿ�(open)��\n"
        ]) );
        set("NONPC",1);
        set("coor/x",10);
        set("coor/y",10);
        set("coor/z",10);
        set("coor/x",10);
        set("coor/y",10);
        set("coor/z",10);
        setup();
}

void init()
{
        add_action("do_open", "open");
        add_action("do_job", "job");
        add_action("do_fail", "fail");
        add_action("do_done", "done");
}
void close_path()
{
        if( !query("exits/north") ) return;
        message("vision",
"�첼������������������ס�˰��š�\n",
                this_object() );
                delete("exits/north");
}


int do_open(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg=="" ) return 0;

        if( arg=="curtain" || arg =="�첼����" || arg=="����") {
                write("���ƿ��첼������");
        if( (int) me->query("force_factor") >= 100 )
                {
                write("�ƿ��˺����򱱵�һ�Ȱ��š�\n");
                if( !query("exits/west") ) {
                set("exits/north", __DIR__"fysecret");
                call_out("close_path", 5);
                                                }
                return 1;       
                }
                else
                write("���������ƺ���İ��ţ���û���ƿ���\n");
                return 1;
        }
                write("��Ҫ�ƿ�ʲô��\n");
}
int do_job()
{      
        object me;
        me = this_player(); 
    
   // if(me->query("mengzhujob") > 3500)
   // {
   //             tell_object(me,"������������˵����������������׵ģ����ǻ����������鰲�š�\n");
    //            return 1;    	
   // }        
    if( me->query("job/sxy-done")>0)
    {
                tell_object(me,"������Ȱ��ϴε����񱨸����Ժ������Ҫ����\n");
                return 1;
    } 
    else 
        if(time()-(int)me->query("done_time") < 60&&me->query("done-time"))
    {
                tell_object(me,"������������˵���������������ˣ���ȥ��Ϣ�����ӡ�\n");
                return 1;
    }
    if( me->query("job/sxy")>0)
    {
                tell_object(me,"������������˵�������Ѿ����������ˣ���ȥ��\n");
                return 1;
     }
    else 
    if( me->query("combat_exp")<10000000)
    {
                tell_object(me,"������������˵����������������׵ģ�������β��Ƕ�Ϸ����Ҫ����������\n");
                return 1;
    }
    else 
   // if( me->query("combat_exp")>20000000)
  //  {
    //            tell_object(me,"������������˵����������������׵ģ����ǻ����������鰲�š�\n");
      //          return 1;
  //  }
    message_vision(CYN"����������$N˵���������ȥ�ɣ�Ϊ���������֣�������ɱ��Ƭ�ײ�����\n"NOR,me); 
        me->set("job/sxy", 1);
        me->set("job/sxy-time", time());
        me->apply_condition("sxy-job", 8*6);
        return 1;   
}

int do_done()
{      

        object me,ob;
        int gong,exp,pot,money,reb;
        me = this_player();
        reb = me->query("reborned");
        gong = me->query("job/gong");
        exp =(random(1800)+455)*gong;
        pot = (random(735)+115)*gong;
        money = gong * 2; 
        
      exp = exp + exp/5*reb;
      pot = pot + pot/5*reb;
      money = money + money/5*reb;
    if( me->query("job/sxy-done")!= 1)
    {
                tell_object(me,"������������˵����ս��Ҫʤ������ҪŬ���ѵ��˻��ˡ�\n");
                return 1;
    }

    message_vision(WHT"����������$N˵�������ò������ս��ʤ�����㹦����Ĩ��\n"NOR,me);
    message_vision(WHT"����������$N˵�������ܹ�����" + gong + "������\n"NOR,me);     
    message_vision(WHT"����������$N˵����������" + exp + "�㾭�飬" + pot + "��Ǳ�ܣ�" + money + "�����ۣ�ϣ���Ժ����Ŭ����\n"NOR,me);        
    me->add("combat_exp",exp+1);
    me->add("potential",pot+1);
    me->add("score",money);
    me->delete("job/gong");
    me->delete("job/sxy");
    me->delete("job/sxy-done");
    me->set("done_time",time());
    me->add("mengzhujob",1);
    return 1;
}
int do_fail()
{
        object me,ob;
        me = this_player();
    if( time()-(int)me->query("job/sxy-time")<1200)
{
                tell_object(me,"������������˵����û����������Ҫ��20���Ӳſ�������Ҫ�����!\n");
                return 1;
    }
    me->delete("job/gong");
    me->delete("job/sxy");
    me->delete("job/sxy-done");
    me->set("done_time",time()+600);
    return 1;
}
int valid_leave(object me, string dir)
{
        object ob;
        int i;
        if( dir == "north" && ob=present("royal servant", this_object()))
        {
        message_vision("$N��$n�ȵ������ȥ����������˵����\n", ob,me);
        ob->kill_ob(me);
        return notify_fail("���ӣ�\n");
        }
        else
                return 1;
}


