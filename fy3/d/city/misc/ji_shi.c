//Cracked by Roath

#include <ansi.h> 
#include <room.h> 
#include <login.h> 
  
inherit ROOM; 
  
string look_sign(); 
  
void create() 
{ 
        set("short", "�� �� �� ��"); 
        set("long", @LONG 
�����ǳ����Ǽ��С����ֵĵ��̶�����һ���š�һ�شص���Ƿ�ơ� 
һ����һ���Ľ������ڸ����ֿڡ�С����˺���Ӧ�����಻������
�е� ��ڴ�������һ������(sign)�� 
LONG 
        ); 
  
        set("outdoors", "changan"); 
  
        set("item_desc", ([ 
                "sign": @TEXT 
���������������������顣 
  
join        ��ʼ������ 
  
TEXT 
        ]) ); 
  
        set("exits", ([ 
            "east" : "/d/city/beiyin1.c",
        ]) ); 
  
        set("no_fight", 1); 
        set("no_magic",1); 
  
/*
        set("objects", ([ 
               "/d/changan/npc/qianmian": 1, 
        ]) ); 
*/
  
        setup(); 
} 
  
void init() 
{ 
        add_action("do_join", "join"); 
        add_action("do_quit", "quit");
} 
  
int do_join(string arg) 
{ 
       string *name = ({ "˽��","ˮ��","ʳƷ","�¾�","�ʻ�","��ҩ","ú̿", 
                "�Ŷ�","�鱦","����","�ֻ�","ľ��","����","����","����","ũ��", 
                "��ƥ","��ƥ","����","�ӻ�", });
        object me; 
        string tempstr, namestr; 
  
        me = this_player(); 
  
        if(me->query_temp("working") == 1) 
                return notify_fail("���Ѿ��ڷ��������ˣ�\n"); 
  
        namestr = name[random(sizeof(name))]; 
        tempstr = "$N��ʼ����" + namestr + "....\n"; 
        message_vision(tempstr, me); 
  
        if( namestr == "˽��" ) { 
                tempstr = "�ٱ���$N׽��������������" + namestr + 
                        "������ǿ�ͷ����������\n"; 
                message_vision(tempstr, me); 
                if( random(10) == 0 ) {         // ������� 
                        me->set("startroom", START_ROOM ); 
                        me->move( __DIR__"dalao" ); 
                        set("name", "�ٸ�"); 
                        set("id", "guanfu"); 
                        set("channel_id","���Ƹ�ʾ");
                        CHANNEL_D->do_channel(this_object(), "chat", 
                                HIY+me->name() + "����" + namestr + 
                                "����������Σ��Ⱥ����ն������"NOR ); 
                } 
                else { 
                        if( random(20) == 0 ) { 
                                switch( random(9) ) { 
case 0: tempstr = "/d/city/recycle"; 
        break; 
case 1: tempstr = "/d/kaifeng/donghu"+(random(5)+1); 
        break; 
case 2: tempstr = "/d/qujing/dudi/shanlu" + ( random(10) + 1); 
        break; 
case 3: tempstr = "/d/qujing/wuzhuang/wzgmaze" + ( random(8) + 1); 
        break; 
case 4: tempstr = "/d/qujing/tianzhu/jiedao" + ( random(8) + 91); 
        break; 
case 5: tempstr = "/d/qujing/nuerguo/townc" + ( random(3) + 1); 
        break; 
case 6: tempstr = "/d/qujing/fengxian/jiedao" + ( random(14) + 1); 
        break; 
case 7: tempstr = "/d/qujing/yinwu/caopo" + ( random(5) + 1); 
        break; 
case 8: tempstr = "/d/sea/maze" + ( random(7)); 
        break; 
                                } 
                            
                                me->set("startroom", tempstr ); 
tempstr = "$N�ͳ����һ����Ʊ�Թٱ�˵����ү���кðɣ��Ҽһ��а�ʮ���������....\n" 
        + "�ٱ�����Ʊһ�����������뻳�У�̽��̽ͷ�������������ˣ��ȵ�����ô�٣�\n" 
        + "�ٱ�һ�Ž�$N�ߵ��������⣺�����㷷��" + namestr + "���»���׽������ͷ���� \n"; 
                                message_vision(tempstr, me); 
                               me->move( tempstr ); 
                        } 
                        else {                  
                                me->set("startroom", START_ROOM ); 
tempstr = "�ٱ�һ�Ű�$N���˳����������㷷��" + namestr 
        + "���»���׽������ͷ����\n"; 
                                message_vision(tempstr, me); 
                               me->move( START_ROOM ); 
                        } 
                } 
                return 1; 
        } 
  
        me->set_temp("working", 1); 
        me->set_temp("no_quit",1);
        call_out( "compelete_join", 4+random(8), me ); 
        return 1; 
} 
  
private void compelete_join(object me) 
{ 
        object ob; 
        int i, n; 
  
        if (!me) return; 
        me->delete_temp("working"); 
        if( present(me) ) { 
                message_vision("$N��չ���⣬����Ȼ�ۻ��ˣ��������治С��\n", me);  
                me->add("kee", -25); 
                me->add("sen", -25); 
                me->add("potential", (me->query("combat_exp") >= 15000) ? 
                        random(4) : 8+random(10) ); 
                me->add("daoxing", (me->query("combat_exp") >= 15000) ? 

                        random(6) : 8+random(8)); 
                n = random(10* me->query("kar")) / 30; 
                if (me->query("combat_exp")>=15000)  n=random(3);
                ob = new("/obj/money/silver"); 
                ob->set_amount(n+1); 
                ob->move(me); 
                tell_object(me, "���Ǳ�ܺ͵��������ˣ�\n"); 
                tell_object(me, sprintf("��׬��"HIW"%s"NOR"�����ӡ�\n", chinese_number(n+1))); 
        } 
  
        return; 
}

int do_quit(object me)
{
        me = this_player();
	if(me->query_temp("working"))
	{
	write("���⻹û���꣬�����\n");
	return 1;
         }
else return 0;
}
	
